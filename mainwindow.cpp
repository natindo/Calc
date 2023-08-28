#include "mainwindow.h"
#include "./ui_mainwindow.h"

double numFirst;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digitNumbers()));
    connect(ui->pushButton_plusMinus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_perCent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(on_pushButton_clear_clicked()));
    connect(ui->pushButton_equals, SIGNAL(clicked()), this, SLOT(on_pushButton_equals_clicked()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(mathOperations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(mathOperations()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(mathOperations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(mathOperations()));

    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitNumbers () {

    QPushButton *button = (QPushButton*) sender();

    double showResult;
    QString newLable;

    if (ui->resultShow->text().contains(".") && button->text() == "0") {
        newLable = ui->resultShow->text() + button->text();
    } else {
        showResult = (ui->resultShow->text() + button->text()).toDouble();
        newLable = QString::number(showResult, 'g', 15);
    }

    ui->resultShow->setText(newLable);

}

void MainWindow::on_pushButton_dot_clicked() {
    if (!ui->resultShow->text().contains(".")) {
        ui->resultShow->setText(ui->resultShow->text() + ".");
    }
}

void MainWindow::operations () {
    QPushButton *button = (QPushButton*) sender();

    double showResult;
    QString newLable;

    if (button->text() == "+/-") {
        showResult = (ui->resultShow->text()).toDouble();
        showResult *= -1;
        newLable = QString::number(showResult, 'g', 15);

        ui->resultShow->setText(newLable);
    }

    if (button->text() == "%") {
        showResult = (ui->resultShow->text()).toDouble();
        showResult *= 0.01;
        newLable = QString::number(showResult, 'g', 15);

        ui->resultShow->setText(newLable);
    }

}


void MainWindow::on_pushButton_clear_clicked() {

    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->resultShow->setText("0");
    numFirst = 0;
}


void MainWindow::on_pushButton_equals_clicked() {

    double lableNumber, numSecond;
    QString newLable;

    numSecond = ui->resultShow->text().toDouble();

    if (ui->pushButton_minus->isChecked()) {
        lableNumber = numFirst - numSecond;
        newLable = QString::number(lableNumber, 'g', 15);
        ui->resultShow->setText(newLable);
        ui->pushButton_minus->setChecked(false);
    }
    if (ui->pushButton_plus->isChecked()) {
        lableNumber = numFirst + numSecond;
        newLable = QString::number(lableNumber, 'g', 15);
        ui->resultShow->setText(newLable);
        ui->pushButton_plus->setChecked(false);
    }
    if (ui->pushButton_divide->isChecked()) {
        if (numSecond == 0) {
            ui->resultShow->setText("NO WAY");
        } else {
            lableNumber = numFirst / numSecond;
            newLable = QString::number(lableNumber, 'g', 15);
            ui->resultShow->setText(newLable);
        }
        ui->pushButton_divide->setChecked(false);
    }
    if (ui->pushButton_multiply->isChecked()) {
        lableNumber = numFirst * numSecond;
        newLable = QString::number(lableNumber, 'g', 15);
        ui->resultShow->setText(newLable);
        ui->pushButton_multiply->setChecked(false);
    }
}

void MainWindow::mathOperations() {
    QPushButton *button = (QPushButton*) sender();

    numFirst = ui->resultShow->text().toDouble();
    ui->resultShow->setText("");

    button->setChecked(true);
}
