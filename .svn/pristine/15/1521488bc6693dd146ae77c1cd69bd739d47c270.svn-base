#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"

/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 */
 DFS::~DFS(){

 }

DFS::DFS(const PNG & png, const Point & start, double tolerance) {
  pngg = png;
  startt = start;
  tolerancee = tolerance;
  stackk.push(startt);
  /** @todo [Part 1] */
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  ImageTraversal *ptr = new DFS(pngg, startt, tolerancee);
  return Iterator(pngg, startt, tolerancee, ptr);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return Iterator(pngg, startt, tolerancee, NULL);
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  stackk.push(point);
  /** @todo [Part 1] */
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  Point p = stackk.top();
  stackk.pop();
  return p;
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  return stackk.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  if (stackk.empty())
    return true;
  else return false;
}
