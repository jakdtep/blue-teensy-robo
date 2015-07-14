TEENSYTOOLS = ~/arduino-1.6.4/hardware/tools
TOOLSBIN = $(TEENSYTOOLS)/arm/bin/

CDEPS := Makefile $(wildcard lib/*.c) $(wildcard lib/*.h)

TARGET = blue_robo

CINCLUDES = /home/jak/arduino-1.6.4/hardware/teensy/avr/cores/teensy3/
OPTIONS = -DF_CPU=48000000 -DUSB_SERIAL -D__MK20DX256__
CFLAGS = -Wall -g -Os -mcpu=cortex-m4 -mthumb -nostdlib -fno-strict-aliasing -Ilib $(OPTIONS)
CXXFLAGS = -std=gnu++0x -felide-constructors -fno-exceptions -fno-rtti $(OPTIONS)
LDFLAGS = -Os -Wl,--gc-sections -Wl,--relax -mcpu=cortex-m4 -mthumb -Tlib/mk20dx256.ld
LIBS = -lm


CC = $(TOOLSBIN)arm-none-eabi-gcc
AR = $(TOOLSBIN)arm-none-eabi-ar
SIZE = $(TOOLSBIN)arm-none-eabi-size
OBJCOPY = $(TOOLSBIN)arm-none-eabi-objcopy

export OPTIONS CFLAGS CXXFLAGS TOOLSBIN CC CXX AR

DEPS = $(CDEPS)
SOURCES = blue_robo.c

all: $(TARGET).hex

$(TARGET).elf: $(SOURCES) $(DEPS) lib/mk20dx256.ld lib/core.a
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(CINCLUDES) -flto -flto-partition=none -fwhole-program  -o $@ $(SOURCES) $(LIBS) lib/core.a

%.hex: %.elf
	$(SIZE) $<
	$(OBJCOPY) -O ihex -R .eeprom $< $@

clean:
	$(MAKE) -C lib clean
	-rm -rf *.o $(TARGET).elf $(TARGET).hex

objdump: $(TARGET).elf
	$(TOOLSBIN)arm-none-eabi-objdump -xdC $(TARGET).elf | less
