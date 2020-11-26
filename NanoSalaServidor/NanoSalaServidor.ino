#include <SoftwareSerial.h>
#include <SimpleDHT.h>

// dispositivo a usar nano \
// Va a carbar con 9V
// alimentzcion  9V / 3V

// Comunicacion 
const int mPin_Rx = 3;
const int mPin_Tx = 4;
// Sensor de temperatra y umedad  T / H
const int mPin_Dht11 = 2;

// Led de advertencia
const int mPin_Led = 5;
// Variable para guardar tempreratura acutal 
byte m_TemSS = 0;
// Variable para guardar humedad actual
byte m_UmeSS = 0;

// Variable que idientifica que el esta dando ERROR
boolean mError = false;

// LIBRERIA para DHT11 
SimpleDHT11 mDht11_SS; 

// Variables para la espera de BAUDIOS GENERAL
const int m_Vau_General = 9600;

// Variable para la comunicacion SERIAL
SoftwareSerial mySerial(mPin_Rx, mPin_Tx); // RX, TX


void setup() { 
  // Da tiempo a la ejecuson segun BAUDIOS 
  Serial.begin(m_Vau_General);

  // Prende el led, para ver si el dispocitivo funciona cuando el dispocitivo le llega voltaj 
  pinMode(mPin_Led, OUTPUT);
  digitalWrite(mPin_Led, HIGH);
  
  // establecer la velocidad de datos para el puerto SoftwareSerial
  mySerial.begin(9600); // Porque esta velocidad??
  mySerial.setTimeout(100);//establecemos un tiempo de espera de 100ms

}

void loop() {
  // put your main code here, to run repeatedly:
  f_TemRack();
  if (mError){
    mySerial.print("E");
  }else{
    String xValorMandar = "{";
    xValorMandar += m_TemSS;
    xValorMandar += "|";
    xValorMandar += m_UmeSS;
    xValorMandar += "}";
    mySerial.print(xValorMandar);
  }
  
  delay(10000);
}


void f_TemRack (){
  int err = SimpleDHTErrSuccess;
  String xRespuesta = "Tem: ";

  byte x_TemSS = 0;
  byte x_UmeSS = 0;
  if ((err = mDht11_SS.read(mPin_Dht11, &x_TemSS, &x_UmeSS, NULL)) != SimpleDHTErrSuccess) {
    mError = true;
    Serial.println(err);
  }

  if (x_TemSS == 0){
    mError = true;
     Serial.println("Error");
  } else {
    mError = false;
    m_TemSS = x_TemSS;
    m_UmeSS = x_UmeSS;
  }
  xRespuesta += m_TemSS;
  xRespuesta +=  " Ume: ";
  xRespuesta += m_UmeSS;
  
  Serial.println(xRespuesta);

}
