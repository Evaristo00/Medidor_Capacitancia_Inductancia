###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = STM32F103T6
COMPILER = "Keil for ARM"
TARGET = Debug
SHELL = C:\WINDOWS\system32\cmd.exe

## Tools general options
ASMFLAGS=--cpu=cortex-m3 --thumb -g
CCFLAGS=--cpu=cortex-m3 --thumb -I.. -IC:/Keil_v5/ARM/CMSIS/Include -g
LDFLAGS=--scatter ../stm32f103x6.sct

## Processing Tools
CC=armcc.exe
LD=armlink.exe
ASM=armasm.exe
BIN2HEX=fromelf.exe
#  G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/Debug/Debug.elf: TOOL=LD
#     G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/Debug/main.o: TOOL=CC
#        G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/main.c
#     G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/Debug/system_stm32f1xx.o: TOOL=CC
#        G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/system_stm32f1xx.c
#     G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/Debug/startup_stm32f103.o: TOOL=ASM
#        G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/startup_stm32f103.s
#     G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/Debug/lcd.o: TOOL=CC
#        G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/lcd.c
#     G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/Debug/delay.o: TOOL=CC
#        G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/delay.c
#     G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/Debug/rlc.o: TOOL=CC
#        G:/Mi unidad/Ing Computacion/Facultad/Cuarto a�o/Taller de proyecto I/Practica/TP3/Proteus/Medidor_Capacitancia_Inductancia/STM32F103T6/rlc.c

# Build tree:
all:	Debug

Debug:	Debug.elf

Debug.elf:	main.o system_stm32f1xx.o startup_stm32f103.o lcd.o delay.o rlc.o 
	$(LD)  $(LDFLAGS)  "main.o" "system_stm32f1xx.o" "startup_stm32f103.o" "lcd.o" "delay.o" "rlc.o" --output "Debug.elf"

main.o:	../main.c 
	$(CC) $(CCFLAGS)  "../main.c" -c -o "main.o"

system_stm32f1xx.o:	../system_stm32f1xx.c 
	$(CC) $(CCFLAGS)  "../system_stm32f1xx.c" -c -o "system_stm32f1xx.o"

startup_stm32f103.o:	../startup_stm32f103.s 
	$(ASM) $(ASMFLAGS)  "../startup_stm32f103.s" -o "startup_stm32f103.o"

lcd.o:	../lcd.c 
	$(CC) $(CCFLAGS)  "../lcd.c" -c -o "lcd.o"

delay.o:	../delay.c 
	$(CC) $(CCFLAGS)  "../delay.c" -c -o "delay.o"

rlc.o:	../rlc.c 
	$(CC) $(CCFLAGS)  "../rlc.c" -c -o "rlc.o"

# tidy - delete all temporary files which are not involved in the target generation
tidy:

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.elf
	rm -rf main.o
	rm -rf system_stm32f1xx.o
	rm -rf startup_stm32f103.o
	rm -rf lcd.o
	rm -rf delay.o
	rm -rf rlc.o
