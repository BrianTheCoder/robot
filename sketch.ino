const int irLongRange = 4;
const int irShortRangeLeft = 5;
const int irShortRangeRight = 2;
const int FORWARD = 1;
const int BACKWARD = 0;

void setup() {
  Serial.begin(9600);
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  
  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
}


void loop(){                       // run over and over again
  leftMotor(true);
  rightMotor(true);
  delay(1000);
  leftMotor(false, 255);
  rightMotor(false, 255);
  delay(1000);
  leftMotor(false, 255, BACKWARD);
  rightMotor(false, 255, BACKWARD);
  delay(1000);
}

void leftMotor(int brake){
  digitalWrite(9, brake);
}

void rightMotor(int brake){
  digitalWrite(8, brake);
}

void leftMotor(int brake, int speed){
  digitalWrite(9, brake);
  digitalWrite(12, HIGH);
  analogWrite(3, speed);
}

void rightMotor(int brake, int speed){
  digitalWrite(8, brake);
  digitalWrite(13, HIGH);
  analogWrite(11, speed);
}

void leftMotor(int brake, int speed, int direction){
  digitalWrite(9, brake);
  digitalWrite(12, direction);
  analogWrite(3, speed);
}

void rightMotor(int brake, int speed, int direction){
  digitalWrite(8, brake);
  digitalWrite(13, direction);
  analogWrite(11, speed);
}
