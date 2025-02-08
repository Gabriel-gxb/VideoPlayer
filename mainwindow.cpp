#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QAudioOutput>
#include <QFileDialog>
#include <QKeyEvent>
#include <QListView>
#include <QToolTip>
#include <qdir.h>
#include <qmediaplayer.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setVideoOutput(ui->video_widget);

    ui->slider_volume->installEventFilter(this);
    ui->slider_progress->installEventFilter(this);
    ui->video_widget->installEventFilter(this);

    connect(player,&QMediaPlayer::durationChanged,this,[&](qint64 duration){
        ui->slider_progress->setMaximum(duration);
        int sec = duration/1000;
        int min = sec/60;
        sec %= 60;
        m_durationTime = QTime(0,min,sec).toString("mm：ss");
        ui->label_time->setText(m_positionTime+"/"+m_durationTime);
    });

    connect(player,&QMediaPlayer::positionChanged,this,[&](qint64 position){
        ui->slider_progress->setValue(position);
        int sec = position/1000;
        int min = sec/60;
        sec %= 60;
        m_positionTime = QTime(0,min,sec).toString("mm：ss");
        ui->label_time->setText(m_positionTime+"/"+m_durationTime);
    });

    connect(player,&QMediaPlayer::playbackStateChanged,this,[&](QMediaPlayer::PlaybackState newState){
        if(newState == QMediaPlayer::StoppedState){
            ui->pushButton_start->setChecked(false);
            ui->pushButton_start->setIcon(QIcon(":/D:/Apps/qIcon/play.png"));
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->slider_volume && event->type() == QEvent::MouseMove){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        int value = static_cast<QSlider*>(watched)->value();
        QToolTip::showText
            (mouseEvent->globalPosition().toPoint(),QString::number(value));
    }
    if(watched == ui->slider_progress && event->type() == QEvent::MouseMove){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if(!player->source().isEmpty())
            QToolTip::showText(mouseEvent->globalPosition().toPoint(),
                               m_positionTime+"/"+m_durationTime);
    }
    if(watched == ui->video_widget && event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key() == Qt::Key_Escape){
            if(ui->video_widget->isFullScreen()){
                ui->video_widget->setFullScreen(false);
                ui->pushButton_full->setChecked(false);
            }
        }
        if(keyEvent->key() == Qt::Key_Space && ui->video_widget->isFullScreen()){
            if(player->isPlaying()){
                ui->pushButton_start->setIcon(QIcon(":/D:/Apps/qIcon/play.png"));
                ui->pushButton_start->setChecked(false);
                player->pause();
            }
            else{
                ui->pushButton_start->setIcon(QIcon(":/D:/Apps/qIcon/pause.png"));
                ui->pushButton_start->setChecked(true);
                player->play();
            }
        }
    }
    return QMainWindow::eventFilter(watched,event);
}


void MainWindow::on_pushButton_volume_clicked(bool checked)
{
    ui->slider_volume->setVisible(checked);
}

void MainWindow::on_pushButton_start_clicked(bool checked)
{
    if(checked){
        ui->pushButton_start->setIcon(QIcon(":/D:/Apps/qIcon/pause.png"));
        player->play();
    }
    else {
        ui->pushButton_start->setIcon(QIcon(":/D:/Apps/qIcon/play.png"));
        player->pause();
    }
}

void MainWindow::on_pushButton_full_clicked(bool checked)
{
    ui->video_widget->setFullScreen(checked);
}

void MainWindow::on_slider_volume_valueChanged(int value)
{
    player->audioOutput()->setVolume(value/100.0);
    if(value==0)
        ui->pushButton_volume->setIcon(QIcon(":/D:/Apps/qIcon/静音.png"));
    else
        ui->pushButton_volume->setIcon(QIcon(":/D:/Apps/qIcon/音量.png"));
}

void MainWindow::on_pushButton_open_clicked()
{
    QString curPath = QDir::currentPath();
    QString title = "打开文件";
    QString filter = "*mp4";
    QFileDialog::Options options = QFileDialog::DontUseNativeDialog;
    QString afile = QFileDialog::getOpenFileName
        (this,curPath,title,filter,nullptr,options);
    if(afile.isEmpty())
        return;

    player->setSource(QUrl::fromLocalFile(afile));
    player->play();

    ui->pushButton_start->setChecked(true);
    ui->pushButton_start->setIcon(QIcon(":/D:/Apps/qIcon/pause.png"));
}

void MainWindow::on_slider_progress_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_slider_progress_sliderPressed()
{
    player->setPosition(ui->slider_progress->value());
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QString str = ui->comboBox->itemText(index);
    qreal value = str.left(str.size()-1).toDouble();
    player->setPlaybackRate(value);
}

