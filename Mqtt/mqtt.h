#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>


WiFiClient espClient;
PubSubClient client(espClient);

char channels[10][10];
char values[10][10];
void (*funtions[10][10])();

int channel_counter = 0;
int values_counter = 0;

void ConnectWifi(char name[], char password[]){
        WiFi.begin(name, password);
        Serial.print("Connecting to ");
        Serial.print(name);
        while (WiFi.status() != WL_CONNECTED) {
                delay(500);
                Serial.print(".");
        }
        Serial.println("");
        Serial.print("Connected to the ");
        Serial.println(name);
}

void callback(char* topic, byte* payload, unsigned int length) {
        for (int i=0; i<=channel_counter; i++) {
                if (!strcmp(channels[i], topic)) {
                        char string[10];
                        strncpy(string, (char*)payload, length);
                        for (int j=0; j<=values_counter; j++) {
                                if (!strcmp(values[j], string)) {
                                        (funtions[i][j])();
                                        return;
                                }
                        }
                }
        }
}

void ConnectMqtt(char SeverName[],char DeviceName[]){
        client.setServer(SeverName, 1883);
        while (!client.connected()) {
                Serial.println("Connecting to MQTT...");
                if (client.connect(DeviceName, "", "" )) {
                        Serial.println("connected");
                } else {
                        Serial.print("failed with state ");
                        Serial.print(client.state());
                        delay(2000);
                }
        }
        client.setCallback(callback);
}


void SetFunction(char channel[],char value[],void (*func)()){
        // char string[10];
        // strcpy(string,channel);
        for(int i=0; i<=channel_counter; i++) {
                if (!strcmp(channels[i], channel)) {
                        goto VALUE;
                }
        }
        client.subscribe(channel);
        strcpy(channels[channel_counter],channel);
        channel_counter++;
VALUE:
        for(int i=0; i<=values_counter; i++) {
                if (!strcmp(values[i], value)) {
                        goto FUNCTION;
                }
        }
        strcpy(values[values_counter],value);
        values_counter++;
FUNCTION:
        for(int i=0; i<=channel_counter; i++) {
                if (!strcmp(channels[i], channel)) {
                        for(int j=0; j<=values_counter; j++) {
                                if (!strcmp(values[j], value)) {
                                        funtions[i][j] = func;
                                }
                        }

                }
        }

}
