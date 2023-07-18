#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
	
	int maxOpcoes;
    int *opcoes;
    int i, numeroSorteado, continuar;

    // Solicitar ao usu�rio o n�mero m�ximo de op��es
    printf("Digite o n�mero m�ximo de op��es: ");
    scanf("%d", &maxOpcoes);

    // Alocar mem�ria para armazenar as op��es
    opcoes = (int*)malloc(maxOpcoes * sizeof(int));

    // Inicializar as op��es de 1 at� maxOpcoes
    for (i = 0; i < maxOpcoes; i++) {
        opcoes[i] = i + 1;
    }

    // Inicializar a semente do gerador de n�meros aleat�rios
    srand(time(NULL));

    // Loop principal
    do {
        // Sortear um n�mero aleat�rio
        numeroSorteado = rand() % maxOpcoes;

        // Exibir o n�mero sorteado
        printf("N�mero sorteado: %d\n", opcoes[numeroSorteado]);

        // Excluir o n�mero sorteado das op��es
        for (i = numeroSorteado; i < maxOpcoes - 1; i++) {
            opcoes[i] = opcoes[i + 1];
        }

        maxOpcoes--;

        // Verificar se deseja sortear novamente ou sair do programa
        printf("Deseja sortear novamente? (1 - Sim, 0 - N�o): ");
        scanf("%d", &continuar);
        printf("\n");

    } while (continuar != 0 && maxOpcoes > 0);

    // Liberar mem�ria alocada
    free(opcoes);

    return 0;
}

