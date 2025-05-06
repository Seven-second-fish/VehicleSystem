project(VehicleSystem)

# MainPage 模块
qt_add_qml_module(MainPage
    URI MainPage
    VERSION 1.0
    QML_FILES
        Main.qml
        Main2.qml
    RESOURCES
        resources.qrc
)

target_include_directories(MainPage PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(MainPage PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

# 设置模块属性
set_target_properties(MainPage PROPERTIES
    AUTOMOC ON
)
