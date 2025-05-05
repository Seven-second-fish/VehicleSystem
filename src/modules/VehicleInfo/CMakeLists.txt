add_library(VehicleInfo
    VehicleInfoController.cpp
    VehicleInfoController.h
)

target_link_libraries(VehicleInfo PRIVATE
    Qt6::Core
    Qt6::Gui
) 