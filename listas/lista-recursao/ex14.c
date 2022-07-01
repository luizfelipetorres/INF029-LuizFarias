/*

*/

#include <stdio.h>

void printEvenNumber0toN(int n){
    if (n >= 0){
        if (n % 2 != 0)
            printEvenNumber0toN(n - 1);
        else{
            printEvenNumber0toN(n - 2);
            printf("%d ", n);
        }
    }
}

int main(){
    printEvenNumber0toN(12);
    return 0;
}
