#include <iostream>

using namespace std;

#include "beiju.cpp"

int main() {

    while (! cin.eof()) {
        string s;
        getline(cin,s);
        cout << beiju(s) << endl;
    }
}


