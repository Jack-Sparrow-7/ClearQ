#include "database.h"

FirebaseApp app;

SSL_CLIENT sslClient;
using AsyncClient = AsyncClientClass;
AsyncClient aClient(sslClient);

UserAuth userAuth(apiKey, userEmail, userPassword);
RealtimeDatabase database;

void dataBaseSetup()
{
    Serial.println("Initializing database...");
    set_ssl_client_insecure_and_buffer(sslClient);
    initializeApp(aClient, app, getAuth(userAuth));
    app.getApp<RealtimeDatabase>(database);
    database.url(dataBaseUrl);
    Serial.println("Initialized Database!");
}

void updateStatus(String status,String orderId)
{
    String path = "/orders/"+orderId+"/status";
    database.set<String>(aClient,path,status);
}

String getData(String orderId)
{
    Serial.println("Getting Data");
    String path = "/orders/" + orderId;
    String data = database.get<String>(aClient, path);
    return data;
}


