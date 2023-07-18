#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
	
	int maxOpcoes;
    int *opcoes;
    int i, numeroSorteado, continuar;

    // Solicitar ao usuário o número máximo de opções
    printf("Digite o número máximo de opções: ");
    scanf("%d", &maxOpcoes);

    // Alocar memória para armazenar as opções
    opcoes = (int*)malloc(maxOpcoes * sizeof(int));

    // Inicializar as opções de 1 até maxOpcoes
    for (i = 0; i < maxOpcoes; i++) {
        opcoes[i] = i + 1;
    }

    // Inicializar a semente do gerador de números aleatórios
    srand(time(NULL));

    // Loop principal
    do {
        // Sortear um número aleatório
        numeroSorteado = rand() % maxOpcoes;

        // Exibir o número sorteado
        printf("Número sorteado: %d\n", opcoes[numeroSorteado]);

        // Excluir o número sorteado das opções
        for (i = numeroSorteado; i < maxOpcoes - 1; i++) {
            opcoes[i] = opcoes[i + 1];
        }

        maxOpcoes--;

        // Verificar se deseja sortear novamente ou sair do programa
        printf("Deseja sortear novamente? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);
        printf("\n");

    } while (continuar != 0 && maxOpcoes > 0);

    // Liberar memória alocada
    free(opcoes);

    return 0;
}

