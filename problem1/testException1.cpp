//testException1.cpp

#include <iostream>
#include "binarySearch.h"
#include "tddFuncs.h"
using namespace std;

int main()
{
	//test cases
	bool caughtArrayNotSortedException = false;

	//test2 - array not sorted
	int arr2[] = {5,4,3,6,7};
	int x = 5;
	int n=sizeof(arr2)/sizeof(arr2[0]);
	try{
		binarySearch(arr2, 0, n-1, x);
	}
	catch(ArrayNotSortedException e)
	{
		caughtArrayNotSortedException = true;
		//std::cout<<"\nArray is not sorted!";
	}
	ASSERT_EQUALS(true, caughtArrayNotSortedException);

	return 0;
}
