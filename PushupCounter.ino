#define trigPin 9
#define echoPin 10

long duration;
int distance;

int pushupCount = 0;
bool downPosition = false; // whether you're currently in the down phase

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo duration and convert to distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // --- Push-up detection logic ---
  if (distance < 10) {
    // You're in the down position
    downPosition = true;
  }

  // Only count when you've gone down and then back up
  if (distance > 20 && downPosition) {
    pushupCount++;
    downPosition = false; // reset state
    Serial.print("Push-ups: ");
    Serial.println(pushupCount);
    delay(1000); // debounce to avoid double-count
  }

  delay(100); // adjust based on sensor speed
}
