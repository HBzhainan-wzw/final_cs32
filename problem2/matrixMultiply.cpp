#include "matrixMultiply.h"

// Part 1
Matrix matrixMultiply1(const Matrix & matrix_1, const Matrix & matrix_2){
    //empty
    if(matrix_1.empty()){throw invalid_argument("-1");}
    if(matrix_1[0].empty()){throw invalid_argument("-1");}
    if(matrix_2.empty()){throw invalid_argument("-1");}
    if(matrix_2[0].empty()){throw invalid_argument("-1");}    

    // not matrix
    for(size_t i = 0; i < matrix_1.size();i++){
        if(matrix_1[i].size()!=matrix_1[0].size()){throw invalid_argument("-1");}
    }
    for(size_t i = 0; i < matrix_2.size();i++){
        if(matrix_2[i].size()!=matrix_2[0].size()){throw invalid_argument("-1");}
    }

    // cannot multiply
    if(matrix_1[0].size()!=matrix_2.size()){throw invalid_argument("-1");}    

    Matrix res = {};
    //have the result size
    size_t nRow = matrix_1.size();
    size_t nCol = matrix_2[0].size();
    for(size_t i = 0; i < nRow;i++){
        Array row = {};
        for(size_t j = 0; j < nCol; j++){
            size_t tempS = 0;
            for (size_t k = 0; k < matrix_1[0].size(); k++)
            {
                /* code */
                tempS= tempS + matrix_1[i][k] * matrix_2[k][j];
            }
            row.push_back(tempS);
        }
        res.push_back(row);
    }
    return res;
}

// Part 2
Matrix matrixMultiply2(const Matrix & matrix_1, const Matrix & matrix_2){
    //empty
    if(matrix_1.empty()){throw invalid_argument("-1");}
    if(matrix_1[0].empty()){throw invalid_argument("-1");}
    if(matrix_2.empty()){throw invalid_argument("-1");}
    if(matrix_2[0].empty()){throw invalid_argument("-1");}    

    // not matrix
    for(size_t i = 0; i < matrix_1.size();i++){
        if(matrix_1[i].size()!=matrix_1[0].size()){throw invalid_argument("-1");}
    }
    for(size_t i = 0; i < matrix_2.size();i++){
        if(matrix_2[i].size()!=matrix_2[0].size()){throw invalid_argument("-1");}
    }

    // cannot multiply
    if(matrix_1[0].size()!=matrix_2.size()){throw invalid_argument("-1");}  

    Matrix res = {};
    //have the result size
    size_t nRow = matrix_1.size();
    size_t nCol = matrix_2[0].size();

    Matrix trans = {};
    for(size_t i = 0; i < nRow;i++){
        Array temp = {};
        for (size_t j = 0; j < matrix_2.size(); j++)
        {
            temp.push_back(matrix_2[j][i]);
        }
        trans.push_back(temp);
    }    

    for(size_t i = 0; i < nRow;i++){
        Array row = {};
        for(size_t j = 0; j < nCol; j++){
            size_t mul = inner_product(matrix_1[i].begin(),matrix_1[i].end(), trans[i].begin(),0);
            row.push_back(mul);
        }
        res.push_back(row);
    }
    return res;

}

// Part 3

int op(Array ar1, Array ar2){
    int result = 0;
    for (int i = 0; i < ar1.size(); i++)
    {
        /* code */
        result += ar1[i]+ar2[i];
    }
    return result;

}


Matrix matrixMultiply3(const Matrix & matrix_1, const Matrix & matrix_2){
    //empty
    if(matrix_1.empty()){throw invalid_argument("-1");}
    if(matrix_1[0].empty()){throw invalid_argument("-1");}
    if(matrix_2.empty()){throw invalid_argument("-1");}
    if(matrix_2[0].empty()){throw invalid_argument("-1");}    

    // not matrix
    for(size_t i = 0; i < matrix_1.size();i++){
        if(matrix_1[i].size()!=matrix_1[0].size()){throw invalid_argument("-1");}
    }
    for(size_t i = 0; i < matrix_2.size();i++){
        if(matrix_2[i].size()!=matrix_2[0].size()){throw invalid_argument("-1");}
    }

    // cannot multiply
    if(matrix_1[0].size()!=matrix_2.size()){throw invalid_argument("-1");}  
    
    Matrix res = {};
    
    size_t nRow = matrix_1.size();
    size_t nCol = matrix_2[0].size();

    
    Matrix trans = {};
    for(size_t i = 0; i < nRow;i++){
        Array temp = {};
        for (size_t j = 0; j < matrix_2.size(); j++)
        {
            temp.push_back(matrix_2[j][i]);
        }
        trans.push_back(temp);
    }    
    for (size_t i = 0; i < nRow; i++) {
        Matrix tempM = {};
        for (size_t j = 0; j < nRow; j++){
            tempM.push_back(matrix_1[i]);
        }
        res.push_back(Array(nRow,0));
        transform(tempM.begin(), tempM.end(), trans.begin(), res[i].begin(), op);
    }
    return res;
}