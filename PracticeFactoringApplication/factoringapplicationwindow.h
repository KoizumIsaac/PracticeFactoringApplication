#ifndef FACTORINGAPPLICATIONWINDOW_H
#define FACTORINGAPPLICATIONWINDOW_H

#include "jkqtmathtext/jkqtmathtext.h"
#include "factoringmodel.h"
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

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

    void updateCurrentStreak(int currentStreak);

    void updateLongestStreak(int longestStreak);

private:
    Ui::FactoringApplicationWindow *ui;
    FactoringModel* factorModel;
};
#endif // FACTORINGAPPLICATIONWINDOW_H
