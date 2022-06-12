#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 4
#define neopin 8
Adafruit_NeoPixel pixels(NUMPIXELS, neopin, NEO_GRB + NEO_KHZ800);

#define piezopin 7

int pushpinoff = 2;
int push1st = 3;
int push2nd = 4;

void setup() {
  pinMode(piezopin, OUTPUT);  //피에조
  pinMode(neopin, OUTPUT);    //네오픽셀
  pinMode(pushpinoff, INPUT_PULLUP);
  pinMode(push1st, INPUT_PULLUP); pinMode(push2nd, INPUT_PULLUP);
  pixels.begin(); //네오픽셀 활성화
  pixels.show();  //픽셀보이게
}

void loop() {
  if (digitalRead(push1st) == HIGH && digitalRead(push2nd) == LOW && digitalRead(pushpinoff) == LOW) {
    singfirst();
  }
  else if (digitalRead(push1st) == LOW && digitalRead(push2nd) == HIGH && digitalRead(pushpinoff) == LOW) {
    singsecond();
  }
  else if (digitalRead(push1st) == LOW && digitalRead(push2nd) == LOW && digitalRead(pushpinoff) == HIGH) {
    white();
    digitalWrite(piezopin, LOW);
  }
  else {
    pixels.clear();
    digitalWrite(piezopin, LOW);
  }
}

void singfirst() {
  red();  //네오픽셀
  //음계
  float singspeed = 0.75; //숫자가 작을수록 빠름
  tone(piezopin, 262, 200); delay(400*singspeed); //도
  tone(piezopin, 262, 200); delay(300*singspeed); //도
  tone(piezopin, 262, 200); delay(300*singspeed); //도
  tone(piezopin, 262, 200); delay(400*singspeed); //도
  tone(piezopin, 262, 200); delay(400*singspeed); //도

  tone(piezopin, 330, 200); delay(400*singspeed); //미
  tone(piezopin, 392, 200); delay(300*singspeed); //솔
  tone(piezopin, 392, 200); delay(300*singspeed); //솔
  tone(piezopin, 330, 200); delay(400*singspeed); //미
  tone(piezopin, 262, 200); delay(400*singspeed); //도

  tone(piezopin, 392, 200); delay(300*singspeed); //솔
  tone(piezopin, 392, 200); delay(300*singspeed); //솔
  tone(piezopin, 330, 200); delay(400*singspeed); //미
  tone(piezopin, 392, 200); delay(300*singspeed); //솔
  tone(piezopin, 392, 200); delay(300*singspeed); //솔
  tone(piezopin, 330, 200); delay(400*singspeed); //미

  tone(piezopin, 262, 200); delay(400*singspeed); //도
  tone(piezopin, 262, 200); delay(400*singspeed); //도
  tone(piezopin, 262, 400); delay(600*singspeed); //도

  tone(piezopin, 392, 200); delay(400*singspeed); //솔
  tone(piezopin, 392, 200); delay(400*singspeed); //솔
  tone(piezopin, 330, 200); delay(400*singspeed); //미
  tone(piezopin, 262, 200); delay(400*singspeed); //도

  tone(piezopin, 392, 200); delay(400*singspeed); //솔
  tone(piezopin, 392, 200); delay(400*singspeed); //솔
  tone(piezopin, 392, 400); delay(800*singspeed); //솔

  tone(piezopin, 392, 200); delay(400*singspeed); //솔
  tone(piezopin, 392, 200); delay(400*singspeed); //솔
  tone(piezopin, 330, 200); delay(400*singspeed); //미
  tone(piezopin, 262, 200); delay(400*singspeed); //도

  tone(piezopin, 392, 200); delay(400*singspeed); //솔
  tone(piezopin, 392, 200); delay(400*singspeed); //솔
  tone(piezopin, 392, 200); delay(800*singspeed); //솔

  tone(piezopin, 392, 200); delay(400*singspeed); //솔
  tone(piezopin, 392, 200); delay(400*singspeed); //솔
  tone(piezopin, 330, 200); delay(400*singspeed); //미
  tone(piezopin, 262, 200); delay(400*singspeed); //도

  tone(piezopin, 392, 200); delay(300*singspeed); //솔
  tone(piezopin, 392, 200); delay(300*singspeed); //솔
  tone(piezopin, 392, 200); delay(300*singspeed); //솔
  tone(piezopin, 440, 200); delay(300*singspeed); //라
  tone(piezopin, 392, 400); delay(800*singspeed); //솔

  tone(piezopin, 523, 200); delay(400*singspeed); //높은도
  tone(piezopin, 392, 200); delay(400*singspeed); //솔
  tone(piezopin, 523, 200); delay(400*singspeed); //높은도
  tone(piezopin, 392, 200); delay(400*singspeed); //솔

  tone(piezopin, 330, 200); delay(400*singspeed); //미
  tone(piezopin, 294, 200); delay(400*singspeed); //레
  tone(piezopin, 262, 400); delay(800*singspeed); //도

  for (int i = 0; i < 10; i++) {
    randomcolor(); delay(100);
  }
  off(); //네오픽셀
}

void singsecond() {
  green();    //네오픽셀
  //음계
  float singspeed = 0.55; //숫자가 작을수록 빠름
  int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};
  tone(piezopin, melody[0], 250);  delay(500*singspeed);
  tone(piezopin, melody[0], 250);  delay(500*singspeed);
  tone(piezopin, melody[4], 250);  delay(500*singspeed);
  tone(piezopin, melody[4], 250);  delay(500*singspeed);
  tone(piezopin, melody[5], 250);  delay(500*singspeed);
  tone(piezopin, melody[5], 250);  delay(500*singspeed);
  tone(piezopin, melody[4], 500);  delay(1000*singspeed);
  tone(piezopin, melody[3], 250);  delay(500*singspeed);
  tone(piezopin, melody[3], 250);  delay(500*singspeed);
  tone(piezopin, melody[2], 250);  delay(500*singspeed);
  tone(piezopin, melody[2], 250);  delay(500*singspeed);
  tone(piezopin, melody[1], 250);  delay(500*singspeed);
  tone(piezopin, melody[1], 250);  delay(500*singspeed);
  tone(piezopin, melody[0], 500);  delay(1000*singspeed);
  tone(piezopin, melody[4], 250);  delay(500*singspeed);
  tone(piezopin, melody[4], 250);  delay(500*singspeed);
  tone(piezopin, melody[3], 250);  delay(500*singspeed);
  tone(piezopin, melody[3], 250);  delay(500*singspeed);
  tone(piezopin, melody[2], 250);  delay(500*singspeed);
  tone(piezopin, melody[2], 250);  delay(500*singspeed);
  tone(piezopin, melody[1], 500);  delay(1000*singspeed);
  tone(piezopin, melody[4], 250);  delay(500*singspeed);
  tone(piezopin, melody[4], 250);  delay(500*singspeed);
  tone(piezopin, melody[3], 250);  delay(500*singspeed);
  tone(piezopin, melody[3], 250);  delay(500*singspeed);
  tone(piezopin, melody[2], 250);  delay(500*singspeed);
  tone(piezopin, melody[2], 250);  delay(500*singspeed);
  tone(piezopin, melody[1], 500);  delay(1000*singspeed);
  tone(piezopin, melody[0], 250);  delay(500*singspeed);
  tone(piezopin, melody[0], 250);  delay(500*singspeed);
  tone(piezopin, melody[4], 250);  delay(500*singspeed);
  tone(piezopin, melody[4], 250);  delay(500*singspeed);
  tone(piezopin, melody[5], 250);  delay(500*singspeed);
  tone(piezopin, melody[5], 250);  delay(500*singspeed);
  tone(piezopin, melody[4], 500);  delay(1000*singspeed);
  tone(piezopin, melody[3], 250);  delay(500*singspeed);
  tone(piezopin, melody[3], 250);  delay(500*singspeed);
  tone(piezopin, melody[2], 250);  delay(500*singspeed);
  tone(piezopin, melody[2], 250);  delay(500*singspeed);
  tone(piezopin, melody[1], 250);  delay(500*singspeed);
  tone(piezopin, melody[1], 250);  delay(500*singspeed);
  tone(piezopin, melody[0], 500);  delay(1000*singspeed);

  for (int i = 0; i < 10; i++) {
    randomcolor(); delay(100);
  }
  off(); //네오픽셀
}

void off() {
  pixels.setBrightness(0);
  pixels.setPixelColor(0, 0, 0, 0);
  pixels.setPixelColor(1, 0, 0, 0);
  pixels.setPixelColor(2, 0, 0, 0);
  pixels.setPixelColor(3, 0, 0, 0);
  pixels.show();
}

void white() {
  pixels.setBrightness(255);
  pixels.setPixelColor(0, 255, 255, 255);
  pixels.setPixelColor(1, 255, 255, 255);
  pixels.setPixelColor(2, 255, 255, 255);
  pixels.setPixelColor(3, 255, 255, 255);
  pixels.show();
}

void red() {
  pixels.setBrightness(255);
  pixels.setPixelColor(0, 255, 0, 0);
  pixels.setPixelColor(1, 255, 0, 0);
  pixels.setPixelColor(2, 255, 0, 0);
  pixels.setPixelColor(3, 255, 0, 0);
  pixels.show();
}

void green() {
  pixels.setBrightness(255);
  pixels.setPixelColor(0, 0, 255, 0);
  pixels.setPixelColor(1, 0, 255, 0);
  pixels.setPixelColor(2, 0, 255, 0);
  pixels.setPixelColor(3, 0, 255, 0);
  pixels.show();
}

void randomcolor() {
  pixels.setBrightness(255);
  pixels.setPixelColor(0, random(256), random(256), random(256));
  pixels.setPixelColor(1, random(256), random(256), random(256));
  pixels.setPixelColor(2, random(256), random(256), random(256));
  pixels.setPixelColor(3, random(256), random(256), random(256));
  pixels.show();
}
