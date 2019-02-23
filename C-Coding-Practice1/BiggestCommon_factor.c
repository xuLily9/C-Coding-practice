

#include<stdio.h>
int main()
{
	int number_1, number_2, c;/*initialize variables*/
	int remainder,multiple,smallest_common;/*initialize variables*/
	/* input two positive integers*/
	scanf("%d%d", &number_1, &number_2);	
	/*making sure the input integer is positive*/
	if(number_1 > 0 && number_2 > 0){
	/*if statement to assign bigger value to number_1*/
		if(number_1 < number_2)
		{
		     c = number_1;
		     number_1 = number_2; /*assign the larger number to number_1*/
		     number_2 = c; /*assign the smaller number to number_2*/
		}
		/*calculate the original multiple, before number_1, number_2 change*/
		multiple = number_1 * number_2;
		/*loop for computing the largest common factor*/
		while(number_2 != 0) 
		{ 	/*until the remainder is equal to 0*/
			remainder = number_1 % number_2; /*r is the remainder of the number_1/number_2 */ 
			/*assign number_2 value to number_1 */
			number_1 = number_2;
			/*assign remainder value to number_2*/
		    number_2 = remainder;
		}

		smallest_common = multiple/number_1;/*calculate the smallest common multiple*/
		printf("%d ", number_1); /*output their largest common factor*/
		printf("%d", smallest_common); /*output their smallest common multiple*/
	}	
	
	return 0;
}