#include <stdio.h>

int main(void)
{
	int total = 0;
	int i;
	for(i = 0; i < 1000; i = i + 1){
		if ((i % 3 == 0) || (i % 5 == 0)){
			total = total + i;
		}
	}

	printf("total = %d\n", total );
}