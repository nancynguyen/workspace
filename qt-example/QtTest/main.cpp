#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "gpio.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    unsigned int LEDGPIO = 60;   // GPIO1_28 = (1x32) + 28 = 60
//    unsigned int ButtonGPIO = 15;   // GPIO0_15 = (0x32) + 15 = 15

//    cout << "Testing the GPIO Pins" << endl;

//    gpio_export(LEDGPIO);    // The LED
//    gpio_export(ButtonGPIO);   // The push button switch
//    gpio_set_dir(LEDGPIO, OUTPUT_PIN);   // The LED is an output
//    gpio_set_dir(ButtonGPIO, INPUT_PIN);   // The push button input

//    // Flash the LED 5 times
//    for(int i=0; i<5; i++){
//        cout << "Setting the LED on" << endl;
//                gpio_set_value(LEDGPIO, HIGH);
//        usleep(1000000);         // on for 200ms
//        cout << "Setting the LED off" << endl;
//                gpio_set_value(LEDGPIO, LOW);
//        usleep(1000000);         // off for 200ms
//    }


    w.showMaximized();
    return a.exec();
}
