#ifndef DataBase_H
#define DataBase_H

#define ENABLE_USER_AUTH
#define ENABLE_DATABASE

#include <FirebaseClient.h>
#include "ExampleFunctions.h"
#include <utils/constants.h>
#include <Arduino.h>

extern FirebaseApp app;

void dataBaseSetup();
void updateStatus(String status,String orderId);

String getData(String orderId);

#endif