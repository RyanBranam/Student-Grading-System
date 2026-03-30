#include <iostream>
#include "Grade.h"

int main() {

// Test Grade class by crating sample objects
    Grade grade1("Exam", 85, 100, 0.30);
    Grade grade2("Homework", 18, 20, 0.10);

// Display info for grade1
    std::cout << "Grade 1 Category: " << grade1.getCategory() << std::endl;
    std::cout << "Grade 1 Percentage: " << grade1.getPercentage() << "%" << std::endl;

// Display info for grade2
    std::cout << "Grade 2 Category: " << grade2.getCategory() << std::endl;
    std::cout << "Grade 2 Percentage: " << grade2.getPercentage() << "%" << std::endl;

    return 0;
}
