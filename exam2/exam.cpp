// Your code here!
#include <cmath>
#include "exam.h"
#include "matrix.h"
using namespace std;
using namespace exam;

Matrix flip_columns(const Matrix &m){
  int rows = m.get_num_rows();
  int columns = m.get_num_columns();
  Matrix *output = Matrix(rows, columns);
  int i,j;
  if (columns%2 ==0){
    for (i = 0; i < columns; i++){
      for (j = 0; j < rows; j++){
        if (i%2 ==0){
          int data = m.get_coord(j,i+1);
          output.set_coord(j,i,data);
        }
        else{
          int data = m.get_coord(j,i-1);
          output.set_coord(j,i,data);
        }

      }
    }
  }else(columns%2 ==1){
    for (i = 0; i < columns-1; i++){
      for (j = 0; j < rows; j++){
        if (i%2 ==0){
          int data = m.get_coord(j,i+1);
          output.set_coord(j,i,data);
        }
        else{
          int data = m.get_coord(j,i-1);
          output.set_coord(j,i,data);
        }

      }
    }
    for(j = 0;j<rows;j++){
      int data = m.get_coord(j,columns-1);
      output.set_coord(j,columns-1,data);
    }
  }
  //const Matrix &output = output;
  return output;
}
