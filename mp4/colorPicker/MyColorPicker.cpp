#include "../cs225/HSLAPixel.h"
#include "../Point.h"
#include <cmath>

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;
MyColorPicker::MyColorPicker(Point p){


}
/**
 * Picks the color for pixel (x, y).
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {

  double dx = x - p.x;
  double dy = y - p.y;
  double d = sqrt((dx * dx) + (dy * dy));
  double a = 30;
    if(d>p.x){
      double a=3;
    }
  /* @todo [Part 3] */
  return HSLAPixel(a,1,0.5);
}
