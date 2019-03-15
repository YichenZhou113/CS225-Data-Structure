#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Hash.h"
using namespace std;
unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	for (int i = 0; i < (int) str.length(); ++i)
	{
		b_hash = b_hash * 33 + str[i];
	}
	return b_hash % M;
}

float hash_goodness(std::string str, int M)
{
    //std::vector<int>* array = new std::vector<int>(M);	// Hint: This comes in handy
	vector<vector<int> > array;
	for(int i=0;i<M;i++){
		vector<int> temp;
		array.push_back(temp);
	}
	int permutation_count = 0;
	float goodness = 0;
	double collision = 0;
	do {
		if (permutation_count == M) break;
		// Code for computing the hash and updating the array
		unsigned long hash_code = bernstein(str, M);
		if(array[hash_code].empty() == false){collision = collision+1;}
		array[hash_code].push_back(1);
		permutation_count = permutation_count+1;

	} while(std::next_permutation(str.begin(), str.end()));
	cout<<collision<<endl;
	goodness = collision/M;
	//Code for determining goodness

	return goodness;
}
