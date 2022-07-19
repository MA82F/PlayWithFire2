cmake_minimum_required(VERSION 3.22)
project(PlayWithFire2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.4.0/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

add_executable(PlayWithFire2 main.cpp src/windows/Home.cpp src/windows/Home.h src/views/TextField.cpp src/views/TextField.h resources.qrc src/views/Label.cpp src/views/Label.h src/views/Button.cpp src/views/Button.h src/windows/Game.cpp src/windows/Game.h src/views/Wall.cpp src/views/Wall.h src/views/Block.h  src/views/Block.cpp src/views/Box.h src/views/Box.cpp src/Controller.cpp src/Controller.h src/views/HomeImage.cpp src/views/HomeImage.h src/views/Player.cpp src/views/Player.h src/views/Box_Place.cpp src/views/Box_Place.h src/views/Bomb.cpp src/views/Bomb.h src/views/Bomb_effect.cpp src/views/Bomb_effect.h src/views/playerspictures.cpp src/views/playerspictures.h
        src/windows/Result.h src/windows/Result.cpp src/views/cup_image.h src/views/cup_image.cpp src/views/you_win.h src/views/you_win.cpp src/views/heart_picture.cpp src/views/heart_picture.h)
target_link_libraries(PlayWithFire2
        Qt::Core
        Qt::Gui
        Qt::Multimedia
        Qt::Widgets
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
