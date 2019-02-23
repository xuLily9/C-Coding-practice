

#include<stdio.h>
int main()
{
	int a, b;/*initialize two positive integers*/
	int n_digit;/*initialize the n-th digit after decimal point*/
    /*input three integers a, b, and n_digit*/
	scanf("%d%d%d", &a, &b, &n_digit);
    /*making sure the input intergers are positive*/
    if(a > 0 && b > 0 && n_digit > 0)
    {
    /*making sure the input integers are all at most 6000*/
        if(a <= 6000 && b <= 6000 && n_digit <= 6000)
        { /*compute a/b and get the float result */      
            float division  = (float)a/(float)b;
            /*loop for get the n-th digit after decimal point*/
            for(int decimal_place = 1; decimal_place <= n_digit; decimal_place++)
            {
                division *= 10;
            }
            /*convert the float data type to integer data type*/
            n_digit = (int)division;
            printf("%d\n", n_digit%10);/*output n-th digit number*/
        } 
    }
       
    return 0;
}