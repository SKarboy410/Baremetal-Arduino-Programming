#  Baremetal Arduino Programming

This project is a part my embedded systems journey. Here I try to implement the standard Arduino library functions using just C, without any fancy abstractions. Everything here directly interacts with the actual hardware.

Atmega328p(or arduino uno) datasheet: https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf

---

##  Required Tools

If you wanna run this command then here are the steps to do it in a UNIX-like system (You can also use WSL to achieve the same on Windows).

Install the necessary libraries:

```
sudo apt install avr-gcc avr-libc binutils-avr avrdude
```

These are necessary for compiling the code and flashing/uploading the code to the MCU.

---

##  Detecting Your Arduino’s Serial Port

After installing them, you have locate the port to which your arduino is connected to.

Run one of the following:

```
ls /dev/ | grep ACM
```

or

```
ls /dev/ | grep ttyUSB
```

Whatever result you get, paste that into the PORT section of the Makefile.

---

##  Building and Uploading

To compile the project:

```
make
```

To flash/upload it to the board:

```
make upload
```

To remove build files:

```
make clean
```

---

##  Project Structure

```
/project-root
│
├── Makefile           # Builds and uploads the project
├── util.c             # Pin mapping + helper utilities
├── util.h
├── waveGen.c          # tone() + noTone() implementation
├── waveGen.h
├── blink.c            # demo application
└── .gitignore
```

---
 
Next time, I will try to add more features to the tone function and implement more of the arduino functions. I also plan to rewrite more of the core arduino(MCU in general) things such as SPI, I2C, ADC and DAC and more stuff which I don't understand. 
The long term goal which starts with this project is gain the skills to get a good embedded engineer and make cool stuff!

##  Thanks for Reading :)

