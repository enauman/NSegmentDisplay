#include <NSegmentDisplay.h>
//common cathode display with 8 segments
const int NUM_SEG_PINS = 8;
const int NUM_DIGIT_PINS = 4;
const int segments[] = {10, 11, 12, 6, 7, 8, 13, 9};
const int digits[] = {3, 5, 4, 2};
NSegmentDisplay disp(false, NUM_SEG_PINS, segments, NUM_DIGIT_PINS, digits);
int state = 0;
int delayTime = 500;
double lastChange = 0;

void setup() {}

void loop() {
if (state == 0) {
    disp.multiDigitNumber(96);
  } else {
    disp.off(0);
  }
  if (millis() > lastChange + delayTime) {
    state = !state;
    lastChange = millis();
  }
}
