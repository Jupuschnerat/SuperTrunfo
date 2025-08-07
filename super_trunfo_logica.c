#include <stdio.h>
#include <string.h>

// Definição da estrutura para representar uma carta
typedef struct {
    char estado[3];             // Sigla do estado (ex: SP)
    char codigo[10];            // Código da carta
    char cidade[50];            // Nome da cidade
    int populacao;              // População em habitantes
    float area;                 // Área em km²
    float PIB;                  // PIB em milhões de reais
    int pontos_turisticos;      // Número de pontos turísticos
    float densidade_populacional; // Calculado: população/área
    float PIB_per_capita;       // Calculado: PIB/população
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("\nCadastro de Carta:\n");
    printf("Estado (sigla): ");
    scanf("%2s", carta->estado);
    printf("Código da carta: ");
    scanf("%9s", carta->codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->cidade); // Lê até encontrar uma quebra de linha
    printf("População (habitantes): ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (milhões de R$): ");
    scanf("%f", &carta->PIB);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    // Cálculos derivados
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->PIB_per_capita = carta->PIB * 1000000 / carta->populacao; // Convertendo para reais/habitante
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("\nDados da Carta:\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões de R$\n", carta.PIB);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f R$/habitante\n", carta.PIB_per_capita);
}

// Função para comparar duas cartas com base em um atributo específico
void compararCartas(Carta carta1, Carta carta2) {
    // Escolha do atributo para comparação (definido no código)
    // Podemos alterar esta variável para testar diferentes comparações
    char atributo_escolhido[] = "populacao"; // Valores possíveis:
                                             // "populacao", "area", "PIB",
                                             // "densidade_populacional", "PIB_per_capita"

    printf("\nComparação de cartas (Atributo: %s):\n", atributo_escolhido);

    // Exibir os valores do atributo escolhido para ambas as cartas
    float valor1, valor2;

    if (strcmp(atributo_escolhido, "populacao") == 0) {
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
        printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);
    }
    else if (strcmp(atributo_escolhido, "area") == 0) {
        valor1 = carta1.area;
        valor2 = carta2.area;
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.area);
    }
    else if (strcmp(atributo_escolhido, "PIB") == 0) {
        valor1 = carta1.PIB;
        valor2 = carta2.PIB;
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.PIB);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.PIB);
    }
    else if (strcmp(atributo_escolhido, "densidade_populacional") == 0) {
        valor1 = carta1.densidade_populacional;
        valor2 = carta2.densidade_populacional;
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.densidade_populacional);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.densidade_populacional);
    }
    else if (strcmp(atributo_escolhido, "PIB_per_capita") == 0) {
        valor1 = carta1.PIB_per_capita;
        valor2 = carta2.PIB_per_capita;
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, carta1.PIB_per_capita);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, carta2.PIB_per_capita);
    }

    // Determinar a carta vencedora
    int vencedor = 0; // 0 = empate, 1 = carta1, 2 = carta2

    // Para densidade populacional, o menor valor vence
    if (strcmp(atributo_escolhido, "densidade_populacional") == 0) {
        if (valor1 < valor2) {
            vencedor = 1;
        } else if (valor2 < valor1) {
            vencedor = 2;
        }
    }
    // Para outros atributos, o maior valor vence
    else {
        if (valor1 > valor2) {
            vencedor = 1;
        } else if (valor2 > valor1) {
            vencedor = 2;
        }
    }

    // Exibir o resultado
    if (vencedor == 0) {
        printf("Resultado: Empate!\n");
    } else if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    }
}

int main() {
    Carta carta1, carta2;

    printf("=== Super Trunfo - Comparação de Cartas ===\n");

    // Cadastrar a primeira carta
    printf("\nCadastro da Carta 1:");
    cadastrarCarta(&carta1);
    exibirCarta(carta1);

    // Cadastrar a segunda carta
    printf("\nCadastro da Carta 2:");
    cadastrarCarta(&carta2);
    exibirCarta(carta2);

    // Comparar as cartas
    compararCartas(carta1, carta2);

    return 0;
}
