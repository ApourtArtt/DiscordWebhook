#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    configured = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(!configured)
        wHook = new Webhook(ui->TB_URL->text());
    wHook->sendMsg(ui->TB_CHAT->document()->toPlainText());
}
