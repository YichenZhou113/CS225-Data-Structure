#include <vector>
#include <bits/stdc++.h>
#include "Primes.h"
using namespace std;

std::vector<int> *genPrimes(int M) {
    std::vector<int> *v = new std::vector<int>();
    // your code here
    bool prime[M+1];
    std::memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=M; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=M; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p=2; p<=M; p++)
       if (prime[p])
          v->push_back(p);

    return v;
}
