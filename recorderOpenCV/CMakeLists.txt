cmake_minimum_required(VERSION 3.16)

project(recorderOpenCV VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenCV_DIR "C:/Users/HPGGS03/Downloads/opencv/build")
set(PortAudio_DIR "C:/portaudio/build")

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Core Multimedia)
find_package(OpenCV REQUIRED)
find_package(PortAudio REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("C:/portaudio/include")

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(apprecorderOpenCV
    main.cpp
)

qt_add_qml_module(apprecorderOpenCV
    URI recorderOpenCV
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES datamanager.h datamanager.cpp
        SOURCES videocapturehandler.h videocapturehandler.cpp
        SOURCES audiocapturehandler.h audiocapturehandler.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apprecorderOpenCV PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apprecorderOpenCV
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apprecorderOpenCV
    PRIVATE Qt6::Quick Qt6::Multimedia
      ${OpenCV_LIBS}
      ${PORTAUDIO_LIBRARIES} portaudio
)

include(GNUInstallDirs)
install(TARGETS apprecorderOpenCV
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
