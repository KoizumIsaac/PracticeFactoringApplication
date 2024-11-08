#include "factoringapplicationwindow.h"
#include "ui_factoringapplicationwindow.h"
#include "jkqtmathtext/jkqtmathtext.h"
#include <QPainter>
#include <QPixmap>


FactoringApplicationWindow::FactoringApplicationWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FactoringApplicationWindow)
{
    ui->setupUi(this);

    //Set up display.
    QPixmap pix(600,400);
    pix.fill(QColor("Orange"));
    QPainter painter;

    //Render Math Text
    JKQTMathText textRenderer;
    textRenderer.useXITS();
    textRenderer.setFontSize(20);

    //Paint Equation
    textRenderer.parse("$\\left[-\\frac{\\hbar^2}{2m}\\frac{\\partial^2}{\\partial x^2}+V(x)\\right]\\Psi(x)=\\mathrm{i}\\hbar\\frac{\\partial}{\\partial t}\\Psi(x)$");
    painter.begin(&pix);
    textRenderer.draw(painter, Qt::AlignCenter, QRectF(0,0,pix.width(), pix.height()), false);
    painter.end();

    ui->equationDisplay->setPixmap(pix);
    ui->equationDisplay->show();
    ui->equationDisplay->resize(600,400);

}

FactoringApplicationWindow::~FactoringApplicationWindow()
{
    delete ui;
}
