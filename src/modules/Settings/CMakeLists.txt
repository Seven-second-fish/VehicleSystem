# Settings 模块
add_library(Settings
        SettingsController.cpp
        SettingsController.h
)

qt_add_qml_module(Settings
    URI Settings
    VERSION 1.0
    QML_FILES
        Settings.qml
)

target_include_directories(Settings PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Settings PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
)

# 设置模块属性
set_target_properties(Settings PROPERTIES
    AUTOMOC ON
)
