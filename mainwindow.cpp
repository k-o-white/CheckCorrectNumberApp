#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QObject::connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString text)
    {
       if (ui->lineEdit->text().isEmpty())
           setStartLabel();
       else
       {
           QRegularExpression exp("^(\\+)\\d{11}$");
           if (exp.match(text).hasMatch())
               setOkLabel();
           else
               setNonOkLabel();
       }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setStartLabel()
{
    ui->label->setText("Input number");
    ui->label->setStyleSheet("QLabel {color : black;}");
}

void MainWindow::setOkLabel()
{
    ui->label->setText("Correct");
    ui->label->setStyleSheet("QLabel {color : green;}");
}

void MainWindow::setNonOkLabel()
{
    ui->label->setText("Incorrect");
    ui->label->setStyleSheet("QLabel {color : red;}");
}

