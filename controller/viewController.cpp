#include "viewController.h"
#include "ui_viewController.h"

ViewController::ViewController(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewController)
{
    ui->setupUi(this);
}

ViewController::~ViewController()
{
    delete ui;
}

