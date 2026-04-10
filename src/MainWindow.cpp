#include "MainWindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QTextEdit>
#include <QAbstractItemView>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    studentTable(nullptr),
    addStudentButton(nullptr),
    addGradeButton(nullptr),
    generateReportButton(nullptr),
    refreshButton(nullptr),
    outputBox(nullptr) {
    setupUi();
}
    MainWindow::~MainWindow() = default;

void MainWindow::setupUi() {
    setWindowTitle("Student Grading System");
    resize(950, 600);

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

    addStudentButton = new QPushButton("Add Student", this);
    addGradeButton = new QPushButton("Add Grade", this);
    generateReportButton = new QPushButton("Generate Report", this);
    refreshButton = new QPushButton("Refresh", this);

    outputBox = new QTextEdit(this);
    outputBox->setReadOnly(true);
    outputBox->setPlaceholderText("Messages and reports will appear here...");

    buttonLayout->addWidget(addStudentButton);
    buttonLayout->addWidget(addGradeButton);
    buttonLayout->addWidget(generateReportButton);
    buttonLayout->addWidget(refreshButton);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(studentTable);
    mainLayout->addWidget(outputBox);
}
