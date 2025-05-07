cmake_minimum_required(VERSION 3.16)
project(VehicleSystem)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(Qt6 COMPONENTS
    Core
    Gui
    Quick
    Multimedia
    Positioning
    REQUIRED
)

# add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(modules/MusicPlayer)
add_subdirectory(modules/Navigation)
add_subdirectory(modules/Settings)
add_subdirectory(modules/VehicleInfo)

qt_add_executable(${PROJECT_NAME}
    app/main.cpp
    app/Main.qml
    app/Main2.qml
)

# qt_add_qml_module(${PROJECT_NAME}
#     URI MainPage
#     VERSION 1.0
#     SOURCES
#         app/main.cpp
#     QML_FILES
#         Main.qml
#         Main2.qml
# )

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::Multimedia
    Qt6::Positioning
    Core
    MusicPlayer
    Navigation
    Settings
    VehicleInfo
)
