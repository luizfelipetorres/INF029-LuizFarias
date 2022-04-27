#include "util.h"

void espere(int segundos){
    if (strcmp(CLEAR, "cls") == 1){
        sleep(segundos);
    }else{
        usleep(segundos * 1000);
    }
}