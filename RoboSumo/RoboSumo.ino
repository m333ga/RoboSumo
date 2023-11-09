// robot 1 pins
int motor_left_pwm = 10,
    motor_left_dir = 12,
    motor_right_pwm = 11,
    motor_right_dir = 13;

int ultrasonic_trig_pin = 2,
    ultrasonic_echo_pin = 3;

float distance;
int trigger_distance = 40;

void setup() {
 Serial.begin(9600);

 // ultrasonic pin modes
 pinMode(ultrasonic_trig_pin, OUTPUT);
 pinMode(ultrasonic_echo_pin, INPUT);

 // motors pin modes
 for(int pin = motor_left_pwm; pin <= motor_right_dir; pin++) {
  pinMode(pin, OUTPUT);
  }
}

void loop() {
  ReadUltrasonicSensor();

  if(distance <= trigger_distance) {
    TurnMotor(motor_left_pwm, 255);
    TurnMotor(motor_right_pwm, 255);
  } else {
    TurnMotor(motor_right_pwm, 125);
    TurnMotor(motor_left_pwm, 0);
  }
}

void ReadUltrasonicSensor() {
  digitalWrite(ultrasonic_trig_pin, 0);
  delayMicroseconds(2);
  digitalWrite(ultrasonic_trig_pin, 1);
  delayMicroseconds(10);
  digitalWrite(ultrasonic_trig_pin, 0);

  long ultrasonic_duration = pulseIn(ultrasonic_echo_pin, 1);
  distance = ultrasonic_duration * 0.034 / 2;

  Serial.println(distance);
  delay(100);
}

void TurnMotor(int(motor), int(status)) {
  analogWrite(motor, status);
}