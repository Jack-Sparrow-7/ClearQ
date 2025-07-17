#ifndef ClearQ_System_H
#define ClearQ_System_H

#include <Arduino.h>
#include <network/internet/wifi_network.h>
#include <network/database/database.h>
#include <ArduinoJson.h>
#include <hardware/printers/printer_driver.h>

void setupSystem();

void manageSystem();

#endif