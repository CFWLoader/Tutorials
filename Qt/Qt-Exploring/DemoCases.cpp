#include "DemoCases.h"
#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int demo1(int argc, char *argv[]){
    QApplication a(argc, argv);
    QLabel* label = new QLabel("Hello Qt!");
    label->show();
    return a.exec();
}

int demo2(int argc, char *argv[]){
    QApplication a(argc, argv);
    QPushButton* button = new QPushButton("Exit");
    QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));
    button->show();
    return a.exec();
}

int demo3(int argc, char* argv[]){
    QApplication a(argc, argv);

    QWidget* window = new QWidget();
    window->setWindowTitle("Setting value");

    QSpinBox* spinBox = new QSpinBox();
    QSlider* slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    spinBox->setValue(35);

    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window->setLayout(layout);

    window->show();

    return a.exec();
}

int demo4(int argc, char *argv[]){
    QApplication app(argc, argv);

    MainWindow w;
    w.show();
    return app.exec();
}
