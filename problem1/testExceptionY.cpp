#include <iostream>
#include "binarySearch.h"
#include "tddFuncs.h"
using namespace std;

int main(){
    int arr[] = {1,2,3,4,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    bool caught1 = false;
    bool caughtIndexOutOfBound = false;
    bool caught2 = false;
    bool real_case_InvalidIndex = false;
    bool real_case_IndexOutOfBound = false;

    try{
        binarySearch(arr, -1, 39, x);
    }catch(IndexOutOfBoundsException e){
        caught1 = true;
    }
    ASSERT_EQUALS(true, caught1);

    try{
        binarySearch(arr, -100, 1, x);
    }catch(IndexOutOfBoundsException e){
        caughtIndexOutOfBound = true;
    }
    ASSERT_EQUALS(true, caughtIndexOutOfBound);


    try{
        binarySearch(arr, 3,1, x);
    }catch(InvalidIndexException e){
        caught2 = true;
    }
    ASSERT_EQUALS(true, caught2);

    int index = -1;
    try{
        index = binarySearch(arr, 0, n-1, x);
    }catch(IndexOutOfBoundsException e){
        real_case_IndexOutOfBound = true;
    }catch(InvalidIndexException e){
        real_case_InvalidIndex = true;
    }
    ASSERT_EQUALS(real_case_IndexOutOfBound, false);
    ASSERT_EQUALS(real_case_InvalidIndex, false);
    ASSERT_EQUALS(index, 2);

    int index2 = -1;
    bool real_case2_InvalidIndex = false;
    bool real_case2_IndexOutOfBound = false;
    bool real_case2_ElementNotFound = false;

    try{
        index2 = binarySearch(arr, 0, n-1, 9);
    }catch(IndexOutOfBoundsException e){
        real_case2_IndexOutOfBound = true;
    }catch(InvalidIndexException e){
        real_case2_InvalidIndex = true;
    }catch(ElementNotFoundException e){
        real_case2_ElementNotFound = true;
    }
    ASSERT_EQUALS(real_case2_IndexOutOfBound, false);
    ASSERT_EQUALS(real_case2_InvalidIndex, false);
    ASSERT_EQUALS(real_case2_ElementNotFound, true);
    


    int arr2[] = {1,1,2,2,2};
    int y = 2;
    bool arr2_indexOutOfBound = false;
    bool arr2_invalidIndex = false;
    bool arr2_notSorted = false;
    int index3 = -1;

    try{
        index3 = binarySearch(arr2, 0, 4, y);
    }catch(IndexOutOfBoundsException e){
        arr2_indexOutOfBound = true;
    }catch(InvalidIndexException e){
        arr2_invalidIndex = true;
    }catch(ArrayNotSortedException e){
        arr2_notSorted = true;
    }
    ASSERT_EQUALS(false, arr2_indexOutOfBound);
    ASSERT_EQUALS(false, arr2_invalidIndex);
    ASSERT_EQUALS(false, arr2_notSorted);
    ASSERT_EQUALS(2, index3);




    return 0;
}