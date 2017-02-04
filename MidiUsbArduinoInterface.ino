/***
 *         __  __ ___ ____ ___   _   _ ____  ____
 * __/\__ |  \/  |_ _|  _ \_ _| | | | / ___|| __ )
 * \    / | |\/| || || | | | |  | | | \___ \|  _ \
 * /_  _\ | |  | || || |_| | |  | |_| |___) | |_) |
 *   \/   |_|  |_|___|____/___|  \___/|____/|____/
 *    ___       _             __
 *   |_ _|_ __ | |_ ___ _ __ / _| __ _  ___ ___
 *    | || '_ \| __/ _ \ '__| |_ / _` |/ __/ _ \
 *    | || | | | ||  __/ |  |  _| (_| | (_|  __/
 *   |___|_| |_|\__\___|_|  |_|  \__,_|\___\___|
 *
 *  Midi to USB Interface
 *
 *  Autor: Artiom FEDOROV
 *  Licence: Mit
 *
 *  Allow you to interface a midi device output with a usb midi
 *  recongnized as a standart midi device on your computer
 *
 *  Works with arduino series boards
 *  Tested on a Teensy 2 ++
 *
 *  Midi input through optocoupler must be connected on :
 *    - Teensy2++ :  PIN 2
 *    - Teensy1++ :  PIN 2
 *    - Teensy2 :    PIN 7
 *    - Teensy1 :    PIN 2
 *    - Teensy3-3.6 : PIN 0
 *    - TeensyLC :    PIN 0
 */

#include <MIDI.h>

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() {
  if (MIDI.read()) {
    switch (MIDI.getType()) {
      case NoteOn:
        usbMIDI.sendNoteOn(MIDI.getData1(), MIDI.getData2(), MIDI.getChannel());
        break;
      case NoteOff:
        usbMIDI.sendNoteOff(MIDI.getData1(), MIDI.getData2(), MIDI.getChannel());
        break;
      case AfterTouchPoly:
        usbMIDI.sendAfterTouch(MIDI.getData1(), MIDI.getChannel());
        break;
      case PitchBend:
        usbMIDI.sendPitchBend(MIDI.getData1(), MIDI.getChannel());
        break;
      case ProgramChange:
        usbMIDI.sendProgramChange(MIDI.getData1(), MIDI.getChannel());
        break;
    }
  }
}
