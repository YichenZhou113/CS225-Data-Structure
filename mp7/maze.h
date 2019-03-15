/* Your code here! */
#ifndef MAZE_H
#define MAZE_H

#include "dsets.h"
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include <vector>
using namespace std;
using namespace cs225;

class SquareMaze
{
public:
  SquareMaze();
  void makeMaze(int width, int height);
  bool canTravel(int x, int y, int dir) const;
  void setWall(int x, int y, int dir, bool exists);
  vector<int> solveMaze();
  PNG *drawMaze() const;
  PNG *drawMazeWithSolution();
private:
  int w;
  int h;
  struct mazeb
  {
    mazeb();
    bool visited;
    bool down;
    bool right;
  };
  mazeb ** maze;
};

#endif
