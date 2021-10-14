#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float temperature;

int relay1 = 8;
int relay2 = 9;
int relay3 = 10;
int relay4 = 11;

void setup() {    
  Serial.begin(9600);  
  dht.begin();          
  pinMode(relay1, OUTPUT); 
  pinMode(relay2, OUTPUT);    
}

void loop() {
  delay(2000);
  float f = dht.readTemperature(true);
  float t = dht.readTemperature();

  temperature = dht.readTemperature();;

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } 
  else {
    if(temperature < 22){
      Serial.print(F("%  Temperature: "));
      Serial.print(t);
      Serial.print(F("°C "));
      Serial.println("The fan is turned off = 0");
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW);
    } 
    else if(temperature < 23){
      Serial.print(F("%  Temperature: "));
      Serial.print(t);
      Serial.print(F("°C "));
      Serial.println("The fan is turned on = 1");
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, HIGH);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, LOW);
    }
    else if(temperature < 25){
      Serial.print(F("%  Temperature: "));
      Serial.print(t);
      Serial.print(F("°C "));
      Serial.println("The fan is turned on = 2");
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, HIGH);
      digitalWrite(relay4, LOW);
    }
    else if(temperature > 27){
      Serial.print(F("%  Temperature: "));
      Serial.print(t);
      Serial.print(F("°C "));
      Serial.println("The fan is turned on = 3");
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      digitalWrite(relay3, LOW);
      digitalWrite(relay4, HIGH);
    }
  }
}
