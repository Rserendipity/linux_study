#include <stdio.h>
#include "Add.h"
#include "Sub.h"

int main()
{
    int a = 10;
    int b = 20;
    printf("a+b = %d\n", Add(a, b));
    printf("a-b = %d\n", Sub(a, b));
    return 0;
}