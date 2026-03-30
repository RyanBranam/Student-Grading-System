#include "Grade.h"

// Initializes Grade object with category, score, maxScore, and weight
Grade::Grade(std::string category, double score, double maxScore, doouble weight)
    : category(category), score(score), maxScore(maxScore), weight(weight) {}

// Returns score earned for that grade
    double Grade::getScore() const {
        return score;
    }

// Return category of the grade (exam, hw, quiz)
    std::string Grade::getCategory() const {
        return category;
    }