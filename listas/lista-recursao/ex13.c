/*

*/

#include <stdio.h>

void imprimirNa0(int n){
    if (n >= 0){
        printf("%d ", n);
        imprimirNa0(n - 1);
    }
}

int main(){
    imprimirNa0(10);
    return 0;
}
