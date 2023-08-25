
const int flameSensorPin = 4;  // Pin yang digunakan untuk sensor API
const int buzzerPin = 26;      // Pin yang digunakan untuk buzzer

void setup() {
  Serial.begin(115200);

  pinMode(flameSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int flameValue = digitalRead(flameSensorPin);

  if (flameValue == LOW) {
    Serial.println("Deteksi Api!");
    playFireAlert();  // Putar suara peringatan menggunakan buzzer
  } else {
    Serial.println("Tidak ada Api.");
    digitalWrite(buzzerPin, LOW);  // Matikan buzzer
  }

  delay(1000);
}
void playFireAlert() {
  tone(buzzerPin, 2000);  // Frekuensi bunyi buzzer
  delay(500);             // Durasi bunyi
  tone(buzzerPin, 2000);  // Frekuensi bunyi buzzer
  noTone(buzzerPin);
}
