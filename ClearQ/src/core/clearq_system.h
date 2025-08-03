#ifndef ClearQ_System_H
#define ClearQ_System_H

#include <Arduino.h>
#include <network/internet/wifi_network.h>
#include <network/database/database.h>
#include <ArduinoJson.h>
#include <drivers/printers/printer_driver.h>
#include <drivers/qr scanner/qr_scanner_driver.h>
#include <utils/constants.h>

void setupSystem();

void manageSystem();

#endif