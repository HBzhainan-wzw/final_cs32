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

void test_null_case(const Matrix &m1, const Matrix &m2){
  Matrix m3;
  bool detected_error = false;
  try{
    m3 = matrixMultiply1(m1, m2);
  }catch(invalid_argument e){
    detected_error = true;
  }
  ASSERT_EQUALS(detected_error, true);

  detected_error = false;
  try{
    m3 = matrixMultiply2(m1, m2);
  }catch(invalid_argument e){
    detected_error = true;
  }
  ASSERT_EQUALS(detected_error, true);

  detected_error = false;
  try{
    m3 = matrixMultiply3(m1, m2);
  }catch(invalid_argument e){
    detected_error = true;
  }
  ASSERT_EQUALS(detected_error, true);

}

int main() {
  Matrix matrix_1 = {{1,2,3,4}, {4,5,6,6},{1,2,3,4}};
  Matrix matrix_2 = {{1,2,3,1,1,3,3}, {4,5,4,2,2,3,3},{7,8,5,3,3,3,3},{1,1,1,4,4,3,3}};
  Matrix matrix_3;
  matrix_3 = matrixMultiply3(matrix_1, matrix_2);

  Matrix expected = {{34, 40, 30, 30, 30, 30, 30},{72, 87, 68, 56, 56, 63, 63},{34, 40, 30, 30, 30, 30, 30}};
  ASSERT_EQUALS(toString(expected), toString(matrix_3));


  Matrix m1 = {{}};
  Matrix m2 = {{}, {2}};
  Matrix m3;
  bool detected_error = false;
  try{
    m3 = matrixMultiply1(m1, m1);
  }catch(invalid_argument e){
    detected_error = true;
  }
  ASSERT_EQUALS(detected_error, true);

  detected_error = false;
  try{
    m3 = matrixMultiply2(m1, m1);
  }catch(invalid_argument e){
    detected_error = true;
  }
  ASSERT_EQUALS(detected_error, true);

  detected_error = false;
  try{
    m3 = matrixMultiply3(m1, m1);
  }catch(invalid_argument e){
    detected_error = true;
  }
  ASSERT_EQUALS(detected_error, true);


  test_null_case(m1, m2);
  test_null_case(Matrix( {{1}} ), Matrix( {{}} ));
  test_null_case(Matrix( {{1}, {}} ), Matrix( {{}, {1}} ));
  test_null_case(Matrix( { {1,2}, {3} } ), Matrix( { {1,2}, {1,2} } ));
  test_null_case(Matrix( { {1,2}, {3,4} } ), Matrix( { {1,2,3}, {1,2,3}, {1,2,3} }));
  test_null_case(Matrix(), Matrix());


  m1 = {{1,2}, {3,4}};
  m3 = matrixMultiply1(m1, m1);
  expected = {{7, 10}, {15, 22}};
  ASSERT_EQUALS(toString(m3), toString(expected));

  m3 = matrixMultiply2(m1, m1);
  ASSERT_EQUALS(toString(m3), toString(expected));

  m3 = matrixMultiply3(m1, m1);
  ASSERT_EQUALS(toString(m3), toString(expected));

  
  m2 = {{4,5, 1}, {7, 6,8}};
  expected = {{18, 17, 17}, {40, 39, 35}};
  m3 = matrixMultiply1(m1, m2);
  ASSERT_EQUALS(toString(m3), toString(expected));

  m3 = matrixMultiply2(m1, m2);
  ASSERT_EQUALS(toString(m3), toString(expected));

  m3 = matrixMultiply3(m1, m2);
  ASSERT_EQUALS(toString(m3), toString(expected));

  return 0;
}



