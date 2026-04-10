#pragma once
#include <QMainWindow>

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

private:
    void setupUi();

    QTableWidget* studentTable;
    QPushButton* addStudentButton;
    QPushButton* addGradeButton;
    QPushButton* generateReportButton;
    QPushButton* refreshButton;
    QTextEdit* outputBox;
};
