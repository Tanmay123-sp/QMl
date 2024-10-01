cmake_minimum_required(VERSION 3.16)

project(recorderOpenCV VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenCV_DIR "C:/Users/HPGGS03/Downloads/opencv/build")
set(PortAudio_DIR "C:/portaudio/build")
set(FFMPEG_INCLUDE_DIR "C:/FFmpeg/ffmpeg-7.0.2-full_build-shared/include")
set(FFMPEG_LIB_DIR "C:/FFmpeg/ffmpeg-7.0.2-full_build-shared/lib")

# Find required packages
find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Core Multimedia)
find_package(OpenCV REQUIRED)
find_package(PortAudio REQUIRED)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("C:/portaudio/include")
include_directories(${FFMPEG_INCLUDE_DIR})

# Link directories
link_directories(${FFMPEG_LIB_DIR})

# Find FFmpeg libraries
find_library(AVFORMAT_LIBRARY avformat HINTS ${FFMPEG_LIB_DIR})
find_library(AVCODEC_LIBRARY avcodec HINTS ${FFMPEG_LIB_DIR})
find_library(AVUTIL_LIBRARY avutil HINTS ${FFMPEG_LIB_DIR})
find_library(SWSCALE_LIBRARY swscale HINTS ${FFMPEG_LIB_DIR})

qt_standard_project_setup(REQUIRES 6.5)

# Add executable
qt_add_executable(apprecorderOpenCV
    main.cpp
)

# Add QML module
qt_add_qml_module(apprecorderOpenCV
    URI recorderOpenCV
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES
        datamanager.h datamanager.cpp
        videocapturehandler.h videocapturehandler.cpp
        audiocapturehandler.h audiocapturehandler.cpp
)

# Set target properties
set_target_properties(apprecorderOpenCV PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Link libraries
target_link_libraries(apprecorderOpenCV
    PRIVATE Qt6::Quick Qt6::Multimedia
    ${OpenCV_LIBS}
    ${AVFORMAT_LIBRARY}
    ${AVCODEC_LIBRARY}
    ${AVUTIL_LIBRARY}
    ${SWSCALE_LIBRARY}
    ${PORTAUDIO_LIBRARIES} portaudio
)

# Install target
include(GNUInstallDirs)
install(TARGETS apprecorderOpenCV
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
