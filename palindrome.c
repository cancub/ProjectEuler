#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MIN 100
#define MAX 999

typedef struct
{
	int* array;
	size_t size;
}Array;

Array get_array(int a, int b){

	int number = a*b;

	int x,y,i,j;

	// find the largest multiple of 10
	for (x = 1; number/x; x *=10){
		i++;
		// printf("%d/%d = %s\nresult = %f\n",i,x, (i/x) ? "true" : "false", (double)i/(double)x);
	}

	Array num_array;
	num_array.array = (int*)malloc(i*sizeof(int));
	num_array.size = i;

	j = 0;

	for (y = x/10; y > 0; y /= 10){
		num_array.array[j++] = (int)floor(number/y);
		// printf("%ds digit = %d\n", y, (int)floor(number/y));
		// sleep(2);
		number = number - (int)floor(number/y) * y;
	}

	return num_array;
}

bool is_palindrome(Array* a)
{
	int i;

	bool equal = 1;

	if (a->size % 2 == 0) {
		for(i = 0; i < (a->size)/2; i++)
		{
			equal = a->array[i] == a->array[a->size-i-1];
			if (equal == 0) {
				break;
			}
		}
	} else {
		for(i = 0; i < (int)floor((double)(a->size)/2); i++)
		{
			equal = a->array[i] == a->array[a->size-i-1];
			if (equal == 0) {
				break;
			}
		}
	}
	return equal;
}

int main()
{
	int i,j;

	Array num_array;

	int biggest;

	for (i = MIN; i <= MAX; i++){
		for (j = i + 1; j <= MAX; j++){

			num_array = get_array(i,j);

			if (is_palindrome(&num_array)){
				printf("i = %d, j = %d, product %d is a palindrome\n",i,j,i*j );

				if (i*j > biggest){
					biggest = i*j;
				}
				// sleep(0.1);
			}

			free(num_array.array);
			num_array.array = NULL;
			
		}
	}

	printf("largest palindrome = %d\n", biggest);
	return 0;
}