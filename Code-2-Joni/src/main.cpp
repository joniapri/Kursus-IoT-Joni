#include <Arduino.h>
#include <wire.h>
#include <SPI.h>

#define POT_PIN 4
#define Led1_Hijau1 5
#define Led2_Putih 18
#define Led3_Merah 19
#define Led4_Hijau2 21

int adcvalue = 0;
float Suhu = 0;

void InitLed(int LedNumber) {
  pinMode(LedNumber, OUTPUT);
}

void LedON (int LedNumber) {
  digitalWrite(LedNumber, HIGH);
}

void LedOff (int LedNumber) {
  digitalWrite(LedNumber, LOW);
}

void LedOffSemua() {
  LedOff(Led1_Hijau1);
  LedOff(Led2_Putih);
  LedOff(Led3_Merah);
  LedOff(Led4_Hijau2);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  InitLed(Led1_Hijau1);
  InitLed(Led2_Putih);
  InitLed(Led3_Merah);
  InitLed(Led4_Hijau2);
}

void loop() {
  // put your main code here, to run repeatedly:
  adcvalue=analogRead(POT_PIN);
  Suhu=float(adcvalue) / 4095.0 * 100;
  
  if ((Suhu)<15) {
    LedOffSemua();
    LedON(Led1_Hijau1);
  }

  if ((Suhu)>=15 and (Suhu)<25) {
    LedOffSemua();
    LedON(Led2_Putih);
  }

  if ((Suhu)>=25 and (Suhu)<30) {
    LedOffSemua();
    LedON(Led3_Merah);
  }

  if ((Suhu)>=30) {
    LedOffSemua();
    LedON(Led4_Hijau2);
  }

    String printData = "Nilai suhu terbaca: " + String(Suhu) + " C";
    Serial.println(printData);
  delay(1000);

}
