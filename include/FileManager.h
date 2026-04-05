#ifndef FileManager_h
#define FileManager_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Student.h"
#include "GradingScale.h"
#include "InputValidator.h"
#include "ReportCard.h"

// File manager uses already existing student class


class FileManager {
private:
    std::string fileName;

public:
    // Constructor to initialize the target filename
    explicit FileManager(const std::string& name) : fileName(name) {}
    
    
     // Saves the list of students to a file using outFile
     // Iterates through the vector and writes each student's data
    
    void saveData(const std::vector<Student>& students) {
        std::ofstream outFile(fileName, std::ios::out | std::ios::trunc);
        //std::ios::trunc overwrites old saved data with the new one to avoid creating duplicates of saved data in files
        
        //provides error message for if the file fails to open for whatever reason
        if (!outFile) {
            std::cerr << "Error: Could not open file " << fileName <<  std::endl;
            return;
        }
        //if data is successfully saved
        outFile.close();
        std::cout << "Data successfully saved to " << fileName << "." << std::endl;
    }
  
    // Loads student data from the file (student vector) into the system using inFile
    std::vector<Student> loadData() {
        std::vector<Student> students;
        std::ifstream inFile(fileName);

        if (!inFile) {
            // Error handling for if file doesn't exist yet
            std::cout << "No existing data file found. Starting with an empty list." << std::endl;
            return students;
        }

        inFile.close();
        return students;
    }
};

#endif
