
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  PNG png;      png.readFromFile("CS_Logo.png");

  FloodFilledImage image(png);
  BFS bfs(png, Point(60, 60), 0.05);
  MyColorPicker mycolorpicker(Point(90,90));
  image.addFloodFill( bfs, mycolorpicker );
  MyColorPicker myc1(Point(300,300));
  image.addFloodFill( bfs, myc1);
  Animation animation = image.animate(1000);
  PNG secondFrame = animation.getFrame(1);
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );

  secondFrame.writeToFile("mycolor.png");
  lastFrame.writeToFile("mycolor.png");
  animation.write("mycolor.gif");
  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.

  /*
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");
  */

  return 0;
}
