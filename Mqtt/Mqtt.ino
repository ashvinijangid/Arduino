//GO TO LIBRARY MANAGER and INSTALL PubSubClient lib
#include "mqtt.h"

void setup() {
        Serial.begin(9600);
        ConnectWifi("WIFI NAME","WIFI PASSWORD");
        ConnectMqtt("SERVER ADDRESS", "YOUR DEVICE NAME");
}
void loop() {
        client.loop();
        Publish("TOPIC_NAME", "DATA");
        
}
