# Install script for directory: E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf

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
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/PBRT-V3/lib/IlmImf.lib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "C:/Program Files (x86)/PBRT-V3/lib" TYPE STATIC_LIBRARY FILES "E:/Project/pbrt-v3/build/src/ext/openexr/OpenEXR/IlmImf/IlmImf.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("E:/Project/pbrt-v3/build/src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/IlmImf.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfForward.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfExport.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfBoxAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfCRgbaFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfChannelList.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfChannelListAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfCompressionAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDoubleAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfFloatAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfFrameBuffer.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfHeader.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfIO.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfInputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfIntAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfLineOrderAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfMatrixAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfOpaqueAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfOutputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfRgbaFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfStringAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfVecAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfHuf.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfWav.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfLut.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfArray.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfCompression.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfLineOrder.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfName.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfPixelType.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfVersion.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfXdr.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfConvert.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfPreviewImage.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfPreviewImageAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfChromaticities.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfChromaticitiesAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfKeyCode.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfKeyCodeAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfTimeCode.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfTimeCodeAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfRational.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfRationalAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfFramesPerSecond.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfStandardAttributes.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfEnvmap.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfEnvmapAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfInt64.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfRgba.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfTileDescription.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfTileDescriptionAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfTiledInputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfTiledOutputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfTiledRgbaFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfRgbaYca.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfTestFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfThreading.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfB44Compressor.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfStringVectorAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfMultiView.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfAcesFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfMultiPartOutputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfGenericOutputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfMultiPartInputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfGenericInputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfPartType.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfPartHelper.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfOutputPart.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfTiledOutputPart.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfInputPart.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfTiledInputPart.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepScanLineOutputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepScanLineOutputPart.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepScanLineInputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepScanLineInputPart.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepTiledInputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepTiledInputPart.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepTiledOutputFile.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepTiledOutputPart.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepFrameBuffer.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepCompositing.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfCompositeDeepScanLine.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfNamespace.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfMisc.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepImageState.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfDeepImageStateAttribute.h;C:/Program Files (x86)/PBRT-V3/include/OpenEXR/ImfFloatVectorAttribute.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "C:/Program Files (x86)/PBRT-V3/include/OpenEXR" TYPE FILE FILES
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfForward.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfExport.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfBoxAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfCRgbaFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfChannelList.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfChannelListAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfCompressionAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDoubleAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfFloatAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfFrameBuffer.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfHeader.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfIO.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfInputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfIntAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfLineOrderAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfMatrixAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfOpaqueAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfOutputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfRgbaFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfStringAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfVecAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfHuf.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfWav.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfLut.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfArray.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfCompression.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfLineOrder.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfName.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfPixelType.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfVersion.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfXdr.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfConvert.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfPreviewImage.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfPreviewImageAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfChromaticities.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfChromaticitiesAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfKeyCode.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfKeyCodeAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfTimeCode.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfTimeCodeAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfRational.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfRationalAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfFramesPerSecond.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfStandardAttributes.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfEnvmap.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfEnvmapAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfInt64.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfRgba.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfTileDescription.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfTileDescriptionAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfTiledInputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfTiledOutputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfTiledRgbaFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfRgbaYca.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfTestFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfThreading.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfB44Compressor.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfStringVectorAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfMultiView.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfAcesFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfMultiPartOutputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfGenericOutputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfMultiPartInputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfGenericInputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfPartType.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfPartHelper.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfOutputPart.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfTiledOutputPart.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfInputPart.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfTiledInputPart.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepScanLineOutputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepScanLineOutputPart.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepScanLineInputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepScanLineInputPart.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepTiledInputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepTiledInputPart.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepTiledOutputFile.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepTiledOutputPart.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepFrameBuffer.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepCompositing.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfCompositeDeepScanLine.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfNamespace.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfMisc.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepImageState.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfDeepImageStateAttribute.h"
    "E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/ImfFloatVectorAttribute.h"
    )
endif()

