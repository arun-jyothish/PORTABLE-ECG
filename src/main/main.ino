/**
 * FunctionalButton.ino - Example for the OneButtonLibrary library.
 * This is a sample sketch to show how to use OneClick library functionally on ESP32,ESP8266... 
 * 
 */
#include <Arduino.h>
#include <OneButton.h>
#include <filters.h>
int ecg_signal  = 0 ; 
unsigned long int endtime =0; 
unsigned long int starttime = 0;
String Ecg_data ="";

const float cutoff_freq   = 17.0;  //Cutoff frequency in Hz
const float sampling_time = 0.007; //Sampling time in seconds.
IIR::ORDER  order  = IIR::ORDER::OD4; // Order (OD1 to OD4)

// Low-pass filter
Filter f(cutoff_freq, sampling_time, order);

unsigned long int timer = millis();
int init_delay = 5000;

class Button{
  private:
    OneButton button;
    int value;
  public:
    explicit Button(uint8_t pin):button(pin) {
      button.attachClick([](void *scope) { ((Button *) scope)->Clicked();}, this);
    }

    void Clicked(){
      starttime = millis() + 5000;
      endtime= millis() + 15000;
    }

    void handle(){
      button.tick();
    }
};

Button button(0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  button.handle();
  time = millis();
  if (starttime < time && time < endtime)
  {
    
    Ecg_data += (String)(f.filterIn(analogRead(A0));
  }

if ( time > endtime )
{
  // push code
  Serial.println(Ecg_date);
}

}
