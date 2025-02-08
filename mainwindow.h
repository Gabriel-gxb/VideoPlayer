#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QMediaPlayer;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_volume_clicked(bool checked);

    void on_pushButton_open_clicked();

    void on_pushButton_start_clicked(bool checked);

    void on_pushButton_full_clicked(bool checked);

    void on_slider_volume_valueChanged(int value);


    void on_slider_progress_sliderMoved(int position);

    void on_slider_progress_sliderPressed();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    QMediaPlayer *player;
    QString m_durationTime;
    QString m_positionTime;


    // QWidget interface

    // QObject interface
public:
    virtual bool eventFilter(QObject *watched, QEvent *event) override;

    // QWidget interface
};


#endif // MAINWINDOW_H
