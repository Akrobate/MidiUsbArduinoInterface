
            __  __ ___ ____ ___   _   _ ____  ____
    __/\__ |  \/  |_ _|  _ \_ _| | | | / ___|| __ )
    \    / | |\/| || || | | | |  | | | \___ \|  _ \
    /_  _\ | |  | || || |_| | |  | |_| |___) | |_) |
      \/   |_|  |_|___|____/___|  \___/|____/|____/
       ___       _             __
      |_ _|_ __ | |_ ___ _ __ / _| __ _  ___ ___
       | || '_ \| __/ _ \ '__| |_ / _` |/ __/ _ \
       | || | | | ||  __/ |  |  _| (_| | (_|  __/
      |___|_| |_|\__\___|_|  |_|  \__,_|\___\___|


# Midi to USB Arduino Interface

## Introduction

This program allow you to interface a midi device output with a USB midi recongnized as a standart Midi Device on your computer. You will need to get [MIDI librairy](https://www.pjrc.com/teensy/td_libs_MIDI.html) installed on your environment 

## Hardware

Works with arduino series boards
Tested on a Teensy 2 ++
Midi input through optocoupler must be connected on :

- Teensy2++ :  PIN 2
- Teensy1++ :  PIN 2
- Teensy2 :    PIN 7
- Teensy1 :    PIN 2
- Teensy3-3.6 : PIN 0
- TeensyLC :    PIN 0

## Features

Velocity, Channel, data1, data2 mapped on supported midi commands (see below)

### Supported midi commands

- NoteOn
- NoteOff
- AfterTouchPoly
- PitchBend
- ProgramChange

### Not yet supported commands
- ControlChange
- AfterTouchChannel
- SystemExclusive
