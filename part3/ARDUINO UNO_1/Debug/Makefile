###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = Arduino Uno
COMPILER = "Arduino AVR (Proteus)"
TARGET = Debug
SHELL = C:\Windows\system32\cmd.exe

## Tools general options
APPFLAGS=-C pro328 -T -std=gnu++11 -T -fno-threadsafe-statics -N atmega328p -F 16000000 -U "D:/Program Files (x86)/Labcenter Electronics/Proteus 8 Professional/DATA/VSM Studio/drivers/Arduino"
CCFLAGS=-Wall -gdwarf-2 -fno-exceptions -ffunction-sections -fdata-sections -DF_CPU=16000000 -I .. -I "D:/Program Files (x86)/Labcenter Electronics/Proteus 8 Professional/DATA/VSM Studio/drivers/Arduino" -DARDUINO_ARCH_AVR @arduino/libs.inc -std=gnu++11 -fno-threadsafe-statics -O0 -mmcu=atmega328p
LDFLAGS=-Wl,--gc-sections -lm -mmcu=atmega328p

## Processing Tools
FLOWCHART=
APP=mksketch
CC=avr-gcc
ASM=avr-gcc
LD=avr-gcc
#  C:/Users/Elecomp/AppData/Local/Temp/VSM Studio/8a5139eb4b5346cf941b876d20f7778d/ARDUINO UNO_1/Debug/Debug.elf: TOOL=LD
#  Post: avr-objcopy -O ihex -R .eeprom "./Debug.elf" "./Debug.hex"
#  Post: avr-objcopy -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 --no-change-warnings -O ihex "./Debug.elf" "./Debug.eep" || exit 0 
#     C:/Users/Elecomp/AppData/Local/Temp/VSM Studio/8a5139eb4b5346cf941b876d20f7778d/ARDUINO UNO_1/Debug/main.o: TOOL=CC
#        C:/Users/Elecomp/AppData/Local/Temp/VSM Studio/8a5139eb4b5346cf941b876d20f7778d/ARDUINO UNO_1/Debug/main.cpp: TOOL=APP
#        Post: make -f arduino/Makefile all
#           C:/Users/Elecomp/AppData/Local/Temp/VSM Studio/8a5139eb4b5346cf941b876d20f7778d/ARDUINO UNO_1/main.ino

# Build tree:
all:	Debug

Debug:	Debug.elf
	avr-size "Debug.ELF"

Debug.elf:	main.o 
	$(LD) $(LDFLAGS)  -o "./Debug.elf" "main.o" arduino/arduino.a -lm
	avr-objcopy -O ihex -R .eeprom "./Debug.elf" "./Debug.hex"
	avr-objcopy -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 --no-change-warnings -O ihex "./Debug.elf" "./Debug.eep" || exit 0 

main.o:	main.cpp 
	$(CC) $(CCFLAGS)  -o "main.o" -c "main.cpp"

main.cpp:	../main.ino 
	$(APP) $(APPFLAGS)  -A "D:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\Tools\Arduino" -O main.cpp "../main.ino"
	make -f arduino/Makefile all

# bootloader - attach bootloader to the firmware
bootloader:
	avr-objcopy -O ihex -R .eeprom "./Debug.elf" "./Debug.hex"
	copy /b bootloader.hex+"./Debug.hex" "with.bootloader.hex"

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf ./main.d
	-make -f arduino/Makefile tidy

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.elf
	rm -rf main.o
	rm -rf main.cpp
	-make -f arduino/Makefile clean
