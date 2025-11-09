// Brushed Motor Test - Single MOSFET Driver
// Arduino UNO

#define MOTOR_PIN 9  // PWM pin connected to MOSFET gate

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_PIN, OUTPUT);
  Serial.println("MOSFET Motor Test Started");
}

void loop() {
  // Gradually increase speed
  for (int speed = 0; speed <= 255; speed += 5) {
    analogWrite(MOTOR_PIN, speed);
    Serial.print("Speed: ");
    Serial.println(speed);
    delay(100);
  }

  // Hold full speed for 2 seconds
  Serial.println("Full Speed");
  analogWrite(MOTOR_PIN, 255);
  delay(2000);

  // Gradually slow down
  for (int speed = 255; speed >= 0; speed -= 5) {
    analogWrite(MOTOR_PIN, speed);
    Serial.print("Speed: ");
    Serial.println(speed);
    delay(100);
  }

  // Stop for 2 seconds
  analogWrite(MOTOR_PIN, 0);
  Serial.println("Motor Stopped");
  delay(2000);
}
