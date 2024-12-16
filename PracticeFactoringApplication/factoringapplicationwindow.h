#ifndef FACTORINGAPPLICATIONWINDOW_H
#define FACTORINGAPPLICATIONWINDOW_H

#include "jkqtmathtext/jkqtmathtext.h"
#include "factoringmodel.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class FactoringApplicationWindow;
}
QT_END_NAMESPACE

class FactoringApplicationWindow : public QMainWindow
{
    Q_OBJECT

public:
    FactoringApplicationWindow(FactoringModel* factorModel, QWidget *parent = nullptr);
    ~FactoringApplicationWindow();

signals:
    void getEquation();
    void checkZeros(int firstZero, int secondZero);

public slots:
    void paintEquation();

    void resultOfCheckEquation(bool resultOfCheck);

private:
    Ui::FactoringApplicationWindow *ui;
    FactoringModel* factorModel;
};
#endif // FACTORINGAPPLICATIONWINDOW_H
