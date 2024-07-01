#include<iostream>
#define LENGTH 10
using namespace std;

int sum(int []);

int main(int argc, char *argv[])
{
  int array[LENGTH];

	for(size_t count = 0; count < LENGTH; count++)
	{
		cout<<"Enter value for "<< count + 1 << " element of array ";
		cin>>array[count];
	}

	cout<<"Sum of Array is " << sum(array);

	return 0;
}

int sum(int array[])
{
	int result=0;

	for(size_t count = 0; count < LENGTH; count++)
	{
		result+=array[count];
	}
	
	return result;
}



