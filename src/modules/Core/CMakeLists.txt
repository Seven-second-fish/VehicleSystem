# Core 模块
add_library(Core
        CoreController.cpp
        CoreController.h
)

qt_add_qml_module(Core
    URI Core
    VERSION 1.0
    QML_FILES
        Core.qml
)

target_include_directories(Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Core PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
)

# 设置模块属性
set_target_properties(Core PROPERTIES
    AUTOMOC ON
)
