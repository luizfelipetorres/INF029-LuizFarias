/*

*/

#include <stdio.h>

void imprimir0aN(int n){
    if (n > 0)
        imprimir0aN(n - 1);
    printf("%d ", n);
}

int main(){
    imprimir0aN(10);
    return 0;
}
