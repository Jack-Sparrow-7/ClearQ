#include <Arduino.h>
#include <ESP32QRCodeReader.h>

ESP32QRCodeReader reader(CAMERA_MODEL_AI_THINKER);

TaskHandle_t qrTaskHandle = NULL;

void setup()
{
  Serial.begin(115200);
  reader.setup();
  reader.beginOnCore(1);
}

void onQrCodeTask(void *pvParameters)
{
  struct QRCodeData qrCodeData;
  String lastCode = "";
  unsigned long lastScanTime = 0;
  const unsigned long debounceTime = 5000;

  while (true)
  {
    if (reader.receiveQrCode(&qrCodeData, 100))
    {
      if (qrCodeData.valid)
      {
        String codeMessage = (char *)qrCodeData.payload;
        if (codeMessage != lastCode || millis() - lastScanTime > debounceTime)
        {
          lastCode = codeMessage;
          lastScanTime = millis();
          Serial.println(codeMessage);
        }
      }
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }

  qrTaskHandle = NULL;

  vTaskDelete(NULL);
}

void loop()
{
  if (qrTaskHandle == NULL)
  {
    xTaskCreate(onQrCodeTask, "onQrCode", 4 * 1024, NULL, 4, &qrTaskHandle);
  }

  delay(100);
}
