#include "factoringapplicationwindow.h"
#include "ui_factoringapplicationwindow.h"
#include "jkqtmathtext/jkqtmathtext.h"
#include "factoringmodel.h"
#include <QPainter>
#include <QPixmap>
#include <QTimer>


FactoringApplicationWindow::FactoringApplicationWindow(FactoringModel* factorModel, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FactoringApplicationWindow)
    , factorModel(factorModel)
{
    ui->setupUi(this);

    paintEquation();

    connect(factorModel,
            &FactoringModel::updateEquation,
            this,
            &FactoringApplicationWindow::paintEquation);

    connect(ui->newEquationButton,
            &QPushButton::clicked,
            factorModel,
            &FactoringModel::updateToNewPolynomial);

    connect(ui->checkAnswerButton,
            &QPushButton::clicked,
            factorModel,
            [this, factorModel] { factorModel->checkEquation(ui->firstZeroInputBox->value(), ui->secondZeroInputBox->value()); });

    connect(factorModel,
            &FactoringModel::updateCurrentStreak,
            this,
            &FactoringApplicationWindow::updateCurrentStreak);

    connect(factorModel,
            &FactoringModel::updateLongestStreak,
            this,
            &FactoringApplicationWindow::updateLongestStreak);
}

FactoringApplicationWindow::~FactoringApplicationWindow()
{
    delete ui;
}

void FactoringApplicationWindow::paintEquation() {
    QPixmap pix(300,200);
    pix.fill(QColor("White"));
    QPainter painter;

    JKQTMathText textRenderer;
    textRenderer.useXITS();
    textRenderer.setFontSize(20);

    textRenderer.parse(factorModel->getPolynomial());
    painter.begin(&pix);
    textRenderer.draw(painter, Qt::AlignCenter, QRectF(0,0,pix.width(), pix.height()), false);
    painter.end();

    ui->equationDisplay->setPixmap(pix);
    ui->equationDisplay->show();
    ui->equationDisplay->resize(300,200);
}

void FactoringApplicationWindow::updateCurrentStreak(int currentStreak) {
    ui->currentStreakLabel->setText("Current Streak: " + QString::number(currentStreak));

    //If the user gets the answer right, they should get a new equation.
    if(currentStreak != 0) {
        ui->checkAnswerButton->setStyleSheet("QPushButton { background-color: green }");
        QTimer::singleShot(500, [this] { ui->checkAnswerButton->setStyleSheet("QPushButton { background-color: gray }"); });
        factorModel->updateToNewPolynomial();
    } else {
        ui->checkAnswerButton->setStyleSheet("QPushButton { background-color: red }");
        QTimer::singleShot(500, [this] { ui->checkAnswerButton->setStyleSheet("QPushButton { background-color: gray }"); });
    }
}

void FactoringApplicationWindow::updateLongestStreak(int longestStreak) {
    ui->longestStreakLabel->setText("Longest Streak: " + QString::number(longestStreak));
}
