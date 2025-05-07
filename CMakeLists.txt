cmake_minimum_required(VERSION 3.16)

# # 设置 QML 策略
# need the version > 5.7
# qt_policy(SET QTP0001 NEW)

project(VehicleSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(
    Qt6 COMPONENTS Core Gui Quick Qml Multimedia
    REQUIRED
)


add_subdirectory(src)
