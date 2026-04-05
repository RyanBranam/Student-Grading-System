#include <iostream>
#include "Grade.h"
#include "Student.h"
#include "GradingScale.h"
#include "GradingSystem.h"


int main() {

    /* NOTE!!!!!!
     * All of this is for testing
     * This has no effect on the final menu system and is gonna get deleted when everything is done
    */

/*
    // Test Grade class by crating sample objects
    Grade grade1("Exam", 85, 100, 0.30);
    Grade grade2("Homework", 18, 20, 0.10);

    // Display info for grade1
    std::cout << "Grade 1 Category: " << grade1.getCategory() << std::endl;
    std::cout << "Grade 1 Percentage: " << grade1.getPercentage() << "%" << std::endl;

    // Display info for grade2
    std::cout << "Grade 2 Category: " << grade2.getCategory() << std::endl;
    std::cout << "Grade 2 Percentage: " << grade2.getPercentage() << "%" << std::endl;

    // Test Grading Scale
        std::cout << "\n Testing Grading Scale";

        GradingScale scale;

        std::cout << "95 -> " << scale.assignLetterGrade(95) << std::endl;
        std::cout << "85 -> " << scale.assignLetterGrade(85) << std::endl;
        std::cout << "75 -> " << scale.assignLetterGrade(75) << std::endl;
        std::cout << "65 -> " << scale.assignLetterGrade(65) << std::endl;
        std::cout << "55 -> " << scale.assignLetterGrade(55) << std::endl;

        // Custom scale test
        scale.setScale(85, 75, 65, 55);
        std::cout << "Custom scale, 84 -> " << scale.assignLetterGrade(84) << std::endl;
*/
    GradingSystem system;
    int choice;
    do {
        std::cout << "Welcome to the Student Grading System!\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Edit Student\n";
        std::cout << "3. Delete Student\n";
        std::cout << "4. Enter Grades for Student\n";
        std::cout << "5. Generate Report Cards\n";
        std::cout << "6. Search for Student\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose an option: ";
        
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int tempId;
                std::string tempName;
                std::cout << "Enter Student ID of student you would like to add: ";
                std::cin >> tempId;
                std::cin.ignore();
                std::cout << "Enter Name of student you would like to add: ";
                std::getline(std::cin, tempName);
                system.addStudent(tempId, tempName);
                break; }
            case 2: {
                int tempId;
                std::string newName, newBehavior, newComments;
                std::cout << "Enter Student ID of student you would like to edit: ";
                std::cin >> tempId;
                std::cin.ignore();
                Student* s = system.searchStudent(tempId);
                if (s == nullptr) {
                    std::cout << "Student with ID " << tempId << " not found.\n";
                    break; }
                else {
                    std::cout << "Student found\n";
                    std::cout << "Enter new name for student or press enter to keep current name: ";
                    std::getline(std::cin, newName);
                    if (!newName.empty()) s->setName(newName);
                    
                    std::cout << "Enter new behavior notes for student or press enter to keep current behavior: ";
                    std::getline(std::cin, newBehavior);
                    if (!newBehavior.empty()) s->setBehavior(newBehavior);
                    
                    std::cout << "Enter new comments notes for student or press enter to keep current comments: ";
                    std::getline(std::cin, newComments);
                    if (!newComments.empty()) s->setComments(newComments); }
                break; }
            case 3: {
                int tempId;
                std::cout << "Enter Student ID of student you would like to delete: ";
                std::cin >> tempId;
                std::cin.ignore();
                system.deleteStudent(tempId);
                break; }
            case 4: {
                int tempId;
                std::cout << "Enter Student ID of student you would like to enter grades for: ";
                std::cin >> tempId;
                std::cin.ignore();
                Student* s = system.searchStudent(tempId);
                if (s == nullptr) {
                    std::cout << "Student with ID " << tempId << " not found.\n";
                    break; }
                else {
                    std::cout << "Student found\n";
                    std::string category;
                    double score, maxScore, weight;
                    std::cout << "Enter a grade category (Ex: Exam, Homework, etc.): ";
                    std::getline(std::cin, category);
                    std::cout << "Enter score earned for this grade: ";
                    std::cin >> score;
                    std::cout << "Enter max possible score for this grade: ";
                    std::cin >> maxScore;
                    std::cout << "Enter weight of this grade toward final grade (Ex: 0.0-1.0): ";
                    std::cin >> weight;
                    s->addGrade(category, score, maxScore, weight); }
                break; }
            case 5: {
                system.generateReports();
                break; }
            case 6: {
                int tempId;
                std::cout << "Enter Student ID of student you would like to search for: ";
                std::cin >> tempId;
                std::cin.ignore();
                Student* s = system.searchStudent(tempId);
                if (s == nullptr) {
                    std::cout << "Student with ID " << tempId << " not found.\n";
                    break; }
                else {
                    std::cout << "Student found: " << s->getName() << "\n"; }
                break; }
            case 7:
                std::cout << "Goodbye!\n";
                break;
            default: {
                std::cout << "Sorry that is an invalid option.\n";
                break; } }
    } while (choice != 7);
    
    return 0;
}
