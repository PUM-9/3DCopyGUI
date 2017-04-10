cmake_minimum_required(VERSION 3.6)
project(3DCopyGUI)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(PCL 1.3 REQUIRED)

# QT base dir
set(QT_PATH "/usr/include/qt5")
# Build output for QT Creator
set(QT_BIN "${PROJECT_SOURCE_DIR}/QtBinDebug")

set(QT4_LIB_DIR ${QT_PATH}/lib/cmake)
set(QT4_CORE ${QT_LIB_DIR}/Qt5Core)
set(QT4_WIDGETS ${QT_LIB_DIR}/Qt5Widgets)
set(QT4_GUI ${QT_LIB_DIR}/Qt5Gui)

set(QT_LIBRARIES Qt5::Core Qt5::Widgets Qt5::Gui)

set(QT_LIBRARIES_REQUIRED Qt5Core Qt5Widgets Qt5Gui)

foreach(QT_LIBRARIES_REQUIRED ${QT_LIBRARIES_REQUIRED})
    find_package( ${QT_LIBRARIES_REQUIRED} REQUIRED )
endforeach()

add_custom_target(qtMakeFile COMMAND make -C ${QT_BIN})

include_directories(${QT_BIN} ${PCL_INCLUDE_DIRS})

link_directories(${PCL_LIBRARY_DIRS})

add_definitions(${PCL_DEFINITIONS})

set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h mainwindow.ui src/Mesh.cpp)

add_executable(3DCopyGUI ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES} ${PCL_LIBRARIES})