#include "factoringapplicationwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FactoringModel* factorModel = new FactoringModel();
    FactoringApplicationWindow w( factorModel );
    w.show();
    return a.exec();
}
