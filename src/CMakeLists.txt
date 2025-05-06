cmake_minimum_required(VERSION 3.16)
project(VehicleSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
    Core
    Gui
    Quick
    Multimedia
    Positioning
    REQUIRED
)

# 添加所有模块
add_subdirectory(modules)

# 添加主应用程序
add_subdirectory(app)

# 设置 QML 导入路径
target_compile_definitions(${PROJECT_NAME} PRIVATE
    QML_IMPORT_PATH="${CMAKE_BINARY_DIR}/lib/qml"
)

# 设置包含路径
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/modules
)
