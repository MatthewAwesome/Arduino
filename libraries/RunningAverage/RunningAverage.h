//
//    FILE: RunningAverage.h
//  AUTHOR: Rob.Tillaart@gmail.com
// VERSION: 0.2.13
//    DATE: 2016-dec-01
// PURPOSE: RunningAverage library for Arduino
//     URL: https://github.com/RobTillaart/Arduino/tree/master/libraries/RunningAverage
// HISTORY: See RunningAverage.cpp
//
// Released to the public domain
//
// backwards compatibility
// clr()   clear()
// add(x)  addValue(x)
// avg()   getAverage()

// The header makes links, imports other libraries, etc.

// define it if it is not defined already:
#ifndef RunningAverage_h
#define RunningAverage_h

// define the library version string..some version control.
#define RUNNINGAVERAGE_LIB_VERSION "0.2.13"

// we want to include the Arduino library.
#include "Arduino.h"

// We instantiate a class called RunningAverage
class RunningAverage
{
// the primary member of the class is a public function, RunningAverage...its the constructor!
public:
  // The constructor here!
  RunningAverage(void);
  // Defining that the RunningAverage constructor takes an argument, an integer.
  explicit RunningAverage(const uint8_t);
    // Define the deconstructor.
  ~RunningAverage();
  // We define some functions, or methods, associated with our class (called via RunningAverageClassVariable.method()
    // void methods return nothing; they are nihilistic.
  void    clear();
  void    addValue(const float);
  void    fillValue(const float, const uint8_t);
  // when we want to return some value, we tell what kind of value, e.g. float.
  float   getAverage() const;      // does iterate over all elements.
  float   getFastAverage() const;  // reuses previous values.

  // return statistical characteristics of the running average
  float   getStandardDeviation() const;
  float   getStandardError() const;

  // returns min/max added to the data-set since last clear
  float   getMin() const { return _min; };
  float   getMax() const { return _max; };

  // returns min/max from the values in the internal buffer
  float   getMinInBuffer() const;
  float   getMaxInBuffer() const;

  // return true if buffer is full
  bool    bufferIsFull() const; //  { return _cnt == _size; };

  float   getElement(uint8_t idx) const;

  uint8_t getSize() const { return _size; }
  uint8_t getCount() const { return _cnt; }



protected:
  uint8_t _size;
  uint8_t _cnt;
  uint8_t _idx;
  float   _sum;
  float*  _ar;
  float   _min;
  float   _max;
};

#endif
// END OF FILE
