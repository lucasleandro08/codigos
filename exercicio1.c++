#include <stdio.h>
#include <conio.h>
int INDICE = 13;
int SOMA = 0;
int K = 0;

while (K < INDICE) {
    K = K + 1;
    SOMA = SOMA + K;
}

printf("%d", SOMA);
//valor final de K será 91