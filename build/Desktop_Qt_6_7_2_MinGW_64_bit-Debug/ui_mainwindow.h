/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mycombobox.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QVideoWidget *video_widget;
    QSlider *slider_progress;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_start;
    QPushButton *pushButton_volume;
    QSlider *slider_volume;
    QLabel *label_time;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_open;
    MyComboBox *comboBox;
    QPushButton *pushButton_full;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(653, 480);
        MainWindow->setMinimumSize(QSize(640, 480));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        video_widget = new QVideoWidget(centralwidget);
        video_widget->setObjectName("video_widget");

        verticalLayout->addWidget(video_widget);

        slider_progress = new QSlider(centralwidget);
        slider_progress->setObjectName("slider_progress");
        slider_progress->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout->addWidget(slider_progress);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_start = new QPushButton(centralwidget);
        pushButton_start->setObjectName("pushButton_start");
        pushButton_start->setStyleSheet(QString::fromUtf8("*{\n"
"	border:none\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/D:/Apps/qIcon/play.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_start->setIcon(icon);
        pushButton_start->setCheckable(true);
        pushButton_start->setChecked(false);

        horizontalLayout->addWidget(pushButton_start);

        pushButton_volume = new QPushButton(centralwidget);
        pushButton_volume->setObjectName("pushButton_volume");
        pushButton_volume->setStyleSheet(QString::fromUtf8("*{\n"
"	border:none\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/D:/Apps/qIcon/\351\237\263\351\207\217.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_volume->setIcon(icon1);
        pushButton_volume->setCheckable(true);
        pushButton_volume->setChecked(true);

        horizontalLayout->addWidget(pushButton_volume);

        slider_volume = new QSlider(centralwidget);
        slider_volume->setObjectName("slider_volume");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(slider_volume->sizePolicy().hasHeightForWidth());
        slider_volume->setSizePolicy(sizePolicy);
        slider_volume->setMaximumSize(QSize(60, 16777215));
        slider_volume->setValue(50);
        slider_volume->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(slider_volume);

        label_time = new QLabel(centralwidget);
        label_time->setObjectName("label_time");

        horizontalLayout->addWidget(label_time);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_open = new QPushButton(centralwidget);
        pushButton_open->setObjectName("pushButton_open");

        horizontalLayout->addWidget(pushButton_open);

        comboBox = new MyComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMaximumSize(QSize(16777215, 16777215));
        comboBox->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        comboBox->setStyleSheet(QString::fromUtf8(""));
        comboBox->setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        comboBox->setDuplicatesEnabled(false);
        comboBox->setFrame(true);

        horizontalLayout->addWidget(comboBox);

        pushButton_full = new QPushButton(centralwidget);
        pushButton_full->setObjectName("pushButton_full");
        pushButton_full->setStyleSheet(QString::fromUtf8("*{\n"
"	border:none\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/D:/Apps/qIcon/mti-\345\205\250\345\261\217.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_full->setIcon(icon2);
        pushButton_full->setCheckable(true);

        horizontalLayout->addWidget(pushButton_full);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 8);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        comboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_start->setText(QString());
        pushButton_volume->setText(QString());
        label_time->setText(QCoreApplication::translate("MainWindow", "00\357\274\23200 / 00\357\274\23200", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200...", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "2x", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1.5x", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "1.25x", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "1.0x", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "0.75x", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("MainWindow", "1.0x", nullptr));
        pushButton_full->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
