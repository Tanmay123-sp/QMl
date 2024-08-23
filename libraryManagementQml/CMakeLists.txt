cmake_minimum_required(VERSION 3.16)

project(libraryManagementQml VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the required Qt6 components including QtWidgets
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Quick Widgets)

qt_standard_project_setup(REQUIRES 6.5)

# Add the executable and include the necessary source files
qt_add_executable(applibraryManagementQml
    main.cpp
    mainwindow.cpp
    mainwindow.h
    # dialog.cpp
    # dialog.h
    # assign.cpp
    # assign.h
    # details.cpp
    # details.h
    # stack.cpp
    # stack.h
)

# Add QML module and link QML files
qt_add_qml_module(applibraryManagementQml
    URI libraryManagementQml
    VERSION 1.0
    QML_FILES
        Main.qml
        update.qml
        assign.qml
        details.qml
        bookList.qml
)

# Set target properties (optional, depends on your target platform)
set_target_properties(applibraryManagementQml PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Link the target with the necessary Qt6 libraries including QtWidgets
target_link_libraries(applibraryManagementQml
    PRIVATE Qt6::Core Qt6::Quick Qt6::Widgets
)

# Install rules
install(TARGETS applibraryManagementQml
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
