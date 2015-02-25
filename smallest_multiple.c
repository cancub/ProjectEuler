#include <stdio.h>
#include <math.h>

int modulo_op(double a, int b)
{
	return (int)(a - ((double)b)*floor(a/(double)b));
}

int main(){

	int i,divisible;
	double j = 1;

	int array[] = {20,19,18,17,16,15,14,13,12,11};

	do{
		j = j + 1;
		divisible = 1;
		for (i=0;i < 10; i++){
			if (modulo_op(j, array[i]) != 0){
				divisible = 0;
				break;
			}
		}
	}while(divisible == 0);

	printf("smallest = %f\n", j);

	return 0;
}