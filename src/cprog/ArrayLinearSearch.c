#include<stdio.h>
int main()
{ 
	int marks[10]={10,14,15,16,18,11,20,21,11,10};
	int counter;
	int item;

	printf("marks array contains following values: \n");
  for(counter=0;counter<=9;counter++)
	{
		printf("%d \t", marks[counter]);
	}


	printf("\nEnter element to search:\t");
	scanf("%d", &item);

	// linear search

	for(counter=0;counter<=9;counter++)
	{
    if(item == marks[counter])
		{
			printf("\n%d, found at %d location of array", item, counter);
			break;
		}
 }
	if(counter ==10)
	{
		printf("\n%d not in array ", item);
	}


}


