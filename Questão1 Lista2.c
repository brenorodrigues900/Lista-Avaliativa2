#include <stdio.h>

int main() {
    int entrada[10], novo_conjunto[10];

    //  entrada
    for (int i = 0; i < 10; i++) {
        scanf("%d", &entrada[i]);
    }

    // Processamento
    for (int i = 0; i < 10; i++) {
        // Inicialização do novo conjunto
        for (int j = 0; j < 10; j++) {
            novo_conjunto[j] = 0;
        }

        // A soma valores da janela deslizante
        for (int j = 0; j < 10 - i; j++) {
            novo_conjunto[j] = entrada[i + j] + novo_conjunto[j];
        }

        //  novo conjunto
        printf("%d ", novo_conjunto[0]);
        for (int j = 1; j < 10; j++) {
            printf("%d ", novo_conjunto[j]);
        }
        printf("\n");
    }

    return 0;
}
