#include <stdio.h>

int Fibonacci(int n) {
    int a = 0, b = 1, temp;
    
    // Caso o número informado seja 0 ou 1, ele pertence à sequência
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Gera a sequência de Fibonacci até que o valor atual seja maior ou igual ao número informado
    while (b < n) {
        temp = a + b;
        a = b;
        b = temp;
    }
    
    // Retorna 1 se o número informado pertence à sequência, caso contrário, retorna 0
    return b == n;
}

int main() {
    int num;
    
    // Solicita ao usuário o número a ser verificado
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    // Verifica se o número pertence à sequência de Fibonacci e imprime a mensagem correspondente
    if (Fibonacci(num)) {
        printf("%d pertence à sequência de Fibonacci.\n", num);
    } else {
        printf("%d não pertence à sequência de Fibonacci.\n", num);
    }

    return 0;
}
//Dev C estava com problemas de compilador, recomendo testar no code blocks ou visual studio.