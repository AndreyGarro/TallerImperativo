#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct _palabra{
	char* dato;
	int cantLineas;
	int numLinea[5];
};


int revisaLista(struct _palabra *lista, char *palabra, int tamano){
	for(int i = 0; i < tamano; i++){
		if(strcmp(lista[i].dato, palabra) == 0){
			return i;
		}
	}
	return -1;
}

void listaPalabras(){
   char nombre[20]="textoPrueba.txt";
   FILE *fichero;
   char palabra[800][21];
   struct _palabra lista[800];
   char c;
   int lineaActual = 1;
   int flag = 0;
   int i = 0;
   int j = 0;
   int pos = 0;

   fichero = fopen( nombre, "r" );
   if( fichero )
      printf( "ABIERTO\n" );
   else
   {
      printf( "NO ABIERTO\n" );
   }

   	while(1){
   		c = tolower(fgetc(fichero));
   		if(c == EOF){
   			break;
   		}
		if((c == ',' | c == '.' | c == ';' | c == ' ' | c == ':' | c == '\n') && flag == 1){
			pos = revisaLista(lista, palabra[i], i);
			if(pos == -1){
			    struct _palabra palabrax = {palabra[i], 1, lineaActual};
				lista[i] = palabrax;
				i++;
			}else{
                int num = lista[pos].cantLineas;
                int ultimaLinea = *(lista[pos].numLinea + num - 1);
                if (ultimaLinea != lineaActual) {
                    *(lista[pos].numLinea + num) = lineaActual;
                    lista[pos].cantLineas += 1;
                }
                int k = 0;
                while (k < 21){
                    palabra[i][k] = NULL;
                    k++;
                }
			}
            if(c == '\n'){
                lineaActual++;
            }
            j=0;
            flag = 0;
		}else if(c == ',' | c == '.' | c == ';' | c == ' ' | c == ':' | c == '\n') {
            if (c == '\n') {
                lineaActual++;
            }
            continue;
        }else{
			palabra[i][j] = c;
			j++;
			flag = 1;
		}
	}

	if(flag == 1){
        pos = revisaLista(lista, palabra[i], i);
        if(pos == -1){
            struct _palabra palabrax = {palabra[i], 1, lineaActual};
            lista[i] = palabrax;
        }else{
            int num = lista[pos].cantLineas;
            int ultimaLinea = *(lista[pos].numLinea + num - 1);
            if (ultimaLinea != lineaActual) {
                *(lista[pos].numLinea + num) = lineaActual;
                lista[pos].cantLineas += 1;
            }
            int k = 0;
            while (k < 21){
                palabra[i][k] = NULL;
                k++;
            }
        }
	}
	for(int k = 0; k < i; k++){
		printf("%s | ", lista[k].dato);
		for(int j = 0; j < lista[k].cantLineas; j++){
		    printf(" %d", lista[k].numLinea[j]);
		}
		printf("\n");
	}

	fclose(fichero);
}
