#include "Student.h"
#include "GradingScale.h"
#include "InputValidator.h"
#include <iostream>

// Initializes student with ID and name, behavior and comments default to empty
Student::Student(int studentId, const std::string& name)
    : studentId(studentId), name(name), behavior(""), comments("") {}

// Validates and adds a new grade to the student
void Student::addGrade(const std::string& category, double score,
                       double maxScore, double weight) {
    if (!InputValidator::isNonEmptyString(category)) {
        std::cout << "Invalid category. Cannot be empty.\n";
        return;
    }
    if (!InputValidator::isValidGrade(score, maxScore)) {
        std::cout << "Invalid grade. Score must be between 0 and maxScore.\n";
        return;
    }

    if (weight < 0.0 || weight > 1.0) {
        std::cout << "Invalid weight. Must be between 0.0 and 1.0.\n";
        return;
    }

    grades.push_back(Grade(category, score, maxScore, weight));
    std::cout << "Grade added successfully.\n";
}

// Edits the score of a grade at the given index
void Student::editGrade(int index, double newScore) {
    if (index < 0 || index >= (int)grades.size()) {
        std::cout << "Invalid index. No grade found at position " << index << ".\n";
        return;
    }
    if (!InputValidator::isValidGrade(newScore, grades[index].getMaxScore())) {
        std::cout << "Invalid score.\n";
        return;
    }

    grades[index].setScore(newScore);
    std::cout << "Grade updated successfully.\n";
}

// Calculates weighted average across all grades
// Formula: sum(percentage * weight) / sum(weights)
double Student::calculateAverage() const {
    if (grades.empty()) {
        return 0.0;   // Edge case: no grades yet
    }

    double totalWeightedScore = 0.0;
    double totalWeight = 0.0;

    for (const Grade& g : grades) {
        totalWeightedScore += g.getPercentage() * g.getWeight();
        totalWeight += g.getWeight();
    }

    if (totalWeight == 0.0) return 0.0;   // Avoid division by zero

    return totalWeightedScore / totalWeight;
}

// Returns letter grade using the provided grading scale
std::string Student::getFinalLetterGrade(const GradingScale& scale) const {
    return scale.assignLetterGrade(calculateAverage());
}

// Getters
int Student::getStudentId() const { return studentId; }
std::string Student::getName() const { return name; }
std::string Student::getBehavior() const { return behavior; }
std::string Student::getComments() const { return comments; }
std::vector<Grade> Student::getGrades() const { return grades; }

// Setters
void Student::setName(const std::string& name) { this->name = name; }
void Student::setBehavior(const std::string& behavior) { this->behavior = behavior; }
void Student::setComments(const std::string& comments) { this->comments = comments; }
