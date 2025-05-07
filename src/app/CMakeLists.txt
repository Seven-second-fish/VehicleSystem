project(VehicleSystem)

qt_add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    MainPage
    Core
    MusicPlayer
    Navigation
    Settings
    VehicleInfo
)

qt_import_qml_plugins(${PROJECT_NAME})
