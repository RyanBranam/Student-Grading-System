#include <QApplication>     // Provides application management
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    // Creates the app object
    QApplication app(argc, argv);
    //Creates the main window object
    MainWindow window;
    // Shows main window on screen
    window.show();

    // Keeps app running
    return app.exec();
}