#include<stdio.h>
int main()
{ 
	int marks[10]={10,14,15,16,18,11,20,21,11,10};
	int counter;
	
  //traverse array: Visit each element of array atleast once
	for(counter=0;counter <=9; counter++)
	{
		printf("%d\n", marks[counter]);
	}

}


