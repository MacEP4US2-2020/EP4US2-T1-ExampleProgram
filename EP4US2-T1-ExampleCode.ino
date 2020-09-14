//Example Arduino Program -> Basics -> EP4US2 Fall 2020
//Last Modified: September 2, 2020
//Program Purpose: To illustrate basic Arduino programming style and syntax for students

//Include Header Files
//you can include header files using this syntax, they can be programmed only if they are integrated in the Arduino IDE
//or are in the same filepath as your program

#include <String> //generic library
#include <DHT.h> //DHT-11 sensor library

//Declaring Objects

#define DHTPIN 4 //define the pin that the DHT sensor's signal is connected to
#define DHTTYPE DHT11 //define the type of DHT sensor, there are two types: DHT-11, DHT-22. This course is using DHT-11
DHT dht(DHTPIN, DHTTYPE); //object declaration constructor

void setup() {
  // put your setup code here, to run once:

  //Serial Monitor initialization
  //The serial monitor is the built in output form, similar to a console.
  //Use "Serial.println("")" to print strings and sensor data to the serial monitor
  Serial.begin(115200); //baud rate of 115200Hz

  //The pinMode function sets a type associated to a specific GPIO (General Purpose Input Output) 
  pinMode(5,OUTPUT); //IO 5 Output
  pinMode(6,OUTPUT); //IO 6 Output 
  pinMode(7,OUTPUT); //IO 7 Output

  //DHT-11 Initialization
  dht.begin(); //function that starts the sensor during the initial setup

}

void loop() {
  // put your main code here, to run repeatedly:

  //Digital Write sends a "1" or "0" to turn ON or OFF a certain output form.
  //In this case lets assume this is writing to an LED
  
  digitalWrite(5,HIGH); //turn ON led
  delay(1000); //wait 1000 ms or 1 second
  digitalWrite(5,LOW); //turn OFF led
  delay(1000); //wait 1 second
  
  //DHT-11 Sensor Data Extraction
  
  //Read humidity as percentage
  float h = dht.readHumidity();
  
  //Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  
  //Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  //Display Sensor data on the Serial Monitor
  Serial.println("Humidity: " + h); 
  Serial.println("Temperature C: " + t);
  Serial.println("Temperature F: " + f);
}
