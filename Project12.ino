// Project 8 - Creating a Quick-Read Thermometer
#include <LiquidCrystal.h>
float celsius    = 0;
float fahrenheit = 0;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup()
{
  lcd.begin(16,2);
}

void findTemps()
{
  float voltage = 0;
  float sensor  = 0; // read the temperature sensor and convert the result to degrees C and F
  sensor  = analogRead(1);
  voltage = (sensor * 5000) / 1024;  // convert the raw sensor value to // millivolts
  voltage = voltage - 500;           // remove the voltage offset
  celsius = voltage / 10;            // convert millivolts to Celsius
  fahrenheit = (1.8 * celsius) + 32; // convert Celsius to Fahrenheit
}

void displayTemps()
{
  lcd.setCursor(0, 0);
  lcd.print("Temp ");
  lcd.print(celsius, 2);
  lcd.print(" Deg C ");
  lcd.setCursor(0, 1);
  lcd.print("Temp ");
  lcd.print(fahrenheit, 2);
  lcd.print(" Deg F");
}

void loop()
{  
  findTemps();
  displayTemps();
  delay(1000);
}
