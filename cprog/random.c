#include <stdio.h>
#include <stdlib.h>

void Random(int lower, int upper, int count) 
{ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        printf("%d ", num); 
    } 
} 

int main()
{
 Random(10,100, 8);
}
