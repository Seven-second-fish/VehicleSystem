add_library(Settings
    SettingsController.cpp
    SettingsController.h
)

target_link_libraries(Settings PRIVATE
    Qt6::Core
    Qt6::Gui
) 