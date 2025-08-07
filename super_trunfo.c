#include <stdio.h>
#include <string.h>

int main() {
    // Variáveis para a primeira carta
    char estado1;
    char pais1[50];
    float area1;
    int populacao1;
    float idh1;
    float pib1;

    // Variáveis para a segunda carta
    char estado2;
    char pais2[50];
    float area2;
    int populacao2;
    float idh2;
    float pib2;

    // Primeira carta
    printf("Cadastro da primeira carta:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Nome do país: ");
    scanf(" %[^\n]s", pais1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("População: ");
    scanf("%d", &populacao1);
    printf("IDH: ");
    scanf("%f", &idh1);
    printf("PIB (em trilhões US$): ");
    scanf("%f", &pib1);

    // Segunda carta
    printf("\nCadastro da segunda carta:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Nome do país: ");
    scanf(" %[^\n]s", pais2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("IDH: ");
    scanf("%f", &idh2);
    printf("PIB (em trilhões US$): ");
    scanf("%f", &pib2);

    // Exibição das cartas cadastradas
    printf("\nCartas cadastradas:\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("País: %s\n", pais1);
    printf("Área: %.2f km²\n", area1);
    printf("População: %d\n", populacao1);
    printf("IDH: %.3f\n", idh1);
    printf("PIB: %.2f trilhões US$\n", pib1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("País: %s\n", pais2);
    printf("Área: %.2f km²\n", area2);
    printf("População: %d\n", populacao2);
    printf("IDH: %.3f\n", idh2);
    printf("PIB: %.2f trilhões US$\n", pib2);

    return 0;
}
