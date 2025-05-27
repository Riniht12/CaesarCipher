/*Universidad AMERIKE
    Ing. en ciberseguridad
    Programación 1
    René Iván Huerta Tovar
    Dr. Alcides Arbona*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cifrado(char c, int desplazamiento) {
    if (c >= 'A' && c <= 'Z') {
        return ((c - 'A' + desplazamiento) % 26) + 'A'; //Con el %26, es el mod y evita que no se pase del alfabeto
    } else if (c >= 'a' && c <= 'z') {
        return ((c - 'a' + desplazamiento) % 26) + 'a'; //Con 'A' o 'a' regresa al valor ascii
    } else {
        return c;  // No se cifra si no es letra
    }
}

int main()
{


    int i,j,k = 0;
    char mensaje[100];
    char matriz[34][3]; //Creamos el tamaño de la matriz siendo el máximo 102 para cumplir con el máximo de 100
    int desplazamiento;


    printf("Demoday Amerike 1er semestre\n");
    printf("Programación 1\n");
    printf("Cifrado César\n");

    printf("Introduce un mensaje sin espacios\n");
    scanf(" %s", mensaje);

    int largo = strlen(mensaje);
    int columna = 3;
    int fila = (largo + columna - 1)/columna;

    printf("Introduce el número de caracteres a desplazar\n");
    scanf(" %d", &desplazamiento);

    for(i=0;i<largo;i++){
        mensaje[i] = cifrado(mensaje[i], desplazamiento);
    }
    for (i=0;i<fila;i++){ //Este ciclo for anidado nos va a servir para llenar la matriz fila por fila
        for(j=0;j<columna;j++){
            if (k<largo) {
                matriz[i][j] = mensaje[k];
                k++;
            } else {
                matriz[i][j] = 'A'; //Si nos hacen falta caracteres, los va a rellenar con A's
            }
        }
    }

    printf("El mensaje cifrado es: \n");
    for (j=0;j<columna;j++){
        for(i=0;i<fila;i++){
            printf(" %c", matriz[i][j]);
        }
        printf(" \n"); //Esto es para poder imprimir el texto de manera vertical en columnas
    }


    return 0;
}
