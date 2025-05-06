# VehicleInfo 模块
add_library(VehicleInfo
        VehicleInfoController.cpp
        VehicleInfoController.h
)

qt_add_qml_module(VehicleInfo
    URI VehicleInfo
    VERSION 1.0
    QML_FILES
        VehicleInfo.qml
)

target_include_directories(VehicleInfo PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(VehicleInfo PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
)

# 设置模块属性
set_target_properties(VehicleInfo PROPERTIES
    AUTOMOC ON
)
