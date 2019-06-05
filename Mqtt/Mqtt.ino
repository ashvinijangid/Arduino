//GO TO LIBRARY MANAGER and INSTALL PubSubClient lib
#include "mqtt.h"

void FUNCTION_TO_BE_CALLED_ON_DATA_REC(){
  Serial.println("Hey! its Function");
}

void setup() {
        Serial.begin(9600);
        ConnectWifi("WIFI NAME","WIFI PASSWORD");
        ConnectMqtt("SERVER ADDRESS", "YOUR DEVICE NAME");
        SetFunction("CHANNEL NAME", "DATA" ,FUNCTION_TO_BE_CALLED_ON_DATA_REC);
}
void loop() {
        client.loop();
}
