project(VehicleSystem)

qt_add_qml_module(MainPage
    URI MainPage
    VERSION 1.0
    QML_FILES
        Main.qml
        Main2.qml
)

target_link_libraries(MainPage PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)
