/* Your code here! */
#include "dsets.h"
#include <vector>
using namespace std;

void DisjointSets::addelements(int num){
  for(int i=0;i<num;i++){
    arr.push_back(-1);
  }
}

int DisjointSets::find(int i){
  if(arr[i]<0){
    return i;
  }else{
    int ret = find(arr[i]);
    arr[i] = ret;
    return ret ;
  }
}

void DisjointSets::setunion(int a, int b){
  int root1 = find(a);
  int root2 = find(b);
  int newsize = arr[root1] + arr[root2];
  if(arr[root1]<arr[root2]){
    arr[root2] = root1;
    arr[root1] = newsize;
  }else{
    arr[root1] = root2;
    arr[root2] = newsize;
  }
}
