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
String Ecg_data ="data: ";

const float cutoff_freq   = 17.0;  //Cutoff frequency in Hz
const float sampling_time = 0.007; //Sampling time in seconds.
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
			int init_delay = 1000;
			int end_delay = 5000;
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

Button button(0);

void setup() {
	Serial.begin(9600);
}

void loop() {
	button.handle();
	unsigned long int Current_time= millis();
	if (starttime < Current_time && Current_time < endtime)
	{
		int filtered_val = f.filterIn(analogRead(A0));
		Ecg_data += (String)(filtered_val);
	}

if ( Current_time > endtime )
{
	// push code
	Serial.println(Ecg_data);
}
//Serial.println(Current_time);/
}
