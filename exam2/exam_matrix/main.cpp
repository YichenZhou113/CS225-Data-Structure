#include <iostream>
#include "exam.h"
#include "matrix.h"

using namespace exam;
using namespace std;

#define ROWS 5
#define COLUMNS 5

int main() {
    Matrix m(ROWS, COLUMNS);

    for(int i=0; i<ROWS; i++) 
        for(int j=0; j<COLUMNS; j++) 
            m.set_coord(i,j,(i + j) % 10);

    m.display();

    flip_columns(m).display();
}
