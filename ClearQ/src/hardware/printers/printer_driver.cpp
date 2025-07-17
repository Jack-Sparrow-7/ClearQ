#include "printer_driver.h"

HardwareSerial mySerial(2);
Adafruit_Thermal printer(&mySerial);

void setupPrinter()
{
    mySerial.begin(9600, SERIAL_8N1, rxPin, txPin);
    printer.begin();
    printer.setDefault();
}

void printHeader(String date, String time)
{
    printer.justify('C');
    printer.boldOn();
    printer.setSize('M');
    printer.println(F("RIT SALES CANTEEN"));
    printer.feed(1);
    printer.setSize('S');
    printer.println(F("13/06/25 13:15"));
    printer.println(F("- - - - - - - - - - - - - - - -"));
    printer.justify('C');
    printer.println(F("ITEM    QTY    PRICE   AMOUNT"));
    printer.println(F("- - - - - - - - - - - - - - - -"));
}

void printItem(String name, int quantity, int price, int total)
{
    printer.justify('L');
    printer.println(name);
    printer.justify('C');
    printer.printf("       %dNO    %d.00    %d.00\n", quantity, price, total);
}

void printFooter(int grandTotal,int itemCount,int quantityCount)
{
    printer.println(F("- - - - - - - - - - - - - - - -"));
    printer.justify('L');
    printer.printf("ITEM: %d  QTY: %d\n",itemCount,quantityCount);
    printer.justify('C');
    printer.println(F("- - - - - - - - - - - - - - - -"));
    printer.justify('L');
    printer.print(F("GRAND TOTAL: "));
    printer.println(grandTotal);
    printer.boldOff();
    printer.feed(4);
    printer.setDefault();
}
