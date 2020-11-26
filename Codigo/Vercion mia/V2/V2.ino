#include <SoftwareSerial.h>
#include <SimpleDHT.h>

// dispositivo a usar nano \
// Va a carbar con 9V
// alimentzcion  9V / 3V

// Comunicacion A la caja principal
const int mPin_Rx = 1;
const int mPin_Tx = 2;

const int mPin_RxTx = 11;
// PIn Sensor de temperatra y umedad  T / H
const int mPin_Dht11 = 32;

// LIBRERIA para DHT11 
SimpleDHT11 mDht11_SS; 

// Led de advertencia para saber el estado del sensor
const int mPin_LedEstatus = 12;
// Variable para guardar tempreratura acutal 
byte m_TemSS = 0;
// Variable para guardar humedad actual
byte m_UmeSS = 0;

// Variable que idientifica que el esta dando ERROR
boolean mError = false;



// Variables para la espera de BAUDIOS GENERAL
const int m_Vel_General = 9600;

// Variable para la comunicacion SERIAL Asia la caja principal
SoftwareSerial mySerial(mPin_Rx, mPin_Tx); // RX, TX

void setup() {
  //Velocidad del Arduina Pesta en Baudios
  Serial.begin(m_Vel_General);

  //Determina que los pienes seiguentes var a emitir 
  pinMode(mPin_LedEstatus, OUTPUT); //Led de el dispositivo
  pinMode(mPin_RxTx, OUTPUT); //Determine que Este pin va emitir y resivir informacion (/??/)

  // Prende el Led De el Sensor
  digitalWrite(mPin_LedEstatus, HIGH);
  Serial.println(mPin_LedEstatus);
}

void loop() {

  /**
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

*/
}


// Metodo para actualizar la temperatura y la umedad de el DHT11
void f_TemRack (){
  int err = SimpleDHTErrSuccess; // (??)
  String xRespuesta = "Tem: ";

  byte x_TemSS = 0;
  byte x_UmeSS = 0;
  if ((err = mDht11_SS.read(mPin_Dht11, &x_TemSS, &x_UmeSS, NULL)) != SimpleDHTErrSuccess) {
    mError = true;
    Serial.println(err);
  }
}
