#include <stdio.h>
#include <math.h>

int main(){
	double a,b,c;
	a = b = c = 0;

	do{
		a+=1;
		b = 0;
		do{
			b+=1;
			c = sqrt(a*a + b*b);

		}while((a+b+c!=1000) && (b<900));
	}while((a+b+c!=1000) && (a < 900));

	printf("a = %f, b = %f, c = %f\n",a,b,c);
	printf("a+b+c = %f, a*b*c = %f\n",a+b+c,a*b*c);
}