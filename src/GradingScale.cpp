#include "GradingScale.h"

// Default constructor sets standard 90/80/70/60 scale
GradingScale::GradingScale()
    : aMin(90.0), bMin(80.0), cMin(70.0), dMin(60.0) {}

// Updates the grade boundaries with custom values
void GradingScale::setScale(double a, double b, double c, double d) {
    aMin = a;
    bMin = b;
    cMin = c;
    dMin = d;
}

// Returns letter grade based on percentage
std::string GradingScale::assignLetterGrade(double percentage) const {
    if (percentage >= aMin) return "A";
    if (percentage >= bMin) return "B";
    if (percentage >= cMin) return "C";
    if (percentage >= dMin) return "D";
    return "F";
}
