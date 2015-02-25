#include <stdio.h>

void shifted(int *param, int value)
{
	param[0] = param[1];

	param[1] = value;
}

int main(void)
{
	int total = 2;
	int i;
	int last_two[]= {1,2};
	int temp;

	for(i = 2; i < 4000000; i = i + 1){

		if (i == (last_two[0] + last_two[1])){
			shifted(last_two, i);
			if (i % 2 == 0){
				total = total + i;
			}
		}
	}

	printf("total = %d\n", total );
}

