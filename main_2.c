#include<stdint.h>
#include"config.h"

// Define registers manually
uint8_t data = 0x67;

int main()
{
	while(1){
		I2C_transmit(data);
		Delay(15);
		I2C_transmit(data + 0x11);
		Delay(15);
		I2C_transmit(data + 0x78);
		Delay(15);
	}
}
