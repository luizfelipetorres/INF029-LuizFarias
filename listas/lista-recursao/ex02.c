/*
2)  Faça  uma  função  recursiva  que  calcule  e  retorne  o  N-ésimo  termo  da  sequência
Fibonacci. Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...
*/

#include <stdio.h>

int fib(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int x;
    printf("Digite um número: ");
    scanf("%d", &x);

    for (int i = 1; i <= x; i++)
    {
        printf("%d, ", fib(i));
    }

    return 0;
}
