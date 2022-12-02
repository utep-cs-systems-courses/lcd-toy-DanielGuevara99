COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS			 = -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc # C COMPILE
AS              = msp430-elf-as  # ASSEMEBLY
AR              = msp430-elf-ar

all:libLcd.a blink_buzz.elf

libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h

lcdutils.o: lcdutils.c lcdutils.h

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

blink_buzz.elf: ${COMMON_OBJECTS} buzzer.o led.o switch.o interrupts.o libLcd.a 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load: blink_buzz.elf
	msp430loader.sh blink_buzz.elf
clean:
	rm -f *.o