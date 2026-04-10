cmake_minimum_required(VERSION 3.20)

project(StudentGradingSystem)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(StudentGradingSystem
    src/main.cpp
    src/Grade.cpp
    src/InputValidator.cpp
    src/Student.cpp
    src/GradingSystem.cpp
    src/GradingScale.cpp
    src/ReportCard.cpp
    src/FileManager.cpp
        include/MainWindow.h
        src/MainWindow.cpp
)
