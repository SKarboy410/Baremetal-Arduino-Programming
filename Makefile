# Project settings
PROGRAM_NAME = blink
BUILD_DIR    = build
PORT         = /dev/ttyUSB0   # Change if your board shows up as /dev/ttyACM0

# MCU / toolchain settings
MCU   = atmega328p
F_CPU = 16000000UL

CC      = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Wall -Os -MMD -MP
LDFLAGS = -mmcu=$(MCU)

# Source files: all .c files in the current directory
SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

# Default target
all: $(BUILD_DIR)/$(PROGRAM_NAME).elf $(BUILD_DIR)/$(PROGRAM_NAME).hex

$(BUILD_DIR):
	mkdir -pv $(BUILD_DIR)

# Compile each .c into .o inside build/
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link all objects into ELF
$(BUILD_DIR)/$(PROGRAM_NAME).elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Create HEX from ELF
$(BUILD_DIR)/$(PROGRAM_NAME).hex: $(BUILD_DIR)/$(PROGRAM_NAME).elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

# Upload to the board
upload: $(BUILD_DIR)/$(PROGRAM_NAME).hex
	$(AVRDUDE) -c arduino -p m328p -P $(PORT) -b 115200 -U flash:w:$<

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all upload clean

# Include auto-generated dependency files
-include $(DEPS)
