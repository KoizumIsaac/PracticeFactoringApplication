#include "factoringapplicationwindow.h"
#include "ui_factoringapplicationwindow.h"
#include "jkqtmathtext/jkqtmathtext.h"
#include "factoringmodel.h"
#include <QPainter>
#include <QPixmap>


FactoringApplicationWindow::FactoringApplicationWindow(FactoringModel* factorModel, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FactoringApplicationWindow)
    , factorModel( factorModel )
{
    ui->setupUi(this);

    //Set up display.
    QPixmap pix(300,200);
    pix.fill(QColor("Orange"));
    QPainter painter;

    //Render Math Text
    JKQTMathText textRenderer;
    textRenderer.useXITS();
    textRenderer.setFontSize(20);

    //Paint Equation
    textRenderer.parse(factorModel->getPolynomial());
    painter.begin(&pix);
    textRenderer.draw(painter, Qt::AlignCenter, QRectF(0,0,pix.width(), pix.height()), false);
    painter.end();

    ui->equationDisplay->setPixmap(pix);
    ui->equationDisplay->show();
    ui->equationDisplay->resize(300,200);

}



FactoringApplicationWindow::~FactoringApplicationWindow()
{
    delete ui;
}
