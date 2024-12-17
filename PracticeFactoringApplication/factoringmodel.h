#ifndef FACTORINGMODEL_H
#define FACTORINGMODEL_H

#include <QObject>

///
/// \brief The FactoringModel class - Class to track and check if polynomial is right.
///
class FactoringModel : public QObject
{
    Q_OBJECT

public:
    explicit FactoringModel(QObject *parent = nullptr);

signals:
    ///
    /// \brief updateEquation - Let's display know it needs to update.
    ///
    void updateEquation();

    ///
    /// \brief resultOfCheckEquation - Result of checking if the zeros were right.
    /// \param result - The boolean of the check.
    ///
    void resultOfCheckEquation(bool result);

    ///
    /// \brief updateLongestStreak - Updates the longest streak label.
    /// \param longestStreak - The new longest streak.
    ///
    void updateLongestStreak(int longestStreak);

    ///
    /// \brief updateCurrentStreak - Updates the current streak.
    /// \param currentStreak - The new current streak.
    ///
    void updateCurrentStreak(int currentStreak);

public slots:
    ///
    /// \brief updateToNewPolynomial - Updates the polynomial to check for a new one.
    ///
    void updateToNewPolynomial();

    ///
    /// \brief getPolynomial - Gets the polynomial as a string.
    /// \return String of the polynomial
    ///
    QString getPolynomial();

    ///
    /// \brief checkEquation - Checks the zeros the user inputted and emits a signal that sends if it
    /// correct or not.
    ///
    /// \param firstZero - First zero to check
    /// \param secondZero - Second zero to check
    ///
    void checkEquation(int firstZero, int secondZero);

private:
    int firstAnswer;
    int secondAnswer;
    int currentStreak;
    int longestStreak;
    bool checkedAnswerBeforeUpdate;
};

#endif // FACTORINGMODEL_H
