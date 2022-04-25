#include "global/util.h"
#include "view/map.h"
#include "view/menu.h"
#include "model/objects.h"
#include "controller/controller.h"


void main(){
  Ponto *p1[10][10];
  
  setlocale(LC_ALL, "Portuguese");

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      p1[i][j] = criarPonto();
    }
  }
  
  menu();

}