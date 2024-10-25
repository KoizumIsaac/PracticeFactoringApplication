#include "factoringapplicationwindow.h"
#include "ui_factoringapplicationwindow.h"

FactoringApplicationWindow::FactoringApplicationWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FactoringApplicationWindow)
{
    ui->setupUi(this);
}

FactoringApplicationWindow::~FactoringApplicationWindow()
{
    delete ui;
}
