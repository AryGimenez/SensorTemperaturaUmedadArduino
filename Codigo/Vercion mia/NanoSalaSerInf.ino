#include <SoftwareSerial.h>
#include <SimpleDHT.h>


const int mPin_Rx = 3;
const int mPin_Tx = 4;
const int mPin_Dht11 = 2;

const int mPin_Led = 7;
const int mPin_EeInf = 6;
const int mPin_ReInf = 4;
const int mPin_RxTx = 8;

byte m_TemSS = 0;
byte m_UmeSS = 0;
boolean mError = false;

SimpleDHT11 mDht11_SS; 

SoftwareSerial mySerial(mPin_Rx, mPin_Tx); // RX, TX


void setup() { 
  Serial.begin(9600);
  
  pinMode(mPin_Led, OUTPUT);
  pinMode(mPin_RxTx, OUTPUT);
  
  digitalWrite(mPin_Led, HIGH);
  digitalWrite(mPin_RxTx, HIGH);
  
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
