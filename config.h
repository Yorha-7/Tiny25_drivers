#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

//Digital Parameters
#define PORTB   (*(volatile uint8_t*) 0x38)
#define DDRB    (*(volatile uint8_t*) 0x37)
#define PINB    (*(volatile uint8_t*) 0x36)
#define PTR_1   (*(volatile uint8_t*) 0xC0)
#define PTR_2   (*(volatile uint8_t*) 0xC1)
//Analog Parameters
#define ADCSRA (*(volatile uint8_t*) 0x26)
#define ADMUX  (*(volatile uint8_t*) 0x27)
#define ADCH   (*(volatile uint8_t*) 0x25)
#define ADCL   (*(volatile uint8_t*) 0x24)

//Analog functions
void confADC(uint8_t a);
void beginADC();
void readAnalog();

void initialize();
void pinMode( uint8_t Pin, char M );
void Delay( uint8_t time );
uint8_t digitalRead( uint8_t Pin );
void digitalWrite( uint8_t Pin, uint8_t Value );

// USI Communication
#define USIDR (*(volatile uint8_t*) 0x2f)
#define USISR (*(volatile uint8_t*) 0x2e)
#define USICR (*(volatile uint8_t*) 0x2d)
#define USIBR (*(volatile uint8_t*) 0x30)
// USI communication
void USI_transmit(uint8_t data);

#endif
