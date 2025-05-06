project(VehicleSystem)

# 主应用程序
qt_add_executable(${PROJECT_NAME}
    main.cpp
)

# 链接所有模块
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Multimedia
    Qt6::Positioning
    MainPage
    Core
    MusicPlayer
    Navigation
    Settings
    VehicleInfo
)

# 设置包含路径
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/modules
)

# 导入 QML 插件
qt_import_qml_plugins(${PROJECT_NAME})
