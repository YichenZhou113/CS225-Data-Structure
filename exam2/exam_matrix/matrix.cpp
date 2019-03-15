#include "matrix.h"
#include <iostream>

using namespace exam;

Matrix::Matrix() {
    data_ = NULL;

    num_rows_ = 0;
    num_columns_ = 0;
}

Matrix::Matrix(int rows, int columns) {
    data_ = new int[rows*columns];

    num_rows_ = rows;
    num_columns_ = columns;
}

Matrix::~Matrix() {
    _destroy();
}

Matrix & Matrix::operator=(const Matrix &m) {
    _destroy();
    _copy(m);
    return *this;
}

Matrix::Matrix(const Matrix &m) {
    _copy(m);
}

int Matrix::get_coord(int row, int column) const {
    return data_[row * num_columns_ + column];
}

void Matrix::set_coord(int row, int column, int i) {
    data_[row * num_columns_ + column] = i;
}

int Matrix::get_num_rows() const { 
    return num_rows_;
}

int Matrix::get_num_columns() const {
    return num_columns_;
}

void Matrix::display() {
    for(int row=0; row<num_rows_; row++) {
        for(int column=0; column<num_columns_; column++)
            std::cout << data_[row * num_columns_ + column] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::_destroy() {
    delete [] data_;
}

void Matrix::_copy(const Matrix &m) {
    num_rows_ = m.num_rows_;
    num_columns_ = m.num_columns_;
    data_ = new int[m.num_rows_*m.num_columns_];
    for(int i=0; i<num_rows_; i++)
        for(int j=0; j<num_columns_; j++)
            set_coord(i,j,m.get_coord(i,j));
}
    

