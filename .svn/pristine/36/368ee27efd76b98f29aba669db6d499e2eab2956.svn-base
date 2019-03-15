
#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;

BFS::~BFS(){
}

/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 */
BFS::BFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  pngg = png;
  startt = start;
  tolerancee = tolerance;
  qq.push(startt);
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */
  ImageTraversal *ptr = new BFS(pngg, startt, tolerancee);
  return Iterator(pngg, startt, tolerancee, ptr);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
  return Iterator(pngg, startt, tolerancee, NULL);
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) {
  /** @todo [Part 1] */
  qq.push(point);
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {
  /** @todo [Part 1] */
    Point front = qq.front();
    qq.pop();
    return front;
}

/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {
  /** @todo [Part 1] */
  return qq.front();
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  /** @todo [Part 1] */
  if (qq.empty())
    return true;
  else return false;
}
