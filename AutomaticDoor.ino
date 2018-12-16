/By Sieuwe Elferink

//config
////////////////
const int MotorDelay = 3100; //change this value to make the door open more or less
const int TimeDelay = 4000; // change this value to change the time between the door opening and closing
const int ActivationDistance = 50; //change this value to change the distance from your hand to the sensor to activate the door.
///////////////

const int trigPin = 4;
const int echoPin = 3;

const int trigPin2 = 10;
const int echoPin2 = 11;

const int ComPin = 5; //Pin for communicating with the CortanaRoom application. Check the CortanaRoom reposetory for more info!

long duration, duration2;
int distanceCm, distanceCm2;


void setup() {

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(ComPin, OUTPUT);

  Serial.begin(9600);

}



void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distanceCm2 = duration2 * 0.034 / 2;

  Serial.print(distanceCm);
  Serial.print("    ");
  Serial.println(distanceCm2);

  if (distanceCm <= ActivationDistance) {
    digitalWrite(ComPin, HIGH);
    digitalWrite(8, HIGH);
    delay(MotorDelay);
    digitalWrite(8, LOW);
    delay(TimeDelay);
    digitalWrite(9, HIGH);
    delay(MotorDelay);
    digitalWrite(9, LOW);
    delay(2000);
    digitalWrite(ComPin, LOW);
  }

  if (distanceCm2 <= ActivationDistance) {
    digitalWrite(ComPin, HIGH);
    digitalWrite(8, HIGH);
    delay(MotorDelay);
    digitalWrite(8, LOW);
    delay(TimeDelay);
    digitalWrite(9, HIGH);
    delay(MotorDelay);
    digitalWrite(9, LOW);
    delay(2000);
    digitalWrite(ComPin, LOW);
  }
}
