#include <stdio.h>

#define T 20

// ------------------- //

void preencher_com_vazio(int bt[T]);
int filho_esquerdo(int raiz);
int filho_direito(int raiz);

int main(){

  int arvore[T];
  preencher_com_vazio(arvore);

  arvore[0] = 2;                   // 0
  arvore[filho_esquerdo(0)] = 7;   // 1
  arvore[filho_direito(0)] = 5;    // 2
  arvore[filho_esquerdo(1)] = 2;   // 3
  arvore[filho_direito(1)] = 6;    // 4
  arvore[filho_direito(2)] = 9;    // 5
  arvore[filho_esquerdo(4)] = 5;   // 6
  arvore[filho_direito(4)] = 11;   // 7
  arvore[filho_esquerdo(5)] = 4;   // 8

  for(int i = 0; i < T; i++){
    if(arvore[i] != -1)
    printf("%i ", arvore[i]);
  }

  return 0;
}

void preencher_com_vazio(int bt[T]){
  for(int i = 0; i < T; i++){
    bt[i] = -1;
  }
}

int filho_esquerdo(int raiz){
  return 2 * raiz + 1;
}

int filho_direito(int raiz){
  return 2 * raiz + 2;
}
