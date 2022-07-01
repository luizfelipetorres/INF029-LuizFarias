/*

*/

#include <stdio.h>

void printEvenNumber0toN(int n){
    if (n >= 0){
        if (n % 2 != 0)
            printEvenNumber0toN(n - 1);
        else{
            printf("%d ", n);
            printEvenNumber0toN(n - 2);
        }
    }
}

int main(){
    printEvenNumber0toN(11);
    return 0;
}
