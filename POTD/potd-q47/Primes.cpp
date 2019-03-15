#include <vector>
#include "Primes.h"
#include <iostream>

std::vector<int> *genPrimes(int M) {
    std::vector<int> *v = new std::vector<int>();
    std::vector<int> *t = new std::vector<int>(M);
    int i=0;
    int nextPrime = 2;

    for(i=0; i<M; i++)
        (*t)[i] = 1;

    (*t)[0]=0;
    (*t)[1]=0;

    v->push_back(2);

    while (nextPrime < M) {
        for(i=nextPrime*nextPrime;
                i < M;
                i+=nextPrime)
            (*t)[i] = 0;
        for(++nextPrime; nextPrime<M; nextPrime++)
            if ((*t)[nextPrime] == 1) {
                v->push_back(nextPrime);
                break;
            }
    }

    delete t;
    return v;
}


int numSequences(std::vector<int> *primes, int num) {
    //std::vector<int> v=primes;
    //std::cout<<((*primes)[1])<<std::endl;
    int in = 0;
    while((*primes)[in]<=num){
      in++;
    }
    int freq=0;
    for(int i=0;i<=in;i++){
      int sum=0;
      for(int k=i;k<=in;k++){
        sum += (*primes)[k];
        //std::cout<<i<<std::endl;
        if(sum==num){
          freq++;
        }
        if(sum>num){
          break;
        }

      }
      //i++;
    }
    // your code here

    // code to quell compiler complaints.  Delete it.
    return freq;
}
