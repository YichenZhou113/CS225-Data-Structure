/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
 #include <cmath>
 #include <iostream>
 using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * This function returns a bool expression of whether the dimension of the first Point is smaller or equal to the second Point.
     */
     if(first[curDim]<=second[curDim]){
       return true;
     }else{
       return false;
     }

}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * This function determines whether should replace the currentbest point with the potential best point based on their distance to the target.
     */
     double d1=0;
     double d2=0;
     for(int i=0;i<Dim;i++){
       d1 += pow((target[i]-currentBest[i]),2);
       d2 += pow((potential[i]-target[i]),2);
     }
     if(d2<d1){
       return true;
     }else if(d2==d1){
       return (potential<currentBest);
     }else{
     return false;
   }
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * This function calls a helper function of building a KDTree.
     */
    points=newPoints;
    builder(0,points.size()-1,0);
}

template <int Dim>
void KDTree<Dim>::builder(int left, int right, int dimension) {
  /* This is the helper function using recursive method to build trees on both sides depending on the left and right boundaries.
   */
  int median = (left+right)/2;
  quickselect(dimension,left,right,median);
  if(left<median-1){
    builder(left,median-1,(dimension+1)%Dim);
  }
  if(right>median+1){
    builder(median+1,right,(dimension+1)%Dim);
  }
}

template<int Dim>
int KDTree<Dim>::partition(int dimension, int left, int right, int pivotIndex)
{
  /*This is the helper function for implementing the quickselect method. It is used to partition a the points of certain dimension based on whether bigger or smaller than the current one and return the median.
  */
    Point<Dim> pivotValue = points[pivotIndex];
    swap(points[pivotIndex], points[right]);
    int storeIndex = left;
    for(int i = left; i <= right-1; i++)
    {
        if(smallerDimVal(points[i], pivotValue, dimension))
        {
            swap(points[storeIndex], points[i]);
            storeIndex++;
        }
    }
    swap(points[right], points[storeIndex]);
    return storeIndex;
}

template<int Dim>
void KDTree<Dim>::quickselect(int dimension, int left, int right, int k){
  /*
  This is the function to sort the points recursively.
  */
  if (left >= right){
    return;
  }
   int pivotIndex=(left+right)/2;
   pivotIndex = partition(dimension, left, right, pivotIndex);
   if(k==pivotIndex){
     return;
   }else if(k < pivotIndex){
     quickselect(dimension,left,pivotIndex-1,k);
   }else{
     quickselect(dimension,pivotIndex+1,right,k);
   }
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     This function calls for the helper function for finding a nearestneighbor.
     */
    return nearestneighbor(0,points.size()-1,0,query);
}

template <int Dim>
Point<Dim> KDTree<Dim>::nearestneighbor(int left,int right, int dimension, const Point<Dim>& query) const{
  /*
  This is the helper function for finding the nearestneighbor. The method first goes to the deepest node and then traverse back and search for the potential better one within radius.
  */
  if(left>=right){
    return points[left];
  }
  int median = (left+right)/2;
  Point<Dim> currentBest;
  if(smallerDimVal(points[median],query,dimension)){
    currentBest = nearestneighbor(median+1,right,(dimension+1)%Dim,query);
  }else{
    currentBest = nearestneighbor(left,median-1,(dimension+1)%Dim,query);
  }
  if(shouldReplace(query,currentBest,points[median])){
    currentBest = points[median];
  }
  int radius=0;
  for(int i=0;i<Dim;i++){
    radius+=pow(query[i]-currentBest[i],2);
  }
  int dis = pow(query[dimension]-points[median][dimension],2);
  Point<Dim> best2;
  if(dis<=radius){
    if(smallerDimVal(points[median],query,dimension)){
      best2 = nearestneighbor(left,median-1,(dimension+1)%Dim,query);
    }else{
      best2 = nearestneighbor(median+1,right,(dimension+1)%Dim,query);
    }
    if(shouldReplace(query,currentBest,best2)){
      currentBest = best2;
    }
  }
  return currentBest;
}
