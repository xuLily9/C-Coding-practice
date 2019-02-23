

#include<stdio.h>
int main ()
{
	int numbers;/*initialize integers*/
	char characters;/*initialize characters*/
	
    while(scanf("%d",&numbers)!=EOF)/*loop for inputing a list of integers */
    {      
    	if(numbers >= 0)/*make sure the input number is positive */
    	{
			characters = (char) numbers; /*convert integers(ASCII code to characters*/
	        printf("%c",characters);/*output a list of characters*/
    	}

    	if(numbers <0 )/*if the the input integer is not positive then break*/
    	{
    		break;
    	}
    }
    return 0;
}