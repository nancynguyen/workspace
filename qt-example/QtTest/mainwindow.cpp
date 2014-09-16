#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtMultimedia>


unsigned int LEDGPIO = 25;   // GPIO1_28 = (1x32) + 28 = 60


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_testButton_clicked()
{
    ui->testEdit->setText("HelloWolrd! This is CM-FX6!");

}

void MainWindow::on_actionOpenImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open Image File",QDir::currentPath());
    if(!fileName.isEmpty())
    {
//        imageObject = new QImage();
//        imageObject->load(fileName);


        QPixmap item(fileName);
//        QPixmap item = QPixmap::fromImage(imageObject);

        int width = ui->graphicsView->geometry().width();
        int height = ui->graphicsView->geometry().height();

        QGraphicsScene* scene = new QGraphicsScene(QRectF(0, 0, width, height), 0);

        scene->addPixmap(item.scaled(QSize((int)scene->width(),(int)scene->height()),Qt::KeepAspectRatio,Qt::SmoothTransformation));
//        scene->addPixmap(item);

        ui->graphicsView->fitInView(QRectF(0,0,width,height),Qt::KeepAspectRatio);

        ui->graphicsView->setScene(scene);
        ui->graphicsView->showMaximized();

    }
}

void MainWindow::on_ledOnButton_clicked()
{
    ui->testEdit->setText("Turning LED On!");

    gpio_export(LEDGPIO);    // The LED
    gpio_set_dir(LEDGPIO, OUTPUT_PIN);   // The LED is an output
    cout << "Setting the LED on" << endl;
    gpio_set_value(LEDGPIO, HIGH);
}

void MainWindow::on_ledOffButton_clicked()
{
    ui->testEdit->setText("Turning LED Off!");

    gpio_export(LEDGPIO);    // The LED
    gpio_set_dir(LEDGPIO, OUTPUT_PIN);   // The LED is an output
    cout << "Setting the LED off" << endl;
    gpio_set_value(LEDGPIO, LOW);

}


void MainWindow::on_actionOpenVideo_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open Video mp4 File",QDir::currentPath());
    if(!fileName.isEmpty())
    {
        player = new QMediaPlayer;



        playlist = new QMediaPlaylist(player);
        playlist->addMedia(fileName);
        playlist->addMedia(fileName);

        videoWidget = new QVideoWidget;
        player->setVideoOutput(videoWidget);

        videoWidget->show();
        playlist->setCurrentIndex(1);
        player->play();
    }
}
