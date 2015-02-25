#include <math.h>
#include <stdio.h>

int main(){
	int i,j;

	double sum = 0;

	for (i=1;i<=100;i++){
		for(j=1;j<=100;j++){
			if (i!=j){
				sum += i*j;
			}
		}
	}

	printf("%f\n", sum);
}