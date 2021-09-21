#include <Arduino.h>
#include "Wire.h"

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
}

void loop()
{
  byte error, address, nDevices = 0;
  for (address = 0; address <= 127; ++address)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.print("success! found address: 0x");
      if (address < 16)
      {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      ++nDevices;
    }
    else if (error >= 3) // 2 means address was attempted but not available and 3 means address is there, but not data were not received
    {
      Serial.print("\ndetected error on: ");
      Serial.print(address, HEX);
      Serial.print(" error: ");
      Serial.print(error);
    }
  }
  Serial.println("\nDONE\n\n\n");
  delay(5000);
}