#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(6, 7, 8);
#define lcdled 9
#define led 5

#define buton A2
#define shtr A5
#define fcs A4

int sn = 5;
int foto = 20;

unsigned long previousMillis = 0;
const long interval = 980;

void setup()   {
  pinMode(shtr, OUTPUT);
  digitalWrite(shtr, HIGH);
  pinMode(fcs, OUTPUT);
  digitalWrite(fcs, HIGH);

  pinMode(lcdled, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(lcdled, LOW);
  Serial.begin(9600);

  display.begin();
  display.setContrast(50);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, 0);
  display.println("ZAMAN ARALIKLI");
  display.println("  CEKiM MODU  ");
  display.println();
  display.setTextColor(BLACK);
  display.println("Kalan: Sn/Foto");
  display.print("       ");
  display.setTextSize(2);
  display.print(sn);
  display.setTextSize(1);
  display.print(" ");
  display.setTextSize(2);
  display.print(foto);
  display.display();

  pinMode(buton, INPUT_PULLUP);
  while (digitalRead(buton)) {
  }
}


void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    sn--;
    display.clearDisplay();
    display.display();
  }

  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, 0);
  display.println("ZAMAN ARALIKLI");
  display.println("  CEKiM MODU  ");
  display.println();
  display.setTextColor(BLACK);
  display.println("Kalan: Sn/Foto");
  display.print("       ");
  display.setTextSize(2);
  display.print(sn);
  display.setTextSize(1);
  display.print(" ");
  display.setTextSize(2);
  display.print(foto);
  display.display();

  digitalWrite(led, LOW);
  if (sn == 0) {
    digitalWrite(led, HIGH);
    foto--;
    digitalWrite(shtr, LOW);
    delay(100);
    digitalWrite(shtr, HIGH);
    sn = 5;
    display.clearDisplay();
    display.display();
  }

}
