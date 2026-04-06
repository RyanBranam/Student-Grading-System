#ifndef Grade_h
#define Grade_h

#include <string>

class Grade {
private:
    std::string category;        // Type of grade (exam, hw, quiz)
    double score;                // Points earned
    double maxScore;             // Max possible points
    double weight;               // Weight of this grade toward final grade

public:
    //Initializes Grade object with required values
    Grade(const std::string& category, double score, double maxScore, double weight);

    double getMaxScore() const;
    double getWeight() const;           // Returns weight of this grade (used in weighted avg calc)
    double getScore() const;            // returns score
    double getPercentage() const;       // returns percentage (score / maxScore * 100)
    std::string getCategory() const;    // returns category of grade

void setScore(double score);     // Updates score value

};

#endif