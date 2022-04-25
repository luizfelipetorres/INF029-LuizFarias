#include "../global/util.h"

void printEmptyMap(){
  printf("\n");
  for(int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++)
      printf("[ ] ");
    printf("\n");
  }
printf("\n");
}