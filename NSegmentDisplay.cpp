#include "Arduino.h"
#include "NSegmentDisplay.h"
/*
Create instance of display, argumnets:
1) common anode or not
2) number of segment pins
3) array of segment pins, first 7 in conventional order (A-F) for number segments if numbers wanted
*   A
* F   B
*   G
* E   C
*   D 
4) number of digit pins
5) array of digit pins, rightmost digit first
*/
NSegmentDisplay::NSegmentDisplay(bool common_anode, const int numSegPins, const int * segPins,const int numDigPins, const int * digPins)
{
  _common_anode = common_anode;
  _numSegPins = numSegPins;
  _segPins = segPins;
  _numDigPins = numDigPins;
  _digPins = digPins;
  for(int i = 0; i<_numSegPins; i++) {
    pinMode(_segPins[i],OUTPUT);
  }
  for(int i = 0; i<_numDigPins; i++) {
    pinMode(_digPins[i],OUTPUT);
  }
}

void NSegmentDisplay::segment(int d, int s, int duration) {
  off(1);
  if(_common_anode) {
    digitalWrite(_digPins[d], HIGH);
    digitalWrite(_segPins[s], LOW);
    delay(duration);
    digitalWrite(_digPins[d], LOW);
    digitalWrite(_segPins[s], HIGH);
  } else {
    digitalWrite(_digPins[d], LOW);
    digitalWrite(_segPins[s], HIGH);
    delay(duration);
    digitalWrite(_digPins[d], HIGH);
    digitalWrite(_segPins[s], LOW);
  }
}

void NSegmentDisplay::blink(int speed) {
  on(speed);
  off(speed);
}

void NSegmentDisplay::on(int duration)
{
  for(int j = 0; j<duration / (5 * _numDigPins); j++) {
    for (int i = 0; i < _numSegPins; i++) {
      if(_common_anode) {
        digitalWrite(_segPins[i], LOW);
      } else {
        digitalWrite(_segPins[i], HIGH);
      }
    }
    for (int i = 0; i < _numDigPins; i++) {
      if(_common_anode) {
        digitalWrite(_digPins[i], HIGH);
      } else {
        digitalWrite(_digPins[i], LOW);
      }
      delay(5);
      if(_common_anode) {
        digitalWrite(_digPins[i], LOW);
      } else {
        digitalWrite(_digPins[i], HIGH);
      }
    } 
  } 
}

void NSegmentDisplay::off(int duration)
{
  for (int i = 0; i < _numSegPins; i++) {
    if(_common_anode) {
      digitalWrite(_segPins[i], HIGH);
    } else {
      digitalWrite(_segPins[i], LOW);
    }
  }
  for (int i = 0; i < _numDigPins; i++) {
    if(_common_anode) {
      digitalWrite(_digPins[i], LOW);
    } else {
      digitalWrite(_digPins[i], HIGH);
    }
  } 
  delay(duration);
}

void NSegmentDisplay::number(int d, int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(_segPins[i], numbers[num][i]);
  }
  for (int j = 0; j < _numDigPins; j++) {
    if (j == d) {
      digitalWrite(_digPins[j], LOW);
    } else {
      digitalWrite(_digPins[j], HIGH);
    }
  }
  delay(5);
}

void NSegmentDisplay::crazyEights(int speed) {
  int segs[] = {0, 1, 6, 4, 3, 2, 6, 5};
  for (int i = 0; i < _numSegPins; i++) {
    if(_common_anode) {
      digitalWrite(_segPins[segs[i]], LOW);
    } else {
      digitalWrite(_segPins[segs[i]], HIGH);
    }
    delay(speed);
    if(_common_anode) {
      digitalWrite(_segPins[segs[i]], HIGH);
    } else {
      digitalWrite(_segPins[segs[i]], LOW);
    }      
  }
  for (int i = 0; i < _numDigPins; i++) {
    if(_common_anode) {
      digitalWrite(_digPins[i], HIGH);
    } else {
      digitalWrite(_digPins[i], LOW);
    }
  }
}
