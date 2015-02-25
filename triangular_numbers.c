#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Factors
{
	int *factor_list;
	size_t num_factors;
};

struct Array
{
	struct Factors *array;
	size_t size;
};

struct mini_array
{
	int * array;
	size_t size;
};

void free_array(struct Array* a);

void add_element(struct Array *a, struct Factors factors);

int modulo_op(double a, double b);

struct Factors get_factors(int test_number);


int main(){

	double i = 1,j;
	int k, biggest = 0;
	double testnum = 0;

	struct Array numbers_and_factors;
	numbers_and_factors.size = 1;
	numbers_and_factors.array = (struct Factors *)malloc(sizeof(struct Factors));


	struct Factors factors_of_one;
	factors_of_one.num_factors = 1;
	factors_of_one.factor_list = (int*)malloc(sizeof(int));
	factors_of_one.factor_list[0] = 1;

	numbers_and_factors.array[0] = factors_of_one;

	// do{
	// 	k = 0;
	// 	i+=1;
	// 	testnum += i;
	// 	for(j = 1; j<=testnum;j+=1){
	// 		if(modulo_op(testnum,j) == 0){
	// 			k++;
	// 		}
	// 	}
	// 	if (k > biggest){
	// 		biggest = k;
	// 		printf("factors for %f, k = %d\n",testnum,k );
	// 	}
	// }while(k<=500);

	// printf("first triangle number with > 500 factors is %f\n", i);

	free_array(&numbers_and_factors);

	return 0;
}

void free_array(struct Array* a)
{
	int i;

	for(i = 0; i < a->size; i++){
		free(a->array[i].factor_list);
		a->array[i].factor_list = NULL;
	}
	free(a->array);
}

void add_element(struct Array *a, struct Factors factors)
{
	a->size += 1;
	a->array = (struct Factors *)realloc(a->array,a->size * sizeof(struct Factors));
	a->array[a->size-1] = factors;
	// printf("array size = %d\n", (int)a->size);
}

int modulo_op(double a, double b)
{
	return (int)(a - b*floor(a/b));
}

struct Factors get_factors(int test_num, struct Array * a)
{

}