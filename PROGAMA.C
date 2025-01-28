#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 32 // Máximo de cartas no jogo

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    int isSuperTrunfo; // Flag para identificar o Super Trunfo
} Carta;

// Declaração de funções
void cadastrarCartas(Carta cartas[], int *numCartas);
void exibirCartas(Carta cartas[], int numCartas);
void duelo(Carta cartas[], int numCartas);
int escolherCarta(Carta cartas[], int numCartas);
void marcarSuperTrunfo(Carta cartas[], int numCartas);

// Função principal para o menu
int main() {
    Carta cartas[MAX_CARTAS];
    int numCartas = 0; // Número de cartas cadastradas
    int opcao;

    do {
        printf("\n🔥 Super Trunfo - Países 🔥\n");
        printf("1. Cadastrar cartas\n");
        printf("2. Exibir cartas\n");
        printf("3. Realizar duelo\n");
        printf("4. Marcar Super Trunfo\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCartas(cartas, &numCartas);
                break;
            case 2:
                exibirCartas(cartas, numCartas);
                break;
            case 3:
                duelo(cartas, numCartas);
                break;
            case 4:
                marcarSuperTrunfo(cartas, numCartas);
                break;
            case 5:
                printf("Encerrando o jogo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

// Função para cadastrar cartas
void cadastrarCartas(Carta cartas[], int *numCartas) {
    if (*numCartas >= MAX_CARTAS) {
        printf("Limite máximo de cartas atingido!\n");
        return;
    }

    Carta novaCarta;
    printf("\nDigite o código da cidade (exemplo: A01): ");
    scanf("%s", novaCarta.codigo);
    printf("Digite a população da cidade: ");
    scanf("%d", &novaCarta.populacao);
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &novaCarta.area);
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &novaCarta.pib);
    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &novaCarta.pontosTuristicos);

    novaCarta.isSuperTrunfo = 0; // Inicialmente, nenhuma carta é Super Trunfo

    cartas[*numCartas] = novaCarta;
    (*numCartas)++;

    printf("Carta cadastrada com sucesso!\n");
}

// Função para exibir todas as cartas cadastradas
void exibirCartas(Carta cartas[], int numCartas) {
    if (numCartas == 0) {
        printf("Nenhuma carta cadastrada.\n");
        return;
    }

    for (int i = 0; i < numCartas; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("  Código: %s\n", cartas[i].codigo);
        printf("  População: %d\n", cartas[i].populacao);
        printf("  Área: %.2f km²\n", cartas[i].area);
        printf("  PIB: %.2f bilhões de USD\n", cartas[i].pib);
        printf("  Pontos turísticos: %d\n", cartas[i].pontosTuristicos);
        if (cartas[i].isSuperTrunfo) {
            printf("  *** SUPER TRUNFO ***\n");
        }
    }
}

// Função para realizar duelo entre duas cartas
void duelo(Carta cartas[], int numCartas) {
    if (numCartas < 2) {
        printf("É necessário cadastrar pelo menos duas cartas para realizar um duelo.\n");
        return;
    }

    printf("\nEscolha a primeira carta:\n");
    int carta1 = escolherCarta(cartas, numCartas);
    printf("\nEscolha a segunda carta:\n");
    int carta2 = escolherCarta(cartas, numCartas);

    if (cartas[carta1].isSuperTrunfo) {
        printf("\nA carta %s é o SUPER TRUNFO e venceu automaticamente!\n", cartas[carta1].codigo);
        return;
    }

    if (cartas[carta2].isSuperTrunfo) {
        printf("\nA carta %s é o SUPER TRUNFO e venceu automaticamente!\n", cartas[carta2].codigo);
        return;
    }

    printf("\nComparando cartas:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("Escolha o atributo para comparar: ");
    int atributo;
    scanf("%d", &atributo);

    int vencedor = -1;
    switch (atributo) {
        case 1:
            vencedor = (cartas[carta1].populacao > cartas[carta2].populacao) ? carta1 : carta2;
            break;
        case 2:
            vencedor = (cartas[carta1].area > cartas[carta2].area) ? carta1 : carta2;
            break;
        case 3:
            vencedor = (cartas[carta1].pib > cartas[carta2].pib) ? carta1 : carta2;
            break;
        case 4:
            vencedor = (cartas[carta1].pontosTuristicos > cartas[carta2].pontosTuristicos) ? carta1 : carta2;
            break;
        default:
            printf("Atributo inválido.\n");
            return;
    }

    printf("\nA carta vencedora é: %s\n", cartas[vencedor].codigo);
}

// Função para escolher uma carta
int escolherCarta(Carta cartas[], int numCartas) {
    for (int i = 0; i < numCartas; i++) {
        printf("%d. %s\n", i + 1, cartas[i].codigo);
    }
    int escolha;
    do {
        printf("Escolha o número da carta: ");
        scanf("%d", &escolha);
    } while (escolha < 1 || escolha > numCartas);
    return escolha - 1;
}

// Função para marcar uma carta como Super Trunfo
void marcarSuperTrunfo(Carta cartas[], int numCartas){
    printf("\nEscolha uma carta para ser o Super Trunfo:\n");
    int escolha = escolherCarta(cartas, numCartas);
    for (int i = 0; i < numCartas; i++) {
        cartas[i].isSuperTrunfo = 0; // Remove o status de Super Trunfo das outras cartas
    }
    cartas[escolha].isSuperTrunfo = 1;
    printf("A carta %s foi marcada como Super Trunfo!\n");

}
