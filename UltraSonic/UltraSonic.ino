// GPIO PIN
int TRIG_PIN=13;
int ECHO_PIN=12;

void setup() {
        pinMode(TRIG_PIN, OUTPUT);
        pinMode(ECHO_PIN, INPUT);
        Serial.begin(9600);
}

int distance(){
        digitalWrite(TRIG_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIG_PIN, LOW);
        int duration =  pulseIn(ECHO_PIN, HIGH);
        int distance = duration/29/2;
        return distance;
}
void loop() {
        Serial.print("Distance >");
        Serial.print(distance());
        Serial.println(" cm");
        delay(100);
}
