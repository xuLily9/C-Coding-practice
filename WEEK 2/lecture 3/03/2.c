#include <stdio.h>
int main(){
	printf("|%3i|%-3i|\n", 12, 12);/*左边多出一个空格*/
	printf("%+i\n",17);/*for positive signed numberic*/
	printf("|% i|\n",12);/*presend a space for positive number type*/
	printf("|%04i|\n",12);/*说明有多少个位数， 缺少的位数用0补齐*/
	printf("%#X\n",26);
	printf("|%5s|\n","ABC");/*有五个数padded space on the left*/
	printf("|%-5s|\n","ABC");/*有五个数padded space on the right*/
	printf("|%-*s|\n",5,"ABC");/*有时候还会被写成这样*/
	printf("%.3f\n",3.1);/*说明有3个浮点*/
	printf("%.3f\n",3.1415);
	printf("%.3d\n",99);/*control the minimum nuber of digits printed*/
	printf("%.3s\n","abcd");/*control the maxmum length of string printed*/
	printf("I have %d modules this term\n", 5);

}