#ifndef Student_h
#define Student_h

#include <string>
#include <vector>
#include "Grade.h"

class Student {
private:
    int studentId;                 // Unique student identifier
    std::string name;              // Studen name
    std::string behavior;          // Behavior notes 
    std::string comments;          // Additional teacher comments
    std::vector<Grade> grades;     // List of all grades for this student

public:
    // Initializes Student with an ID and name
    Student(int studentId, const std::string& name);

    // Adds a new grade to the student's grade list
    void addGrade(const std::string& category, double score,
                  double maxScore, double weight);

    // Edits an existing grade by index
    void editGrade(int index, double newScore);

    // Calcs and returns the weighted average of all grades
    double calculateAverage() const;

    // Returns the final letter grade based on the weighted average
    std::string getFinalLetterGrade(const class GradingScale& scale) const;

    // Getters
    int getStudentId() const;
    std::string getName() const;
    std::string getBehavior() const;
    std::string getComments() const;
    std::vector<Grade> getGrades() const;

    // Setters
    void setName(const std::string& name);
    void setBehavior(const std::string& behavior);
    void setComments(const std::string& comments);
};

#endif
