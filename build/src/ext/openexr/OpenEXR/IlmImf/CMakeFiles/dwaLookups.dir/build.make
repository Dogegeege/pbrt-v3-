# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\CMake\bin\cmake.exe

# The command to remove a file.
RM = C:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Project\pbrt-v3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Project\pbrt-v3\build

# Include any dependencies generated for this target.
include src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/compiler_depend.make

# Include the progress variables for this target.
include src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/progress.make

# Include the compile flags for this target's objects.
include src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/flags.make

src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/dwaLookups.cpp.obj: src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/flags.make
src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/dwaLookups.cpp.obj: E:/Project/pbrt-v3/src/ext/openexr/OpenEXR/IlmImf/dwaLookups.cpp
src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/dwaLookups.cpp.obj: src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Project\pbrt-v3\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/dwaLookups.cpp.obj"
	cd /d E:\Project\pbrt-v3\build\src\ext\openexr\OpenEXR\IlmImf && $(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\dwaLookups.dir\dwaLookups.cpp.obj.d --working-dir=E:\Project\pbrt-v3\build\src\ext\openexr\OpenEXR\IlmImf --filter-prefix="注意: 包含文件:  " -- C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1434~1.319\bin\Hostx64\x64\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\dwaLookups.dir\dwaLookups.cpp.obj /FdCMakeFiles\dwaLookups.dir/ /FS -c E:\Project\pbrt-v3\src\ext\openexr\OpenEXR\IlmImf\dwaLookups.cpp

src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/dwaLookups.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dwaLookups.dir/dwaLookups.cpp.i"
	cd /d E:\Project\pbrt-v3\build\src\ext\openexr\OpenEXR\IlmImf && C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1434~1.319\bin\Hostx64\x64\cl.exe > CMakeFiles\dwaLookups.dir\dwaLookups.cpp.i  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Project\pbrt-v3\src\ext\openexr\OpenEXR\IlmImf\dwaLookups.cpp

src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/dwaLookups.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dwaLookups.dir/dwaLookups.cpp.s"
	cd /d E:\Project\pbrt-v3\build\src\ext\openexr\OpenEXR\IlmImf && C:\PROGRA~1\MICROS~2\2022\COMMUN~1\VC\Tools\MSVC\1434~1.319\bin\Hostx64\x64\cl.exe  /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\dwaLookups.dir\dwaLookups.cpp.s /c E:\Project\pbrt-v3\src\ext\openexr\OpenEXR\IlmImf\dwaLookups.cpp

# Object files for target dwaLookups
dwaLookups_OBJECTS = \
"CMakeFiles/dwaLookups.dir/dwaLookups.cpp.obj"

# External object files for target dwaLookups
dwaLookups_EXTERNAL_OBJECTS =

src/ext/openexr/OpenEXR/IlmImf/dwaLookups.exe: src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/dwaLookups.cpp.obj
src/ext/openexr/OpenEXR/IlmImf/dwaLookups.exe: src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/build.make
src/ext/openexr/OpenEXR/IlmImf/dwaLookups.exe: src/ext/openexr/IlmBase/Half/Half.lib
src/ext/openexr/OpenEXR/IlmImf/dwaLookups.exe: src/ext/openexr/IlmBase/IlmThread/IlmThread.lib
src/ext/openexr/OpenEXR/IlmImf/dwaLookups.exe: src/ext/openexr/IlmBase/Iex/Iex.lib
src/ext/openexr/OpenEXR/IlmImf/dwaLookups.exe: src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/objects1.rsp
src/ext/openexr/OpenEXR/IlmImf/dwaLookups.exe: src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\Project\pbrt-v3\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dwaLookups.exe"
	cd /d E:\Project\pbrt-v3\build\src\ext\openexr\OpenEXR\IlmImf && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\dwaLookups.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/build: src/ext/openexr/OpenEXR/IlmImf/dwaLookups.exe
.PHONY : src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/build

src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/clean:
	cd /d E:\Project\pbrt-v3\build\src\ext\openexr\OpenEXR\IlmImf && $(CMAKE_COMMAND) -P CMakeFiles\dwaLookups.dir\cmake_clean.cmake
.PHONY : src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/clean

src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Project\pbrt-v3 E:\Project\pbrt-v3\src\ext\openexr\OpenEXR\IlmImf E:\Project\pbrt-v3\build E:\Project\pbrt-v3\build\src\ext\openexr\OpenEXR\IlmImf E:\Project\pbrt-v3\build\src\ext\openexr\OpenEXR\IlmImf\CMakeFiles\dwaLookups.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/ext/openexr/OpenEXR/IlmImf/CMakeFiles/dwaLookups.dir/depend

