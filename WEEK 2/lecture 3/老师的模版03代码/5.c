#include <stdio.h>
int main(void)
{
    int a, b, c, max;
    printf("Enter three numbers: ");
    scanf("%d%d%d", &a, &b, &c);
    max = ( a > b ) ? a : b;
    max = ( max > c ) ? max : c;
    printf("Maximum value = %d\n", max);
    return 0;
}