#ifndef NSegmentDisplay_h
#define NSegmentDisplay_h

#include "Arduino.h"

class NSegmentDisplay
{

public:
	NSegmentDisplay(bool common_anode, const int numSegPins, const int * segPins,const int numDigPins, const int * digPins);
	void on(int duration);
	void off(int duration);
	void blink(int duration);
	void number(int d, int num);
	void multiDigitNumber(int num);
	void segment(int d, int s);
	void segment(int d, int s, int duration);
	void crazyEights(int speed);
private:
	bool _common_anode;
	int _numSegPins;
	const int * _segPins;
	int _numDigPins;
	const int * _digPins;
	const int anodeNumbers[10][7] = {
	  {0, 0, 0, 0, 0, 0, 1},//0
	  {1, 0, 0, 1, 1, 1, 1},//1
	  {0, 0, 1, 0, 0, 1, 0},//2
	  {0, 0, 0, 0, 1, 1, 0},//3
	  {1, 0, 0, 1, 1, 0, 0},//4
	  {0, 1, 0, 0, 1, 0, 0},//5
	  {0, 1, 0, 0, 0, 0, 0},//6
	  {0, 0, 0, 1, 1, 1, 1},//7
	  {0, 0, 0, 0, 0, 0, 0},//8
	  {0, 0, 0, 0, 1, 0, 0}//9
	};
	const int cathodeNumbers[10][7] = {
	  {1, 1, 1, 1, 1, 1, 0},//0
	  {0, 1, 1, 0, 0, 0, 0},//1
	  {1, 1, 0, 1, 1, 0, 1},//2
	  {1, 1, 1, 1, 0, 0, 1},//3
	  {0, 1, 1, 0, 0, 1, 1},//4
	  {1, 0, 1, 1, 0, 1, 1},//5
	  {1, 0, 1, 1, 1, 1, 1},//6
	  {1, 1, 1, 0, 0, 0, 0},//7
	  {1, 1, 1, 1, 1, 1, 1},//8
	  {1, 1, 1, 1, 0, 1, 1}//9
	};
};

#endif
