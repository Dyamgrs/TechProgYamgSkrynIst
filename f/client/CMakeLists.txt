cmake_minimum_required(VERSION 3.16)
project(client VERSION 0.1 LANGUAGES CXX)

# Базовые настройки Qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск необходимых модулей Qt (добавлен Test)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network Test LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network Test LinguistTools)

set(TS_FILES client_en_US.ts)

# Группировка исходных файлов
set(CORE_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

set(AUTH_SOURCES
    authorization.cpp
    authorization.h
    authorization.ui
)

set(TASK_SOURCES
    task1_caesar.cpp
    task1_caesar.h
    task1_caesar.ui
    task2_hash.cpp
    task2_hash.h
    task2_hash.ui
)

set(NETWORK_SOURCES
    singleton_client.cpp
    singleton_client.h
    functionClient.cpp
    functionClient.h
)

set(PROJECT_SOURCES
    ${CORE_SOURCES}
    ${AUTH_SOURCES}
    ${TASK_SOURCES}
    ${NETWORK_SOURCES}
    ${TS_FILES}
)

# Основное приложение
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(client
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}


    )
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(client SHARED ${PROJECT_SOURCES})
    else()
        add_executable(client ${PROJECT_SOURCES})
    endif()
    qt6_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(client PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)

# Настройки для платформ
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.client)
endif()

set_target_properties(client PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Установка
include(GNUInstallDirs)
install(TARGETS client
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Секция тестов (только если это основной проект)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND NOT ANDROID)
    enable_testing()

    # Тест для Caesar Cipher
    add_executable(test_caesar
        test_caesar.cpp
        task1_caesar.cpp
        task1_caesar.h
        task1_caesar.ui
    )
    target_link_libraries(test_caesar PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Test
    )
    set_property(SOURCE test_caesar.cpp PROPERTY AUTOMOC ON)
    add_test(NAME caesar_cipher_tests COMMAND test_caesar)

    # Тест для Hash Calculator
    add_executable(test_hash
        test_hash.cpp
        task2_hash.cpp
        task2_hash.h
        task2_hash.ui
    )
    target_link_libraries(test_hash PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Test
    )
    set_property(SOURCE test_hash.cpp PROPERTY AUTOMOC ON)
    add_test(NAME hash_tests COMMAND test_hash)
endif()

# Финальная настройка для Qt6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(client)
endif()
