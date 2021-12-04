#include <Nokia_LCD.h>

Nokia_LCD lcd(13 /* CLK */, 12 /* DIN */, 11 /* DC */, 10 /* CE */, 9 /* RST */);
int but=7;
int but2=6;
int sayac=0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(); 
  lcd.clear();
  pinMode(but,INPUT);
  pinMode(but2,INPUT);
  Serial.begin(9600);
  arayuz();
}

void loop() {
  // put your main code here, to run repeatedly:
  arayuz();
  int butDurum = digitalRead(but);
  int but2Durum = digitalRead(but2);
  if(butDurum){
    Serial.println("but 1 basildi");
    sayac++;
    Serial.println(sayac);
  }
  switch(sayac){
    case 1:
      arayuz1();
      Serial.println("arayuz 1");
      if(but2Durum){
        verigonder();
      }
    break;
    case 2:
      arayuz2();
      Serial.println("arayuz 2");
      if(but2Durum){
        verigonder();
      }
    break;
    case 3:
      arayuz3();
      Serial.println("arayuz 3");
      if(but2Durum){
        verigonder();
      }
    break;
  }
  delay(500);
  arayuz();
  if(sayac>3){
    sayac=0;
  }
  delay(500);
}

void arayuz(){
  lcd.setBacklight(false); 
  lcd.setCursor(0, 0);
  lcd.print("Merhaba\n");
  lcd.println("Nasilsin");
  lcd.println("Iyiyim");
}

void arayuz1(){
  lcd.setBacklight(false); 
  lcd.setCursor(0, 0);
  lcd.setInverted(true); 
  lcd.print("Merhaba\n");
  lcd.setInverted(false); 
  lcd.println("Nasilsin");
  lcd.println("Iyiyim");
}

void arayuz2(){
  lcd.setBacklight(false); 
  lcd.setCursor(0, 0); 
  lcd.print("Merhaba\n");
  lcd.setInverted(true);
  lcd.println("Nasilsin");
  lcd.setInverted(false);
  lcd.println("Iyiyim");
}
void arayuz3(){
  lcd.setBacklight(false); 
  lcd.setCursor(0, 0); 
  lcd.print("Merhaba\n"); 
  lcd.println("Nasilsin");
  lcd.setInverted(true); 
  lcd.println("Iyiyim");
  lcd.setInverted(false); 
}

void verigonder(){
  Serial.println("Veri gonderildi.");
}
