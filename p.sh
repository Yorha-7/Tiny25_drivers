avr-gcc -s -mmcu=attiny25 main.c config.c -o main.elf
avr-objcopy -O ihex main.elf main.hex
