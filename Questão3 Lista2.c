#include <stdio.h>

int main() {
  //  entrada
  int matriz_a[4][4], matriz_b[4][4], matriz_resultado[4][4];
  char operacao[10];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &matriz_a[i][j]);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &matriz_b[i][j]);
    }
  }
  scanf("%s", operacao);

  //  operação entre as matrizes.
  switch (operacao[0]) {
    case 's':
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          matriz_resultado[i][j] = matriz_a[i][j] + matriz_b[i][j];
        }
      }
      break;
    case 'u':
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          matriz_resultado[i][j] = matriz_a[i][j] - matriz_b[i][j];
        }
      }
      break;
    case 'm':
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          matriz_resultado[i][j] = 0;
          for (int k = 0; k < 4; k++) {
            matriz_resultado[i][j] += matriz_a[i][k] * matriz_b[k][j];
          }
        }
      }
      break;
    default:
      printf("Operação inválida.\n");
      return 1;
  }

  //  saída.
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%4d", matriz_resultado[i][j]);
    }
    printf("\n");
  }

  return 0;
}
