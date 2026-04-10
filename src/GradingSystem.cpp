#include "GradingSystem.h"
#include <algorithm>
#include <iostream>

//  constructor — scale uses default 90/80/70/60 boundaries
GradingSystem::GradingSystem() {}

// looks if valid and  adds a new student to the system
void GradingSystem::addStudent(int studentId, const std::string &name)
{
    if (!InputValidator::isValidStudent(studentId)) {
        std::cout << "Invalid student ID. Must be a positive integer.\n";
        return;
    }
    if (!InputValidator::isNonEmptyString(name)) {
        std::cout << "Invalid name. Name cannot be empty.\n";
        return;
    }
    // looks for duplicate ID
    if (searchStudent(studentId) != nullptr) {
        std::cout << "A student with ID " << studentId << " already exists.\n";
        return;
    }

    students.push_back(Student(studentId, name));
    std::cout << "Student " << name << " added successfully.\n";
}

// looks and removes a student by ID
void GradingSystem::deleteStudent(int studentId)
{
    if (students.empty()) {
        std::cout << "No students to delete.\n";
        return;
    }

    auto it = std::remove_if(students.begin(), students.end(), [studentId](const Student &s) {
        return s.getStudentId() == studentId;
    });

    if (it == students.end()) {
        std::cout << "Student with ID " << studentId << " not found.\n";
    } else {
        students.erase(it, students.end());
        std::cout << "Student with ID " << studentId << " deleted successfully.\n";
    }
}

// returns a pointer to the student with the given ID, or nullptr if not found
Student *GradingSystem::searchStudent(int studentId)
{
    for (Student &s : students) {
        if (s.getStudentId() == studentId) {
            return &s;
        }
    }
    return nullptr;
}

// generates and displays a report card for every student
void GradingSystem::generateReports() const
{
    if (students.empty()) {
        std::cout << "No students in the system.\n";
        return;
    }

    for (const Student &s : students) {
        double avg = s.calculateAverage();
        std::string letterGrade = s.getFinalLetterGrade(scale);

        ReportCard report(s.getName(), avg, letterGrade, s.getBehavior(), s.getComments());
        report.generateReport();
        report.displayReport();
    }
}

// returns reference to the students vector
std::vector<Student> &GradingSystem::getStudents()
{
    return students;
}

// return reference to the grading scale
GradingScale &GradingSystem::getScale()
{
    return scale;
}
