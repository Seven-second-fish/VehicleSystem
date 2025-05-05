project(VehicleSystem)

add_library(MusicPlayer
    MusicController.cpp
    MusicController.h
    # Music.qml
    resources.qrc
)

target_link_libraries(MusicPlayer PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Multimedia
)
