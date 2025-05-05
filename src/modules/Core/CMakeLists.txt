add_library(Core
    CoreController.cpp
    CoreController.h
)

target_link_libraries(Core PRIVATE
    Qt6::Core
    Qt6::Gui
) 