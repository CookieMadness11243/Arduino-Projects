const int Red_Led = 5;
const int Blue_Led = 6;
const int Green_Led = 7;

const int Echo = 13;
const int Trigger = 12;

float duration, distance_cm;
void setup() {
  Serial.begin(9600);

  pinMode(Red_Led, OUTPUT);
  pinMode(Blue_Led, OUTPUT);
  pinMode(Green_Led, OUTPUT);

  pinMode(Echo, INPUT);
  pinMode(Trigger, OUTPUT);
}

void loop() {
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  // the duration is the pulse from the Echo
  duration = pulseIn(Echo, HIGH);

  // Calculate distance
  distance_cm = 0.017 * duration;

  if     (distance_cm > 200)                     { digitalWrite(Green_Led, HIGH); digitalWrite(Blue_Led, LOW);  digitalWrite(Red_Led, LOW); }
  else if(distance_cm < 200 && distance_cm > 100){ digitalWrite(Green_Led, LOW);  digitalWrite(Blue_Led, HIGH); digitalWrite(Red_Led, LOW); }
  else if(distance_cm < 100)                     { digitalWrite(Green_Led, LOW);  digitalWrite(Blue_Led, LOW);  digitalWrite(Red_Led, HIGH); }
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}
