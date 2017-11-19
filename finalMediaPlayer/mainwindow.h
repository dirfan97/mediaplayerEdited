#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QGraphicsVideoItem>
#include <QVideoEncoderSettings>
#include <QString>
#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QBoxLayout>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:


    void on_actionPlay_triggered();

    void on_actionStop_triggered();

    void on_actionPause_triggered();

    void on_actionFileOpen_triggered();

    void on_ProgressSlider_sliderMoved(int position);

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 position);

    void on_dial_sliderMoved(int position);

    void showFullScreen(bool fullScreen);

    void on_actionFullScreen_triggered(bool fullScreen);

    void on_spinBox_valueChanged(int brightness);


    void on_Contspin_valueChanged(int contrast);

    void on_SatSpin_valueChanged(int saturation);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QVideoWidget *vw;
    QProgressBar *bar;
    QSlider *slider;
};

#endif // MAINWINDOW_H
