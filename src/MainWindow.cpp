#include "MainWindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QTextEdit>
#include <QAbstractItemView>
#include <QInputDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QLineEdit>
#include <QString>

#include <sstream>
#include <vector>
#include <string>

// Constructor initializes UI components and connects signals to slots
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    fileManager("students.txt"),
    studentTable(nullptr),
    addStudentButton(nullptr),
    deleteStudentButton(nullptr),
    addGradeButton(nullptr),
    editNotesButton(nullptr),
    generateReportButton(nullptr),
    refreshButton(nullptr),
    saveButton(nullptr),
    loadButton(nullptr),
    outputBox(nullptr) {
    // sets up all UI elements
    setupUi();

    // Load initial table state
    refreshTable();
    // Log successful startup
    logMessage("GUI loaded successfully.");

    //Connect button clicks to corresponding slot functions
    connect(addStudentButton, &QPushButton::clicked, this, &MainWindow::addStudent);
    connect(deleteStudentButton, &QPushButton::clicked, this, &MainWindow::deleteStudent);
    connect(addGradeButton, &QPushButton::clicked, this, &MainWindow::addGrade);
    connect(editNotesButton, &QPushButton::clicked, this, &MainWindow::editNotes);
    connect(generateReportButton, &QPushButton::clicked, this, &MainWindow::generateReport);
    connect(refreshButton, &QPushButton::clicked, this, &MainWindow::refreshTable);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveToFile);
    connect(loadButton, &QPushButton::clicked, this, &MainWindow::loadFromFile);
}

// Destructor
MainWindow::~MainWindow() = default;

// Sets up GUI layout and widges
void MainWindow::setupUi() {
    setWindowTitle("Student Grading System");
    resize(1100, 650);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    studentTable = new QTableWidget(this);
    studentTable->setColumnCount(4);
    studentTable->setHorizontalHeaderLabels({"ID", "Name", "Average", "Letter Grade"});
    studentTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    studentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    studentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    studentTable->setSelectionMode(QAbstractItemView::SingleSelection);

    // Buttons for user actions
    addStudentButton = new QPushButton("Add Student", this);
    deleteStudentButton = new QPushButton("Delete Student", this);
    addGradeButton = new QPushButton("Add Grade", this);
    editNotesButton = new QPushButton("Edit Notes", this);
    generateReportButton = new QPushButton("Generate Report", this);
    refreshButton = new QPushButton("Refresh", this);
    saveButton = new QPushButton("Save", this);
    loadButton = new QPushButton("Load", this);

    // Outputs for logs and reports
    outputBox = new QTextEdit(this);
    outputBox->setReadOnly(true);
    outputBox->setPlaceholderText("Messages and report output will appear here...");

    // Add buttons to layout
    buttonLayout->addWidget(addStudentButton);
    buttonLayout->addWidget(deleteStudentButton);
    buttonLayout->addWidget(addGradeButton);
    buttonLayout->addWidget(editNotesButton);
    buttonLayout->addWidget(generateReportButton);
    buttonLayout->addWidget(refreshButton);
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(loadButton);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(studentTable);
    mainLayout->addWidget(outputBox);
}

// Adds new student
void MainWindow::addStudent() {
    bool ok = false;
    // Prompts for student id
    int id = QInputDialog::getInt(
        this,
        "Add Student",
        "Enter student ID:",
        1000,
        1,
        999999,
        1,
        &ok
        );

    if (!ok) {
        return;
    }
    // Prompt for student name
    QString name = QInputDialog::getText(
        this,
        "Add Student",
        "Enter student name:",
        QLineEdit::Normal,
        "",
        &ok
        );

    if (!ok || name.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Student name cannot be empty.");
        return;
    }
    // Add student to system
    gradingSystem.addStudent(id, name.trimmed().toStdString());
    refreshTable();
    logMessage("Attempted to add student: " + name.trimmed());
}
// Deletes selected student
void MainWindow::deleteStudent() {
    int row = studentTable->currentRow();
    std::vector<Student>& students = gradingSystem.getStudents();
    // Validate selection
    if (row < 0 || row >= static_cast<int>(students.size())) {
        QMessageBox::information(this, "Select Student", "Please select a student first.");
        return;
    }

    Student& student = students[row];
    int id = student.getStudentId();
    QString name = QString::fromStdString(student.getName());

    // Confirm deletion
    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Delete Student",
        "Are you sure you want to delete " + name + "?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::No) {
        return;
    }

    // Delete student
    gradingSystem.deleteStudent(id);
    refreshTable();
    logMessage("Deleted student: " + name);
}

// Adds grade to student
void MainWindow::addGrade() {
    int row = studentTable->currentRow();
    std::vector<Student>& students = gradingSystem.getStudents();

    if (row < 0 || row >= static_cast<int>(students.size())) {
        QMessageBox::information(this, "Select Student", "Please select a student first.");
        return;
    }

    Student& student = students[row];
    bool ok = false;

    // Gets grade inputs
    QString category = QInputDialog::getText(
        this,
        "Add Grade",
        "Enter category:",
        QLineEdit::Normal,
        "",
        &ok
        );

    if (!ok || category.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Category cannot be empty.");
        return;
    }

    double score = QInputDialog::getDouble(
        this,
        "Add Grade",
        "Enter score:",
        0.0,
        0.0,
        1000.0,
        2,
        &ok
        );

    if (!ok) {
        return;
    }

    double maxScore = QInputDialog::getDouble(
        this,
        "Add Grade",
        "Enter max score:",
        100.0,
        0.0,
        1000.0,
        2,
        &ok
        );

    if (!ok) {
        return;
    }

    double weight = QInputDialog::getDouble(
        this,
        "Add Grade",
        "Enter weight:",
        1.0,
        0.0,
        100.0,
        2,
        &ok
        );

    if (!ok) {
        return;
    }

    // Add grade to student
    student.addGrade(category.trimmed().toStdString(), score, maxScore, weight);

    refreshTable();
    logMessage("Added grade for " + QString::fromStdString(student.getName()));
}

// Allows editing of behavior and comments for student
void MainWindow::editNotes() {
    int row = studentTable->currentRow();
    std::vector<Student>& students = gradingSystem.getStudents();

    if (row < 0 || row >= static_cast<int>(students.size())) {
        QMessageBox::information(this, "Select Student", "Please select a student first.");
        return;
    }

    Student& student = students[row];
    bool ok = false;

    // Prompt user to edit behavior notes
    QString behavior = QInputDialog::getMultiLineText(
        this,
        "Edit Behavior",
        "Enter behavior notes:",
        QString::fromStdString(student.getBehavior()),
        &ok
        );

    if (!ok) {
        return;
    }

    // Prompts user to edit comments
    QString comments = QInputDialog::getMultiLineText(
        this,
        "Edit Comments",
        "Enter teacher comments:",
        QString::fromStdString(student.getComments()),
        &ok
        );

    if (!ok) {
        return;
    }

    // Updates student notes
    student.setBehavior(behavior.toStdString());
    student.setComments(comments.toStdString());

    logMessage("Updated notes for " + QString::fromStdString(student.getName()));
}

// Generates and displays report card for selected student
void MainWindow::generateReport() {
    int row = studentTable->currentRow();
    std::vector<Student>& students = gradingSystem.getStudents();

    if (row < 0 || row >= static_cast<int>(students.size())) {
        QMessageBox::information(this, "Select Student", "Please select a student first.");
        return;
    }

    Student& student = students[row];

    // Display formatted report
    outputBox->append("------------------------------");
    outputBox->append("Report Card");
    outputBox->append("ID: " + QString::number(student.getStudentId()));
    outputBox->append("Name: " + QString::fromStdString(student.getName()));
    outputBox->append("Average: " + QString::number(student.calculateAverage(), 'f', 1) + "%");
    outputBox->append("Letter Grade: " +
                      QString::fromStdString(student.getFinalLetterGrade(gradingSystem.getScale())));
    outputBox->append("Behavior: " + QString::fromStdString(student.getBehavior()));
    outputBox->append("Comments: " + QString::fromStdString(student.getComments()));
    outputBox->append("------------------------------");
    outputBox->append("");
}

// Refreshes current table to reflect current data
void MainWindow::refreshTable() {
    std::vector<Student>& students = gradingSystem.getStudents();
    // Set number of rows to match number of students
    studentTable->setRowCount(static_cast<int>(students.size()));
    // Row = student data
    for (int i = 0; i < static_cast<int>(students.size()); ++i) {
        Student& student = students[i];
        //Displays student id
        studentTable->setItem(i, 0,
                              new QTableWidgetItem(QString::number(student.getStudentId())));
        // Displays student name
        studentTable->setItem(i, 1,
                              new QTableWidgetItem(QString::fromStdString(student.getName())));
        // Displays average
        studentTable->setItem(i, 2,
                              new QTableWidgetItem(
                                  QString::number(student.calculateAverage(), 'f', 1) + "%"));
        // Display final letter grade
        studentTable->setItem(i, 3,
                              new QTableWidgetItem(
                                  QString::fromStdString(
                                      student.getFinalLetterGrade(gradingSystem.getScale()))));
    }
}
// Saves all student data and grades to a file
void MainWindow::saveToFile() {
    std::vector<Student>& students = gradingSystem.getStudents();
    std::ostringstream out;

    for (const Student& student : students) {
        out << "STUDENT|"
            << student.getStudentId() << "|"
            << student.getName() << "|"
            << student.getBehavior() << "|"
            << student.getComments() << "\n";

        std::vector<Grade> grades = student.getGrades();
        for (const Grade& grade : grades) {
            out << "GRADE|"
                << grade.getCategory() << "|"
                << grade.getScore() << "|"
                << grade.getMaxScore() << "|"
                << grade.getWeight() << "\n";
        }

        out << "END_STUDENT\n";
    }
    // Save string to file
    fileManager.saveData(out.str());
    logMessage("Saved student data to students.txt");
}
// Loads student data and grades from a file
void MainWindow::loadFromFile() {
    std::string data = fileManager.loadData();

    // Checks if empty
    if (data.empty()) {
        QMessageBox::information(this, "Load", "No saved data found.");
        return;
    }

    // Clears exisitng data before loading
    gradingSystem.getStudents().clear();

    std::istringstream in(data);
    std::string line;
    Student* currentStudent = nullptr;

    // Reads file line by line
    while (std::getline(in, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string type;
        std::getline(ss, type, '|');

        // Handles student data
        if (type == "STUDENT") {
            std::string idStr, name, behavior, comments;
            std::getline(ss, idStr, '|');
            std::getline(ss, name, '|');
            std::getline(ss, behavior, '|');
            std::getline(ss, comments, '|');

            int id = std::stoi(idStr);

            // Add student and store pointer
            gradingSystem.addStudent(id, name);
            currentStudent = gradingSystem.searchStudent(id);

            // Set notes if student found
            if (currentStudent != nullptr) {
                currentStudent->setBehavior(behavior);
                currentStudent->setComments(comments);
            }
        }
        // Handle grade data
        else if (type == "GRADE" && currentStudent != nullptr) {
            std::string category, scoreStr, maxScoreStr, weightStr;
            std::getline(ss, category, '|');
            std::getline(ss, scoreStr, '|');
            std::getline(ss, maxScoreStr, '|');
            std::getline(ss, weightStr, '|');

            double score = std::stod(scoreStr);
            double maxScore = std::stod(maxScoreStr);
            double weight = std::stod(weightStr);

            // Add grade to current student
            currentStudent->addGrade(category, score, maxScore, weight);
        }
        // End of student data
        else if (type == "END_STUDENT") {
            currentStudent = nullptr;
        }
    }

    refreshTable();
    logMessage("Loaded student data from students.txt");
}

void MainWindow::logMessage(const QString& message) {
    outputBox->append(message);
}