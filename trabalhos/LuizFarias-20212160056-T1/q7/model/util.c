#include "util.h"

void espere(int segundos){
    if (CLEAR=="cls"){
        sleep(segundos);
    }else{
        usleep(segundos * 1000);
    }
}