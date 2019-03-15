// your code here!
#include "potd.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

int* potd::raise(int* arr){
  int i = 0;
  while(arr[i]>0){
    i++;
  }
  i++;
  int* newarr = new int[i];
  for(int k = 0;k<=i-3;k++){
    newarr[k] = pow(arr[k],arr[k+1]);
  }
  newarr[i-2] = arr[i-2];
  newarr[i-1] = -1;
  return newarr;
}
