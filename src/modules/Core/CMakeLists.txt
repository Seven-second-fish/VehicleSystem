# add_library(Core
#     CoreController.cpp
#     CoreController.h
# )

qt_add_qml_module(Core
    URI Core
    VERSION 1.0
    QML_FILES
        #qml/Core.qml  # 没有 QML 也可以不写
    SOURCES
        CoreController.cpp
        CoreController.h
)

target_link_libraries(Core PRIVATE
    Qt6::Core
    Qt6::Gui
) 
