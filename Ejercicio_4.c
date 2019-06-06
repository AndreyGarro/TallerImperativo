
int contarPares_aux(int num, int cont){
    if (num==0){
        return cont;
    }
    else if((num%10) % 2 == 0){
        return contarPares_aux(num/10, cont+1);
    } else{
        return contarPares_aux(num/10, cont);
    }
}

int contarPares(int num){
    if(num == 0){
        return 1;
    }
    else{
        return contarPares_aux(num, 0);
    }
}