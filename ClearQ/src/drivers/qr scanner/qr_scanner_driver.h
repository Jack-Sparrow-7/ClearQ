#ifndef Qr_Scanner_H
#define Qr_Scanner_H

#include <ESP32QRCodeReader.h>
#include <Arduino.h>
#include <utils/constants.h>
#include <HardwareSerial.h>

extern void setupQrScanner();
extern String scanOrderId();

#endif