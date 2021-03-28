## Description
This directory contains the program that demonstrate basic I/O using timer and button interrupts.

Program | Description
------- | -----------
Blink   | Uses timer interrupts to flash the LEDs in a silly pattern.
Button  | Uses interrupts to detect when a switch is pressed or released.
Buzzer  | Emits a single continuous note from the buzzer.

## How to Use

The Makefile in this direcory contains rules to run the Makefile in each demo directory. Use **make** in this directory to build all demo programs and the timer library. Once the programs are built, you can load the program onto the MSP430 by changing into the blink_buzz directory and using **make load**.

You may use **mspdebug rf2500 "erase"** to clear a program from the MSP430.

---------------------------------------------------------------------------------------------------

Different patterns available in my project

Switch | Pattern
-------|--------
  1    | LEDs toggle and the B-flat major scale plays 
  2    | LEDs turn on in binary from 0-3 then 3-0 and an arpeggio plays up and down
  3    | Plays a race countdown sound and the red LED blinks 3 times then the green LED lights up
  4    | LEDs flash together on and off repeatedly and a siren begins to play
