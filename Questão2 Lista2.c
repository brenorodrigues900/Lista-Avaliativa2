#include <stdio.h>

typedef struct {
   char nome[30];
   char posicao;
   int forca;
   char time[30];
} Jogador;

float get_forca(Jogador jogador) {
   switch (jogador.posicao) {
       case 'G':
           return 8 * jogador.forca / 100;
       case 'L':
           return 10 * jogador.forca / 100;
       case 'Z':
           return 5 * jogador.forca / 100;
       case 'V':
           return 8 * jogador.forca / 100;
       case 'M':
           return 11 * jogador.forca / 100;
       case 'A':
           return 12 * jogador.forca / 100;
   }

   return 0;
}

float get_forca_ponderada(Jogador *jogadores) {
   float forca_ponderada = 0;

   for (int i = 0; i < 11; i++) {
       forca_ponderada += get_forca(jogadores[i]);
   }

   return forca_ponderada;
}

char *get_time_mais_forte(Jogador *jogadores1, Jogador *jogadores2) {
   float forca_ponderada1 = get_forca_ponderada(jogadores1);
   float forca_ponderada2 = get_forca_ponderada(jogadores2);

   if (forca_ponderada1 > forca_ponderada2) {
       return jogadores1[0].time;
   } else if (forca_ponderada1 < forca_ponderada2) {
       return jogadores2[0].time;
   } else {
       return "Empate";
   }
}

int main() {
   Jogador jogadores1[12], jogadores2[12];

   // entrada
   scanf("%30s", jogadores1[0].time);
   for (int i = 0; i < 11; i++) {
       scanf("%30s %c %d", jogadores1[i].nome, &jogadores1[i].posicao, &jogadores1[i].forca);
   }
   scanf("%30s", jogadores2[0].time);
   for (int i = 0; i < 11; i++) {
       scanf("%30s %c %d", jogadores2[i].nome, &jogadores2[i].posicao, &jogadores2[i].forca);
   }

   // saida
   printf("%s\n", get_time_mais_forte(jogadores1, jogadores2));

   return 0;
}