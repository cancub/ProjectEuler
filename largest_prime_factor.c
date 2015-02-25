#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
	int *array;
	size_t size;
} Array;

void add_element(Array *a, int new_element)
{
	a->size += 1;
	a->array = (int *)realloc(a->array,a->size * sizeof(int));
	a->array[a->size-1] = new_element;
	// printf("array size = %d\n", (int)a->size);
}

void freeArray(Array *a) 
{
  free(a->array);
  a->array = NULL;
}

int modulo_op(double a, int b)
{
	return (int)(a - ((double)b)*floor(a/(double)b));
}

int main()
{
	double test_num;

	int i,j,k;

	int biggest_pf;

	Array prime_factors;

	prime_factors.array = (int *)malloc(0);
	prime_factors.size = 0;

	printf("Type in a number to find its largest prime\n");
	scanf("%lf", &test_num);

	for (i = 2; i < test_num; i++)
	{
		// printf("%d\n", i);
		if (modulo_op(test_num,i) == 0){
			// it's a factor

			if (prime_factors.size == 0)
			{
				add_element(&prime_factors,i);
				biggest_pf = i;
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
					biggest_pf = i;
					printf("prime = %d\n", biggest_pf);
					// sleep(0.5);
				}
			}
		}

		

	}

	printf("List of prime factors: \n");

	for(k = 0; k < prime_factors.size; k++)
	{
		printf("%d ", prime_factors.array[k]);
	}

	printf("\nbiggest prime factor = %d\n", biggest_pf);

	freeArray(&prime_factors);
}