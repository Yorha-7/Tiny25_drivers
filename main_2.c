#include<stdint.h>
#include"config.h"

// Define registers manually
uint8_t data = 0x67;

int main()
{
	while(1){
		USI_transmit(data);
		Delay(15);
		USI_transmit(data + 0x11);
		Delay(15);
		USI_transmit(data + 0x78);
		Delay(15);
	}
}
