#include <Wire.h>
#include <U8g2lib.h>
#include <DHT.h>

#define OLED_RESET -1
#define DHTPIN  2
#define DHTTYPE DHT22

U8G2_SH1107_128X128_1_HW_I2C display(U8G2_R0, OLED_RESET);

DHT dht(DHTPIN, DHTTYPE);

int airpin = 8;
int conc   = A0;
int buzzpin = 4;

void setup() {
  delay(2000);
  Serial.begin(9600);
  Wire.begin();
  display.begin();
  display.setFont(u8g2_font_6x10_tf); 
  dht.begin();
  pinMode(airpin, INPUT);
  pinMode(buzzpin, OUTPUT);
  pinMode(conc, INPUT);
}

void loop() {
  delay(1000);

  float humidity    = dht.readHumidity();
  float temperature = dht.readTemperature();
  int airquality    = digitalRead(airpin);
  digitalWrite(buzzpin, LOW);
  float concentration = ((5.0 / 1025.0) * analogRead(conc));
  display.firstPage();
  do {
    // Temperature
    display.setCursor(0, 10);
    display.print("Temperature: ");
    display.print(temperature);

    if (temperature < 18) {
      digitalWrite(buzzpin, HIGH);
      display.setCursor(0, 20);
      display.print("Temp low");
    } else if (temperature > 35) {
      digitalWrite(buzzpin, HIGH);
      display.setCursor(0, 20);
      display.print("Temp high");
    }

    // Humidity
    display.setCursor(0, 40);
    display.print("Humidity: ");
    display.print(humidity);
    display.print("%");

    if (humidity < 40) {
      digitalWrite(buzzpin, HIGH);
      display.setCursor(0, 50);
      display.print("humid low");
    } else if (humidity > 70) {
      digitalWrite(buzzpin, HIGH);
      display.setCursor(0, 50);
      display.print("humid high");
    }

    // Air Quality / concentration
    display.setCursor(0, 70);
    display.print("conc= ");
    display.print(concentration);
    display.print("ppm");

    if (airquality == LOW) {
      digitalWrite(buzzpin, HIGH);
      display.setCursor(0, 80);
      display.print("Air Bad");
    }

  } while (display.nextPage()); 

  delay(2000);
}
