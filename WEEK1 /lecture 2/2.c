#include <stdio.h>
#define PI 3.14
int main()
{
	int r = 2, area;
	printf("The radius of circle is %d.\n",r);
	area = PI * (r * r);
	printf("Area of the circle = %d.\n", area);
	return 0;
}