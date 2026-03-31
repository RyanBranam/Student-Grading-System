#ifndef InputValidator_h
#define InputValidator_h

#include <string>

class InputValidator {
public:
    // returns true if score is between 0 and maxScore
    static bool isValidGrade(double score, double maxScore);

    // returns true if studentId is a positive integer
    static bool isValidStudent(int studentId);

    // goes to true if the string is not empty or only whitespace
    static bool isNonEmptyString(const std::string& str);
};

#endif
