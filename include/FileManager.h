#ifndef FileManager_h
#define FileManager_h

#include <string>

class FileManager {
private:
    std::string fileName;   // Name of the file to read/write

public:
    // Initializes FileManager with a given file name
    FileManager(const std::string& fileName);

    // Saves the given data string to the file
    void saveData(const std::string& data) const;

    // Loads and returns the contents of the file as a string
    std::string loadData() const;

    // Getter and setter for fileName
    std::string getFileName() const;
    void setFileName(const std::string& fileName);
};

#endif
