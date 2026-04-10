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
    explicit MainWindow(QWidget* parent = nullptr);
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
    void setupUi();
    void logMessage(const QString& message);

    GradingSystem gradingSystem;
    FileManager fileManager;

    QTableWidget* studentTable;
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
