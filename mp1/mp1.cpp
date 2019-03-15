#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>

#include "cs225/PNG.h"
//#include "cs225/HSLAPixel.h"
#include "mp1.h"
using namespace cs225;
using namespace std;

PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    return image;
}


void rotate(std::string inputFile, std::string outputFile) {
  PNG* original = new PNG();
  original->readFromFile(inputFile);
  unsigned width = original->width();
  unsigned height = original->height();

  PNG* output;
  output = setupOutput(width, height);

  for (unsigned x = 0; x < width; x++) {
      for (unsigned y = 0; y < height; y++) {
          // Calculate the pixel difference

        *(output->getPixel(width-1-x,height-1-y)) = *(original->getPixel(x,y));
      }
      //std::cout << y << std::endl;
  }
  //std::cout << "line 56" << std::endl;

  // Save the output file
  output->writeToFile(outputFile);
  delete original;
  delete output;

}
