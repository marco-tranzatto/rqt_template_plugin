cmake_minimum_required(VERSION 2.8.3)
project(rqt_template_plugin)

# Set compiler flags
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
        rqt_gui
        rqt_gui_cpp
        )

if ("${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
    find_package(Qt5Widgets REQUIRED)
else ()
    find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
    include(${QT_USE_FILE})
endif ()

catkin_python_setup()

###########
# sources #
###########
set(rqt_template_plugin_SRCS
        src/rqt_template_plugin/TemplatePlugin.cpp
        src/rqt_template_plugin/TemplateWidget.cpp
        )
###########


###########
# headers #
###########
set(rqt_template_plugin_HDRS
        include/rqt_template_plugin/TemplatePlugin.hpp
        include/rqt_template_plugin/TemplateWidget.hpp
        )
###########


############
# ui files #
############
set(rqt_template_plugin_UIS
        resource/template_widget.ui
        )
############

set(rqt_template_plugin_INCLUDE_DIRECTORIES
        include
        ${CMAKE_CURRENT_BINARY_DIR}
        )

catkin_package(
        LIBRARIES ${PROJECT_NAME}
        CATKIN_DEPENDS
        rqt_gui
        rqt_gui_cpp
        DEPENDS
)

if ("${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
    qt5_wrap_cpp(rqt_template_plugin_MOCS ${rqt_template_plugin_HDRS})
    qt5_wrap_ui(rqt_template_plugin_UIS_H ${rqt_template_plugin_UIS})
else ()
    qt4_wrap_cpp(rqt_template_plugin_MOCS ${rqt_template_plugin_HDRS})
    qt4_wrap_ui(rqt_template_plugin_UIS_H ${rqt_template_plugin_UIS})
endif ()

include_directories(
        ${rqt_template_plugin_INCLUDE_DIRECTORIES}
        ${catkin_INCLUDE_DIRS}
)


add_library(rqt_template_plugin
        ${rqt_template_plugin_SRCS}
        ${rqt_template_plugin_MOCS}
        ${rqt_template_plugin_UIS_H}
        )

target_link_libraries(rqt_template_plugin
        ${catkin_LIBRARIES}
        )

if ("${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
    target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
else ()
    target_link_libraries(${PROJECT_NAME} ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
endif ()


find_package(class_loader)
class_loader_hide_library_symbols(rqt_template_plugin)


install(FILES plugin.xml
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
        )

install(TARGETS rqt_template_plugin
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        )

install(PROGRAMS scripts/rqt_template_plugin
        DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        )

install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        )
