#include <stdio.h>
#include "Ejercicio_1.c"
#include "Ejercicio_2.c"
#include "Ejercicio_4.c"
#include "Ejercicio_6.c"
#include "Ejercicio_7.c"
#include "Ejercicio_8.c"
#include "Ejercicio_9.c"
#include "Ejercicio_3.c"

int main() {

    /**
     * Prueba Ejercicio 1: Equivalente en millas
     */

    printf("Ejercicio 1.\n");
    equivalenteMillas();
    printf("-----------------------------------------------------\n");

    /**
     * Prueba Ejercicio 2: Equivalente en Farenheit
     */

    printf("Ejercicio 2. Con 30, 50 y 0\n");
    conversionCentigradosFarenheit(30);
    conversionCentigradosFarenheit(50);
    conversionCentigradosFarenheit(0);
    printf("-----------------------------------------------------\n");

    /**
     *Ejercicio 3 y 4: Cantidad de digitos de un numero y numeros pares
     * con 0, 134, 8765 y 98765432
     */

    printf("Ejercicio 3 y 4\n");

    int cantidad = contarDigitos(0);
    int pares = contarPares(0);
    printf("Cantidad de digitos para 0: %d y la cantidad de digitos pares: %d\n", cantidad, pares);
    cantidad = contarDigitos(134);
    pares = contarPares(134);
    printf("Cantidad de digitos para 134: %d y la cantidad de digitos pares: %d\n", cantidad, pares);
    cantidad = contarDigitos(8765);
    pares = contarPares(8765);
    printf("Cantidad de digitos para 8765: %d y la cantidad de digitos pares: %d\n", cantidad, pares);
    cantidad = contarDigitos(98765432);
    pares = contarPares(98765432);
    printf("Cantidad de digitos para 98765432: %d y la cantidad de digitos pares: %d\n", cantidad, pares);

    printf("-----------------------------------------------------\n");

    /**
     * Ejercicio 5 y 6: Comparar dos string.
     */

    printf("Ejercicio 6.\n");
    char s1[] = "hola\0";
    char p1[] = "hola\0";
    printf("Para s = hola y p = hola: %d\n", strcmp1(s1, p1));
    char s2[] = "hola\0";
    char p2[] = "adios\0";
    printf("Para s = hola y p = adios: %d\n", strcmp1(s2, p2));
    char s3[] = "adios\0";
    char p3[] = "hola\0";
    printf("Para s = adios y p = hola: %d\n", strcmp1(s3, p3));
    printf("-----------------------------------------------------\n");

    /**
     * Ejercicio 7. Pegar al final de string otro string.
     */
    printf("Ejercicio 7.\n");

    char s4[] = "hola\0";
    char p4[] = " mundo!\0";
    printf("Uniendo 'hola' y ' mundo!': ");
    strcat1(s4, p4);

    char s5[] = "adios\0";
    char p5[] = " mundo!\0";
    printf("Uniendo 'adios' y ' mundo!': ");
    strcat1(s5, p5);

    printf("-----------------------------------------------------\n");

    /**
     * Ejercicio 8: Lista de palabras de un documento y
     * su línea de aparicion. Se utiliza el .txt dentro
     * de la carpeta del taller.
     */

    printf("Ejericio 8. Utilizando el textoPrueba.txt\n");

    listaPalabras();

    printf("-----------------------------------------------------\n");

    /**
     * Ejercicio 8: Lista de palabras de un documento y
     * su línea de aparicion. Se utiliza el .txt dentro
     * de la carpeta del taller.
    */

    printf("Ejericio 9. Utilizando el textoPrueba.txt y ordenando mediante Quicksort\n");

    frecuenciaOcurrencia();

    printf("-----------------------------------------------------\n");

    return (EXIT_SUCCESS);
}