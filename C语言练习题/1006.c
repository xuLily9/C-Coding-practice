#include<stdio.h>
int main(void) {
    int a, b, c;
    printf("Please enter 3 numbers: ")
    scanf("%d%d%d", &a, &b, &c);
    if(a > 10 || a < 0 || b > 10 || b < 0 || c > 5 || c < 0){
        return 0;
    }else{
	printf("%d", a+b+c);	
    }
    
    return 0;
	
}