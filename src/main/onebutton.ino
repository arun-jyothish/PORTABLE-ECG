/**
 * FunctionalButton.ino - Example for the OneButtonLibrary library.
 * This is a sample sketch to show how to use OneClick library functionally on ESP32,ESP8266... 

 * 
 */
#include <Arduino.h>
#include <OneButton.h>
#include <filters.h>

#define button_pin D4
int ecg_signal  = 0 ; 
unsigned long int endtime =0; 
unsigned long int starttime = 0;
String Ecg_data ="data: ";
bool flag = false;
const float cutoff_freq   = 17.0;  //Cutoff frequency in Hz
const float sampling_time = 0.007; //Sampling time in seconds.

//int count =0 ;/
IIR::ORDER  order  = IIR::ORDER::OD4; // Order (OD1 to OD4)

// Low-pass filter
Filter f(cutoff_freq, sampling_time, order);

//unsigned long int timer = millis();/

class Button{
	private:
		OneButton button;
		int value;
	public:
		explicit Button(uint8_t pin):button(pin) {
			button.attachClick([](void *scope) { ((Button *) scope)->Clicked();}, this);
		}

		void Clicked(){
			Ecg_data = "data : ";
			flag = true;
			int init_delay = 5000;
			int end_delay = 10000;
			starttime = millis() + init_delay;
			endtime= millis() + end_delay;
			Serial.print("start time: ");
			Serial.print("end time: ");
			Serial.println(starttime);
			Serial.println(endtime);
		}

		void handle(){
			button.tick();
		}
};

Button button(button_pin);

void setup() {
	pinMode(4,INPUT_PULLUP);
	Serial.begin(9600);
}

void loop() {
	button.handle();
	unsigned long int Current_time= millis();
	if (starttime < Current_time && Current_time < endtime)
	{

		int filtered_val = f.filterIn(analogRead(A0));
		Ecg_data += (String)(filtered_val) +",";
    
//    count ++;/
//		Serial.print("Count data: ");/
//		Serial.println(count);/
	}

	if ( Current_time > endtime && flag)
	{
		// push code
		Serial.println(Ecg_data);
		flag = false;
	}
	//Serial.println(Current_time);/
}
