int pm25Pin = A1;  // PM2.5 simulated input
int co2Pin = A3;   // CO2 simulated input

void setup() {
  Serial.begin(9600);
  Serial.println("IoT Air Quality Monitor Initialized");
}

void loop() {
  int pm25Raw = analogRead(pm25Pin);
  int co2Raw = analogRead(co2Pin);

  // Convert raw values to simulated air quality metrics
  float pm25 = map(pm25Raw, 0, 1023, 0, 500);    // µg/m3 (PM2.5)
  float co2 = map(co2Raw, 0, 1023, 400, 2000);   // ppm (CO2)

  // Print to Serial Monitor
  Serial.print("PM2.5: ");
  Serial.print(pm25);
  Serial.print(" µg/m3 | CO2: ");
  Serial.print(co2);
  Serial.println(" ppm");

  delay(2000); // Refresh every 2 seconds
}