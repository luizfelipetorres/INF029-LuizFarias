/*

*/

#include <stdio.h>

int tetranacci(int n){
    if (n < 4)
        return 0;
    
    if (n == 4)
        return 1;

    return tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
}

int main(){
    printf("%d ", tetranacci(10));
    return 0;
}
