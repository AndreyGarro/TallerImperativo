#include <stdio.h>
#include <stdlib.h>

void strcat1(char *dest, char *src){
    int i;
    int j;

    for(i = 0; *(dest + i) != '\0'; i++){
        continue;
    }

    for(j = 0; *(src + j) != '\0'; j++){
        *(dest + j + i) = *(src + j);
    }

    *(dest + j + i) = '\0';

    for(int i = 0; *(dest + i) != '\0'; i++){
    	printf("%c", *(dest+i));
    }
    printf("\n");
}
