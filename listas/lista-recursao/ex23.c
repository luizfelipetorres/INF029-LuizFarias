/*

*/

#include <stdio.h>

int padovan(int n){
    if (n >= 0 && n <= 2)
        return 1;
    
    return padovan(n - 2) + padovan(n - 3);
}

int main(){
    for (int i = 0; i < 20; i++)
    {
        printf("%d, ", padovan(i));
    }
    
    return 0;
}
