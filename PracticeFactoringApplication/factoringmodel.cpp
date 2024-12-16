#include "factoringmodel.h"

#include <QRandomGenerator>
#include <QDebug>

FactoringModel::FactoringModel(QObject *parent) : QObject{parent} {
    updateToNewPolynomial();
}

QString FactoringModel::getPolynomial() {
    int intendedMultiplierFirst = firstAnswer * -1;
    int intendedMultiplierSecond = secondAnswer * -1;
    if(intendedMultiplierFirst + intendedMultiplierSecond < 0) {
        if(intendedMultiplierFirst * intendedMultiplierSecond < 0) {
            return "x^2-" + QString::number(intendedMultiplierFirst + intendedMultiplierSecond) + "x-" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        } else if(intendedMultiplierFirst*intendedMultiplierSecond > 0) {
            return "x^2-" + QString::number(intendedMultiplierFirst + intendedMultiplierSecond) + "x+" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        } else {
            return "x^2-" + QString::number(intendedMultiplierFirst + intendedMultiplierSecond) + "x";
        }
    } else if(intendedMultiplierFirst + intendedMultiplierSecond == 0) {
        if(intendedMultiplierFirst * intendedMultiplierSecond < 0) {
            return "x^2-" + QString::number(intendedMultiplierFirst * intendedMultiplierSecond);
        } else {
            return "x^2+" + QString::number(intendedMultiplierFirst * intendedMultiplierSecond);
        }
    } else {
        if(intendedMultiplierFirst * intendedMultiplierSecond < 0) {
            return "x^2+" + QString::number(intendedMultiplierFirst + intendedMultiplierSecond) + "x-" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        } else if(intendedMultiplierFirst * intendedMultiplierSecond > 0) {
            return "x^2+" + QString::number(intendedMultiplierFirst + intendedMultiplierSecond) + "x+" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        } else {
            return "x^2+" + QString::number(intendedMultiplierFirst + intendedMultiplierSecond) + "x";
        }
    }
}

void FactoringModel::updateToNewPolynomial() {
    firstAnswer = numberGenerator.bounded(-10, 10);
    secondAnswer = numberGenerator.bounded(-10, 10);

    if(firstAnswer > secondAnswer) {
        std::swap(firstAnswer, secondAnswer);
    }

    emit updateEquation();
}

void FactoringModel::checkEquation(int firstZero, int secondZero) {
    if((firstZero != firstAnswer && secondZero != firstAnswer) ||
       (firstZero != secondAnswer && secondZero != secondAnswer)) {
        emit resultOfCheckEquation(false);
        return;
    }
    emit resultOfCheckEquation(true);
}
