
#include "StickerSheet.h"
#include <iostream>
#include "assert.h"
#include "StickerSheet.h"

using namespace cs225;

int main() {
  Image alma; alma.readFromFile("tests/alma.png");
  Image i;    i.readFromFile("i.png");
//  Image i;    I2.readFromFile("I2.png");
  //Image i;    I3.readFromFile("I3.png");

  StickerSheet sheet(alma, 5);
  sheet.addSticker(i, 20, 200);
  sheet.addSticker(i, 50, 90);
  sheet.addSticker(i, 180, 0);
  Image newp = sheet.render();
  newp.writeToFile("myImage.png");



  return 0;
}
