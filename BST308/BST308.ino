#include <LiquidCrystal.h>

// normal değer alarm butonu
#define normalca 16
#define normalec 17
#define normalph 18
#define normalnt 19
#define normalsd 20

//yüksek değer alarm butonu 
#define yec A15
#define yph A14
#define ynt A13
#define ysd A12
#define yca A11

// alarm ledleri
#define redPin A4
#define tredPin A3
#define greenPin A5
#define bluePin A6
#define yellowPin A7

int phdata = 0;

// ekran tanımlaması
LiquidCrystal lcd(34, 35, 36, 38, 39, 40, 41, 42, 43, 44, 45);

void islemler() {
  getData();
  if (digitalRead(yec) == LOW) // yüksek ec olunca
  {
    digitalWrite(redPin, HIGH);
    delay(300);
    digitalWrite(redPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YUKSEK EC DEGERI");
    delay(500);
    islemler();
  }

  if (digitalRead(yph) == LOW) // yüksek ph olunca
  {

    digitalWrite(greenPin, HIGH);
    delay(300);
    digitalWrite(greenPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YUKSEK PH DEGERI");
    delay(500);
    islemler();

  }
  if (digitalRead(ynt) == LOW) // yüksek nt olunca
  {

    digitalWrite(bluePin, HIGH);
    delay(300);
    digitalWrite(bluePin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YUKSEK NT DEGERI");
    delay(500);
    islemler();
  }

  if (digitalRead(ysd) == LOW) // yüksek sodyum olunca
  {

    digitalWrite(yellowPin, HIGH);
    delay(300);
    digitalWrite(yellowPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YUKSEK SD DEGERI");
    delay(500);
    islemler();

  }
  if (digitalRead(yca) == LOW) // yüksek sodyum olunca
  {

    digitalWrite(tredPin, HIGH);
    delay(300);
    digitalWrite(tredPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YUKSEK CA DEGERI");
    delay(500);
    islemler();

  }

  if (digitalRead(normalec) == LOW) // yüksek sodyum olunca
  {

    digitalWrite(yellowPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NORMAL EC DEGERI");
    delay(500);
    islemler();

  }

  if (digitalRead(normalph) == LOW) // yüksek sodyum olunca
  {

    digitalWrite(yellowPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NORMAL PH DEGERI");
    delay(500);
    islemler();

  }

  if (digitalRead(normalnt) == LOW) // yüksek sodyum olunca
  {

    digitalWrite(yellowPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NORMAL NT DEGERI");
    delay(500);
    islemler();

  }

  if (digitalRead(normalsd) == LOW) // yüksek sodyum olunca
  {

    digitalWrite(yellowPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NORMAL SD DEGERI");
    delay(500);
    islemler();

  }

  if (digitalRead(normalca) == LOW) // yüksek sodyum olunca
  {

    digitalWrite(tredPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NORMAL CA DEGERI");
    delay(500);
    islemler();

  }

}


void getData(){
  if (Serial.available() > 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ph verisi bekleniyor");
    delay(2);
    Serial.println(phdata);
    int c1 = Serial.parseInt();
    phdata = c1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(phdata);
    Serial.println(phdata);
    delay(500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ec verisi bekleniyor");
    delay(2);
    Serial.println(phdata);
    int c2 = Serial.parseInt();
    phdata = c2;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(phdata);
    Serial.println(phdata);
    delay(500);
    // Serial.println(phdata);
  }
}


void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(A15, INPUT_PULLUP);
  pinMode(A14, INPUT_PULLUP);
  pinMode(A13, INPUT_PULLUP);
  pinMode(A12, INPUT_PULLUP);
  pinMode(A11, INPUT_PULLUP);
  pinMode(redPin, OUTPUT); //su satın alındığında kırmızı ısık yanar 
  pinMode(greenPin, OUTPUT); //kek satın alındığında kırmızı ısık yanar 
  pinMode(bluePin, OUTPUT); //gofret satın alındığında kırmızı ısık yanar 
  pinMode(yellowPin, OUTPUT); //çikolata satın alındığında kırmızı ısık yanar 

}

void loop() {

  //mevcut durumla ilgili bilgi yaz
  lcd.setCursor(0, 0);
  lcd.print("AKILLI TARIM    ");

  islemler();

}
