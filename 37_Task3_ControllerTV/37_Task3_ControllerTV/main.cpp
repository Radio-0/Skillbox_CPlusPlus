#include "Task3_ControllerTV.h"
#include <QtWidgets/QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Task3_ControllerTV window(nullptr);
    Ui::Task3_ControllerTVClass control;
    control.setupUi(&window);
    window.canalLab = control.canalLab;
    window.volLab = control.volLab;
    window.resize(240, 680);
    window.show();
    return app.exec();
}
