volatile unsigned long pulseCount = 0;
#define PIN_PULSE 13
#define IMPULSES_PER_KWH 1000.0

void IRAM_ATTR onPulse() { pulseCount++; }

void setup() {
  Serial.begin(115200);
  pinMode(PIN_PULSE, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_PULSE), onPulse, FALLING);
}

void loop() {
  float kwh = pulseCount / IMPULSES_PER_KWH;
  Serial.printf("Total Energy Consumed: %.3f kWh (Pulses: %lu)\n", kwh, pulseCount);
  delay(5000);
}