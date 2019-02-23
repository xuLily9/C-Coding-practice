

#include<stdio.h>
int main()
{
/* constant PI to 3.14*/
const float PI = 3.14;
	/*initialize two radius of circles*/
	int radius_1, radius_2; 
	int c;
	/*initialize area and circumference of circles*/
	float area = 0.0, circumference= 0.0;
	/*input the two radius，radius_1, radius_2*/
	scanf("%d%d",&radius_1, &radius_2 );	
	if(radius_1 > radius_2)/*if statement to assign bigger value to radius_2*/
	{
		c = radius_2;
		/*assign the larger value to radius_2 */
		radius_2 = radius_1;
		/*assign the smaller value to radius_1 */
		radius_1 = c;
	}
	/*loop for adding the sum of area and circumference*/
	for(;radius_1 <= radius_2;++radius_1)
    {	
   		/*sum the area */
    	area += radius_1 * radius_1 * PI;
    	/*sum the circumference*/
		circumference += 2 * PI * radius_1;	
	}	

	printf("%.3f\n",area);/*output sum of area*/
	printf("%.3f\n", circumference);/*output sum of circumference*/
	return 0;
}