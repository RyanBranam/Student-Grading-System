#ifndef GradingSystem_h
#define GradingSystem_h

#include <vector>
#include <string>
#include "Student.h"
#include "GradingScale.h"
#include "InputValidator.h"
#include "ReportCard.h"
#include "FileManager.h"

class GradingSystem {
private:
    std::vector<Student> students;   // list all students
    GradingScale scale;              // grading scale used for letter grades

public:
    //  constructor
    GradingSystem();

    // adds a new student to the system
    void addStudent(int studentId, const std::string& name);

    // deletes a student by their ID
    void deleteStudent(int studentId);

    // looks for a student by ID, returns pointer or nullptr if not found
    Student* searchStudent(int studentId);

    // generates and displays report cards for all students
    void generateReports() const;

    // returns reference to the list of students
    std::vector<Student>& getStudents();

    // returns reference to the grading scale
    GradingScale& getScale();
};

#endif
