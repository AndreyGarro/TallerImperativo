#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Estructura para las palabras
struct _palabraCantidad{
    char* dato;
    int cantPalabras;
};

//Quicksort
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (struct _palabraCantidad arr[], int low, int high) {
    int pivot = arr[high].cantPalabras;
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++){
        if (arr[j].cantPalabras >= pivot){
            i++;
            swap(&arr[i].cantPalabras, &arr[j].cantPalabras);
        }
    }
    swap(&arr[i + 1].cantPalabras, &arr[high].cantPalabras);
    return (i + 1);
}

void quickSort(struct _palabraCantidad arr[], int low, int high) {
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//____________________________________________________________________________________


int revisaListaCantidad(struct _palabraCantidad *lista, char *palabra, int tamano){
    for(int i = 0; i < tamano; i++){
        if(strcmp(lista[i].dato, palabra) == 0){
            return i;
        }
    }
    return -1;
}

void frecuenciaOcurrencia(){
    char nombre[20]="textoPrueba.txt";
    FILE *fichero;
    char palabra[800][21];
    struct _palabraCantidad lista[800];
    char c;
    int lineaActual = 1;
    int flag = 0;
    int i = 0;
    int j = 0;
    int pos = 0;

    fichero = fopen( nombre, "r" );
    if( fichero )
        printf( "ABIERTO\n" );
    else{
        printf( "NO ABIERTO\n" );
    }

    while(1){
        c = tolower(fgetc(fichero));
        if(c == EOF){
            break;
        }
        if((c == ',' | c == '.' | c == ';' | c == ' ' | c == ':' | c == '\n') && flag == 1){
            pos = revisaListaCantidad(lista, palabra[i], i);
            if(pos == -1){
                struct _palabraCantidad palabrax = {palabra[i], 1};
                lista[i] = palabrax;
                i++;
            }else{
                lista[pos].cantPalabras ++;
            }
            j=0;
            flag = 0;
        }else if(c == ',' | c == '.' | c == ';' | c == ' ' | c == ':' | c == '\n') {
            continue;
        }else{
            palabra[i][j] = c;
            j++;
            flag = 1;
        }
    }
    if(flag == 1){
        if(pos == -1){
            struct _palabraCantidad palabrax = {palabra[i], 1};
            lista[i] = palabrax;
            i++;
        }else{
            lista[pos].cantPalabras ++;
        }
    }

    quickSort(lista, 0, i);
    for(int k = 0; k < i; k++){
        printf("%s | %d\n", lista[k].dato, lista[k].cantPalabras);
    }
    fclose(fichero);
}
