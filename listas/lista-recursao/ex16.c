/*

*/

#include <stdio.h>

int factorialDouble(int n)
{
    if (n > 0)
        if (n % 2 == 1)
            return n * factorialDouble(n - 2);

    return 1;
}

int main()
{
    printf("%d ", factorialDouble(5));
    return 0;
}
