#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "html.h"

ESP8266WebServer server(80);

void root() {
        server.send(200, "text/html", html);
}

void one(){
        Serial.print("called");
        server.send(200, "text/html", "");
}

void setup(void){
        Serial.begin(9600);
        WiFi.softAP("ash", "ashvinijangid");
        server.on("/", root);
        server.on("/1", one);
        server.begin();
}

void loop(void){
        server.handleClient();
}
