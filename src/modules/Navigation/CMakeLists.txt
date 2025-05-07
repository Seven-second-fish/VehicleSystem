project(VehicleSystem)

qt_add_qml_module(Navigation
    URI Navigation
    VERSION 1.0
    QML_FILES
        NavigationView.qml
    SOURCES
        NavigationController.cpp
        NavigationController.h
)

target_link_libraries(Navigation PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
) 