/*

*/

#include <stdio.h>

int tribonacci(int n){
    if (n < 3)
        return 0;
    
    if (n == 3)
        return 1;

    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

int main(){
    printf("%d ", tribonacci(9));
    return 0;
}
