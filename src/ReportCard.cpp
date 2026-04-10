#include "ReportCard.h"
#include "FileManager.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

// initializes all report card fields
ReportCard::ReportCard(const std::string &studentName,
                       double average,
                       const std::string &finalGrade,
                       const std::string &behavior,
                       const std::string &comments)
    : studentName(studentName)
    , average(average)
    , finalGrade(finalGrade)
    , behavior(behavior)
    , comments(comments)
{}

// Confirms report data is ready
void ReportCard::generateReport()
{
    // Data is set via constructor; this method is a hook for
    // any pre-display processing (e.g. rounding, formatting)
    average = std::round(average * 100.0) / 100.0;
}

// Prints a formatted report card to the console
void ReportCard::displayReport() const
{
    std::cout << "\n==============================\n";
    std::cout << "         REPORT CARD\n";
    std::cout << "==============================\n";
    std::cout << "Student Name : " << studentName << "\n";
    std::cout << "Average      : " << std::fixed << std::setprecision(2) << average << "%\n";
    std::cout << "Final Grade  : " << finalGrade << "\n";
    std::cout << "Behavior     : " << behavior << "\n";
    std::cout << "Comments     : " << comments << "\n";
    std::cout << "==============================\n\n";
}

// Saves the report card to a file using FileManager
void ReportCard::saveReport(const std::string &fileName) const
{
    std::ostringstream out;
    out << "==============================\n"
        << "         REPORT CARD\n"
        << "==============================\n"
        << "Student Name : " << studentName << "\n"
        << "Average      : " << std::fixed << std::setprecision(2) << average << "%\n"
        << "Final Grade  : " << finalGrade << "\n"
        << "Behavior     : " << behavior << "\n"
        << "Comments     : " << comments << "\n"
        << "==============================\n";

    FileManager fm(fileName);
    fm.saveData(out.str());
}

// Getters
std::string ReportCard::getStudentName() const
{
    return studentName;
}
double ReportCard::getAverage() const
{
    return average;
}
std::string ReportCard::getFinalGrade() const
{
    return finalGrade;
}
std::string ReportCard::getBehavior() const
{
    return behavior;
}
std::string ReportCard::getComments() const
{
    return comments;
}
