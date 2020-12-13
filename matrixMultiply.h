#ifndef MATRIXMULTIPLY_H
#define MATRIXMULTIPLY_H

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <functional> // std::multiplies  

typedef std::vector<int> Array;
typedef std::vector<Array> Matrix;

Matrix matrixMultiply1(const Matrix & matrix_1, const Matrix & matrix_2);
Matrix matrixMultiply2(const Matrix & matrix_1, const Matrix & matrix_2);
Matrix matrixMultiply3(const Matrix & matrix_1, const Matrix & matrix_2);


#endif