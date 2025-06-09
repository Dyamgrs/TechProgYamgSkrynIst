cmake_minimum_required(VERSION 3.16)
project(client VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network Test)

# Основное приложение
add_executable(client
    main.cpp
    authorization.cpp
    authorization.h
    authorization.ui
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    task1_caesar.cpp
    task1_caesar.h
    task1_caesar.ui
    functionClient.cpp
    functionClient.h
    singleton_client.cpp
    singleton_client.h
)

target_link_libraries(client PRIVATE
    Qt6::Widgets
    Qt6::Network
)

# Тесты
enable_testing()
add_executable(test_caesar
    test_caesar.cpp
    task1_caesar.cpp
)
target_link_libraries(test_caesar PRIVATE
    Qt6::Test
    Qt6::Core
    Qt6::Widgets
)
add_test(NAME caesar_cipher_tests COMMAND test_caesar)

