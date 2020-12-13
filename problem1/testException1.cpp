//testException1.cpp

#include <iostream>
#include "binarySearch.h"
#include "tddFuncs.h"
using namespace std;

int main()
{
	//test cases
	bool caughtArrayNotSortedException = false;
	bool outofIndex = 0;
	bool elementnotFound = 0;
	bool invalidIndex = 0;

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


	// out of index
	int arr3[] = {1,2,3,4,5,6};
	try{
		binarySearch(arr3, -1, n-1, 6);
	}
	catch(IndexOutOfBoundsException e)
	{
		outofIndex = true;
		//std::cout<<"\nArray is not sorted!";
	}
	ASSERT_EQUALS(true, outofIndex);
	outofIndex=0;

	try{
		binarySearch(arr3, 0, 6, 6);
	}
	catch(IndexOutOfBoundsException e)
	{
		outofIndex = true;
		//std::cout<<"\nArray is not sorted!";
	}
	cout << binarySearch(arr3, 0, 6, 6)<<endl;
	ASSERT_EQUALS(true, outofIndex);
	outofIndex=0;

	//not found
	try{
		binarySearch(arr3, 0, 3, 5);
	}
	catch(ElementNotFoundException e)
	{
		elementnotFound = true;
		//std::cout<<"\nArray is not sorted!";
	}
	ASSERT_EQUALS(true, elementnotFound);
	elementnotFound=0;

	try{
		binarySearch(arr3, 0, 3, 8);
	}
	catch(ElementNotFoundException e)
	{
		elementnotFound = true;
		//std::cout<<"\nArray is not sorted!";
	}
	ASSERT_EQUALS(true, elementnotFound);
	elementnotFound=0;

	//invalid index
	try{
		binarySearch(arr3, 3, 0, 3);
	}
	catch(InvalidIndexException e)
	{
		invalidIndex = true;
		//std::cout<<"\nArray is not sorted!";
	}
	ASSERT_EQUALS(true, invalidIndex);
	invalidIndex=0;


	return 0;
}
