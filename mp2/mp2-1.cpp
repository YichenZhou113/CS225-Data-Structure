#include "Image.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;





int main() {
  Image alma;

  alma.readFromFile("alma.png");
  alma.lighten(0.2);
  alma.writeToFile("lighten.png");

  alma.readFromFile("alma.png");
  alma.saturate(0.2);
  alma.writeToFile("saturate.png");

  alma.readFromFile("alma.png");
  alma.scale(2);
  alma.writeToFile("scale2x.png");

  return 0;
}
