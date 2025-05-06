# Navigation 模块
add_library(Navigation
        NavigationController.cpp
        NavigationController.h
)

qt_add_qml_module(Navigation
    URI Navigation
    VERSION 1.0
    QML_FILES
        Navigation.qml
)

target_include_directories(Navigation PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Navigation PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Positioning
)

# 设置模块属性
set_target_properties(Navigation PROPERTIES
    AUTOMOC ON
) 
