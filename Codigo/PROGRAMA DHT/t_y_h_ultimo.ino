//Libraries
#include <dht.h>
dht DHT;
//Constants
#define DHT21_PIN 2     // DHT 22  (AM2302) - what pin we're connected to

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value
int cuenta;
void setup()
{
  cuenta == 0 ;
    Serial.begin(9600);
}

void loop()
{
    
    int chk = DHT.read21(DHT21_PIN);
    //Read data and store it to variables hum and temp
    hum = DHT.humidity;
    temp= DHT.temperature;
     int tempe;
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println("Celsius");
    delay(2000); //Delay 2 sec.
    tempe == temp;
            if( tempe > 32); {
  digitalWrite(3, HIGH); //prende placa peltier 
    else (tempe < 28) ;
    digitalWrite(3, LOW);
            }  
 

}   








