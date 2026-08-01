#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

Servo servo;
WebServer server(80);

const int servoPin = 13;
const int greenLED = 26;
const int redLED = 27;

void handleRoot() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>Servo Control</title>
<style>
body{
  font-family:Arial;
  text-align:center;
  margin-top:60px;
}
button{
  width:140px;
  height:55px;
  font-size:22px;
  margin:15px;
}
</style>
</head>
<body>
<h2>ESP32 Servo Control</h2>

<a href="/open"><button>Open</button></a>
<a href="/close"><button>Close</button></a>

</body>
</html>
)rawliteral";

  server.send(200, "text/html", page);
}

void openServo() {
  servo.write(90);
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);

  server.sendHeader("Location","/");
  server.send(303);
}

void closeServo() {
  servo.write(0);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);

  server.sendHeader("Location","/");
  server.send(303);
}

void setup() {

  Serial.begin(115200);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  servo.attach(servoPin);
  servo.write(0);

  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);

  WiFi.softAP("ESP32-Servo","12345678");

  Serial.println("WiFi Started");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/open", openServo);
  server.on("/close", closeServo);

  server.begin();
}

void loop() {
  server.handleClient();
}