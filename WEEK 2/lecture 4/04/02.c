/*Write a program to check if a given number is even or odd. */
#include <stdio.h>
int main(void)
{
	int var;
	printf("Enter a number: ");
	scanf("%d", &var);
	if ( var % 2 ==0)
	{
		printf("You entered an Event Number.\n");
	}
	else
	{
		printf("You entered an Odd Number\n");
	}
	return 0;
}