//CONFIGURE THIS:
const int ULTRA_SOUND_TRIGGER = 10;

// Pins
const int trigPin = 9;
const int echoPin = 10;
const byte UV_Left_pin = 3;
const byte UV_Right_pin = 4;
const byte power_LED = 5;
const byte indicator_LED = 6;
const byte switch_pin_left = 7;
const byte switch_pin_right = 8;
//Variables
float ultrasound_measurement = 0.0;
bool SwitchON = false;
bool Switch_left_ON = LOW;
bool Switch_right_ON = LOW;
float ultrasound_average;

unsigned long startTimer;
long duration = 0;
float distance = 0;
bool onIdleState = true;  


float GetDistance () {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  //Serial.print("Distance: ");
  ////Serial.println(distance);
  return distance;
}

float Get_ultrasound_distance() {
  float average = 0;
  float total = 0;
  float sum = 0;

  for (int i = 0; i < 10; i++) {
    ultrasound_measurement = GetDistance();
    delay(10);
    if (ultrasound_measurement != 0) {
      sum += ultrasound_measurement;
      total ++;
    }
  }
  if (total == 0) {
    sum = 0;
    total = 0;
    return 0;
  }
  average = sum / total;
  sum = 0;
  total = 0;
  return average;
}


void Light_ON() {
  digitalWrite(UV_Left_pin, HIGH);
  digitalWrite(UV_Right_pin, HIGH);
  digitalWrite(indicator_LED, HIGH);
}

void Idle() {
  digitalWrite(UV_Left_pin, LOW);
  digitalWrite(UV_Right_pin, LOW);
  digitalWrite(indicator_LED, LOW);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(power_LED, OUTPUT);
  pinMode(indicator_LED, OUTPUT);
  pinMode(UV_Left_pin, OUTPUT);
  pinMode(UV_Right_pin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(switch_pin_left, INPUT);
  pinMode(switch_pin_right, INPUT);
  delay(10);
  Serial.println("Setup");
  digitalWrite(power_LED, HIGH);
}

void loop() {
  Switch_left_ON = digitalRead(switch_pin_left);
  Switch_right_ON = digitalRead(switch_pin_right);

  if (Switch_left_ON == true && Switch_right_ON == true) {
    SwitchON = true;
  }
  else {
    SwitchON = false;
  }
  Serial.print("Switch State: ");
  Serial.println(SwitchON);
  ultrasound_average = Get_ultrasound_distance();
  Serial.print("Ultrasound Measurement");
  Serial.println(ultrasound_average);

  if (onIdleState) { //TODO: Need to set up timer
    if (!SwitchON && ultrasound_average < ULTRA_SOUND_TRIGGER) {
      startTimer = millis();
      Serial.print("Timer started at: ");
      Serial.println(startTimer);

      digitalWrite(indicator_LED, HIGH);
      Serial.println("Transition to LIGHT ON STATE");
      delay(5000);
      onIdleState = false;
      Light_ON();
    }
    else {
      return;
    }
  }
  else { //on light on state
    unsigned long currentmillis = millis();
    unsigned long duration_ = abs(currentmillis - startTimer);
    if (duration_ > 25000) {
      digitalWrite(UV_Left_pin, LOW);
      digitalWrite(UV_Right_pin, LOW);
      digitalWrite(indicator_LED, LOW);
    }
    if (SwitchON || ultrasound_average > ULTRA_SOUND_TRIGGER) {
      Serial.println("Transition to Idle State");
      Idle();
      onIdleState = true;
    }

  }
  delay(20);
}
