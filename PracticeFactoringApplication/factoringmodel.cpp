#include "factoringmodel.h"

FactoringModel::FactoringModel(QObject *parent)
    : QObject{parent}
    , firstAnswer(2)
    , secondAnswer(3)
{}

QString FactoringModel::getPolynomial() {
    int intendedMultiplierFirst = firstAnswer * -1;
    int intendedMultiplierSecond = secondAnswer * -1;
    if(intendedMultiplierFirst+intendedMultiplierSecond < 0) {
        if(intendedMultiplierFirst*intendedMultiplierSecond < 0) {
            return "x^2-" + QString::number(intendedMultiplierFirst+intendedMultiplierSecond) + "x-" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        } else {
            return "x^2-" + QString::number(intendedMultiplierFirst+intendedMultiplierSecond) + "x+" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        }
    } else if(intendedMultiplierFirst+intendedMultiplierSecond == 0) {
        if(intendedMultiplierFirst*intendedMultiplierSecond < 0) {
            return "x^2-" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        } else {
            return "x^2+" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        }
    } else {
        if(intendedMultiplierFirst*intendedMultiplierSecond < 0) {
            return "x^2+" + QString::number(intendedMultiplierFirst+intendedMultiplierSecond) + "x-" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        } else {
            return "x^2+" + QString::number(intendedMultiplierFirst+intendedMultiplierSecond) + "x+" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        }
    }
}

void FactoringModel::updateToNewPolynomial() {

}
