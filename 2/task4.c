#include <stdio.h>
int main(void)
{
    printf("\nSolution:\n"
           "A → B = !A||B\n");
    printf("----------\n A| B|A→B|\n%2d|%2d|%3d|\n%2d|%2d|%3d|\n%2d|%2d|%3d|\n%2d|%2d|%3d|\n----------\n", 0,0,1, 0,1,1, 1,0,0, 1,1,1);
    printf("------------\n A| B|!A||B|\n%2d|%2d|%5d|\n%2d|%2d|%5d|\n%2d|%2d|%5d|\n%2d|%2d|%5d|\n------------\n", 0,0,1, 0,1,1, 1,0,0, 1,1,1);
    printf("identical\n\n");

        printf("\nSolution:\n"
           "A ↔︎ B = (A && B) || (!A && !B)\n");
    printf("----------\n a| b|A↔︎B|\n%2d|%2d|%3d|\n%2d|%2d|%3d|\n%2d|%2d|%3d|\n%2d|%2d|%3d|\n----------\n", 0,0,1, 0,1,0, 1,0,0, 1,1,1);
    printf("-----------------------\n a| b|(A&&B)||(!A&&!B)|\n%2d|%2d|%16d|\n%2d|%2d|%16d|\n%2d|%2d|%16d|\n%2d|%2d|%16d|\n-----------------------\n", 
           0,0,1, 0,1,0, 1,0,0, 1,1,1);
    printf("identical\n\n");
    return 0;
}