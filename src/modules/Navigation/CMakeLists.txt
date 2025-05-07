add_library(Navigation
    NavigationController.cpp
    NavigationController.h
)

target_link_libraries(Navigation PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Positioning
) 