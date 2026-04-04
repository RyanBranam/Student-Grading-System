#include <iostream>
#include "Grade.h"
#include "Student.h"
#include "GradingScale.h"


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


    int choice;

    std::cout << "Welcome to the Student Grading System!\n";
    std::cout << "1. Add Student\n";

    std::cin>>choice;



    return 0;
}
