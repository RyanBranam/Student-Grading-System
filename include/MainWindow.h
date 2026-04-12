#pragma once
#include <QMainWindow>
#include "GradingSystem.h"


QT_BEGIN_NAMESPACE
class QTableWidget;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    // Constructor initializes the main window
    explicit MainWindow(QWidget* parent = nullptr);
    // Destructor, cleans up allocated resources
    ~MainWindow();

private slots:
    void addStudent();
    void addGrade();
    void generateReport();
    void refreshTable();
    void deleteStudent();
    void saveToFile();
    void loadFromFile();
    void editNotes();

private:
    void setupUi();     // Sets up all UI components
    void logMessage(const QString& message);    //Displays messages in the output box

    GradingSystem gradingSystem;
    FileManager fileManager;

    QTableWidget* studentTable;
    // Buttons for user actions
    QPushButton* addStudentButton;
    QPushButton* addGradeButton;
    QPushButton* editNotesButton;
    QPushButton* generateReportButton;
    QPushButton* refreshButton;
    QPushButton* deleteStudentButton;
    QPushButton* saveButton;
    QPushButton* loadButton;
    QTextEdit* outputBox;
};
