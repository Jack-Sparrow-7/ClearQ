#include "clearq_system.h"

void setupSystem()
{
    Serial.begin(9600);
    Serial.println("Serial Initialized");
    connectWifi(wifiName, wifiPassword);
    dataBaseSetup();
    setupPrinter();
}

void manageSystem()
{
    app.loop();
    if (app.ready())
    {
        String orderId;
        while (!Serial)
        {
        }
        Serial.println("Enter orderId:");
        while (orderId.isEmpty())
        {
            orderId = Serial.readStringUntil('\n');
            orderId.trim();
        }

        String data = getData(orderId);

        JsonDocument doc;
        deserializeJson(doc, data);

        String status = doc["status"];

        if (status == "pending")
        {
            updateStatus("printing", orderId);
            String date = doc["date"];
            int grandTotal = doc["grand-total"];
            String time = doc["time"];
            int itemCount = doc["item-count"];
            int quantityCount = doc["quantity-count"];
            JsonArray items = doc["items"];
            printHeader(date,time);
            for (JsonObject item : items)
            {
                String name = item["name"];
                name.toUpperCase();
                int price = item["price"];
                int quantity = item["quantity"];
                int total = item["total"];
                printItem(name,quantity,price,total);
            }
            printFooter(grandTotal,itemCount,quantityCount);
            updateStatus("completed",orderId);
        }
        else if (status == "completed")
        {
            Serial.println("Your bill is already generated!");
        }
        else if (status == "printing")
        {
            Serial.println("Your bill is printing!");
        }
    }
}
