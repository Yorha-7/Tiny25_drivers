#include "config.h"

void initialize() {
    PORTB = 0x00;
    DDRB  = 0x00;
    PINB  = 0x00;
}

void pinMode(uint8_t Pin, char M){
	if (M == 'O'){
		DDRB |= (1 << Pin);
	}
	if (M == 'I'){
		DDRB &= ~(1 << Pin);
	}
}

uint8_t digitalRead(uint8_t Pin){
	return ((PINB & (1 << Pin)) >> Pin);
}

void digitalWrite(uint8_t Pin, uint8_t Value){
	if (Value) PORTB |=  ((0x00 +  Value) << Pin);
	else       PORTB &= ~((0x00 + ~Value) << Pin);
}

void Delay(uint8_t time){
	float t_units = time/0.325;
	uint8_t units = (uint8_t) t_units;
	uint8_t i;
	for (i = 0; i < units; i++){}
}

void confADC(uint8_t a){
	ADCSRA = (uint8_t) 0x00;
	switch(a){
		case 1:     ADMUX = (uint8_t) 0x21;
			    break;
		case 2:     ADMUX = (uint8_t) 0x22;
			    break;
		case 3:     ADMUX = (uint8_t) 0x23;
			    break;
		default:    ADMUX = (uint8_t) 0x00;
	}
}

void beginADC(){
	ADCSRA = (uint8_t) 0x80;
	Delay(15);
	ADCSRA = (uint8_t) 0xC0;
}

void readAnalog(){
	while((ADCSRA & 0x10) != 0x10) { PTR_1 = (ADCSRA & 0x10); }
	PTR_2 = ADCL;
	PTR_1 = ADCH;
}

// USI Communication

void USI_transmit(uint8_t data){
	PORTB = 0x04;
	DDRB  = 0x04;
	USIDR = data;
	USISR = 0x40;
	do {
        	USICR = 0x1B;
		PTR_1 = USIBR;
    	}
    	while (!(USISR & (1<<6)));
}

void I2C_transmit(uint8_t data){
//	MCUCR |= 0x00;  // 0x40 to set pull ups.
	PORTB  = 0x05;	// 0x05 pull up value
	DDRB   = 0x05;
	USIDR  = (0xFE & data);
	USISR  = 0x40;
	PTR_1  = USIDR;
	do {
		USICR = 0x2B;
//		PTR_1 = USIBR;
	}
	while (!(USISR & (1<<6)));
//	DDRB  = 0x04;
//	USISR = 0x40;
//	PORTB = 0x05;
//	do {
//		USICR = 0x2B;
//		PTR_1 = USIBR;
//	}
//	while (!(USISR & (1<<6)));
//	USISR = 0x40;
//	USICR = 0x2B;
//	DDRB  = 0xFE;
//	while (!(USISR & (1<<6)));
//	PTR_2 = USIDR;
}

