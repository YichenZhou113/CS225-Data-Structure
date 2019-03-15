#ifndef MATRIX_H
#define MATRIX_H

namespace exam {
    class Matrix {
        public:
            Matrix();
            Matrix(int rows, int columns);
            Matrix(const Matrix &m);
            Matrix & operator=(const Matrix &m);
            ~Matrix();

            int get_coord(int rows, int columns) const;
            void set_coord(int rows, int columns, int i);

            int get_num_rows() const;
            int get_num_columns() const;

            void display();

        private:

            int *data_;
            int num_rows_;
            int num_columns_;

            void _destroy();
            void _copy(const Matrix & m);
    };
}

#endif
