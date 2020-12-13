//testException5.cpp

#include <iostream>
#include "binarySearch.h"
#include "tddFuncs.h"
using namespace std;

int main()
{
	bool ElementFoundInArray = false;

	//cout<<"Running tests from: "<<__FILE__<<endl;
	//test1 - run normally, this should run normally after all your changes
	int arr[] = {2,3,4,10,40};
  int x = 10;
  int n=sizeof(arr)/sizeof(arr[0]);
  int result = binarySearch(arr, 0, n-1, x);
	//cout << "\nElement is present at index " << result;

	if(result==3)
		ElementFoundInArray = true;
	ASSERT_EQUALS(true, ElementFoundInArray);

	/*catch(...)//default exception
	{
		std::cout<<"\nDefault Exception!"<<endl;
		//terminate();
	}*/
	return 0;
}
