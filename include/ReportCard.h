#ifndef ReportCard_h
#define ReportCard_h

#include <string>
#include <cmath>

class ReportCard {
private:
    std::string studentName;   // name of  student
    double average;            //  grade average
    std::string finalGrade;    // Letter grade 
    std::string behavior;      // Behavior notes 
    std::string comments;      //  teacher comments

public:
    // Initializes ReportCard with all required  info
    ReportCard(const std::string& studentName, double average,
               const std::string& finalGrade, const std::string& behavior,
               const std::string& comments);

    // Prepares the report card data for display/saving
    void generateReport();

    // Displays the report card to the console
    void displayReport() const;

    // Saves the report card to a file via FileManager
    void saveReport(const std::string& fileName) const;

    
    std::string getStudentName() const;
    double getAverage() const;
    std::string getFinalGrade() const;
    std::string getBehavior() const;
    std::string getComments() const;
};

#endif
