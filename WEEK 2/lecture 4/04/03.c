/* Write a program to find Maximum out of three numbers.*/
#include <stdio.h>
int main(void)
{
	int a, b, c;
	printf("Enter three integers:");
	scanf("%d%d%d", &a, &b, &c);
	if ( a > c){
		if (a > b){
			printf("%i is the biggest value\n",a );
		}
		else{
			printf("%i is the biggest value\n",b);
		}
	}
	else{
		if (c >b){
			printf("%i is the biggest value\n",c);

		}else{
			printf("%i is the biggest value\n",b);
		}
	}
}