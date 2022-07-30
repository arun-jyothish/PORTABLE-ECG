/*
Copyright (c) by Ruebn Gaertner
2017-09-19
*/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneButton.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_MOSI  D1
#define OLED_CLK   D0
#define OLED_DC    D2
#define OLED_CS    D3
#define OLED_RESET D4

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                         OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

int pic = 0;
int maxPics_L1 = 5;
int maxPics_L2 = 3;

int button_brd = D5;

OneButton button(button_brd,true);

long lastmillis = 0;
long maxtime = 10000;

//#if (SSD1306_LCDHEIGHT != 64)
//#error("Height incorrect, please fix Adafruit_SSD1306.h!");
//#endif

void setup()   {
  pinMode(button_brd,INPUT_PULLUP);
button.attachClick(click);
button.attachDoubleClick(doubleclick);
button.attachLongPressStop(longPressStop);
button.attachLongPressStart(longPressStart);

display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
display.clearDisplay();
}

void loop() {
  button.tick();

//JUMP TO DEFAULT IF NO CLICK IS DETECTED
if (millis() >= (lastmillis + maxtime))
{
    pic = 0;
}

if (pic == 0)
{
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(22,0);
  display.setCursor(0,1);
  display.print  ("Ver: 1.0.2");
  display.setTextSize(4);
  display.setCursor(  0,   21);
  display.print ("P.ECG");
  refresh();
}
//LAYER 1////////////////////////////////////////////////////
if (pic == 1)
{
  header();
  display.setCursor(0,11);  display.print (">PARAMETERS");
  display.setCursor(0,20);  display.print (" DATA RECORD");
  display.setCursor(0,29);  display.print (" DISPLAY");
  display.setCursor(0,47);  display.print (" HELP");
  display.setCursor(0,56);  display.print (" PROJECT INFO");
  refresh();
}

if (pic == 2)
{
  header();
  display.setCursor(0,11);  display.print (" PARAMETERS");
  display.setCursor(0,20);  display.print (">DATA RECORD");
  display.setCursor(0,29);  display.print (" DISPLAY");
  display.setCursor(0,47);  display.print (" HELP");
  display.setCursor(0,56);  display.print (" PROJECT INFO");
  refresh();
}

if (pic == 3)
{
  header();
  display.setCursor(0,11);  display.print (" PARAMETERS");
  display.setCursor(0,20);  display.print (" DATA RECORD");
  display.setCursor(0,29);  display.print (">DISPLAY");
  display.setCursor(0,47);  display.print (" HELP");
  display.setCursor(0,56);  display.print (" PROJECT INFO");
  refresh();
}

if (pic == 4)
{
  header();
  display.setCursor(0,11);  display.print (" PARAMETERS");
  display.setCursor(0,20);  display.print (" DATA RECORD");
  display.setCursor(0,29);  display.print (" DISPLAY");
  display.setCursor(0,47);  display.print (">HELP");
  display.setCursor(0,56);  display.print (" PROJECT INFO");
  refresh();
}

if (pic == 5)
{
  header();
  display.setCursor(0,11);  display.print (" PARAMETERS");
  display.setCursor(0,20);  display.print (" DATA RECORD");
  display.setCursor(0,29);  display.print (" DISPLAY");
  display.setCursor(0,47);  display.print (" HELP");
  display.setCursor(0,56);  display.print (">PROJECT INFO");
  refresh();
}

//LAYER 2////////////////////////////////////////////////////
if (pic == 11)
{
  header();
  display.setCursor(0,11);  display.print ("PARAMETERS");
  display.setCursor(0,20);  display.print (">UNIT:");
  display.setCursor(90,20); display.print ("none");
  display.setCursor(0,29);  display.print (" SIGNALS:");
  display.setCursor(90,29); display.print ("6");
  display.setCursor(0,38);  display.print (" DIAMETER [mm]:");
  display.setCursor(90,38); display.print ("9999");
  refresh();
}

if (pic == 21)
{
  header();
  display.setCursor(0,11);  display.print ("PARAMETERS");
  display.setCursor(0,20);  display.print (" UNIT:");
  display.setCursor(90,20); display.print ("none");
  display.setCursor(0,29);  display.print (">SIGNALS:");
  display.setCursor(90,29); display.print ("6");
  display.setCursor(0,38);  display.print (" DIAMETER [mm]:");
  display.setCursor(90,38); display.print ("9999");
  refresh();
}

if (pic == 31)
{
  header();
  display.setCursor(0,11);  display.print ("PARAMETERS");
  display.setCursor(0,20);  display.print (" UNIT:");
  display.setCursor(90,20); display.print ("none");
  display.setCursor(0,29);  display.print (" SIGNALS:");
  display.setCursor(90,29); display.print ("6");
  display.setCursor(0,38);  display.print (">DIAMETER [mm]:");
  display.setCursor(90,38); display.print ("9999");
  refresh();
}

if (pic == 12)
{
  header();
  display.setCursor(0,11);  display.print ("DATA RECORD");
  display.setCursor(0,20);  display.print ("M-CARDIAL INFR.");
  display.setCursor(0,29);  display.print ("MA.TACHYCARDIA");
  display.setCursor(0,38);  display.print ("M ISCHAEMIA");
  display.setCursor(0,47);  display.print ("VAL3");
  display.setCursor(0,56);  display.print ("VAL4");
  refresh();
}

if (pic == 13)
{
  header();
  display.setCursor(0,11);  display.print ("DISPLAY");
//  display.setCursor(0,20);  display.print ("VAL0");
//  display.setCursor(0,29);  display.print ("VAL1");
//  display.setCursor(0,38);  display.print ("VAL2");
   display.setCursor(0,20);  display.print ("M-CARDIAL INFR.");
  display.setCursor(0,29);  display.print ("MA.TACHYCARDIA");
  display.setCursor(0,38);  display.print ("M ISCHAEMIA");
  display.setCursor(0,47);  display.print ("VAL3");
  display.setCursor(0,56);  display.print ("VAL4");
  refresh();
}

if (pic == 14)
{
  header();
  display.setCursor(0,11);  display.print ("HELP");
 display.setCursor(0,20);  display.print ("Connect");
  display.setCursor(0,29);  display.print ("RA- R.Arm");
  display.setCursor(0,38);  display.print ("LA- L.Arm");
 display.setCursor(0,47);  display.print ("RL- R.Leg");
//
//
//   display.setCursor(0,20);  display.print ("M-CARDIAL INFR.");
//  display.setCursor(0,29);  display.print ("MA.TACHYCARDIA");
//  display.setCursor(0,38);  display.print ("M ISCHAEMIA");
//  display.setCursor(0,47);  display.print ("VAL3");
//  display.setCursor(0,56);  display.print ("VAL4");
  refresh();
}

if (pic == 15)
{
  header();
  display.setCursor(0,11);  display.print ("PROJECT INFO");
  display.setCursor(0,20);  display.print ("NAME: ");
  display.setCursor(50,20); display.print ("P-ECG");
  display.setCursor(0,29);  display.print ("DATE:");
  display.setCursor(50,29); display.print ("2022-JUL-7");
  display.setCursor(0,38);  display.print ("BY:");
  display.setCursor(50,38); display.print ("GROUP 05");
  refresh();
}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void click(){
  lastmillis = millis();
  if(pic>=0 && pic<10)
  {
    if (pic >= maxPics_L1)
    {
      pic=1;
    }
    else if(pic < maxPics_L1)
    {
      pic++;
    }
  }

  if(pic>=10 && pic<100)
  {
    if (pic > 30)
    {
      pic=11;
    }
    else if (pic < 30)
    {
      pic=pic+10;
    }
  }
}

void doubleclick(){
  lastmillis = millis();
  if (pic == 11 || pic == 21 || pic == 31) pic=1;
  if (pic == 12) pic=2;
  if (pic == 13) pic=3;
  if (pic == 14) pic=4;
  if (pic == 15) pic=5;
}

void longPressStart(){
  lastmillis = millis();
  if (pic>0 & pic<10)
  {
    pic=pic+10;
  }
}

void longPressStop(){
    ;
}

void header()
{
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(22,0);  display.print("P-ECG");
  display.drawLine (0,9,128,9, WHITE);
}

void refresh()
{
  display.display();
  delay(00);
  display.clearDisplay();
}
