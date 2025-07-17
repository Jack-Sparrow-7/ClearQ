#ifndef Printer_Driver_H
#define Printer_Driver_H

#include<Arduino.h>
#include<Adafruit_Thermal.h>
#include<utils/constants.h>

extern void setupPrinter();

extern void printHeader(String date,String time);

extern void printItem(String name,int quantity,int price,int total);

extern void printFooter(int grandTotal,int itemCount,int quantityCount);

#endif