#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
	double *array;
	size_t size;
} Array;

void add_element(Array *a, double new_element)
{
	a->size += 1;
	a->array = (double *)realloc(a->array,a->size * sizeof(double));
	a->array[a->size-1] = new_element;
	// printf("array size = %d\n", (int)a->size);
}

void freeArray(Array *a) 
{
  free(a->array);
  a->array = NULL;
}

int modulo_op(double a, double b)
{
	return (int)(a - b*floor(a/b));
}

int main()
{
	double i;
	int j,k;

	Array prime_factors;

	prime_factors.array = (double *)malloc(0);
	prime_factors.size = 0;

	for (i = 2; prime_factors.size < 10001; i=i+1)
	{
		// printf("%d\n", i);

		if (prime_factors.size == 0)
		{
			add_element(&prime_factors,i);
			// printf("array[0] = %d\n", prime_factors.array[0]);
		}
		else
		{
			// printf("here\n");
			for (j = 0; j < prime_factors.size; j++)
			{
				// printf("i = %d, prime_factors.array[j] = %d, i %% prime_factors.array[j] = %d\n", i, 
				// 	prime_factors.array[j], i % prime_factors.array[j]);
				if (modulo_op(i,prime_factors.array[j]) == 0)
				{
					break;
				}
			}

			if (j == prime_factors.size)
			{
				add_element(&prime_factors, i);
				// printf("prime = %d\n", (int)i);
				// sleep(0.5);
			}
		}
	}

	// printf("10001st prime factor = %d\n", (int)i);

	for (j = 0; j < prime_factors.size; j++){
		printf("%d\n", (int)prime_factors.array[j]);
	}

	freeArray(&prime_factors);

	return 0;
}