# MusicPlayer 模块
add_library(MusicPlayer
    MusicController.cpp
    MusicController.h
)

qt_add_qml_module(MusicPlayer
    URI MusicPlayer
    VERSION 1.0
    QML_FILES
        MusicPlayer.qml
)

target_include_directories(MusicPlayer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(MusicPlayer PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Multimedia
)

# 设置模块属性
set_target_properties(MusicPlayer PROPERTIES
    AUTOMOC ON
)
