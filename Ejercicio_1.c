#include <stdio.h>
#include <stdlib.h>

void equivalenteMillas() {
    
    int rangoKilometros[10] = {1,2,3,4,5,6,7,8,9,10};
    
    for(int i = 0; i<10; i++){
        printf("El equivalente de %dkm es %f millas\n\0" , rangoKilometros[i], rangoKilometros[i]*0.621371);
    }

}

