QT += core network
CONFIG += c++11

SOURCES += main.cpp \
           ../client/authorization.cpp \
           ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/3.30.5/CompilerIdCXX/CMakeCXXCompilerId.cpp \
           ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/EWIEGA46WW/moc_authorization.cpp \
           ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/EWIEGA46WW/moc_mainwindow.cpp \
           ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/EWIEGA46WW/moc_task1_caesar.cpp \
           ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/EWIEGA46WW/moc_task2_hash.cpp \
           ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/mocs_compilation.cpp \
           ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_caesar_autogen/EWIEGA46WW/moc_task1_caesar.cpp \
           ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_caesar_autogen/mocs_compilation.cpp \
           ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_hash_autogen/EWIEGA46WW/moc_task2_hash.cpp \
           ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_hash_autogen/mocs_compilation.cpp \
           ../client/functionClient.cpp \
           ../client/main.cpp \
           ../client/mainwindow.cpp \
           ../client/singleton_client.cpp \
           ../client/task1_caesar.cpp \
           ../client/task2_hash.cpp \
           ../client/test_caesar.cpp \
           ../client/test_hash.cpp \
           mytcpserver.cpp

HEADERS += mytcpserver.h \
    ../client/authorization.h \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/include/ui_authorization.h \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/include/ui_mainwindow.h \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/include/ui_task1_caesar.h \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/include/ui_task2_hash.h \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/moc_predefs.h \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_caesar_autogen/include/ui_task1_caesar.h \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_caesar_autogen/moc_predefs.h \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_hash_autogen/include/ui_task2_hash.h \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_hash_autogen/moc_predefs.h \
    ../client/functionClient.h \
    ../client/mainwindow.h \
    ../client/singleton_client.h \
    ../client/task1_caesar.h \
    ../client/task2_hash.h

DISTFILES += \
    ../client/CMakeLists.txt \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/query/cache-v2 \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/query/cmakeFiles-v1 \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/query/codemodel-v2 \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/cache-v2-90f072ddda437fc5c345.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/cmakeFiles-v1-699fc18697e4b1b3348c.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/codemodel-v2-f43f8fd3d2fc1f2d8e29.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/directory-.-Debug-61f74cf55049888c4892.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/index-2025-06-22T17-51-45-0519.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/target-client-Debug-a71dc72daacbd6b6292f.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/target-client_autogen-Debug-4fc2045aee63c1653f06.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/target-client_autogen_timestamp_deps-Debug-5c32b5e9156718d9abbd.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/target-test_caesar-Debug-391c38f9a95dae38cf5f.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/target-test_caesar_autogen-Debug-3eab9fd2c9b6c420cec4.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/target-test_caesar_autogen_timestamp_deps-Debug-c452f04563f39a7fa83b.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/target-test_hash-Debug-9626b041a73f51048c8f.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/target-test_hash_autogen-Debug-571561baab11e2f2b846.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.cmake/api/v1/reply/target-test_hash_autogen_timestamp_deps-Debug-a1b9f3baabc545e9164d.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.ninja_deps \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.ninja_log \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.qt/QtDeployTargets.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.qtc/package-manager/LICENSE.conan \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.qtc/package-manager/auto-setup.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.qtc/package-manager/conan.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/.qtc/package-manager/conan_provider.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeCache.txt \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeCache.txt.prev \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeCache.txt.tmp91e01 \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/3.30.5/CMakeCXXCompiler.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/3.30.5/CMakeDetermineCompilerABI_CXX.bin \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/3.30.5/CMakeRCCompiler.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/3.30.5/CMakeSystem.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/3.30.5/CompilerIdCXX/a.exe \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/CMakeConfigureLog.yaml \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/TargetDirectories.txt \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/VerifyGlobs.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/clean_additional.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/client_autogen.dir/AutogenInfo.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/client_autogen.dir/AutogenUsed.txt \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/client_autogen.dir/ParseCache.txt \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/client_en_US.ts_lst_file \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/cmake.check_cache \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/cmake.verify_globs \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/rules.ninja \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/test_caesar_autogen.dir/AutogenInfo.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/test_caesar_autogen.dir/AutogenUsed.txt \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/test_caesar_autogen.dir/ParseCache.txt \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/test_hash_autogen.dir/AutogenInfo.json \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/test_hash_autogen.dir/AutogenUsed.txt \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CMakeFiles/test_hash_autogen.dir/ParseCache.txt \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/CTestTestfile.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/Testing/Temporary/LastTest.log \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/build.ninja \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client.exe \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/EWIEGA46WW/moc_authorization.cpp.d \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/EWIEGA46WW/moc_mainwindow.cpp.d \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/EWIEGA46WW/moc_task1_caesar.cpp.d \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/EWIEGA46WW/moc_task2_hash.cpp.d \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/deps \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/client_autogen/timestamp \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/cmake_install.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/qtcsettings.cmake \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_caesar.exe \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_caesar_autogen/EWIEGA46WW/moc_task1_caesar.cpp.d \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_caesar_autogen/deps \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_caesar_autogen/include/test_caesar.moc \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_caesar_autogen/include/test_caesar.moc.d \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_caesar_autogen/timestamp \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_hash.exe \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_hash_autogen/EWIEGA46WW/moc_task2_hash.cpp.d \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_hash_autogen/deps \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_hash_autogen/include/test_hash.moc \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_hash_autogen/include/test_hash.moc.d \
    ../client/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/test_hash_autogen/timestamp

FORMS += \
    ../client/authorization.ui \
    ../client/mainwindow.ui \
    ../client/task1_caesar.ui \
    ../client/task2_hash.ui

TRANSLATIONS += \
    ../client/client_en_US.ts
