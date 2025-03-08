
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

#ifndef PBRT_CORE_GEOMETRY_H
    #define PBRT_CORE_GEOMETRY_H

    // core/geometry.h*
    #include <iterator>
    #include "pbrt.h"
    #include "stringprint.h"

namespace pbrt {

/**
 * @brief 判断是否为`NaN`
 * @return 如果`x`是`NaN`，返回`true`，否则返回`false`
 */
template <typename T>
inline bool isNaN(const T x) {
    return std::isnan(x);
}
template <>
inline bool isNaN(const int x) {
    return false;
}

/**
 * @brief 二维向量
 * @param x 第一维参数
 * @param y 第二维参数
 */
template <typename T>
class Vector2 {
   public:
    // Vector2 Public Methods

    Vector2() { x = y = 0; }
    Vector2(T xx, T yy) : x(xx), y(yy) { DCHECK(!HasNaNs()); }
    bool HasNaNs() const { return isNaN(x) || isNaN(y); }
    explicit Vector2(const Point2<T>& p);
    explicit Vector2(const Point3<T>& p);
    #ifndef NDEBUG  // 调试模式
    // The default versions of these are fine for release builds; for debug
    // we define them so that we can add the Assert checks.

    Vector2(const Vector2<T>& v) {
        DCHECK(!v.HasNaNs());
        x = v.x;
        y = v.y;
    }
    Vector2<T>& operator=(const Vector2<T>& v) {
        DCHECK(!v.HasNaNs());
        x = v.x;
        y = v.y;
        return *this;
    }
    #endif  // !NDEBUG

    Vector2<T> operator+(const Vector2<T>& v) const {
        DCHECK(!v.HasNaNs());
        return Vector2(x + v.x, y + v.y);
    }

    Vector2<T>& operator+=(const Vector2<T>& v) {
        DCHECK(!v.HasNaNs());
        x += v.x;
        y += v.y;
        return *this;
    }
    Vector2<T> operator-(const Vector2<T>& v) const {
        DCHECK(!v.HasNaNs());
        return Vector2(x - v.x, y - v.y);
    }

    Vector2<T>& operator-=(const Vector2<T>& v) {
        DCHECK(!v.HasNaNs());
        x -= v.x;
        y -= v.y;
        return *this;
    }
    bool operator==(const Vector2<T>& v) const { return x == v.x && y == v.y; }
    bool operator!=(const Vector2<T>& v) const { return x != v.x || y != v.y; }
    template <typename U>
    Vector2<T> operator*(U f) const {
        return Vector2<T>(f * x, f * y);
    }

    template <typename U>
    Vector2<T>& operator*=(U f) {
        DCHECK(!isNaN(f));
        x *= f;
        y *= f;
        return *this;
    }
    template <typename U>
    Vector2<T> operator/(U f) const {
        CHECK_NE(f, 0);  // 检查除数是否为0
        Float inv = (Float)1 / f;
        return Vector2<T>(x * inv, y * inv);
    }

    template <typename U>
    Vector2<T>& operator/=(U f) {
        CHECK_NE(f, 0);
        Float inv = (Float)1 / f;
        x *= inv;
        y *= inv;
        return *this;
    }
    Vector2<T> operator-() const { return Vector2<T>(-x, -y); }

    /**
     * @brief 重载`[]`运算符，使用`const`常量修饰，不允许修改成员变量。
     * @return 第`i`维的值
     */
    T operator[](int i) const {
        DCHECK(i >= 0 && i <= 1);
        if (i == 0) return x;
        return y;
    }

    /**
     * @brief 重载`[]`运算符
     * @return 第`i`维的值
     */
    T& operator[](int i) {
        DCHECK(i >= 0 && i <= 1);
        if (i == 0) return x;
        return y;
    }

    /**
     * @brief 计算向量的长度的平方
     */
    Float LengthSquared() const { return x * x + y * y; }

    /**
     * @brief 计算向量的长度
     */
    Float Length() const { return std::sqrt(LengthSquared()); }

    // Vector2 Public Data

    T x, y;
};

/**
 * @brief 重载`<<`运算符，输出`[ x, y ]`
 */
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Vector2<T>& v) {
    os << "[ " << v.x << ", " << v.y << " ]";
    return os;
}
/**
 * @brief 特化浮点类型`Float`，确保以小数格式输出，重载`<<`运算符，输出`[ x, y ]`
 */
template <>
inline std::ostream& operator<<(std::ostream& os, const Vector2<Float>& v) {
    os << StringPrintf("[ %f, %f ]", v.x, v.y);
    return os;
}

/**
 * @brief 三维向量
 * @param x 第一维参数
 * @param y 第二维参数
 * @param z 第三维参数
 */
template <typename T>
class Vector3 {
   public:
    // Vector3 Public Methods

    /**
     * @brief 重载`[]`运算符，使用`const`常量修饰，不允许修改成员变量。
     * @return 第`i`维的值
     */
    T operator[](int i) const {
        DCHECK(i >= 0 && i <= 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    /**
     * @brief 重载`[]`运算符
     * @return 第`i`维的值
     */
    T& operator[](int i) {
        DCHECK(i >= 0 && i <= 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }
    Vector3() { x = y = z = 0; }
    Vector3(T x, T y, T z) : x(x), y(y), z(z) { DCHECK(!HasNaNs()); }
    bool HasNaNs() const { return isNaN(x) || isNaN(y) || isNaN(z); }
    explicit Vector3(const Point3<T>& p);
    #ifndef NDEBUG
    // The default versions of these are fine for release builds; for debug
    // we define them so that we can add the Assert checks.
    Vector3(const Vector3<T>& v) {
        DCHECK(!v.HasNaNs());
        x = v.x;
        y = v.y;
        z = v.z;
    }

    Vector3<T>& operator=(const Vector3<T>& v) {
        DCHECK(!v.HasNaNs());
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
    #endif  // !NDEBUG
    Vector3<T> operator+(const Vector3<T>& v) const {
        DCHECK(!v.HasNaNs());
        return Vector3(x + v.x, y + v.y, z + v.z);
    }
    Vector3<T>& operator+=(const Vector3<T>& v) {
        DCHECK(!v.HasNaNs());
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    Vector3<T> operator-(const Vector3<T>& v) const {
        DCHECK(!v.HasNaNs());
        return Vector3(x - v.x, y - v.y, z - v.z);
    }
    Vector3<T>& operator-=(const Vector3<T>& v) {
        DCHECK(!v.HasNaNs());
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    bool operator==(const Vector3<T>& v) const { return x == v.x && y == v.y && z == v.z; }
    bool operator!=(const Vector3<T>& v) const { return x != v.x || y != v.y || z != v.z; }
    template <typename U>
    Vector3<T> operator*(U s) const {
        return Vector3<T>(s * x, s * y, s * z);
    }
    template <typename U>
    Vector3<T>& operator*=(U s) {
        DCHECK(!isNaN(s));
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
    template <typename U>
    Vector3<T> operator/(U f) const {
        CHECK_NE(f, 0);  // 检查除数是否为0
        Float inv = (Float)1 / f;
        return Vector3<T>(x * inv, y * inv, z * inv);
    }

    template <typename U>
    Vector3<T>& operator/=(U f) {
        CHECK_NE(f, 0);
        Float inv = (Float)1 / f;
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }
    Vector3<T> operator-() const { return Vector3<T>(-x, -y, -z); }

    /**
     * @brief 计算向量的长度的平方
     */
    Float LengthSquared() const { return x * x + y * y + z * z; }

    /**
     * @brief 计算向量的长度
     */
    Float Length() const { return std::sqrt(LengthSquared()); }
    explicit Vector3(const Normal3<T>& n);

    // Vector3 Public Data

    T x, y, z;
};

/**
 * @brief 重载`<<`运算符，输出`[ x, y, z ]`
 */
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Vector3<T>& v) {
    os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
    return os;
}

/**
 * @brief 特化浮点类型`Float`，确保以小数格式输出，重载`<<`运算符，输出`[ x, y, z ]`
 */
template <>
inline std::ostream& operator<<(std::ostream& os, const Vector3<Float>& v) {
    os << StringPrintf("[ %f, %f, %f ]", v.x, v.y, v.z);
    return os;
}

typedef Vector2<Float> Vector2f;
typedef Vector2<int>   Vector2i;
typedef Vector3<Float> Vector3f;
typedef Vector3<int>   Vector3i;

/**
 * @brief 二维坐标
 * @param x 第一维参数
 * @param y 第二维参数
 */
template <typename T>
class Point2 {
   public:
    // Point2 Public Methods
    /**
     * @brief 三维坐标舍弃`z`分量转换为二维坐标，禁止隐式转换。
     * @param p 三维坐标
     */
    explicit Point2(const Point3<T>& p) : x(p.x), y(p.y) { DCHECK(!HasNaNs()); }
    Point2() { x = y = 0; }
    Point2(T xx, T yy) : x(xx), y(yy) { DCHECK(!HasNaNs()); }

    /**
     * @brief 给定`U`类型的坐标，显式构造`T`类型坐标，禁止隐式转换。
     *
     * 例如：
     *
     * `Point2i p(1, 2);`
     *
     * `Point2f pf = static_cast<Point2f>(p);`
     *
     *
     * @param p 类型为`U`的二维坐标
     */
    template <typename U>
    explicit Point2(const Point2<U>& p) {
        x = (T)p.x;
        y = (T)p.y;
        DCHECK(!HasNaNs());
    }

    /**
     * @brief 给定`U`类型向量，显式构造`T`类型坐标，禁止隐式转换。
     *
     * 例如：
     *
     * `Vector2i v(1, 2);`
     *
     * `Point2f pf = static_cast<Point2f>(v);`
     *
     *
     * @param p 类型为`U`的二维向量
     */
    template <typename U>
    explicit Point2(const Vector2<U>& p) {
        x = (T)p.x;
        y = (T)p.y;
        DCHECK(!HasNaNs());
    }

    /**
     * @brief 重载`Vector2()`
     *
     * 将`T`类型的坐标显式转化为`U`类型的向量，禁止隐式转换。该功能已在Vector2中实现。
     *
     * 例如：
     *
     * `Point2i  p(1, 2);`
     *
     * `Vector2i vi = static_cast<Vector2i>(p);`
     *@return 一个新的`Vector2<U>`类型的向量
     */
    template <typename U>
    explicit operator Vector2<U>() const {
        return Vector2<U>(x, y);
    }

    #ifndef NDEBUG
    Point2(const Point2<T>& p) {
        DCHECK(!p.HasNaNs());
        x = p.x;
        y = p.y;
    }

    Point2<T>& operator=(const Point2<T>& p) {
        DCHECK(!p.HasNaNs());
        x = p.x;
        y = p.y;
        return *this;
    }
    #endif  // !NDEBUG
    /**
     * @brief 坐标加向量
     * @return 新的二维坐标
     */
    Point2<T> operator+(const Vector2<T>& v) const {
        DCHECK(!v.HasNaNs());
        return Point2<T>(x + v.x, y + v.y);
    }

    Point2<T>& operator+=(const Vector2<T>& v) {
        DCHECK(!v.HasNaNs());
        x += v.x;
        y += v.y;
        return *this;
    }
    Vector2<T> operator-(const Point2<T>& p) const {
        DCHECK(!p.HasNaNs());
        return Vector2<T>(x - p.x, y - p.y);
    }

    Point2<T> operator-(const Vector2<T>& v) const {
        DCHECK(!v.HasNaNs());
        return Point2<T>(x - v.x, y - v.y);
    }
    Point2<T>  operator-() const { return Point2<T>(-x, -y); }
    Point2<T>& operator-=(const Vector2<T>& v) {
        DCHECK(!v.HasNaNs());
        x -= v.x;
        y -= v.y;
        return *this;
    }
    Point2<T>& operator+=(const Point2<T>& p) {
        DCHECK(!p.HasNaNs());
        x += p.x;
        y += p.y;
        return *this;
    }
    Point2<T> operator+(const Point2<T>& p) const {
        DCHECK(!p.HasNaNs());
        return Point2<T>(x + p.x, y + p.y);
    }
    template <typename U>
    Point2<T> operator*(U f) const {
        return Point2<T>(f * x, f * y);
    }
    template <typename U>
    Point2<T>& operator*=(U f) {
        x *= f;
        y *= f;
        return *this;
    }
    template <typename U>
    Point2<T> operator/(U f) const {
        CHECK_NE(f, 0);
        Float inv = (Float)1 / f;
        return Point2<T>(inv * x, inv * y);
    }
    template <typename U>
    Point2<T>& operator/=(U f) {
        CHECK_NE(f, 0);
        Float inv = (Float)1 / f;
        x *= inv;
        y *= inv;
        return *this;
    }
    T operator[](int i) const {
        DCHECK(i >= 0 && i <= 1);
        if (i == 0) return x;
        return y;
    }

    T& operator[](int i) {
        DCHECK(i >= 0 && i <= 1);
        if (i == 0) return x;
        return y;
    }
    bool operator==(const Point2<T>& p) const { return x == p.x && y == p.y; }
    bool operator!=(const Point2<T>& p) const { return x != p.x || y != p.y; }
    bool HasNaNs() const { return isNaN(x) || isNaN(y); }

    // Point2 Public Data
    T x, y;
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Point2<T>& v) {
    os << "[ " << v.x << ", " << v.y << " ]";
    return os;
}

template <>
inline std::ostream& operator<<(std::ostream& os, const Point2<Float>& v) {
    os << StringPrintf("[ %f, %f ]", v.x, v.y);
    return os;
}

/**
 * @brief 三维坐标
 * @param T 坐标元素类型
 * @param x 第一维参数
 * @param y 第二维参数
 * @param z 第三维参数
 */
template <typename T>
class Point3 {
   public:
    // Point3 Public Methods

    Point3() { x = y = z = 0; }
    Point3(T x, T y, T z) : x(x), y(y), z(z) { DCHECK(!HasNaNs()); }

    /**
     * @brief 给定`U`类型的坐标，显式构造`T`类型坐标，禁止隐式转换。
     *
     * 例如：
     *
     * `Point3i p(1, 2, 3);`
     *
     * `Point3f pf = static_cast<Point3f>(p);`
     *
     *
     * @param p 类型为`U`的三维坐标
     */
    template <typename U>
    explicit Point3(const Point3<U>& p) : x((T)p.x), y((T)p.y), z((T)p.z) {
        DCHECK(!HasNaNs());
    }

    /**
     * @brief 给定`U`类型的向量，显式构造`T`类型坐标，禁止隐式转换。
     *
     * 例如：
     *
     * `Vector3i v(1, 2, 3);`
     *
     * `Point3f pf = static_cast<Point3f>(v);`
     *
     *
     * @param p 类型为`U`的三维坐标
     */
    template <typename U>
    explicit operator Vector3<U>() const {
        return Vector3<U>(x, y, z);
    }
    #ifndef NDEBUG
    Point3(const Point3<T>& p) {
        DCHECK(!p.HasNaNs());
        x = p.x;
        y = p.y;
        z = p.z;
    }

    Point3<T>& operator=(const Point3<T>& p) {
        DCHECK(!p.HasNaNs());
        x = p.x;
        y = p.y;
        z = p.z;
        return *this;
    }
    #endif  // !NDEBUG
    Point3<T> operator+(const Vector3<T>& v) const {
        DCHECK(!v.HasNaNs());
        return Point3<T>(x + v.x, y + v.y, z + v.z);
    }
    Point3<T>& operator+=(const Vector3<T>& v) {
        DCHECK(!v.HasNaNs());
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    Vector3<T> operator-(const Point3<T>& p) const {
        DCHECK(!p.HasNaNs());
        return Vector3<T>(x - p.x, y - p.y, z - p.z);
    }
    Point3<T> operator-(const Vector3<T>& v) const {
        DCHECK(!v.HasNaNs());
        return Point3<T>(x - v.x, y - v.y, z - v.z);
    }
    Point3<T>& operator-=(const Vector3<T>& v) {
        DCHECK(!v.HasNaNs());
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    Point3<T>& operator+=(const Point3<T>& p) {
        DCHECK(!p.HasNaNs());
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    Point3<T> operator+(const Point3<T>& p) const {
        DCHECK(!p.HasNaNs());
        return Point3<T>(x + p.x, y + p.y, z + p.z);
    }
    template <typename U>
    Point3<T> operator*(U f) const {
        return Point3<T>(f * x, f * y, f * z);
    }
    template <typename U>
    Point3<T>& operator*=(U f) {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
    template <typename U>
    Point3<T> operator/(U f) const {
        CHECK_NE(f, 0);
        Float inv = (Float)1 / f;
        return Point3<T>(inv * x, inv * y, inv * z);
    }
    template <typename U>
    Point3<T>& operator/=(U f) {
        CHECK_NE(f, 0);
        Float inv = (Float)1 / f;
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }
    T operator[](int i) const {
        DCHECK(i >= 0 && i <= 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    T& operator[](int i) {
        DCHECK(i >= 0 && i <= 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }
    bool      operator==(const Point3<T>& p) const { return x == p.x && y == p.y && z == p.z; }
    bool      operator!=(const Point3<T>& p) const { return x != p.x || y != p.y || z != p.z; }
    bool      HasNaNs() const { return isNaN(x) || isNaN(y) || isNaN(z); }
    Point3<T> operator-() const { return Point3<T>(-x, -y, -z); }

    // Point3 Public Data

    T x, y, z;
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Point3<T>& v) {
    os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
    return os;
}

template <>
inline std::ostream& operator<<(std::ostream& os, const Point3<Float>& v) {
    os << StringPrintf("[ %f, %f, %f ]", v.x, v.y, v.z);
    return os;
}

typedef Point2<Float> Point2f;
typedef Point2<int>   Point2i;
typedef Point3<Float> Point3f;
typedef Point3<int>   Point3i;

/**
 * @brief 三维法线，定义于曲面上一点，任意两条不平行的切线的外积方向。
 *
 * 法线不能与坐标相加，也没有外积运算。
 * @param T 法线元素类型
 * @param x 第一维参数
 * @param y 第二维参数
 * @param z 第三维参数
 */
template <typename T>
class Normal3 {
   public:
    // Normal3 Public Methods

    Normal3() { x = y = z = 0; }
    Normal3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) { DCHECK(!HasNaNs()); }
    Normal3<T> operator-() const { return Normal3(-x, -y, -z); }
    Normal3<T> operator+(const Normal3<T>& n) const {
        DCHECK(!n.HasNaNs());
        return Normal3<T>(x + n.x, y + n.y, z + n.z);
    }

    Normal3<T>& operator+=(const Normal3<T>& n) {
        DCHECK(!n.HasNaNs());
        x += n.x;
        y += n.y;
        z += n.z;
        return *this;
    }
    Normal3<T> operator-(const Normal3<T>& n) const {
        DCHECK(!n.HasNaNs());
        return Normal3<T>(x - n.x, y - n.y, z - n.z);
    }

    Normal3<T>& operator-=(const Normal3<T>& n) {
        DCHECK(!n.HasNaNs());
        x -= n.x;
        y -= n.y;
        z -= n.z;
        return *this;
    }
    bool HasNaNs() const { return isNaN(x) || isNaN(y) || isNaN(z); }
    template <typename U>
    Normal3<T> operator*(U f) const {
        return Normal3<T>(f * x, f * y, f * z);
    }

    template <typename U>
    Normal3<T>& operator*=(U f) {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
    template <typename U>
    Normal3<T> operator/(U f) const {
        CHECK_NE(f, 0);
        Float inv = (Float)1 / f;
        return Normal3<T>(x * inv, y * inv, z * inv);
    }

    template <typename U>
    Normal3<T>& operator/=(U f) {
        CHECK_NE(f, 0);
        Float inv = (Float)1 / f;
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }

    /**
     * @brief 计算法线的长度的平方
     */
    Float LengthSquared() const { return x * x + y * y + z * z; }

    /**
     * @brief 计算法线的长度
     */
    Float Length() const { return std::sqrt(LengthSquared()); }

    #ifndef NDEBUG
    Normal3<T>(const Normal3<T>& n) {
        DCHECK(!n.HasNaNs());
        x = n.x;
        y = n.y;
        z = n.z;
    }

    Normal3<T>& operator=(const Normal3<T>& n) {
        DCHECK(!n.HasNaNs());
        x = n.x;
        y = n.y;
        z = n.z;
        return *this;
    }
    #endif  // !NDEBUG
    explicit Normal3<T>(const Vector3<T>& v) : x(v.x), y(v.y), z(v.z) { DCHECK(!v.HasNaNs()); }
    bool operator==(const Normal3<T>& n) const { return x == n.x && y == n.y && z == n.z; }
    bool operator!=(const Normal3<T>& n) const { return x != n.x || y != n.y || z != n.z; }

    T operator[](int i) const {
        DCHECK(i >= 0 && i <= 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    T& operator[](int i) {
        DCHECK(i >= 0 && i <= 2);
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    // Normal3 Public Data
    T x, y, z;
};

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Normal3<T>& v) {
    os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
    return os;
}

template <>
inline std::ostream& operator<<(std::ostream& os, const Normal3<Float>& v) {
    os << StringPrintf("[ %f, %f, %f ]", v.x, v.y, v.z);
    return os;
}

typedef Normal3<Float> Normal3f;

/**
 * @brief 二维轴对齐包围盒（边界框）
 * @param T 包围盒元素类型
 * @param pMin 最小点
 * @param pMax 最大点，与`pMin`构成对顶角
 */
template <typename T>
class Bounds2 {
   public:
    // Bounds2 Public Methods

    // 默认构造一个无穷大的包围盒
    Bounds2() {
        T minNum = std::numeric_limits<T>::lowest();
        T maxNum = std::numeric_limits<T>::max();
        pMin     = Point2<T>(maxNum, maxNum);
        pMax     = Point2<T>(minNum, minNum);
    }
    explicit Bounds2(const Point2<T>& p) : pMin(p), pMax(p) {}
    Bounds2(const Point2<T>& p1, const Point2<T>& p2) {
        pMin = Point2<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
        pMax = Point2<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y));
    }
    /**
     * @brief 不同类型变量显示转换
     */
    template <typename U>
    explicit operator Bounds2<U>() const {
        return Bounds2<U>((Point2<U>)pMin, (Point2<U>)pMax);
    }

    Vector2<T> Diagonal() const { return pMax - pMin; }
    T          Area() const {
        Vector2<T> d = pMax - pMin;
        return (d.x * d.y);
    }

    /**
     * @return 包围盒最长的边的索引
     */
    int MaximumExtent() const {
        Vector2<T> diag = Diagonal();
        if (diag.x > diag.y)
            return 0;
        else
            return 1;
    }
    inline const Point2<T>& operator[](int i) const {
        DCHECK(i == 0 || i == 1);
        return (i == 0) ? pMin : pMax;
    }
    inline Point2<T>& operator[](int i) {
        DCHECK(i == 0 || i == 1);
        return (i == 0) ? pMin : pMax;
    }
    bool operator==(const Bounds2<T>& b) const { return b.pMin == pMin && b.pMax == pMax; }
    bool operator!=(const Bounds2<T>& b) const { return b.pMin != pMin || b.pMax != pMax; }

    /**
     * @brief 对顶角之间线性插值
     */
    Point2<T> Lerp(const Point2f& t) const { return Point2<T>(pbrt::Lerp(t.x, pMin.x, pMax.x), pbrt::Lerp(t.y, pMin.y, pMax.y)); }

    /**
     * @brief 计算点`p`相对于包围盒的偏移量`o`，`o`的每个分量都在[0, 1]之间
     * @param p 二维坐标(一般位于包围盒内)
     */
    Vector2<T> Offset(const Point2<T>& p) const {
        Vector2<T> o = p - pMin;
        if (pMax.x > pMin.x) o.x /= pMax.x - pMin.x;
        if (pMax.y > pMin.y) o.y /= pMax.y - pMin.y;
        return o;
    }

    /**
     * @brief 计算包围盒的外接球(如果有)的半径
     * @param c 待返回的参数，外接球的中心
     * @param rad 待返回的参数，外接球的半径，如果不存在外接球则`rad`为0
     */
    void BoundingSphere(Point2<T>* c, Float* rad) const {
        *c   = (pMin + pMax) / 2;
        *rad = Inside(*c, *this) ? Distance(*c, pMax) : 0;
    }
    friend std::ostream& operator<<(std::ostream& os, const Bounds2<T>& b) {
        os << "[ " << b.pMin << " - " << b.pMax << " ]";
        return os;
    }

    // Bounds2 Public Data
    Point2<T> pMin, pMax;
};

/**
 * @brief 三维轴对齐包围盒（边界框）
 * @param T 包围盒元素类型
 * @param pMin 最小点
 * @param pMax 最大点，与`pMin`构成对顶角
 */
template <typename T>
class Bounds3 {
   public:
    // Bounds3 Public Methods

    // 默认构造一个无穷大的包围盒
    Bounds3() {
        T minNum = std::numeric_limits<T>::lowest();
        T maxNum = std::numeric_limits<T>::max();
        pMin     = Point3<T>(maxNum, maxNum, maxNum);
        pMax     = Point3<T>(minNum, minNum, minNum);
    }
    explicit Bounds3(const Point3<T>& p) : pMin(p), pMax(p) {}
    Bounds3(const Point3<T>& p1, const Point3<T>& p2)
        : pMin(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z)),
          pMax(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z)) {}

    const Point3<T>& operator[](int i) const;
    Point3<T>&       operator[](int i);
    bool             operator==(const Bounds3<T>& b) const { return b.pMin == pMin && b.pMax == pMax; }
    bool             operator!=(const Bounds3<T>& b) const { return b.pMin != pMin || b.pMax != pMax; }

    /**
     * @brief 返回包围盒的8个角坐标
     * @param corner 角索引，限制`corner`在[0, 8)之间
     */
    Point3<T> Corner(int corner) const {
        DCHECK(corner >= 0 && corner < 8);
        return Point3<T>((*this)[(corner & 1)].x, (*this)[(corner & 2) ? 1 : 0].y, (*this)[(corner & 4) ? 1 : 0].z);
    }
    Vector3<T> Diagonal() const { return pMax - pMin; }
    T          SurfaceArea() const {
        Vector3<T> d = Diagonal();
        return 2 * (d.x * d.y + d.x * d.z + d.y * d.z);
    }
    T Volume() const {
        Vector3<T> d = Diagonal();
        return d.x * d.y * d.z;
    }

    /**
     * @return 包围盒最长的边的索引
     */
    int MaximumExtent() const {
        Vector3<T> d = Diagonal();
        if (d.x > d.y && d.x > d.z)
            return 0;
        else if (d.y > d.z)
            return 1;
        else
            return 2;
    }

    /**
     * @brief 对顶角之间线性插值
     */
    Point3<T> Lerp(const Point3f& t) const {
        return Point3<T>(pbrt::Lerp(t.x, pMin.x, pMax.x), pbrt::Lerp(t.y, pMin.y, pMax.y), pbrt::Lerp(t.z, pMin.z, pMax.z));
    }

    /**
     * @brief 计算点`p`相对于包围盒的偏移量`o`，`o`的每个分量都在[0, 1]之间
     * @param p 三维坐标(一般位于包围盒内)
     */
    Vector3<T> Offset(const Point3<T>& p) const {
        Vector3<T> o = p - pMin;
        if (pMax.x > pMin.x) o.x /= pMax.x - pMin.x;
        if (pMax.y > pMin.y) o.y /= pMax.y - pMin.y;
        if (pMax.z > pMin.z) o.z /= pMax.z - pMin.z;
        return o;
    }
    void BoundingSphere(Point3<T>* center, Float* radius) const {
        *center = (pMin + pMax) / 2;
        *radius = Inside(*center, *this) ? Distance(*center, pMax) : 0;
    }
    template <typename U>
    explicit operator Bounds3<U>() const {
        return Bounds3<U>((Point3<U>)pMin, (Point3<U>)pMax);
    }
    bool                 IntersectP(const Ray& ray, Float* hitt0 = nullptr, Float* hitt1 = nullptr) const;
    inline bool          IntersectP(const Ray& ray, const Vector3f& invDir, const int dirIsNeg[3]) const;
    friend std::ostream& operator<<(std::ostream& os, const Bounds3<T>& b) {
        os << "[ " << b.pMin << " - " << b.pMax << " ]";
        return os;
    }

    // Bounds3 Public Data

    Point3<T> pMin, pMax;
};

typedef Bounds2<Float> Bounds2f;
typedef Bounds2<int>   Bounds2i;
typedef Bounds3<Float> Bounds3f;
typedef Bounds3<int>   Bounds3i;

/**
 * @brief `Bounds2i`的迭代器，对于二维整数型包围盒，可以通过迭代器遍历包围盒内的所有像素。
 *
 * 例如：
 *
 * `Bounds2i tileBounds(Point2i(x0, y0), Point2i(x1, y1));`
 *
    `for (Point2i pixel : tileBounds) {//...}`
 * @param b: Bounds2i
 * @param pt: 二维坐标
 */
class Bounds2iIterator : public std::forward_iterator_tag {
   public:
    Bounds2iIterator(const Bounds2i& b, const Point2i& pt) : p(pt), bounds(&b) {}
    // 前置递增运算符
    Bounds2iIterator operator++() {
        advance();
        return *this;
    }
    // 后置递增运算符
    Bounds2iIterator operator++(int) {
        Bounds2iIterator old = *this;
        advance();
        return old;
    }
    bool operator==(const Bounds2iIterator& bi) const { return p == bi.p && bounds == bi.bounds; }
    bool operator!=(const Bounds2iIterator& bi) const { return p != bi.p || bounds != bi.bounds; }

    Point2i operator*() const { return p; }  // 解引用

   private:
    void advance() {
        ++p.x;
        if (p.x == bounds->pMax.x) {  // 下一行
            p.x = bounds->pMin.x;
            ++p.y;
        }
    }
    Point2i         p;
    const Bounds2i* bounds;
};
/**
 * @brief 射线，r = o + t * d ，t表示射线上的某点位置，
 * @param o 起始坐标
 * @param d 射线方向
 * @param time 射线参数在有动画的场景中，`time`表示和场景关联的一个时间值
 * @param tMax 参数`t`的上限，表示射线最大长度。
 * @param medium 射线端点所在的介质属性（如空气、水、玻璃等）
 */
class Ray {
   public:
    // Ray Public Methods
    Ray() : tMax(Infinity), time(0.f), medium(nullptr) {}
    Ray(const Point3f& o, const Vector3f& d, Float tMax = Infinity, Float time = 0.f, const Medium* medium = nullptr)
        : o(o), d(d), tMax(tMax), time(time), medium(medium) {}
    /**
     * @param t 射线参数
     * @return 射线在参数`t`处的位置
     */
    Point3f              operator()(Float t) const { return o + d * t; }
    bool                 HasNaNs() const { return (o.HasNaNs() || d.HasNaNs() || isNaN(tMax)); }
    friend std::ostream& operator<<(std::ostream& os, const Ray& r) {
        os << "[o=" << r.o << ", d=" << r.d << ", tMax=" << r.tMax << ", time=" << r.time << "]";
        return os;
    }

    // Ray Public Data

    Point3f       o;
    Vector3f      d;
    mutable Float tMax;  // mutable 修饰的变量，可以在const函数中修改。
    Float         time;
    const Medium* medium;
};

/**
 * @brief 继承自`Ray`，表示差分射线，在抗锯齿中对相邻像素和射线采样。
 * @param hasDifferentials 是否使用差分射线，如果为`true` 则表示使用差分射线，否则表示不使用差分射线，可以视为对象`Ray`。
 * @param rxOrigin
 * @param ryOrigin
 * @param rxDirection
 * @param ryDirection
 */
class RayDifferential : public Ray {
   public:
    // RayDifferential Public Methods

    RayDifferential() { hasDifferentials = false; }
    RayDifferential(const Point3f& o, const Vector3f& d, Float tMax = Infinity, Float time = 0.f, const Medium* medium = nullptr)
        : Ray(o, d, tMax, time, medium) {
        hasDifferentials = false;
    }
    RayDifferential(const Ray& ray) : Ray(ray) { hasDifferentials = false; }

    bool HasNaNs() const {
        return Ray::HasNaNs() || (hasDifferentials && (rxOrigin.HasNaNs() || ryOrigin.HasNaNs() || rxDirection.HasNaNs() || ryDirection.HasNaNs()));
    }
    /**
     * @brief 放缩差分参数
     */
    void ScaleDifferentials(Float s) {
        rxOrigin    = o + (rxOrigin - o) * s;
        ryOrigin    = o + (ryOrigin - o) * s;
        rxDirection = d + (rxDirection - d) * s;
        ryDirection = d + (ryDirection - d) * s;
    }
    friend std::ostream& operator<<(std::ostream& os, const RayDifferential& r) {
        os << "[ " << (Ray&)r << " has differentials: " << (r.hasDifferentials ? "true" : "false") << ", xo = " << r.rxOrigin
           << ", xd = " << r.rxDirection << ", yo = " << r.ryOrigin << ", yd = " << r.ryDirection << " ]";
        return os;
    }

    // RayDifferential Public Data

    bool     hasDifferentials;
    Point3f  rxOrigin, ryOrigin;
    Vector3f rxDirection, ryDirection;
};

// Geometry Inline Functions
template <typename T>
inline Vector3<T>::Vector3(const Point3<T>& p) : x(p.x), y(p.y), z(p.z) {
    DCHECK(!HasNaNs());
}

template <typename T, typename U>
inline Vector3<T> operator*(U s, const Vector3<T>& v) {
    return v * s;
}
template <typename T>
Vector3<T> Abs(const Vector3<T>& v) {
    return Vector3<T>(std::abs(v.x), std::abs(v.y), std::abs(v.z));
}

/**
 * @brief 内积
 * @param T 向量元素类型
 * @param v1 向量1
 * @param v2 向量2
 * @return 内积值
 */
template <typename T>
inline T Dot(const Vector3<T>& v1, const Vector3<T>& v2) {
    DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

/**
 * @brief 内积绝对值
 * @param v1 向量1
 * @param v2 向量2
 * @return 内积绝对值
 */
template <typename T>
inline T AbsDot(const Vector3<T>& v1, const Vector3<T>& v2) {
    DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
    return std::abs(Dot(v1, v2));
}

/**
 * @brief 外积（左手系，逆时针）
 * @param v1 向量
 * @param v2 向量
 * @return 三维的外积向量
 */
template <typename T>
inline Vector3<T> Cross(const Vector3<T>& v1, const Vector3<T>& v2) {
    DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
    // 固定转化为双精度类型
    double v1x = v1.x, v1y = v1.y, v1z = v1.z;
    double v2x = v2.x, v2y = v2.y, v2z = v2.z;
    return Vector3<T>((v1y * v2z) - (v1z * v2y), (v1z * v2x) - (v1x * v2z), (v1x * v2y) - (v1y * v2x));
}

/**
 * @brief 外积（左手系，逆时针）
 * @param v1 向量
 * @param v2 法线
 * @return 三维的外积向量
 */
template <typename T>
inline Vector3<T> Cross(const Vector3<T>& v1, const Normal3<T>& v2) {
    DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
    // 固定转化为双精度类型
    double v1x = v1.x, v1y = v1.y, v1z = v1.z;
    double v2x = v2.x, v2y = v2.y, v2z = v2.z;
    return Vector3<T>((v1y * v2z) - (v1z * v2y), (v1z * v2x) - (v1x * v2z), (v1x * v2y) - (v1y * v2x));
}

/**
 * @brief 外积（左手系，逆时针）
 * @param v1 法线
 * @param v2 向量
 * @return 三维的外积向量
 */
template <typename T>
inline Vector3<T> Cross(const Normal3<T>& v1, const Vector3<T>& v2) {
    DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
    // 固定转化为双精度类型
    double v1x = v1.x, v1y = v1.y, v1z = v1.z;
    double v2x = v2.x, v2y = v2.y, v2z = v2.z;
    return Vector3<T>((v1y * v2z) - (v1z * v2y), (v1z * v2x) - (v1x * v2z), (v1x * v2y) - (v1y * v2x));
}

/**
 * @brief 规范化为单位向量
 * @return 单位化三维向量
 */
template <typename T>
inline Vector3<T> Normalize(const Vector3<T>& v) {
    return v / v.Length();
}
/**
 * @brief 求三维向量的最小分量
 * @return 分量最小值
 */
template <typename T>
T MinComponent(const Vector3<T>& v) {
    return std::min(v.x, std::min(v.y, v.z));
}
/**
 * @brief 求三维向量的最大分量
 * @return 分量最大值
 */
template <typename T>
T MaxComponent(const Vector3<T>& v) {
    return std::max(v.x, std::max(v.y, v.z));
}
/**
 * @brief 求三维向量最大分量的维度
 * @return `[0,3)`的最大分量维度
 */
template <typename T>
int MaxDimension(const Vector3<T>& v) {
    return (v.x > v.y) ? ((v.x > v.z) ? 0 : 2) : ((v.y > v.z) ? 1 : 2);
}
/**
 * @brief 在两个向量中，取每个分量的较小值组成新的向量
 * @return 最小三维分量向量
 */
template <typename T>
Vector3<T> Min(const Vector3<T>& p1, const Vector3<T>& p2) {
    return Vector3<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z));
}

/**
 * @brief 在两个向量中，取每个分量的较大值组成新的向量
 * @return 最大三维分量向量
 */
template <typename T>
Vector3<T> Max(const Vector3<T>& p1, const Vector3<T>& p2) {
    return Vector3<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z));
}
/**
 * @brief 根据给定索引重新排列向量分量
 * @param v 三维向量
 * @param x 第一维索引
 * @param y 第二维索引
 * @param z 第三维索引
 * @return 按索引重新排列的三维向量
 */
template <typename T>
Vector3<T> Permute(const Vector3<T>& v, int x, int y, int z) {
    return Vector3<T>(v[x], v[y], v[z]);
}

/**
 * @brief 给定一个单位向量，构造一个单位正交坐标系
 * @param v1 已知单位向量
 * @param v2 构造的单位向量
 * @param v3 构造的单位向量
 */
template <typename T>
inline void CoordinateSystem(const Vector3<T>& v1, Vector3<T>* v2, Vector3<T>* v3) {
    if (std::abs(v1.x) > std::abs(v1.y))
        *v2 = Vector3<T>(-v1.z, 0, v1.x) / std::sqrt(v1.x * v1.x + v1.z * v1.z);
    else
        *v2 = Vector3<T>(0, v1.z, -v1.y) / std::sqrt(v1.y * v1.y + v1.z * v1.z);
    *v3 = Cross(v1, *v2);
}

template <typename T>
Vector2<T>::Vector2(const Point2<T>& p) : x(p.x), y(p.y) {
    DCHECK(!HasNaNs());
}

template <typename T>
Vector2<T>::Vector2(const Point3<T>& p) : x(p.x), y(p.y) {
    DCHECK(!HasNaNs());
}

template <typename T, typename U>
inline Vector2<T> operator*(U f, const Vector2<T>& v) {
    return v * f;
}
template <typename T>
inline Float Dot(const Vector2<T>& v1, const Vector2<T>& v2) {
    DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
    return v1.x * v2.x + v1.y * v2.y;
}

template <typename T>
inline Float AbsDot(const Vector2<T>& v1, const Vector2<T>& v2) {
    DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
    return std::abs(Dot(v1, v2));
}

/**
 * @brief 规范化为单位向量
 * @return 单位话二维向量
 */
template <typename T>
inline Vector2<T> Normalize(const Vector2<T>& v) {
    return v / v.Length();
}

/**
 * @brief 逐元素取绝对值
 */
template <typename T>
Vector2<T> Abs(const Vector2<T>& v) {
    return Vector2<T>(std::abs(v.x), std::abs(v.y));
}

/**
 * @brief 求两点间距离
 * @return 平方欧氏距离
 */
template <typename T>
inline Float Distance(const Point3<T>& p1, const Point3<T>& p2) {
    return (p1 - p2).Length();
}

/**
 * @brief 求两点间距离的平方
 * @return 平方欧氏距离
 */
template <typename T>
inline Float DistanceSquared(const Point3<T>& p1, const Point3<T>& p2) {
    return static_cast<Vector3<T>>(p1 - p2).LengthSquared();
}

template <typename T, typename U>
inline Point3<T> operator*(U f, const Point3<T>& p) {
    DCHECK(!p.HasNaNs());
    return p * f;
}

/**
 * @brief 求两点间的线性插值坐标
 * @param t 插值系数，当`t = 0`时，返回`v0`，当`t = 1`时，返回`v1`.
 * @return 位于`v0`和`v1`的直线上的三维坐标点
 */
template <typename T>
Point3<T> Lerp(Float t, const Point3<T>& p0, const Point3<T>& p1) {
    return (1 - t) * p0 + t * p1;
}

/**
 * @brief 在两个点中，取每个分量的较小值组成新的坐标
 * @return 最小三维分量坐标
 */
template <typename T>
Point3<T> Min(const Point3<T>& p1, const Point3<T>& p2) {
    return Point3<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z));
}

/**
 * @brief 在两个点中，取每个分量的较小值组成新的坐标
 * @return 最大三维分量坐标
 */
template <typename T>
Point3<T> Max(const Point3<T>& p1, const Point3<T>& p2) {
    return Point3<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z));
}

/**
 * @brief 逐元素向下取整
 */
template <typename T>
Point3<T> Floor(const Point3<T>& p) {
    return Point3<T>(std::floor(p.x), std::floor(p.y), std::floor(p.z));
}

/**
 * @brief 逐元素向上取整
 */
template <typename T>
Point3<T> Ceil(const Point3<T>& p) {
    return Point3<T>(std::ceil(p.x), std::ceil(p.y), std::ceil(p.z));
}

/**
 * @brief 逐元素取绝对值
 */
template <typename T>
Point3<T> Abs(const Point3<T>& p) {
    return Point3<T>(std::abs(p.x), std::abs(p.y), std::abs(p.z));
}

/**
 * @brief 求两点间距离
 * @return F浮点型距离
 */
template <typename T>
inline Float Distance(const Point2<T>& p1, const Point2<T>& p2) {
    return (p1 - p2).Length();
}

/**
 * @brief 求两点间距离
 * @return 浮点型距离
 */
template <typename T>
inline Float DistanceSquared(const Point2<T>& p1, const Point2<T>& p2) {
    return static_cast<Vector2<T>>(p1 - p2).LengthSquared();
}

template <typename T, typename U>
inline Point2<T> operator*(U f, const Point2<T>& p) {
    DCHECK(!p.HasNaNs());
    return p * f;
}

/**
 * @brief 逐元素向下取整
 */
template <typename T>
Point2<T> Floor(const Point2<T>& p) {
    return Point2<T>(std::floor(p.x), std::floor(p.y));
}

/**
 * @brief 逐元素向上取整
 */
template <typename T>
Point2<T> Ceil(const Point2<T>& p) {
    return Point2<T>(std::ceil(p.x), std::ceil(p.y));
}

/**
 * @brief 求两点间的线性插值坐标
 * @param t 插值系数，当`t = 0`时，返回`v0`，当`t = 1`时，返回`v1`.
 * @return 位于`v0`和`v1`的直线上的二维坐标点
 */
template <typename T>
Point2<T> Lerp(Float t, const Point2<T>& v0, const Point2<T>& v1) {
    return (1 - t) * v0 + t * v1;
}

/**
 * @brief 在两个点中，取每个分量的较小值组成新的坐标
 * @return 最二维小分量坐标
 */
template <typename T>
Point2<T> Min(const Point2<T>& pa, const Point2<T>& pb) {
    return Point2<T>(std::min(pa.x, pb.x), std::min(pa.y, pb.y));
}

/**
 * @brief 在两个点中，取每个分量的较大值组成新的坐标
 * @return 最大二维分量坐标
 */
template <typename T>
Point2<T> Max(const Point2<T>& pa, const Point2<T>& pb) {
    return Point2<T>(std::max(pa.x, pb.x), std::max(pa.y, pb.y));
}

template <typename T>
Point3<T> Permute(const Point3<T>& p, int x, int y, int z) {
    return Point3<T>(p[x], p[y], p[z]);
}

template <typename T, typename U>
inline Normal3<T> operator*(U f, const Normal3<T>& n) {
    return Normal3<T>(f * n.x, f * n.y, f * n.z);
}

/**
 * @brief 规范化为单位向量
 * @return 规范化的三维法向量
 */
template <typename T>
inline Normal3<T> Normalize(const Normal3<T>& n) {
    return n / n.Length();
}

template <typename T>
inline Vector3<T>::Vector3(const Normal3<T>& n) : x(n.x), y(n.y), z(n.z) {
    DCHECK(!n.HasNaNs());
}

template <typename T>
inline T Dot(const Normal3<T>& n1, const Vector3<T>& v2) {
    DCHECK(!n1.HasNaNs() && !v2.HasNaNs());
    return n1.x * v2.x + n1.y * v2.y + n1.z * v2.z;
}

template <typename T>
inline T Dot(const Vector3<T>& v1, const Normal3<T>& n2) {
    DCHECK(!v1.HasNaNs() && !n2.HasNaNs());
    return v1.x * n2.x + v1.y * n2.y + v1.z * n2.z;
}

template <typename T>
inline T Dot(const Normal3<T>& n1, const Normal3<T>& n2) {
    DCHECK(!n1.HasNaNs() && !n2.HasNaNs());
    return n1.x * n2.x + n1.y * n2.y + n1.z * n2.z;
}

template <typename T>
inline T AbsDot(const Normal3<T>& n1, const Vector3<T>& v2) {
    DCHECK(!n1.HasNaNs() && !v2.HasNaNs());
    return std::abs(n1.x * v2.x + n1.y * v2.y + n1.z * v2.z);
}

template <typename T>
inline T AbsDot(const Vector3<T>& v1, const Normal3<T>& n2) {
    DCHECK(!v1.HasNaNs() && !n2.HasNaNs());
    return std::abs(v1.x * n2.x + v1.y * n2.y + v1.z * n2.z);
}

template <typename T>
inline T AbsDot(const Normal3<T>& n1, const Normal3<T>& n2) {
    DCHECK(!n1.HasNaNs() && !n2.HasNaNs());
    return std::abs(n1.x * n2.x + n1.y * n2.y + n1.z * n2.z);
}

/**
 * @brief 调整法线方向，使其与指定向量方向一致（方向夹角小于90度）
 * @param n 待调整法线
 * @param v 指定向量方向
 * @return 若法线与指定向量方向一致，返回`n`，否则返回`-n`
 */
template <typename T>
inline Normal3<T> Faceforward(const Normal3<T>& n, const Vector3<T>& v) {
    return (Dot(n, v) < 0.f) ? -n : n;
}

/**
 * @brief 调整法线方向，使其与指定法线方向一致（方向夹角小于90度）
 * @param n 待调整法线
 * @param n2 指定法线方向
 * @return 若法线与指定法线方向一致，返回`n`，否则返回`-n`
 */
template <typename T>
inline Normal3<T> Faceforward(const Normal3<T>& n, const Normal3<T>& n2) {
    return (Dot(n, n2) < 0.f) ? -n : n;
}

/**
 * @brief 调整向量方向，使其与指定向量方向一致（方向夹角小于90度）
 * @param v 待调整向量
 * @param v2 指定向量方向
 * @return 若向量与指定向量方向一致，返回`v`，否则返回`-v`
 */
template <typename T>
inline Vector3<T> Faceforward(const Vector3<T>& v, const Vector3<T>& v2) {
    return (Dot(v, v2) < 0.f) ? -v : v;
}

/**
 * @brief 调整向量方向，使其与指定法线方向一致（方向夹角小于90度）
 * @param v 待调整向量
 * @param n2 指定法线方向
 * @return 若向量与指定法线方向一致，返回`v`，否则返回`-v`
 */
template <typename T>
inline Vector3<T> Faceforward(const Vector3<T>& v, const Normal3<T>& n2) {
    return (Dot(v, n2) < 0.f) ? -v : v;
}

template <typename T>
Normal3<T> Abs(const Normal3<T>& v) {
    return Normal3<T>(std::abs(v.x), std::abs(v.y), std::abs(v.z));
}

template <typename T>
inline const Point3<T>& Bounds3<T>::operator[](int i) const {
    DCHECK(i == 0 || i == 1);
    return (i == 0) ? pMin : pMax;
}

template <typename T>
inline Point3<T>& Bounds3<T>::operator[](int i) {
    DCHECK(i == 0 || i == 1);
    return (i == 0) ? pMin : pMax;
}

/**
 * @brief 包围盒求并集
 */
template <typename T>
Bounds3<T> Union(const Bounds3<T>& b, const Point3<T>& p) {
    Bounds3<T> ret;
    ret.pMin = Min(b.pMin, p);
    ret.pMax = Max(b.pMax, p);
    return ret;
}

/**
 * @brief 包围盒求并集
 */
template <typename T>
Bounds3<T> Union(const Bounds3<T>& b1, const Bounds3<T>& b2) {
    Bounds3<T> ret;
    ret.pMin = Min(b1.pMin, b2.pMin);
    ret.pMax = Max(b1.pMax, b2.pMax);
    return ret;
}

/**
 * @brief 包围盒求交集
 *
 * 重要提示：直接赋值给pMin/pMax，不要运行Bounds2（）构造函数，因为它需要传递给它的点的最小/最大值。反过来，对于我们与非重叠边界相交的情况（正如我们希望发生的那样），这会导致返回无效的边界。
 */
template <typename T>
Bounds3<T> Intersect(const Bounds3<T>& b1, const Bounds3<T>& b2) {
    Bounds3<T> ret;
    ret.pMin = Max(b1.pMin, b2.pMin);
    ret.pMax = Min(b1.pMax, b2.pMax);
    return ret;
}

/**
 * @brief 判断包围盒是否重合
 * @return 如果重合返回`true`，否则返回`false`
 */
template <typename T>
bool Overlaps(const Bounds3<T>& b1, const Bounds3<T>& b2) {
    bool x = (b1.pMax.x >= b2.pMin.x) && (b1.pMin.x <= b2.pMax.x);
    bool y = (b1.pMax.y >= b2.pMin.y) && (b1.pMin.y <= b2.pMax.y);
    bool z = (b1.pMax.z >= b2.pMin.z) && (b1.pMin.z <= b2.pMax.z);
    return (x && y && z);
}

/**
 * @brief 判断某点是否在包围盒内(包括上边界)
 * @return 如果在包围盒内返回`true`，否则返回`false`
 */
template <typename T>
bool Inside(const Point3<T>& p, const Bounds3<T>& b) {
    return (p.x >= b.pMin.x && p.x <= b.pMax.x && p.y >= b.pMin.y && p.y <= b.pMax.y && p.z >= b.pMin.z && p.z <= b.pMax.z);
}

/**
 * @brief 判断某点是否在包围盒内(不包括上边界，通常适用于整数边界)
 * @return 如果在包围盒内返回`true`，否则返回`false`
 */
template <typename T>
bool InsideExclusive(const Point3<T>& p, const Bounds3<T>& b) {
    return (p.x >= b.pMin.x && p.x < b.pMax.x && p.y >= b.pMin.y && p.y < b.pMax.y && p.z >= b.pMin.z && p.z < b.pMax.z);
}

/**
 * @brief 在所有维度上往外扩展包围盒
 * @param b 包围盒
 * @param delta 扩展距离
 * @return 一个新的三维包围盒
 */
template <typename T, typename U>
inline Bounds3<T> Expand(const Bounds3<T>& b, U delta) {
    return Bounds3<T>(b.pMin - Vector3<T>(delta, delta, delta), b.pMax + Vector3<T>(delta, delta, delta));
}

// Minimum squared distance from point to box; returns zero if point is
// inside.
template <typename T, typename U>
inline Float DistanceSquared(const Point3<T>& p, const Bounds3<U>& b) {
    Float dx = std::max({Float(0), b.pMin.x - p.x, p.x - b.pMax.x});
    Float dy = std::max({Float(0), b.pMin.y - p.y, p.y - b.pMax.y});
    Float dz = std::max({Float(0), b.pMin.z - p.z, p.z - b.pMax.z});
    return dx * dx + dy * dy + dz * dz;
}

template <typename T, typename U>
inline Float Distance(const Point3<T>& p, const Bounds3<U>& b) {
    return std::sqrt(DistanceSquared(p, b));
}

inline Bounds2iIterator begin(const Bounds2i& b) {
    return Bounds2iIterator(b, b.pMin);
}

inline Bounds2iIterator end(const Bounds2i& b) {
    // Normally, the ending point is at the minimum x value and one past
    // the last valid y value.
    Point2i pEnd(b.pMin.x, b.pMax.y);
    // However, if the bounds are degenerate, override the end point to
    // equal the start point so that any attempt to iterate over the bounds
    // exits out immediately.
    if (b.pMin.x >= b.pMax.x || b.pMin.y >= b.pMax.y) pEnd = b.pMin;
    return Bounds2iIterator(b, pEnd);
}

/**
 * @brief 包围盒求并集
 */
template <typename T>
Bounds2<T> Union(const Bounds2<T>& b, const Point2<T>& p) {
    Bounds2<T> ret;
    ret.pMin = Min(b.pMin, p);
    ret.pMax = Max(b.pMax, p);
    return ret;
}

/**
 * @brief 包围盒求并集
 */
template <typename T>
Bounds2<T> Union(const Bounds2<T>& b, const Bounds2<T>& b2) {
    Bounds2<T> ret;
    ret.pMin = Min(b.pMin, b2.pMin);
    ret.pMax = Max(b.pMax, b2.pMax);
    return ret;
}

/**
 * @brief 包围盒求交集
 *
 * 重要提示：直接赋值给pMin/pMax，不要运行Bounds2（）构造函数，因为它需要传递给它的点的最小/最大值。反过来，对于我们与非重叠边界相交的情况（正如我们希望发生的那样），这会导致返回无效的边界。
 */
template <typename T>
Bounds2<T> Intersect(const Bounds2<T>& b1, const Bounds2<T>& b2) {
    Bounds2<T> ret;
    ret.pMin = Max(b1.pMin, b2.pMin);
    ret.pMax = Min(b1.pMax, b2.pMax);
    return ret;
}

/**
 * @brief 判断包围盒是否重合
 * @return 如果重合返回`true`，否则返回`false`
 */
template <typename T>
bool Overlaps(const Bounds2<T>& ba, const Bounds2<T>& bb) {
    bool x = (ba.pMax.x >= bb.pMin.x) && (ba.pMin.x <= bb.pMax.x);
    bool y = (ba.pMax.y >= bb.pMin.y) && (ba.pMin.y <= bb.pMax.y);
    return (x && y);
}

/**
 * @brief 判断某点是否在包围盒内(包括上边界)
 * @return 如果在包围盒内返回`true`，否则返回`false`
 */
template <typename T>
bool Inside(const Point2<T>& pt, const Bounds2<T>& b) {
    return (pt.x >= b.pMin.x && pt.x <= b.pMax.x && pt.y >= b.pMin.y && pt.y <= b.pMax.y);
}

/**
 * @brief 判断某点是否在包围盒内(不包括上边界，通常适用于整数边界)
 * @return 如果在包围盒内返回`true`，否则返回`false`
 */
template <typename T>
bool InsideExclusive(const Point2<T>& pt, const Bounds2<T>& b) {
    return (pt.x >= b.pMin.x && pt.x < b.pMax.x && pt.y >= b.pMin.y && pt.y < b.pMax.y);
}

/**
 * @brief 在所有维度上往外扩展包围盒
 * @param b 包围盒
 * @param delta 扩展距离
 * @return 一个新的二维包围盒
 */
template <typename T, typename U>
Bounds2<T> Expand(const Bounds2<T>& b, U delta) {
    return Bounds2<T>(b.pMin - Vector2<T>(delta, delta), b.pMax + Vector2<T>(delta, delta));
}

/**
 * @brief 光线与包围盒相交
 * @param ray 光线
 * @param hitt0 光线与物体交的最近距离
 * @param hitt1 光线与物体交的最远距离
 *@return 如果判断成功相交返回`true`，否则返回`false`
 */
template <typename T>
inline bool Bounds3<T>::IntersectP(const Ray& ray, Float* hitt0, Float* hitt1) const {
    Float t0 = 0, t1 = ray.tMax;
    for (int i = 0; i < 3; ++i) {
        // 根据包围盒的每个对面计算出射线的参数

        Float invRayDir = 1 / ray.d[i];
        Float tNear     = (pMin[i] - ray.o[i]) * invRayDir;
        Float tFar      = (pMax[i] - ray.o[i]) * invRayDir;

        // 更新远近交点
        if (tNear > tFar) std::swap(tNear, tFar);

        // 保证任何出现Nan的情况都会被返回false
        tFar *= 1 + 2 * gamma(3);
        t0 = tNear > t0 ? tNear : t0;
        t1 = tFar < t1 ? tFar : t1;
        if (t0 > t1) return false;
    }
    if (hitt0) *hitt0 = t0;
    if (hitt1) *hitt1 = t1;
    return true;
}

/**
 * @brief 光线与包围盒相交
 *
 * 该重载接收光线的预处理参数，求交速度更快
 * @param ray 光线
 * @param invDir 光线方向每个维度的倒数
 * @param dirIsNeg[3] 光线每个方向的分量是否为负
 * @return 如果判断成功相交返回`true`，否则返回`false`
 */
template <typename T>
inline bool Bounds3<T>::IntersectP(const Ray& ray, const Vector3f& invDir, const int dirIsNeg[3]) const {
    const Bounds3f& bounds = *this;
    // Check for ray intersection against $x$ and $y$ slabs
    Float           tMin   = (bounds[dirIsNeg[0]].x - ray.o.x) * invDir.x;
    Float           tMax   = (bounds[1 - dirIsNeg[0]].x - ray.o.x) * invDir.x;
    Float           tyMin  = (bounds[dirIsNeg[1]].y - ray.o.y) * invDir.y;
    Float           tyMax  = (bounds[1 - dirIsNeg[1]].y - ray.o.y) * invDir.y;

    // Update _tMax_ and _tyMax_ to ensure robust bounds intersection
    tMax *= 1 + 2 * gamma(3);
    tyMax *= 1 + 2 * gamma(3);
    if (tMin > tyMax || tyMin > tMax) return false;
    if (tyMin > tMin) tMin = tyMin;
    if (tyMax < tMax) tMax = tyMax;

    // Check for ray intersection against $z$ slab
    Float tzMin = (bounds[dirIsNeg[2]].z - ray.o.z) * invDir.z;
    Float tzMax = (bounds[1 - dirIsNeg[2]].z - ray.o.z) * invDir.z;

    // Update _tzMax_ to ensure robust bounds intersection
    tzMax *= 1 + 2 * gamma(3);
    if (tMin > tzMax || tzMin > tMax) return false;
    if (tzMin > tMin) tMin = tzMin;
    if (tzMax < tMax) tMax = tzMax;
    return (tMin < ray.tMax) && (tMax > 0);
}

inline Point3f OffsetRayOrigin(const Point3f& p, const Vector3f& pError, const Normal3f& n, const Vector3f& w) {
    Float    d      = Dot(Abs(n), pError);
    Vector3f offset = d * Vector3f(n);
    if (Dot(w, n) < 0) offset = -offset;
    Point3f po = p + offset;
    // Round offset point _po_ away from _p_
    for (int i = 0; i < 3; ++i) {
        if (offset[i] > 0)
            po[i] = NextFloatUp(po[i]);
        else if (offset[i] < 0)
            po[i] = NextFloatDown(po[i]);
    }
    return po;
}

inline Vector3f SphericalDirection(Float sinTheta, Float cosTheta, Float phi) {
    return Vector3f(sinTheta * std::cos(phi), sinTheta * std::sin(phi), cosTheta);
}

inline Vector3f SphericalDirection(Float sinTheta, Float cosTheta, Float phi, const Vector3f& x, const Vector3f& y, const Vector3f& z) {
    return sinTheta * std::cos(phi) * x + sinTheta * std::sin(phi) * y + cosTheta * z;
}

inline Float SphericalTheta(const Vector3f& v) {
    return std::acos(Clamp(v.z, -1, 1));
}

inline Float SphericalPhi(const Vector3f& v) {
    Float p = std::atan2(v.y, v.x);
    return (p < 0) ? (p + 2 * Pi) : p;
}

}  // namespace pbrt

#endif  // PBRT_CORE_GEOMETRY_H
