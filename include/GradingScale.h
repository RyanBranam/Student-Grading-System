#ifndef GradingScale_h
#define GradingScale_h

#include <string>

class GradingScale {
private:
    double aMin;   // min score for A
    double bMin;   // Min score for B
    double cMin;   // min score for C
    double dMin;   // min score for D
    // anything below dMin is an F

public:
    // initializes GradingScale with default boundaries (A=90, B=80, C=70, D=60)
    GradingScale();

    // allows customization of grade boundaries
    void setScale(double aMin, double bMin, double cMin, double dMin);

    // returns letter grade to A, B, C, D, F based on a percentage score
    std::string assignLetterGrade(double percentage) const;
};

#endif
