#include<stdint.h>
#include"config.h"

// Define registers manually
uint8_t data = 0xEE;

int main()
{
	while(1){
		I2C_transmit(data);
		Delay(15);
	}
}
