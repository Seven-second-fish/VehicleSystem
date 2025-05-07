project(VehicleSystem)

qt_add_qml_module(MusicPlayer
    URI MusicPlayer
    VERSION 1.0
    QML_FILES
        MusicPlayerView.qml
    SOURCES
        MusicController.cpp
        MusicController.h
)


target_link_libraries(MusicPlayer PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Multimedia
)
