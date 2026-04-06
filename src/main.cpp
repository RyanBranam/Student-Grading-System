#include <iostream>
#include <limits>
#include "Student.h"
#include "GradingSystem.h"



int main() {

    GradingSystem system;
    int choice;
    do {
        std::cout << "\nWelcome to the Student Grading System!\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Edit Student\n";
        std::cout << "3. Delete Student\n";
        std::cout << "4. Enter Grades for Student\n";
        std::cout << "5. Generate Report Cards\n";
        std::cout << "6. Search for Student\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose an option: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                int tempId;
                std::string tempName;

                std::cout << "Enter Student ID of student you would like to add: ";
                if (!(std::cin >> tempId)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid student ID.\n";
                    break;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter Name of student you would like to add: ";
                std::getline(std::cin, tempName);

                system.addStudent(tempId, tempName);
                break;
            }

            case 2: {
                int tempId;
                std::string newName, newBehavior, newComments;

                std::cout << "Enter Student ID of student you would like to edit: ";
                if (!(std::cin >> tempId)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid student ID.\n";
                    break;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                Student* s = system.searchStudent(tempId);
                if (s == nullptr) {
                    std::cout << "Student with ID " << tempId << " not found.\n";
                    break;
                }

                std::cout << "Student found.\n";

                std::cout << "Enter new name for student or press enter to keep current name: ";
                std::getline(std::cin, newName);
                if (!newName.empty()) {
                    s->setName(newName);
                }

                std::cout << "Enter new behavior notes for student or press enter to keep current behavior: ";
                std::getline(std::cin, newBehavior);
                if (!newBehavior.empty()) {
                    s->setBehavior(newBehavior);
                }

                std::cout << "Enter new comments for student or press enter to keep current comments: ";
                std::getline(std::cin, newComments);
                if (!newComments.empty()) {
                    s->setComments(newComments);
                }

                std::cout << "Student updated successfully.\n";
                break;
            }

            case 3: {
                int tempId;

                std::cout << "Enter Student ID of student you would like to delete: ";
                if (!(std::cin >> tempId)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid student ID.\n";
                    break;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                system.deleteStudent(tempId);
                break;
            }

            case 4: {
                int tempId;

                std::cout << "Enter Student ID of student you would like to enter grades for: ";
                if (!(std::cin >> tempId)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid student ID.\n";
                    break;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                Student* s = system.searchStudent(tempId);
                if (s == nullptr) {
                    std::cout << "Student with ID " << tempId << " not found.\n";
                    break;
                }

                std::cout << "Student found.\n";

                std::string category;
                double score, maxScore, weight;

                std::cout << "Enter a grade category (Ex: Exam, Homework, etc.): ";
                std::getline(std::cin, category);

                std::cout << "Enter score earned for this grade: ";
                if (!(std::cin >> score)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid score.\n";
                    break;
                }

                std::cout << "Enter max possible score for this grade: ";
                if (!(std::cin >> maxScore)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid max score.\n";
                    break;
                }

                std::cout << "Enter weight of this grade toward final grade (Ex: 0.0-1.0): ";
                if (!(std::cin >> weight)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid weight.\n";
                    break;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                s->addGrade(category, score, maxScore, weight);
                break;
            }

            case 5: {
                system.generateReports();
                break;
            }

            case 6: {
                int tempId;

                std::cout << "Enter Student ID of student you would like to search for: ";
                if (!(std::cin >> tempId)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid student ID.\n";
                    break;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                Student* s = system.searchStudent(tempId);
                if (s == nullptr) {
                    std::cout << "Student with ID " << tempId << " not found.\n";
                } else {
                    std::cout << "Student found: " << s->getName() << "\n";
                }
                break;
            }

            case 7:
                std::cout << "Goodbye!\n";
                break;

            default:
                std::cout << "Sorry, that is an invalid option.\n";
                break;
        }

    } while (choice != 7);
    
    return 0;
}
