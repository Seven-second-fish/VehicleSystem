project(VehicleSystem)

qt_add_qml_module(VehicleInfo
    URI VehicleInfo
    VERSION 1.0
    QML_FILES
        VehicleInfoView.qml
    SOURCES
        VehicleInfoController.cpp
        VehicleInfoController.h
)

target_link_libraries(VehicleInfo PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
) 