# CMake generated Testfile for 
# Source directory: E:/Project/pbrt-v3/src/ext/ptex/src/tests
# Build directory: E:/Project/pbrt-v3/build/src/ext/ptex/src/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(wtest "E:/Project/pbrt-v3/build/src/ext/ptex/src/tests/wtest.exe")
set_tests_properties(wtest PROPERTIES  _BACKTRACE_TRIPLES "E:/Project/pbrt-v3/src/ext/ptex/src/tests/CMakeLists.txt;32;add_test;E:/Project/pbrt-v3/src/ext/ptex/src/tests/CMakeLists.txt;0;")
add_test(rtest "C:/CMake/bin/cmake.exe" "-DOUT=E:/Project/pbrt-v3/build/src/ext/ptex/src/tests/rtest.out" "-DDATA=E:/Project/pbrt-v3/src/ext/ptex/src/tests/rtestok.dat" "-DCMD=E:/Project/pbrt-v3/build/src/ext/ptex/src/tests/rtest.exe" "-P" "E:/Project/pbrt-v3/src/ext/ptex/src/tests/compare_test.cmake")
set_tests_properties(rtest PROPERTIES  _BACKTRACE_TRIPLES "E:/Project/pbrt-v3/src/ext/ptex/src/tests/CMakeLists.txt;23;add_test;E:/Project/pbrt-v3/src/ext/ptex/src/tests/CMakeLists.txt;33;add_compare_test;E:/Project/pbrt-v3/src/ext/ptex/src/tests/CMakeLists.txt;0;")
add_test(ftest "C:/CMake/bin/cmake.exe" "-DOUT=E:/Project/pbrt-v3/build/src/ext/ptex/src/tests/ftest.out" "-DDATA=E:/Project/pbrt-v3/src/ext/ptex/src/tests/ftestok.dat" "-DCMD=E:/Project/pbrt-v3/build/src/ext/ptex/src/tests/ftest.exe" "-P" "E:/Project/pbrt-v3/src/ext/ptex/src/tests/compare_test.cmake")
set_tests_properties(ftest PROPERTIES  _BACKTRACE_TRIPLES "E:/Project/pbrt-v3/src/ext/ptex/src/tests/CMakeLists.txt;23;add_test;E:/Project/pbrt-v3/src/ext/ptex/src/tests/CMakeLists.txt;34;add_compare_test;E:/Project/pbrt-v3/src/ext/ptex/src/tests/CMakeLists.txt;0;")
add_test(halftest "E:/Project/pbrt-v3/build/src/ext/ptex/src/tests/halftest.exe")
set_tests_properties(halftest PROPERTIES  _BACKTRACE_TRIPLES "E:/Project/pbrt-v3/src/ext/ptex/src/tests/CMakeLists.txt;35;add_test;E:/Project/pbrt-v3/src/ext/ptex/src/tests/CMakeLists.txt;0;")
