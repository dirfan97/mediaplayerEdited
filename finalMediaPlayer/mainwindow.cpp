#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player=new QMediaPlayer(this);
    vw=new QVideoWidget(this);
    player->setVideoOutput(vw);
    //this->setCentralWidget(vw);
    vw->show();
    vw->setGeometry(00,100,480,400);

    QVideoEncoderSettings videoSettings;
    videoSettings.setCodec("H.264/MPEG-4");
    connect(player,&QMediaPlayer::positionChanged,this,&MainWindow::on_positionChanged);
    connect(player,&QMediaPlayer::durationChanged,this,&MainWindow::on_durationChanged);
    connect(vw,&QVideoWidget::fullScreenChanged,this,&MainWindow::showFullScreen);
    connect(vw,&QVideoWidget::brightnessChanged,this,&MainWindow::on_spinBox_valueChanged);
    connect(vw,&QVideoWidget::contrastChanged,this,&MainWindow::on_Contspin_valueChanged);
    connect(vw,&QVideoWidget::saturationChanged,this,&MainWindow::on_SatSpin_valueChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionFileOpen_triggered()
{
    QString filename= QFileDialog::getOpenFileName(this,"Open A File","","(*.MP3 *.WAV *.WMV *.MP4)");
    player->setMedia(QUrl::fromLocalFile(filename));
    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
}

void MainWindow::on_positionChanged(qint64 position)
{
    ui->ProgressSlider->setValue(position);
}

void MainWindow::on_ProgressSlider_sliderMoved(int position)
{
    player->setPosition(position);

}

void MainWindow::on_dial_sliderMoved(int position)
{
     player->setVolume(position);
}

void MainWindow::on_durationChanged(qint64 position)
{
   ui->ProgressSlider->setMaximum(position);
}

void MainWindow::showFullScreen(bool fullScreen){
    ui->actionFullScreen->setDisabled(fullScreen);

}

void MainWindow::on_actionFullScreen_triggered(bool fullScreen)
{
    vw->setFullScreen(fullScreen);

}



void MainWindow::on_spinBox_valueChanged(int brightness)
{
    vw->setBrightness(brightness);
}

void MainWindow::on_Contspin_valueChanged(int contrast)
{
    vw->setContrast(contrast);
}



void MainWindow::on_SatSpin_valueChanged(int saturation)
{
    vw->setSaturation(saturation);
}
