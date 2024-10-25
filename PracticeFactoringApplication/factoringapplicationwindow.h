#ifndef FACTORINGAPPLICATIONWINDOW_H
#define FACTORINGAPPLICATIONWINDOW_H

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
    FactoringApplicationWindow(QWidget *parent = nullptr);
    ~FactoringApplicationWindow();

private:
    Ui::FactoringApplicationWindow *ui;
};
#endif // FACTORINGAPPLICATIONWINDOW_H
