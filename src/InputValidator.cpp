#include "InputValidator.h"
#include <algorithm>
#include <cctype>

// if score is non negative and does not exceed maxScore
bool InputValidator::isValidGrade(double score, double maxScore)
{
    return score >= 0.0 && score <= maxScore && maxScore > 0.0;
}

// sees if  studentId is a positive non-zero integer
bool InputValidator::isValidStudent(int studentId)
{
    return studentId > 0;
}

// Checks that string is not empty or entirely whitespace
bool InputValidator::isNonEmptyString(const std::string &str)
{
    return !str.empty() && std::any_of(str.begin(), str.end(), [](char c) {
        return !std::isspace(static_cast<unsigned>(c));
    });
}
