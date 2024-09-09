#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;
String pasword = "ESP32test";
String dato;

//salida binaria
#define led 2
// SALIDA DEMUX
#define b0 4
#define b1 16
#define b2 17
#define b3 5
//SALIDAS SIN DEMUX
#define CONT 18      // contacto
#define LA 19       // luces altas
#define LM 21        // luces bajas
#define LB 3        // luces bajas
#define LI 1        // guiñadores izquieda
#define LD 22        // guiñadores derecha
#define PAR 23       // parqueo


//comandos bluetooth
//(salidas demux)
#define CMD_V1_UP "V1U"  //Comando Vidrio 1
#define CMD_V2_UP "V2U"    //Comando Vidrio 2
#define CMD_V3_UP "V3U"    //Comando Vidrio 3
#define CMD_V4_UP "V4U"    //Comando Vidrio 4
#define CMD_V1_DOWN "V1D"  //Comando Vidrio 1
#define CMD_V2_DOWN "V2D"  //Comando Vidrio 2
#define CMD_V3_DOWN "V3D"  //Comando Vidrio 3
#define CMD_V4_DOWN "V4D"  //Comando Vidrio 4
#define CMD_AR "AR"        //Comando aranque
#define CMD_PUE "PUE"      //Comando puertas
#define CMD_OFF "OFF"   //Comando apagar
// salidas sin demux
#define CMD_CONT "CO"      //Comando contacto
#define CMD_LA "LA"       //Comando luces altas
#define CMD_LM "LM"        //Comando luces bajas
#define CMD_LB "LB"        //Comando luces bajas
#define CMD_LI "LI"        //Comando guiñadores izquieda
#define CMD_LD "LD"        //Comando guiñadores derecha
#define CMD_PAR "PA"       //Comando parqueo
// salidas virtuales
#define CMD_CP "CP"  // Comando cambiar pasword


void setup() {
  //Bluetooth nombre
  SerialBT.begin("ESP32test");
  // salidas para el demux
  pinMode(led, OUTPUT);
  pinMode(b0, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b3, OUTPUT);
  // salidas fisicas
  pinMode(CONT, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(LM, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(LI, OUTPUT);
  pinMode(LD, OUTPUT);
  pinMode(PAR, OUTPUT);
  //estado inicial
  binario(0);
  digitalWrite(CONT, LOW);
  digitalWrite(LA, LOW);
  digitalWrite(LM, LOW);
  digitalWrite(LB, LOW);
  digitalWrite(LI, LOW);
  digitalWrite(LD, LOW);
  digitalWrite(PAR, LOW);

}
bool NOT (bool bin){
  if (bin == 1){
    return 0;
  }
  else{
    return 1;
  }
}

void binario(int binario) {
  if (binario == 0) { // pagado
    digitalWrite(b0, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(b3, LOW);
  }
  if (binario == 1) {// V1 UP
    digitalWrite(b0, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(b3, LOW);
  }
  if (binario == 2) {// V2 UP
    digitalWrite(b0, LOW);
    digitalWrite(b1, HIGH);
    digitalWrite(b2, LOW);
    digitalWrite(b3, LOW);
  }
  if (binario == 3) {// V3 UP
    digitalWrite(b0, HIGH);
    digitalWrite(b1, HIGH);
    digitalWrite(b2, LOW);
    digitalWrite(b3, LOW);
  }
  if (binario == 4) {// V4 UP
    digitalWrite(b0, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, LOW);
  }
  if (binario == 5) {// V1 DOWN
    digitalWrite(b0, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, LOW);
  }
  if (binario == 6) {// V2 DOWN
    digitalWrite(b0, LOW);
    digitalWrite(b1, HIGH);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, LOW);
  }
  if (binario == 7) {// V3 DOWN
    digitalWrite(b0, HIGH);
    digitalWrite(b1, HIGH);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, LOW);
  }
  if (binario == 8) {// V4 DOWN
    digitalWrite(b0, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(b3, HIGH);
  }
  if (binario == 9) {// PUERTAS
    digitalWrite(b0, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(b2, LOW);
    digitalWrite(b3, HIGH);
  }
  if (binario == 10) {// ARRANQUES
    digitalWrite(b0, LOW);
    digitalWrite(b1, HIGH);
    digitalWrite(b2, LOW);
    digitalWrite(b3, HIGH);
  }
  if (binario == 11) {
    digitalWrite(b0, HIGH);
    digitalWrite(b1, HIGH);
    digitalWrite(b2, LOW);
    digitalWrite(b3, HIGH);
  }
  if (binario == 12) {
    digitalWrite(b0, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, HIGH);
  }

  if (binario == 13) {
    digitalWrite(b0, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, HIGH);
  }
  if (binario == 14) {
    digitalWrite(b0, LOW);
    digitalWrite(b1, HIGH);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, HIGH);
  }
  if (binario == 15) {
    digitalWrite(b0, HIGH);
    digitalWrite(b1, HIGH);
    digitalWrite(b2, HIGH);
    digitalWrite(b3, HIGH);
  }
}

void ejecutar(String cmd) {
  bool estado;
  if (cmd == CMD_V1_UP) {
    binario(1);
  }
  if (cmd == CMD_V2_UP) {
    binario(2);
  }
  if (cmd == CMD_V3_UP) {
    binario(3);
  }
  if (cmd == CMD_V4_UP) {
    binario(4);
  }
  if (cmd == CMD_V1_DOWN) {
    binario(5);
  }
  if (cmd == CMD_V2_DOWN) {
    binario(6);
  }
  if (cmd == CMD_V3_DOWN) {
    binario(7);
  }
  if (cmd == CMD_V4_DOWN) {
    binario(8);
  }
  if (cmd == CMD_OFF) {
    binario(0);
  }
  if (cmd == CMD_PUE) {
    binario(9);
  }
  if (cmd == CMD_CONT) {
    estado=digitalRead(CONT);
    digitalWrite(CONT,NOT(estado));
  }
  if (cmd == CMD_AR) {
    binario(10);
  }
  if (cmd == CMD_LA) {
    estado=digitalRead(LA);
    digitalWrite(LA,NOT(estado));
  }
  if (cmd == CMD_LB) {
    estado=digitalRead(LB);
    digitalWrite(LB,NOT(estado));
  }
  if (cmd == CMD_LM) {
    estado=digitalRead(LM);
    digitalWrite(LM,NOT(estado));
  }

  if (cmd == CMD_LI) {
    estado=digitalRead(LI);
    digitalWrite(LI,NOT(estado));
    digitalWrite(LD,0);   
    digitalWrite(PAR,0);      
  }
  if (cmd == CMD_LD) {
    estado=digitalRead(LD);
    digitalWrite(LI,0);
    digitalWrite(LD,NOT(estado));   
    digitalWrite(PAR,0);      
  }
  if (cmd == CMD_PAR) {
    estado=digitalRead(PAR);
    digitalWrite(LI,0);
    digitalWrite(LD,0);   
    digitalWrite(PAR,NOT(estado));      
  }
}


bool verif(String pas_password) {
  if (pas_password == pasword) {
    return true;
  } else {
    return false;
  }
}



void loop() {
  if (SerialBT.available()) {
    dato = SerialBT.read();
    if (verif(dato) == true) {
      SerialBT.write(1);
      while (true) {
        if (SerialBT.available()) {
          dato = SerialBT.read();
          ejecutar(dato);
        }
        delay(20);
      }
    } else {
      SerialBT.write(0);
    }
  }
  delay(20);
}