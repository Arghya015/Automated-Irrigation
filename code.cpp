// 🌾 Smart Agriculture Project (Arduino UNO)
// Sensors: Soil Moisture (A0), Rain Sensor (A1), LDR (Digital D6)
// Outputs: Green LED, Red LED, Active HIGH Relay + Pump

#define SOIL_PIN A1
#define RAIN_PIN A0
#define LDR_PIN 6          // LDR digital output (D0)
#define GREEN_LED 7
#define RED_LED 8
#define RELAY_PIN 9        // Relay control (Active HIGH)

// --- Thresholds  ---
int soilDryThreshold = 600;    // higher = dryer soil
int rainDryThreshold = 300;    // higher = no rain

int soilValue, rainValue;
int ldrState;  // 0 = dark (evening), 1 = bright (day)

void setup() {
  Serial.begin(9600);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(RELAY_PIN, HIGH);  // Pump OFF at start

  Serial.println("🌱 Smart Agriculture System (Evening Pump Mode + Active HIGH Relay) Started");
  delay(2000);
}

void loop() {
  // --- Read sensors ---
  soilValue = analogRead(SOIL_PIN);
  rainValue = analogRead(RAIN_PIN);
  ldrState = digitalRead(LDR_PIN); // 1 = bright, 0 = dark/evening

  Serial.println("------------------------------------------------");
  Serial.print("Soil: "); Serial.print(soilValue);
  Serial.print(" | Rain: "); Serial.print(rainValue);
  Serial.print(" | LDR: "); Serial.println(ldrState == LOW ? "Evening (Dark)" : "Daylight");

  bool soilDry = (soilValue > soilDryThreshold);
  bool noRain = (rainValue > rainDryThreshold);
  bool eveningTime = (ldrState == LOW); // evening or dark

  Serial.print("Soil Dry: "); Serial.print(soilDry);
  Serial.print(" | No Rain: "); Serial.print(noRain);
  Serial.print(" | Evening: "); Serial.println(eveningTime);

  // --- Decision ---
  if (soilDry && noRain && eveningTime) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(RELAY_PIN, LOW);   // Relay ON (Active HIGH)
    Serial.println("💧 Pump ON + Green LED ON (Evening, Dry, No Rain)");
  } else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(RELAY_PIN, HIGH);    // Relay OFF
    Serial.println("❌ Pump OFF + Red LED ON (Conditions not met)");
  }

  delay(100);
}
