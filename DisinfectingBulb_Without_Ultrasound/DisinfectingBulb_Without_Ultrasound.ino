// Pins
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

unsigned long startTimer;
long duration = 0;
float distance = 0;
bool onIdleState = true;  


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

  if (onIdleState) { //TODO: Need to set up timer
    if (!SwitchON) {
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
    if (SwitchON) {
      Serial.println("Transition to Idle State");
      Idle();
      onIdleState = true;
    }

  }
  delay(20);
}
