// ===== LINE FOLLOWING ROBOT =====

// Motor pins (L298N)
const int IN1 = 6;
const int IN2 = 7;
const int IN3 = 10;
const int IN4 = 11;

// Enable pins (use ONLY if connected and jumpers removed)
const int ENA = 3;
const int ENB = 9;

const int LEFT_SENSOR_PIN  = 4;
const int RIGHT_SENSOR_PIN = 5;

const int SPEED = 150;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // More stable sensor readings
  pinMode(LEFT_SENSOR_PIN, INPUT_PULLUP);
  pinMode(RIGHT_SENSOR_PIN, INPUT_PULLUP);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);
}

void loop() {
  int leftSensor  = digitalRead(LEFT_SENSOR_PIN);
  int rightSensor = digitalRead(RIGHT_SENSOR_PIN);

  // NOTE:
  // With INPUT_PULLUP, sometimes the logic becomes inverted.
  // If it behaves wrong, swap HIGH/LOW in these conditions.

  if (leftSensor == LOW && rightSensor == LOW) {
    moveForward();
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    turnLeft();
  } else if (leftSensor == LOW && rightSensor == HIGH) {
    turnRight();
  } else {
    stopMotors();
  }

  delay(10);
}

void moveForward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}