cmake_minimum_required(VERSION 3.14)

project(lab01 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(lab01
  main.cpp
  command.h command.cpp
  receiver.h receiver.cpp
  invoker.h invoker.cpp
  task1command.h task1command.cpp
  task2command.h task2command.cpp
  task3command.h task3command.cpp
)
target_link_libraries(lab01 Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS lab01
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
