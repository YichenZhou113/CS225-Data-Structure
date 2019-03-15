/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */
#include <cmath>
#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
    /**
     * This is the function to go through the tiles, which are the image with the nearest color of that region on the mosaic canvas. I first push the points into vector and then compare to find the nearest whendoing the traverse.
     */
     MosaicCanvas* ret = new MosaicCanvas(theSource.getRows(),theSource.getColumns());
     HSLAPixel pix;
	   Point<3> point1;
	   vector<Point<3>> stack;
	   map<Point<3>, TileImage*> mapt;
     int i = 0;
     while(i<int(theTiles.size())){
       pix = theTiles[i].getAverageColor();
		   point1 = Point<3>(pix.h/360, pix.s, pix.l);
		   stack.push_back(point1);
		   TileImage* mapp = new TileImage(theTiles[i]);
       mapt[point1] = mapp;
		   i++;
     }
     KDTree<3> kd(stack);
	   int x = 0;
	   while(x<theSource.getRows()){
		   int y = 0;
		   while(y<theSource.getColumns()){
			   pix = theSource.getRegionColor(x,y);
			   point1 = Point<3>(pix.h/360, pix.s, pix.l);
			   point1 = kd.findNearestNeighbor(point1);
			   ret->setTile(x, y, mapt[point1]);
			  y++;
		   }
		   x++;
	   }
	   return ret;

}
