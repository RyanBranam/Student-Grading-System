#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Initializes FileManager with the provided file name
FileManager::FileManager(const std::string &fileName)
    : fileName(fileName)
{}

// Saves data string to the file, overwrites existing content
void FileManager::saveData(const std::string &data) const
{
    std::ofstream outFile(fileName);

    if (!outFile.is_open()) {
        std::cout << "Error: Could not open file \"" << fileName << "\" for writing.\n";
        return;
    }

    outFile << data;
    outFile.close();
    std::cout << "Data saved to \"" << fileName << "\" successfully.\n";
}

// Loads and returns the full contents of the file as a string
std::string FileManager::loadData() const
{
    std::ifstream inFile(fileName);

    if (!inFile.is_open()) {
        std::cout << "Error: Could not open file \"" << fileName << "\" for reading.\n";
        return "";
    }

    std::ostringstream buffer;
    buffer << inFile.rdbuf();
    inFile.close();

    return buffer.str();
}

// Getter
std::string FileManager::getFileName() const
{
    return fileName;
}

// Setter
void FileManager::setFileName(const std::string &newFileName)
{
    fileName = newFileName;
}
