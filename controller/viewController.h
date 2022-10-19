#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ViewController; }
QT_END_NAMESPACE

class ViewController : public QMainWindow
{
    Q_OBJECT

public:
    ViewController(QWidget *parent = nullptr);
    ~ViewController();

private:
    Ui::ViewController *ui;
};
