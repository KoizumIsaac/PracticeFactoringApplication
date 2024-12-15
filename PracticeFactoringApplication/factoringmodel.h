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

public slots:
    ///
    /// \brief updateToNewPolynomial - Updates the polynomial to check for a new one.
    ///
    void updateToNewPolynomial();

    ///
    /// \brief getPolynomial - Gets the polynomial as a string
    /// \return String of the polynomial
    ///
    QString getPolynomial();

private:
    int firstAnswer;
    int secondAnswer;
};

#endif // FACTORINGMODEL_H
