# Install script for directory: E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/PBRT-V3")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/Project/pbrt-v3/build/src/ext/openexr/IlmBase/Imath/Imath.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("E:/Project/pbrt-v3/build/src/ext/openexr/IlmBase/Imath/CMakeFiles/Imath.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenEXR" TYPE FILE FILES
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathBoxAlgo.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathBox.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathColorAlgo.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathColor.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathEuler.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathExc.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathExport.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathForward.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathFrame.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathFrustum.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathFrustumTest.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathFun.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathGL.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathGLU.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathHalfLimits.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathInt64.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathInterval.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathLimits.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathLineAlgo.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathLine.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathMath.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathMatrixAlgo.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathMatrix.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathNamespace.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathPlane.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathPlatform.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathQuat.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathRandom.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathRoots.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathShear.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathSphere.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathVecAlgo.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Imath/ImathVec.h"
    )
endif()

