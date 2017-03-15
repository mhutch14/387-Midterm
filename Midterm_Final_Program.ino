int LED_Bluetooth = 7; // led pin
int info = 0;  // variable for the information comming from the bluetooth module

int LED_Motion = 13;                // choose the pin for the LED
int Motion_Sensor = A0;               // choose the input pin (for PIR sensor)

void setup() {
  Serial.begin(9600); // making serial connection
  pinMode(LED_Bluetooth, OUTPUT);    // defining LED pin
  digitalWrite(LED_Bluetooth, LOW);  // once the programm starts, it's going to turn of the led, as it can be missleading.

  pinMode(LED_Motion, OUTPUT);      // declare LED as output
  pinMode(Motion_Sensor, INPUT);     // declare sensor as input
}

void loop() {
  if(Serial.available() > 0){  // if there is any information comming from the serial lines...
    info = Serial.read();  // ...than store it into the "info" variable   
  }
  if(info == '1'){                // if it gets the number 1(stored in the info variable...
    digitalWrite(LED_Bluetooth, HIGH);    // it's gonna turn the blutooth led on

    if(digitalRead(Motion_Sensor) == HIGH) {    // read input value
      digitalWrite(LED_Motion, HIGH); // turn LED ON
      Serial.println("Motion Detected");
      delay(500);
    } else {
      digitalWrite(LED_Motion, LOW);
      Serial.println("No Motion Detected");
      delay(500);
  }   
 }
  else if(info == '0'){
    digitalWrite(LED_Bluetooth, LOW);      //else, it's going to turn it off
  }
}

