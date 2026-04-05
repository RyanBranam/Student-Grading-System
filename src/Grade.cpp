#include "Grade.h"

// Initializes Grade object with category, score, maxScore, and weight
Grade::Grade(const std::string& category, double score, double maxScore, double weight)
    : category(category), score(score), maxScore(maxScore), weight(weight) {}

// Returns score earned for that grade
    double Grade::getScore() const {
        return score;
    }

double Grade::getMaxScore() const {
    return maxScore;
}

// Return category of the grade (exam, hw, quiz)
    std::string Grade::getCategory() const {
        return category;
    }

// Calculates and returns percentage of the grade
    double Grade::getPercentage() const {
         if (maxScore == 0) {
            return 0;      // Avoid div by 0
    }
    return (score / maxScore) * 100;
}

// Getter for weight value (needed for student avg calc)
    double Grade::getWeight() const {
    return weight;
}

// Updates score for this grade
    void Grade::setScore(double newScore) {
        score = newScore;
}