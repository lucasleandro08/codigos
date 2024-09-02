#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h" //https://github.com/DaveGamble/cJSON <--- link da biblioteca para instalação

// Função para ler o conteúdo de um arquivo e retornar como uma string
char* lerArquivo(const char* nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", nomeArquivo);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long tamanho = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *conteudo = (char*)malloc(tamanho + 1);
    fread(conteudo, 1, tamanho, file);
    conteudo[tamanho] = '\0';
    fclose(file);
    
    return conteudo;
}

int main() {
    // Lê o arquivo JSON
    char* conteudoJson = lerArquivo("faturamento.json");
    if (conteudoJson == NULL) {
        return 1;
    }

    // Parseia o JSON
    cJSON *json = cJSON_Parse(conteudoJson);
    if (json == NULL) {
        printf("Erro ao processar o JSON.\n");
        free(conteudoJson);
        return 1;
    }

    // Variáveis para armazenar informações necessárias
    double menor = -1, maior = -1, soma = 0.0, media;
    int diasValidos = 0, diasAcimaMedia = 0;

    // Percorre os valores de faturamento
    cJSON *dia;
    cJSON_ArrayForEach(dia, json) {
        // Obtém o valor do faturamento do dia
        double valor = cJSON_GetObjectItem(dia, "valor")->valuedouble;

        // Ignora dias com faturamento zero (finais de semana/feriados)
        if (valor > 0) {
            if (menor == -1 || valor < menor) {
                menor = valor;
            }
            if (maior == -1 || valor > maior) {
                maior = valor;
            }
            soma += valor;
            diasValidos++;
        }
    }

    // Calcula a média mensal considerando apenas os dias válidos
    if (diasValidos > 0) {
        media = soma / diasValidos;
    }

    // Conta os dias com faturamento acima da média
    cJSON_ArrayForEach(dia, json) {
        double valor = cJSON_GetObjectItem(dia, "valor")->valuedouble;
        if (valor > media) {
            diasAcimaMedia++;
        }
    }

    // Imprime os resultados
    printf("Menor faturamento: %.2f\n", menor);
    printf("Maior faturamento: %.2f\n", maior);
    printf("Número de dias com faturamento acima da média: %d\n", diasAcimaMedia);

    // Limpa a memória
    cJSON_Delete(json);
    free(conteudoJson);

    return 0;
}
