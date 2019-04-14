#include <stdio.h>
int main(){
	printf ("%c\n", 'v');/* a single character*/
	printf("%s%s\n","Hi", "Lei");
	printf("%d\n", 27);
	printf("%o\n", 27);/*8进制*/
	printf("%x\n", 27);/*a lowercase hexadecimal 16进制*/
	printf("%X\n", 27);//*a uppercase hexadecimal 16进制*/
	printf("%f\n", 1.23);/*a floating point number for floats*/
	printf("%e\n", 3.14);
	printf("%%\n");/*a % character*/
}