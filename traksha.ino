#include <BluetoothSerial.h>
BluetoothSerial SerialBT;
// Ultrasonic Sensor Pins
#define TRIG_PIN 33
#define ECHO_PIN 25
// PIR Sensor Pin
#define PIR_SENSOR_PIN 32
// LED and Buzzer Pins
#define LED_PIN 23
#define BUZZER_PIN 27
// Function prototypes
long measureDistance();
void alertSequence();
void setup() {
// Initialize Serial and Bluetooth
Serial.begin(115200);
SerialBT.begin("ESP32_Train"); // Bluetooth name
Serial.println("Bluetooth started, waiting for connection...");
// Initialize sensor pins
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
pinMode(PIR_SENSOR_PIN, INPUT);
// Initialize LED and Buzzer pins
pinMode(LED_PIN, OUTPUT);
pinMode(BUZZER_PIN, OUTPUT);
// Initial states
digitalWrite(LED_PIN, LOW);
digitalWrite(BUZZER_PIN, LOW);
}
void loop() {
// Measure distance
long distance = measureDistance();
bool motionDetected = digitalRead(PIR_SENSOR_PIN);
// Print and send status via Bluetooth
if (distance < 10 && motionDetected) {
Serial.println("Criteria met: Living being detected");
SerialBT.println("Distance: " + String(distance) + " cm Motion: Detected");
SerialBT.println("Criteria met: Living being detected");
// Trigger alert sequence
alertSequence();
} else {
String motionStatus = motionDetected ? "Detected" : "Not Detected";
Serial.println("Distance: " + String(distance) + " cm Motion: " + motionStatus);
SerialBT.println("Distance: " + String(distance) + " cm Motion: " + motionStatus);
}
// Small delay for stable readings
delay(500);
}
// Function to measure distance using ultrasonic sensor
long measureDistance() {
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);
