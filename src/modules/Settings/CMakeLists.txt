project(VehicleSystem)

qt_add_qml_module(Settings
    URI Settings
    VERSION 1.0
    QML_FILES
        SettingsView.qml
    SOURCES
        SettingsController.cpp
        SettingsController.h
)

target_link_libraries(Settings PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
) 