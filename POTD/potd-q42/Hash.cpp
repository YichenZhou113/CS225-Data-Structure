#include "Hash.h"
#include <string>

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	//Your code here
	for(int i =0;i<int(str.length());i++){
		b_hash = 33*b_hash+str[i];
	}
	return b_hash % M;
}

std::string reverse(std::string str)
{
    std::string output;
		for(int i=0;i<int(str.length());i++){
			output[i]=str[int(str.length())-1-i];
		}
	//Your code here

	return output;
}
