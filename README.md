# Student Grading System

## Team Members

* Neison Arias Solares
* Ryan Branam
* Diego Castro
* Jessica Vasquez Costeno


## Project Overview

The Student Grading System is a C++ application designed to help teachers manage and calculate student grades for assignments, quizzes, and exams. Many teachers rely on spreadsheets or outdated systems, which can be time-consuming and prone to human error.

This system automates calculations, organizes student data, and provides an easy-to-use interface for managing grades. The overall goal is to save time, reduce errors, and provide a reliable grading system.


## Features

* Add, edit, and delete students
* Enter grades for assignments, quizzes, and exams
* Automatic grade calculation
* Assign letter grades based on grading scale
* Generate report cards
* Search and filter students
* Menu-based console interface


## Class Design

### Student

* Attributes: studentId, name, behavior, comments, grades
* Methods: addGrade(), editGrade(), calculateAverage(), getFinalLetterGrade()
* Relationship: A Student has many Grades

### Grade

* Attributes: category, score, maxScore, weight
* Methods: getScore(), getPercentage(), getCategory()
* Relationship: Grade belongs to Student

### GradingScale

* Attributes: grade boundaries (A, B, C, D, F)
* Methods: setScale(), assignLetterGrade()
* Relationship: Used by GradingSystem

### ReportCard

* Attributes: student name, average, final grade, behavior, comments
* Methods: generateReport(), displayReport(), saveReport()
* Relationship: Uses Student

### GradingSystem

* Attributes: list of students, grading scale
* Methods: addStudent(), deleteStudent(), searchStudent(), generateReports()
* Relationships:

  * Has many Students
  * Uses GradingScale
  * Creates ReportCard

### FileManager

* Attributes: fileName
* Methods: saveData(), loadData()
* Relationship: Works with GradingSystem

### InputValidator

* Methods: isValidGrade(), isValidStudentId(), isNonEmptyString()
* Relationship: Used by GradingSystem to validate user input

 ### MainWindow.cpp
* Attributes 
* gradingSystem, fileManager, UI widget pointers

* method
* setupUi(), addStudent(), deleteStudent(), addGrade(), editNotes(), generateReport(), refreshTable(), saveToFile(), 
* loadFromFile(), logMessage()

### ConsoleBackup.cpp
* Attributes
* uses local GradingSystem instance)
* Methods
* runConsoleBackup()  — menu loop: add, edit, delete, grade entry, report generation, search


## Error Handling

The program will validate user input using helper functions and setter methods. Invalid inputs such as negative grades or incorrect values will be rejected or corrected.

Edge cases handled include:

* Calculating grades when no grades exist
* Searching for non-existent students
* Deleting from an empty list

File errors will be handled safely by checking file operations before reading or writing. Exception handling may also be used where appropriate to prevent crashes.


## OOP Concepts Used

* **Encapsulation**: Private data with public getters/setters
* **Abstraction**: Functions hide complex logic
* **Inheritance**: Specialized grade types (e.g., ExamGrade, HomeworkGrade)
* **Polymorphism**: Different grade calculations depending on type


## Tools & Libraries

* C++20
* `<iostream>`
* `<string>`
* `<vector>`
* `<fstream>`
* `<iomanip>`
* `<algorithm>`

* ai for help

## How to Run

1. Clone the repository
2. Open in CLion or Visual Studio
3. Build and run the project

## Future Improvements

* Add a GUI-based interface for easier interaction
  
