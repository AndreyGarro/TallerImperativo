#include <stdio.h>
#include <stdlib.h>

int contarDigitosAux(int num, int cont){
    if(num == 0){
        return 0;
    }else{
        return cont + contarDigitosAux(num/10, cont++);
    }
}

int contarDigitos(int num){
    if(num == 0){
        return 1;
    }else{
        return contarDigitosAux(num, 0);
    }
}
