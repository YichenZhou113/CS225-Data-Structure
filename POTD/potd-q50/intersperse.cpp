#include "intersperse.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//bool func(int a, int b){return(a>b);}

struct myclass {
  bool operator() (int i,int j) { return (i>j);}
} myobject;

std::vector<int> zigZag(std::vector<int> v1, std::vector<int> v2){

	//write your code here
  std::sort(v1.begin(),v1.end());
  std::sort(v2.begin(),v2.end());
  std::vector<int> v;
int k = int(v1.size());
  for(int i =0;i<k;i++){
    v.push_back(v1.back());
    v1.pop_back();
    v.push_back(v2.back());
    v2.pop_back();
  }
return v;
}
