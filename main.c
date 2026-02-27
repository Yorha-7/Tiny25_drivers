#include "config.h"
#include <stdint.h>

volatile uint8_t delay = 15;

int main(){

uint8_t Pin_1 = 3;
uint8_t Pin_2 = 1;

//    volatile uint8_t i;
//    initialize();
    // Pin 0 is Output
    // Pin 4 in Output
    pinMode(0,'O');
    pinMode(2,'I');
//    Delay(delay);

    while(1) {

	confADC(Pin_1);
	beginADC();
	readAnalog();
	Delay(delay);
	confADC(Pin_2);
	beginADC();
	readAnalog();
//	PTR = digitalRead(4);         // for debug purposes
	if (digitalRead(2))
		digitalWrite(0,1);
	else digitalWrite(0,0);
	Delay(delay);
	}
}
