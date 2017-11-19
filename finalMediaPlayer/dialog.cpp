#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    vw=new QVideoWidget(this);
    connect(MainWindow::vw,&QVideoWidget::brightnessChanged,this,&Dialog::on_BrightnessSlider_sliderMoved)
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_BrightnessSlider_sliderMoved(int position)
{
   MainWindow::vw->brightness();
}
