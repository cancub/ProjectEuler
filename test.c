#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct
{
	int *array;
	size_t num_factors;
}Factors;

typedef struct 
{
	Factors *array;
	size_t size;
} Array;

void free_array(Array* a){
	int i;

	for(i = 0; i < a->size; i++){
		free(a->array[i].array);
		a->array[i].array = NULL;
	}
	free(a->array);
}


int main()
{	

	Array myarray;
	myarray.size = 2;
	myarray.array = (Factors *)malloc(sizeof(Factors)*myarray.size);


	int j = 0,i;

	for (i=1; i <= 12; i++){
		if((12 % i) == 0){
			j++;
		}
	}

	// printf("%d\n", j);

	Factors factors_of_12;
	factors_of_12.num_factors = j;
	factors_of_12.array = (int *)malloc(sizeof(int)*factors_of_12.num_factors);

	j = 0;

	for (i=1; i <= 12; i++){
		if((12 % i) == 0){
			factors_of_12.array[j++] = i;
		}
	}

	myarray.array[0] = factors_of_12;

	printf("myarray.array[0].array[2] = %d\n", myarray.array[0].array[2]);

	free_array(&myarray);

	return 0;
}