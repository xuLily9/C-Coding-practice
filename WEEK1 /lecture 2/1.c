#include <stdio.h>
void main(){
	int i = 1;
	const int x = 2;
	i = 3;
	x = 4; /*这里会出现一个错误*/
	printf("i = %d\n x = %d ", i, x);
}