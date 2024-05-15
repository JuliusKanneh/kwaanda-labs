#define FLOOR_1_BUTTON_PIN D0
#define FLOOR_2_BUTTON_PIN D1
#define FLOOR_3_BUTTON_PIN D2
#define FLOOR_4_BUTTON_PIN D3
#define FLOOR_5_BUTTON_PIN D4

int motor1Pin1 = 12; 
int motor1Pin2 = 14; 
int enable1Pin = 13; 

// Setting minimum duty cycle
int dutyCycle = 60; //60

// int prev_button_state = LOW;  // The previous state from the input pin
// int button_state;     // The current reading from the input pin
// int prev_down_button_state = LOW;  // The previous state from the input pin
// int down_button_state;     // The current reading from the input pin

int prev_floor_1_button_state = LOW;
int floor_1_button_state;
int prev_floor_2_button_state = LOW;
int floor_2_button_state;
int prev_floor_3_button_state = LOW;
int floor_3_button_state;
int prev_floor_4_button_state = LOW;
int floor_4_button_state;
int prev_floor_5_button_state = LOW;
int floor_5_button_state;

int current_floor = 0;

void setup() {
  // Initialize the Serial to communicate with the Serial Monitor.
  // Serial.begin(9600);
  // Configure the ESP8266 pin as a pull-up input: HIGH when the button is open, LOW when pressed.
  // pinMode(UP_BUTTON_PIN, INPUT_PULLUP);
  // pinMode(DOWN_BUTTON_PIN, INPUT_PULLUP);

  pinMode(FLOOR_1_BUTTON_PIN, INPUT_PULLUP);
  pinMode(FLOOR_2_BUTTON_PIN, INPUT_PULLUP);
  pinMode(FLOOR_3_BUTTON_PIN, INPUT_PULLUP);
  pinMode(FLOOR_4_BUTTON_PIN, INPUT_PULLUP);
  pinMode(FLOOR_5_BUTTON_PIN, INPUT_PULLUP);


  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // read the state of the switch/button:
  // button_state = digitalRead(UP_BUTTON_PIN);
  // down_button_state = digitalRead(DOWN_BUTTON_PIN);
  floor_1_button_state = digitalRead(FLOOR_1_BUTTON_PIN);
  floor_2_button_state = digitalRead(FLOOR_2_BUTTON_PIN);
  floor_3_button_state = digitalRead(FLOOR_3_BUTTON_PIN);
  floor_4_button_state = digitalRead(FLOOR_4_BUTTON_PIN);
  floor_5_button_state = digitalRead(FLOOR_5_BUTTON_PIN);

  //Apply power to spin at maximum speed
  digitalWrite(enable1Pin, HIGH);

  // if (prev_button_state == HIGH && button_state == LOW){
  //   moveUpward();
  // } else if (prev_down_button_state == HIGH && down_button_state == LOW){
  //    moveDownward();
  // }else if (prev_button_state == LOW && button_state == HIGH)
  //   Serial.println("The button is released");
  if (prev_floor_1_button_state == HIGH && floor_1_button_state == LOW) {
    moveToFloor(1);
  } else if (prev_floor_2_button_state == HIGH && floor_2_button_state == LOW) {
    moveToFloor(2);
  } else if (prev_floor_3_button_state == HIGH && floor_3_button_state == LOW) {
    moveToFloor(3);
  } else if (prev_floor_4_button_state == HIGH && floor_4_button_state == LOW) {
    moveToFloor(4);
  } else if (prev_floor_5_button_state == HIGH && floor_5_button_state == LOW) {
    moveToFloor(5);
  }

  // save the the last state
  // prev_button_state = button_state;
  // prev_down_button_state = down_button_state;

  prev_floor_1_button_state = floor_1_button_state;
  prev_floor_2_button_state = floor_2_button_state;
  prev_floor_3_button_state = floor_3_button_state;
  prev_floor_4_button_state = floor_4_button_state;
  prev_floor_5_button_state = floor_5_button_state;
}

void moveToFloor(int floor) {
  // int current_floor = 0;
  Serial.print("Moving to Floor ");
  Serial.println(floor);

  // Move the elevator to the desired floor based on the logic you implement here
  if(floor > current_floor){
      //moving up
      moveUpward(floor - current_floor);
      current_floor = floor;
    }else if(floor < current_floor){
      //moving down
      moveDownward(current_floor - floor);
      current_floor = floor;
    }else{
      //do nothing
      Serial.println("The elevator is already at the desired floor.");
      current_floor = floor;
    }

  // For example:
  // switch (floor) {
    
    // case 1:
    //   // Move elevator to floor 1
      
    //   break;
    // case 2:
    //   // Move elevator to floor 2
    //   break;
    // case 3:
    //   // Move elevator to floor 3
    //   break;
    // case 4:
    //   // Move elevator to floor 4
    //   break;
    // case 5:
    //   // Move elevator to floor 5
    //   break;
    // default:
    //   // Invalid floor
    //   break;
  // }

  // You can implement the logic to move the elevator to the desired floor here
}

// void moveToFloor(int floor) {
//   Serial.print("Moving to Floor ");
//   Serial.println(floor);

//   // Assume current_floor represents the current floor of the elevator
//   int current_floor = 0; // Initialize with the ground floor

//   // Determine direction of movement
//   if (floor > current_floor) {
//     // Move the elevator up
//     for (int i = current_floor + 1; i <= floor; i++) {
//       moveUpward(); // Implement your moveUpward function here
//       delay(1000); // Adjust delay as needed, this is just an example
//       current_floor = i;
//       Serial.print("Current Floor: ");
//       Serial.println(current_floor);
//     }
//   } else if (floor < current_floor) {
//     // Move the elevator down
//     for (int i = current_floor - 1; i >= floor; i--) {
//       moveDownward(); // Implement your moveDownward function here
//       delay(1000); // Adjust delay as needed, this is just an example
//       current_floor = i;
//       Serial.print("Current Floor: ");
//       Serial.println(current_floor);
//     }
//   }

//   // Stop the elevator at the desired floor
//   stopAtFloor(floor);
// }

// void stopAtFloor(int floor) {
//   // Implement the logic to stop the elevator at the desired floor
//   // You can stop the motor and hold the elevator doors open for some time

//   Serial.println("Elevator reached the desired floor.");
//   // Stop the motor
//   digitalWrite(enable1Pin, LOW);

//   // Open the elevator doors (if applicable)
//   // Implement code to open the elevator doors

//   // Delay for some time to keep the doors open
//   delay(3000); // Adjust the delay as needed

//   // Close the elevator doors (if applicable)
//   // Implement code to close the elevator doors

//   // Resume normal operation or standby mode
// }

void moveUpward(int steps){
  Serial.println("The button is pressed");
    // Move the DC motor forward at maximum speed
    Serial.println("Moving Forward");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    delay(170 * steps);

    // Stop the DC motor
    Serial.println("Motor stopped");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    delay(1000);
}

void moveDownward(int steps){
  // Move DC motor backwards at maximum speed
    Serial.println("Moving Backwards");
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW); 
    delay(170 * steps);

    // Stop the DC motor
    Serial.println("Motor stopped");
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor1Pin1, LOW);
    delay(1000);
}