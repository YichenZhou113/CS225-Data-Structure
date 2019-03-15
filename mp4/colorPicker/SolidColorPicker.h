#ifndef SolidColorPicker_H
#define SolidColorPicker_H

#include "ColorPicker.h"
#include "../cs225/HSLAPixel.h"
#include "../Point.h"

using namespace cs225;

class SolidColorPicker : public ColorPicker {
public:
  SolidColorPicker(HSLAPixel color);
  HSLAPixel getColor(unsigned x, unsigned y);

private:
  HSLAPixel color;
};

#endif
