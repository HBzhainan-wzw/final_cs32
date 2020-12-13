#include "matrixMultiply.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;


std::string toString(const Matrix & matrix ){
  std::stringstream stream;
  for(int i = 0; i < (int) matrix.size(); i++) {
    for(int j = 0 ; j < (int) matrix[0].size(); j++){
      stream << matrix[i][j] << " ";
    }
    stream << std::endl;
  }
  return stream.str();
}

int main() {

  bool caughtException = false;

  Matrix matrix_1 = {{1,2,3,4}, {4,5,6,6},{1,2,3,4}};
  Matrix matrix_2 = {{1,2,3,1,1,3,3}, {4,5,4,2,2,3,3},{7,8,5,3,3,3,3},{1,1,1,4,4,3,3}};
  Matrix matrix_3;
  matrix_3 = matrixMultiply1(matrix_1, matrix_2);

  Matrix expected = {{34, 40, 30, 30, 30, 30, 30},{72, 87, 68, 56, 56, 63, 63},{34, 40, 30, 30, 30, 30, 30}};
  ASSERT_EQUALS(toString(expected), toString(matrix_3));

  Matrix matrix_4 = {{1,2,3,4}, {4,5,6,6}};
  Matrix matrix_5 = {{1,2,3,1,1,3,3}, {4,5,4,2,2,3,3},{7,8,5,3,3,3,3},{1,1,1,4,4,3,3}};
  Matrix matrix_6 = {};
  Matrix matrix_7 = {{1,2,3,1,1,3}, {4,5,4,2,2,3,3},{7,8,5,3,3,3,3},{1,1,1,4,4,3,3}};


	try {
    matrix_3 = matrixMultiply1(matrix_4, matrix_5);		
	} catch (invalid_argument e) {
		caughtException = true;
	}
	ASSERT_EQUALS(true, caughtException);
	caughtException = false;

  cout<<"testing empty"<<endl<<matrix_6.empty()<<endl;
	try {
    matrix_3 = matrixMultiply1(matrix_4, matrix_6);		
	} catch (invalid_argument e) {
		caughtException = true;
	}
	ASSERT_EQUALS(true, caughtException);
	caughtException = false;

	try {
    matrix_3 = matrixMultiply1(matrix_2, matrix_7);		
	} catch (invalid_argument e) {
		caughtException = true;
	}
	ASSERT_EQUALS(true, caughtException);
	caughtException = false;

  return 0;
}



