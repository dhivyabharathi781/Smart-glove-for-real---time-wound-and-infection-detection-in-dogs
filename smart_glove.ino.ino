#include <Wire.h>
#include "DHT.h"
#include <Adafruit_MLX90614.h>
#include <Adafruit_TCS34725.h>

// ---------------- DHT11 ----------------
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ---------------- IR TEMP ----------------
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// ---------------- COLOR SENSOR ----------------
Adafruit_TCS34725 tcs = Adafruit_TCS34725(
  TCS34725_INTEGRATIONTIME_50MS,
  TCS34725_GAIN_4X
);

void setup()
{
  Serial.begin(115200);

  dht.begin();
  mlx.begin();

  if (!tcs.begin())
  {
    Serial.println("TCS34725 NOT found");
    while (1);
  }

  // LED ON for proper color detection
  tcs.setInterrupt(false);

  Serial.println("Sensors Ready...");
}

void loop()
{
  // -------- DHT11 --------
  float humidity = dht.readHumidity();
  float dhtTemp = dht.readTemperature();

  // -------- MLX90614 --------
  float ambientTemp = mlx.readAmbientTempC();
  float objectTemp = mlx.readObjectTempC();

  // -------- COLOR SENSOR --------
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);

  // 🔥 IMPORTANT: Normalize using clear channel (better accuracy)
  float sum = c;
  float red = 0, green = 0, blue = 0;

  if (sum > 0)
  {
    red = (float)r / sum * 255.0;
    green = (float)g / sum * 255.0;
    blue = (float)b / sum * 255.0;
  }

  // -------- SERIAL OUTPUT (for VS Code) --------
  Serial.print(humidity); Serial.print(",");
  Serial.print(dhtTemp); Serial.print(",");
  Serial.print(ambientTemp); Serial.print(",");
  Serial.print(objectTemp); Serial.print(",");
  Serial.print((int)red); Serial.print(",");
  Serial.print((int)green); Serial.print(",");
  Serial.println((int)blue);

  delay(2000);
}
