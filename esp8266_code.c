#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Servo.h>


const char* ssid = "ESP8266_Car";
const char* password = "12345678";


#define ENA 5    
#define IN1 4    
#define IN2 0    
#define IN3 14   
#define IN4 12   
#define ENB 13   


#define SERVO_PIN 2   
Servo servo;

int speedVal = 200; 

AsyncWebServer server(80);

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);
  Serial.println("Moving Forward");
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);
  Serial.println("Moving Backward");
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);
  Serial.println("Turning Left");
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);
  Serial.println("Turning Right");
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Stopped");
}

void setup() {
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  servo.attach(SERVO_PIN);
  servo.write(90);

  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Access Point IP: ");
  Serial.println(IP); 

  

  server.on("/forward", HTTP_GET, [](AsyncWebServerRequest *request){
    moveForward();
    request->send(200, "text/plain", "Forward");
  });

  server.on("/backward", HTTP_GET, [](AsyncWebServerRequest *request){
    moveBackward();
    request->send(200, "text/plain", "Backward");
  });

  server.on("/left", HTTP_GET, [](AsyncWebServerRequest *request){
    turnLeft();
    request->send(200, "text/plain", "Left");
  });

  server.on("/right", HTTP_GET, [](AsyncWebServerRequest *request){
    turnRight();
    request->send(200, "text/plain", "Right");
  });

  server.on("/stop", HTTP_GET, [](AsyncWebServerRequest *request){
    stopCar();
    request->send(200, "text/plain", "Stop");
  });

  server.on("/servo", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("angle")) {
      int angle = request->getParam("angle")->value().toInt();
      angle = constrain(angle, 0, 180);
      servo.write(angle);
      request->send(200, "text/plain", "Servo Angle Set to " + String(angle));
      Serial.printf("Servo set to %d°\n", angle);
    } else {
      request->send(400, "text/plain", "Missing angle");
    }
  });

  server.on("/speed", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("value")) {
      speedVal = request->getParam("value")->value().toInt();
      speedVal = constrain(speedVal, 0, 255);
      request->send(200, "text/plain", "Speed Set to " + String(speedVal));
      Serial.printf("Speed updated to %d\n", speedVal);
    } else {
      request->send(400, "text/plain", "Missing value");
    }
  });

  server.begin();
  Serial.println("Web server started");
}

void loop() {
}
