#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "html.h"

ESP8266WebServer server(80);

void root() {
        server.send(200, "text/html", html);
}
void ajax(){
        if (data.length()>0) {
                server.send(200, "text/plain", data);
        }

}

void setup(void){
        Serial.begin(9600);
        WiFi.softAP("ash", "ashvinijangid");
        server.on("/", root);
        server.on("/data", ajax);
        server.begin();
}
void loop(void){
        server.handleClient();
        if (Serial.available()>0) {
                data = Serial.readString();
        }
}
