#include "wifi_network.h"

void connectWifi(String wifiName, String wifiPassword)
{
    WiFi.begin(wifiName,wifiPassword);
    Serial.print("Connecting...");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println("\nWifi Connected!!!");
}