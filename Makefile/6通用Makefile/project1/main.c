#include <stdio.h>
extern int Add(int x, int y);
int main()
{
    printf("sum = %d\n", Add(10, 20));

    return 0;
}