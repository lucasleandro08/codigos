#include <stdio.h>
#include <string.h>

void inverterString(char str[]) {
    int tamanho = 0;
    // Calcula o comprimento da string manualmente
    while (str[tamanho] != '\0') {
        tamanho++;
    }
    
    // Inverte a string
    for (int i = 0; i < tamanho / 2; i++) {
        char temp = str[i];
        str[i] = str[tamanho - 1 - i];
        str[tamanho - 1 - i] = temp;
    }
}

int main() {
    char string[100];  // Define um tamanho máximo para a string

    // Solicita ao usuário para inserir uma string
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);
    
    // Remove o caractere de nova linha que fgets pode adicionar
    string[strcspn(string, "\n")] = '\0';

    // Inverte a string usando a função definida
    inverterString(string);

    // Exibe a string invertida
    printf("String invertida: %s\n", string);

    return 0;
}
