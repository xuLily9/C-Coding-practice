#include <stdio.h>
int main(void)
{
    int score1, score2;
    printf("Enter scores for two tests: ");
    scanf("%d%d", &score1, &score2);
    switch( (score1 + score2) / 2 / 10 )
    {
        case 10:
        case 9:
        case 8:
            printf("Distinction.\n");
            break;
        case 7:
        case 6:
            printf("First Division.\n");
            break;
        case 5:
            printf("Second Division.\n");
            break;
        case 4:
            printf("Pass.\n");
            break;
        default:
            printf("Fail.\n");
    }
    return 0;
}
