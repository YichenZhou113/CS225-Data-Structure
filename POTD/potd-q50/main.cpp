#include <iostream>
#include <queue>
#include <string>

#include "intersperse.h"

int main(){

    std::vector<int> v1, v2;
    v1 = {50,40,20,30,10};
    v2 = {1,2,3,4,5};

    std::vector<int> answer = zigZag(v1,v2);

    std::cout << "The zig zag vector is " <<std::endl;
    for (unsigned int i =0; i < answer.size(); i ++){
        std::cout << answer[i] << std::endl;
    }

    return 0;

}
