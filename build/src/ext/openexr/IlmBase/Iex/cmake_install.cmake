# Install script for directory: E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Iex

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/Project/pbrt-v3/build/src/ext/openexr/IlmBase/Iex/Iex.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("E:/Project/pbrt-v3/build/src/ext/openexr/IlmBase/Iex/CMakeFiles/Iex.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenEXR" TYPE FILE FILES
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Iex/IexBaseExc.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Iex/IexMathExc.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Iex/IexThrowErrnoExc.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Iex/IexErrnoExc.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Iex/IexMacros.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Iex/Iex.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Iex/IexNamespace.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Iex/IexExport.h"
    "E:/Project/pbrt-v3/src/ext/openexr/IlmBase/Iex/IexForward.h"
    )
endif()

