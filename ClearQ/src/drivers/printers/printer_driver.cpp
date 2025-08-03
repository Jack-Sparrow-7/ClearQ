#include "printer_driver.h"

HardwareSerial printer(2);
uint8_t bold_on_command[] = {0x1B, 0x45, 0x01};
uint8_t bold_off_command[] = {0x1B, 0x45, 0x00};
uint8_t feed_one_command[] = {0x1B, 0x64, 1};
uint8_t feed_four_command[] = {0x1B, 0x64, 4};
uint8_t font_medium_command[] = {0x1D, 0x21, 1};
uint8_t fontsize_default_command[] = {0x1D, 0x21, 0};
uint8_t jusify_center_command[] = {0x1B, 0x61, 1};
uint8_t justify_left_command[] = {0x1B, 0x61, 0};
uint8_t justify_right_command[] = {0x1B, 0x61, 2};

void setupPrinter()
{
    printer.begin(9600);
}

void printHeader(String date, String time)
{
    printer.write(jusify_center_command,sizeof(jusify_center_command));
    printer.write(bold_on_command,sizeof(bold_on_command));
    printer.write(font_medium_command,sizeof(font_medium_command));
    printer.println(F("RIT SALES CANTEEN"));
    printer.write(fontsize_default_command,sizeof(fontsize_default_command));
    printer.printf("%s %s\n", date, time);
    printer.println(F("- - - - - - - - - - - - - - - -\nITEM    QTY    PRICE   AMOUNT\n- - - - - - - - - - - - - - - -"));
}

void printItem(String name, int quantity, int price, int total)
{
    printer.write(justify_left_command,sizeof(justify_left_command));
    printer.println(name);
    printer.write(jusify_center_command,sizeof(jusify_center_command));
    printer.printf("       %dNO    %d.00    %d.00\n", quantity, price, total);
}

void printFooter(int grandTotal, int itemCount, int quantityCount)
{
    printer.write(justify_left_command,sizeof(justify_left_command));
    printer.printf("- - - - - - - - - - - - - - - -\nITEM: %d  QTY: %d\n- - - - - - - - - - - - - - - -\nGRAND TOTAL: %d.00\n",
                   itemCount, quantityCount, grandTotal);
    printer.write(bold_off_command,sizeof(bold_off_command));
    printer.write(feed_four_command,sizeof(feed_four_command));
}
