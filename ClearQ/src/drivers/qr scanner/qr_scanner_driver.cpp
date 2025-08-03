#include "qr_scanner_driver.h"

HardwareSerial scanner(1);

void setupQrScanner()
{
    scanner.begin(115200, SERIAL_8N1, camRxPin, camTxPin);
}

String scanOrderId()
{
    String orderId = scanner.readStringUntil('\n');
    return orderId;
}
