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

///
/// \brief The FactoringApplicationWindow class - Displays polynomials for the user to find the zeros of.
///
class FactoringApplicationWindow : public QMainWindow
{
    Q_OBJECT

public:
    FactoringApplicationWindow(FactoringModel* factorModel, QWidget *parent = nullptr);
    ~FactoringApplicationWindow();

signals:
    ///
    /// \brief getEquation - Signals to get an equation from the model.
    ///
    void getEquation();

    ///
    /// \brief checkZeros - Asks model to check if the zeros inputted by the user are correct.
    /// \param firstZero - First zero to check
    /// \param secondZero - Second zero to check
    ///
    void checkZeros(int firstZero, int secondZero);

public slots:
    ///
    /// \brief paintEquation - Method to display a new polynomial given by the model.
    ///
    void paintEquation();

    ///
    /// \brief updateCurrentStreak - Updates the current streak the user is on
    /// # of polynomials they have found the zeros of in a row.
    /// \param currentStreak - Current streak as an int.
    ///
    void updateCurrentStreak(int currentStreak);

    ///
    /// \brief updateLongestStreak - Updates the longest streak of the user.
    /// \param longestStreak - Longest streak as an int.
    ///
    void updateLongestStreak(int longestStreak);

private:
    Ui::FactoringApplicationWindow *ui;
    FactoringModel* factorModel;
};
#endif // FACTORINGAPPLICATIONWINDOW_H
