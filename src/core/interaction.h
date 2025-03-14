
/*
    pbrt source code is Copyright(c) 1998-2016
                        Matt Pharr, Greg Humphreys, and Wenzel Jakob.

    This file is part of pbrt.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are
    met:

    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
    IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
    TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef PBRT_CORE_INTERACTION_H
#define PBRT_CORE_INTERACTION_H

// core/interaction.h*
#include "geometry.h"
#include "material.h"
#include "medium.h"
#include "pbrt.h"
#include "transform.h"

namespace pbrt {

/**
 * @brief 交互作用类，记录了光线相交处的局部属性
 * @param p 交点
 * @param time 时间
 * @param pError 误差上界
 * @param wo 出射光线方向，没有出射交互默认退化为`(0, 0, 0)`
 * @param n 交点的法线
 * @param mediumInterface 散射介质接口
 *
 */
struct Interaction {
    // Interaction Public Methods
    Interaction() : time(0) {}
    Interaction(const Point3f& p, const Normal3f& n, const Vector3f& pError,
                const Vector3f& wo, Float time,
                const MediumInterface& mediumInterface)
        : p(p),
          time(time),
          pError(pError),
          wo(Normalize(wo)),
          n(n),
          mediumInterface(mediumInterface) {}
    bool IsSurfaceInteraction() const { return n != Normal3f(); }
    Ray SpawnRay(const Vector3f& d) const {
        Point3f o = OffsetRayOrigin(p, pError, n, d);
        return Ray(o, d, Infinity, time, GetMedium(d));
    }
    Ray SpawnRayTo(const Point3f& p2) const {
        Point3f origin = OffsetRayOrigin(p, pError, n, p2 - p);
        Vector3f d = p2 - p;
        return Ray(origin, d, 1 - ShadowEpsilon, time, GetMedium(d));
    }
    Ray SpawnRayTo(const Interaction& it) const {
        Point3f origin = OffsetRayOrigin(p, pError, n, it.p - p);
        Point3f target = OffsetRayOrigin(it.p, it.pError, it.n, origin - it.p);
        Vector3f d = target - origin;
        return Ray(origin, d, 1 - ShadowEpsilon, time, GetMedium(d));
    }
    Interaction(const Point3f& p, const Vector3f& wo, Float time,
                const MediumInterface& mediumInterface)
        : p(p), time(time), wo(wo), mediumInterface(mediumInterface) {}
    Interaction(const Point3f& p, Float time,
                const MediumInterface& mediumInterface)
        : p(p), time(time), mediumInterface(mediumInterface) {}
    bool IsMediumInteraction() const { return !IsSurfaceInteraction(); }
    const Medium* GetMedium(const Vector3f& w) const {
        return Dot(w, n) > 0 ? mediumInterface.outside : mediumInterface.inside;
    }
    const Medium* GetMedium() const {
        CHECK_EQ(mediumInterface.inside, mediumInterface.outside);
        return mediumInterface.inside;
    }

    // Interaction Public Data
    Point3f p;
    Float time;
    Vector3f pError;
    Vector3f wo;
    Normal3f n;
    MediumInterface mediumInterface;
};

class MediumInteraction : public Interaction {
  public:
    // MediumInteraction Public Methods
    MediumInteraction() : phase(nullptr) {}
    MediumInteraction(const Point3f& p, const Vector3f& wo, Float time,
                      const Medium* medium, const PhaseFunction* phase)
        : Interaction(p, wo, time, medium), phase(phase) {}
    bool IsValid() const { return phase != nullptr; }

    // MediumInteraction Public Data
    const PhaseFunction* phase;
};

/**
 * @brief
 * 曲面表面交互作用类，记录了光线相交处的局部属性和几何特征，继承自`Interaction`
 * @param p 交点
 * @param time 时间
 * @param pError 误差上界
 * @param wo 出射光线方向，没有出射交互默认退化为`(0, 0, 0)`
 * @param n 交点的法线
 * @param uv 交点的uv坐标，曲面方程的参数
 * @param dpdu
 * 交点处的曲面参数方程对`u`的偏导，固定`v`，`dpdu`表示经过`v`点，在`u`方向上的曲线切线
 * @param dpdv
 * 交点处的曲面参数方程对`v`的偏导，固定`u`，`dpdv`表示经过`u`点，在`v`方向上的曲线切线
 * @param dndu
 * 交点处的法向量参数方程对`u`的偏导，表示固定`v`时，法线沿`u`方向的变化率
 * @param dndv
 * 交点处的法向量参数方程对`v`的偏导，表示固定`u`时，法线沿`v`方向的变化率
 * @param sh 形状（曲面）
 * @param faceIndex 面索引
 * @param shading 交点处的着色几何信息,用于凹凸贴图或者三角形插值中的扰动值
 */
class SurfaceInteraction : public Interaction {
  public:
    // SurfaceInteraction Public Methods
    SurfaceInteraction() {}
    SurfaceInteraction(const Point3f& p, const Vector3f& pError,
                       const Point2f& uv, const Vector3f& wo,
                       const Vector3f& dpdu, const Vector3f& dpdv,
                       const Normal3f& dndu, const Normal3f& dndv, Float time,
                       const Shape* sh, int faceIndex = 0);
    void SetShadingGeometry(const Vector3f& dpdu, const Vector3f& dpdv,
                            const Normal3f& dndu, const Normal3f& dndv,
                            bool orientationIsAuthoritative);
    void ComputeScatteringFunctions(
        const RayDifferential& ray, MemoryArena& arena,
        bool allowMultipleLobes = false,
        TransportMode mode = TransportMode::Radiance);
    void ComputeDifferentials(const RayDifferential& r) const;
    Spectrum Le(const Vector3f& w) const;

    // SurfaceInteraction Public Data
    Point2f uv;
    Vector3f dpdu, dpdv;
    Normal3f dndu, dndv;
    const Shape* shape = nullptr;
    struct {  // 交点处的着色几何信息
        Normal3f n;
        Vector3f dpdu, dpdv;
        Normal3f dndu, dndv;
    } shading;
    const Primitive* primitive = nullptr;
    BSDF* bsdf = nullptr;
    BSSRDF* bssrdf = nullptr;
    mutable Vector3f dpdx, dpdy;
    mutable Float dudx = 0, dvdx = 0, dudy = 0, dvdy = 0;

    // Added after book publication. Shapes can optionally provide a face
    // index with an intersection point for use in Ptex texture lookups.
    // If Ptex isn't being used, then this value is ignored.
    int faceIndex = 0;
};

}  // namespace pbrt

#endif  // PBRT_CORE_INTERACTION_H
