

#include <stdio.h>
int main ()
{
	int score;/*initialize score*/
	int count_Number [3] = {0,0,0};/*initialize number of students in three segments*/ 
	
	while(scanf("%d", &score)!= 0)/*input a list of marks*/	
	{
		/*input end with 0, 0 is not someone's mark*/
		if (score <= 0)
		{
		/*if the input score is euql or less than 0, then break*/
			break;
		}
		/*count number of students whose score is at least 85*/
		if(score >= 85)
			count_Number[0]++;
		/*count number of students whose score is between 60-84*/
		if(score >= 60 && score <= 84)
			count_Number[1]++;
		/*count number of students whose score is at most 60*/
		if(score < 60)
			count_Number[2]++;		
	}

	printf(">=85:%d\n", count_Number[0]);/*output number of students whose score is at least 85*/
	printf("60-84:%d\n", count_Number[1]);/*output number of students whose score is between 60-84*/
	printf("<60:%d\n", count_Number[2]);/*output number of students whose score is at most 60*/
	
	return 0;
}