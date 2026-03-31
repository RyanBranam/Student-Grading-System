#ifndef GradingScale_h
#define GradingScale_h

#include <string>

class GradingScale {
private:
    double aMin;   // Minimum score for A
    double bMin;   // Minimum score for B
    double cMin;   // Minimum score for C
    double dMin;   // Minimum score for D
    // Anything below dMin is an F

public:
    // Initializes GradingScale with default boundaries (A=90, B=80, C=70, D=60)
    GradingScale();

    // Allows customization of grade boundaries
    void setScale(double aMin, double bMin, double cMin, double dMin);

    // Returns letter grade (A, B, C, D, F) based on a percentage score
    std::string assignLetterGrade(double percentage) const;
};

#endif
