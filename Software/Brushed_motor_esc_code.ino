#include <WiFi.h>
#include <WebServer.h>

// ---------- Wi-Fi Setup ----------
const char* ssid = "ESP32_Motor_AP";
const char* password = "12345678";

// ---------- Motor Setup ----------
#define MOTOR_PIN 25   // ESP32 DAC pin (25 or 26)
int motorSpeed = 0;    // 0-255

// ---------- Web Server ----------
WebServer server(80);

// ---------- HTML Page ----------
const char htmlPage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>ESP32 Motor Speed Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    body { text-align:center; font-family:Arial; background:#f0f0f0; color:#333; }
    h1 { color:#2b2b2b; }
    input[type=range] { width:80%; height:25px; margin:20px; }
    p { font-size:20px; }
  </style>
</head>
<body>
  <h1>ESP32 Motor Speed Control</h1>
  <p>Speed: <span id="speedValue">0</span></p>
  <input type="range" min="0" max="255" value="0" id="speedSlider" oninput="updateSpeed(this.value)">
  <script>
    function updateSpeed(val) {
      document.getElementById('speedValue').innerText = val;
      fetch('/speed?value=' + val);
    }
  </script>
</body>
</html>
)rawliteral";

// ---------- Web Handlers ----------
void handleRoot() {
  server.send_P(200, "text/html", htmlPage);
}

void handleSpeed() {
  if (server.hasArg("value")) {
    motorSpeed = server.arg("value").toInt();
    dacWrite(MOTOR_PIN, motorSpeed);  // DAC PWM alternative
    Serial.print("Motor Speed set to: ");
    Serial.println(motorSpeed);
    server.send(200, "text/plain", "Speed set to " + String(motorSpeed));
  } else {
    server.send(400, "text/plain", "Missing value parameter");
  }
}

// ---------- Setup ----------
void setup() {
  Serial.begin(115200);

  // Start DAC at 0
  dacWrite(MOTOR_PIN, 0);

  // Start Wi-Fi AP
  WiFi.softAP(ssid, password);
  Serial.print("Wi-Fi AP started: ");
  Serial.println(ssid);
  Serial.print("Connect at: ");
  Serial.println(WiFi.softAPIP());

  // Web server
  server.on("/", handleRoot);
  server.on("/speed", handleSpeed);
  server.begin();
}

// ---------- Loop ----------
void loop() {
  server.handleClient();
}