avr-gcc -s -mmcu=attiny25 main_2.c config.c -o main_2.elf
avr-objcopy -O ihex main_2.elf main_2.hex
