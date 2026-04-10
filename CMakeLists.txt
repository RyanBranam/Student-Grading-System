cmake_minimum_required(VERSION 3.20)

project(StudentGradingSystem)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(include)

add_executable(StudentGradingSystem
    src/main.cpp
        src/MainWindow.cpp
        include/MainWindow.h

        src/Student.cpp
        include/Student.h

        src/Grade.cpp
        include/Grade.h

        src/GradingScale.cpp
        include/GradingScale.h

        src/GradingSystem.cpp
        include/GradingSystem.h

        src/InputValidator.cpp
        include/InputValidator.h

        src/FileManager.cpp
        include/FileManager.h

        src/ReportCard.cpp
        include/ReportCard.h
)

target_link_libraries(StudentGradingSystem PRIVATE Qt6::Widgets)