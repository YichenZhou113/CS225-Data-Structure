#include "Heap.h"
#include <iostream>

void Heap::_percolateDown(int hole) {
    // your code here
    int child;
 int tmp = std::move( _data[ hole ] );

for( ; hole * 2 <= int(_data.size()); hole = child )
{
child = hole * 2;
if( child != int(_data.size()) && _data[ child + 1 ] < _data[ child ] )
++child;
if( _data[ child ] < tmp )
_data[ hole ] = std::move( _data[ child ] );
else
break;
}
_data[ hole ] = std::move( tmp );
}

int Heap::size() const {
    return _data.size();
}

void Heap::enQueue(const int &x){
    _data.push_back(x);
    int hole = _data.size() - 1;
    for(; hole > 1 && x > _data[hole/2]; hole /= 2){
        _data[hole] = _data[hole/2];
    }
    _data[hole] = x;
}

int Heap::deQueue(){
    int minItem = _data[1];
    _data[1] = _data[_data.size() - 1];
    _data.pop_back();
    _percolateDown(1);
    return minItem;
}

void Heap::printQueue(){
    std::cout << "Current Priority Queue is: ";
    for(auto i = _data.begin() + 1; i != _data.end(); ++i){
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

std::vector<int> & Heap::getData() {
    return _data;
}
