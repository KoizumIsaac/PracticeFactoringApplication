#include "factoringmodel.h"

FactoringModel::FactoringModel(QObject *parent) :  QObject{parent}, currentStreak(0), longestStreak(0), checkedAnswerBeforeUpdate(false) {
    updateToNewPolynomial();
}

QString FactoringModel::getPolynomial() {
    int intendedMultiplierFirst = firstAnswer * -1;
    int intendedMultiplierSecond = secondAnswer * -1;

    //Checks if certain parts of the polynomial should be omitted.
    if(intendedMultiplierFirst + intendedMultiplierSecond < 0) {
        if(intendedMultiplierFirst * intendedMultiplierSecond < 0) {
            return "x^2-" + QString::number(intendedMultiplierFirst + intendedMultiplierSecond) + "x-" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        } else if(intendedMultiplierFirst*intendedMultiplierSecond > 0) {
            return "x^2-" + QString::number(intendedMultiplierFirst + intendedMultiplierSecond) + "x+" + QString::number(intendedMultiplierFirst*intendedMultiplierSecond);
        } else {
            return "x^2-" + QString::number(intendedMultiplierFirst + intendedMultiplierSecond) + "x";
        }
    } else if(intendedMultiplierFirst + intendedMultiplierSecond == 0) {
        if(intendedMultiplierFirst * intendedMultiplierSecond == 0) {
            return "x^2";
        }
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
    firstAnswer = rand() % 21 - 10;
    secondAnswer = rand() % 21 - 10;

    if(firstAnswer > secondAnswer) {
        std::swap(firstAnswer, secondAnswer);
    }

    //If the user did not check their answer before getting a new equation, consider it as incorrect.
    if(!checkedAnswerBeforeUpdate) {
        emit updateCurrentStreak(0);
        currentStreak = 0;
    }
    emit updateEquation();
}

void FactoringModel::checkEquation(int firstZero, int secondZero) {
    checkedAnswerBeforeUpdate = true;

    //If both zeros are the same; if user does not input both, consider incorrect.
    if(firstAnswer == secondAnswer) {
        if(firstAnswer != firstZero || firstAnswer != secondZero) {
            emit updateCurrentStreak(0);
            currentStreak = 0;
            return;
        }
    }

    //If both zeros are different; if user does not input both, consider incorrect.
    if((firstZero != firstAnswer && secondZero != firstAnswer) ||
       (firstZero != secondAnswer && secondZero != secondAnswer)) {
        emit updateCurrentStreak(0);
        currentStreak = 0;
        return;
    }

    if(++currentStreak > longestStreak) {
        longestStreak = currentStreak;
        emit updateLongestStreak(longestStreak);
    }
    emit updateCurrentStreak(currentStreak);
}
