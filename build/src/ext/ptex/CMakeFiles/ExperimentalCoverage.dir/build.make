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

# Utility rule file for ExperimentalCoverage.

# Include any custom commands dependencies for this target.
include src/ext/ptex/CMakeFiles/ExperimentalCoverage.dir/compiler_depend.make

# Include the progress variables for this target.
include src/ext/ptex/CMakeFiles/ExperimentalCoverage.dir/progress.make

src/ext/ptex/CMakeFiles/ExperimentalCoverage:
	cd /d E:\Project\pbrt-v3\build\src\ext\ptex && C:\CMake\bin\ctest.exe -D ExperimentalCoverage

ExperimentalCoverage: src/ext/ptex/CMakeFiles/ExperimentalCoverage
ExperimentalCoverage: src/ext/ptex/CMakeFiles/ExperimentalCoverage.dir/build.make
.PHONY : ExperimentalCoverage

# Rule to build all files generated by this target.
src/ext/ptex/CMakeFiles/ExperimentalCoverage.dir/build: ExperimentalCoverage
.PHONY : src/ext/ptex/CMakeFiles/ExperimentalCoverage.dir/build

src/ext/ptex/CMakeFiles/ExperimentalCoverage.dir/clean:
	cd /d E:\Project\pbrt-v3\build\src\ext\ptex && $(CMAKE_COMMAND) -P CMakeFiles\ExperimentalCoverage.dir\cmake_clean.cmake
.PHONY : src/ext/ptex/CMakeFiles/ExperimentalCoverage.dir/clean

src/ext/ptex/CMakeFiles/ExperimentalCoverage.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Project\pbrt-v3 E:\Project\pbrt-v3\src\ext\ptex E:\Project\pbrt-v3\build E:\Project\pbrt-v3\build\src\ext\ptex E:\Project\pbrt-v3\build\src\ext\ptex\CMakeFiles\ExperimentalCoverage.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/ext/ptex/CMakeFiles/ExperimentalCoverage.dir/depend

