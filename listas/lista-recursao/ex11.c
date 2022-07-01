/*

*/

#include <stdio.h>

int Multip_rec(int n1, int n2){

    if (n2 > 0)
        return n1 + Multip_rec(n1, n2 - 1);
    return 0;
}

int main(){
    printf("%d", Multip_rec(10, 3));
    return 0;
}
