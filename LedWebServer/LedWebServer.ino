#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "html.h"

int pin = 13;

ESP8266WebServer server(80);

void root() {
        server.send(200, "text/html", html);
}
void on() {
        digitalWrite(pin, HIGH);
        server.send(200, "text/plain", "");
}
void off() {
        digitalWrite(pin, LOW);
        server.send(200, "text/plain", "");
}
void setup(void){
        pinMode(pin,  OUTPUT);
        Serial.begin(9600);
        WiFi.softAP("vb", "vbvbvbvb");
        server.on("/", root);
        server.on("/on", on);
        server.on("/off", off);
        server.begin();
}
void loop(void){
        server.handleClient();
}
