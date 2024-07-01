/* A is the Array, L = lower bound of array, R = upper bound of array, T= target value to search
 * procedure binary_search(A, L, R, T):
    if R>=L:
        m := floor((L + R) / 2)
				if A[m] ==  T:
				    return m
        if A[m] > T:
            return binary_search(A, L , m - 1, T)
        else:
            return binary_search(A, m+1, R, T)
    return unsuccessful
 end procedure
 */
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int binary_search(int A[], int L, int R, int T);

int binary_search(int A[], int L, int R, int T)
{
 int m;
	if(R>=L)
	{
		 m = floor((L+R)/2);
		 if(A[m]== T)
		 {
			 return m; 
			 exit(1);
		 }
		 else if(A[m] > T)
		 {
			 return binary_search(A, L,  m - 1, T);
		 }
		 else 
		 {
       return binary_search(A, m+1, R, T);
		 }
	}
   return -1;
}


void main()
{
	const int MAX=10;
	int arr[MAX];
  int counter, search, result; 
	//set seed for generating random numbers
	srand(1978);
  // initialize arr with random numbers
	
	for(counter=0;counter<MAX; counter++)
	{
		arr[counter]=rand()%100;
	}

	// sort array
	for(int i=0; i<MAX;i++)
	{
		for(int j=0;j<MAX-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

  printf("\nElements in arr: ");
	for(counter=0;counter<MAX; counter++)
	{
		printf("%d\t", arr[counter]);
	}

	printf("\nEnter element to search\t");
	scanf("%d", &search);

	result= binary_search(arr, 0, MAX-1, search);

	if(result == -1)
	{
		printf("\n%d not found in arr\n", search);
	}
	else{
		printf("\n%d found at %d location in arr\n", search, result);
	}
}

	
