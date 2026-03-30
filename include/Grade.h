#ifndef Grade_h
#define Grade_h

#include <string>

class Grade {
private:
    std::string category;
    double score;
    double maxScore;
    double weight;

public:
    Grade(std::string category, double score, double maxScore, double weight);

    double getScore() const;
    double getPercentage() const;
    std::string getCategory() const;

void setScore(double score);

};

#endif