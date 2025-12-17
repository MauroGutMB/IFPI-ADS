#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#define N 100

/*
 * \int Vals[100]
 * \int c
 * */
typedef struct pilha {
  int vals[N];
  int c;
} Pilha;

/*
 * Retorna uma nova pilha
 * */
Pilha* pilha_cria(){
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));
  p->c = 0;

  return p;
}

/*
 * Verifica se a pilha está vazia
 * \1: true
 * \0: false
 * */
int pilha_vazia(Pilha* p){
  if(p == NULL || p->c == 0)return 1; return 0;
}

/*
 * Adiciona um elemento na pilha: int
 * */
void pilha_add(Pilha* p, int v){
  if(p == NULL || p->c == 100){
    printf("Estouro de pilha.\n");
    return;
  }
  p->vals[p->c] = v;
  p->c++;
}

/*
 * Remove um elemento da pilha: int
 * */
int pilha_remove(Pilha* p){
  p->c--;
  return p->vals[p->c+1];
}

/*
 * Busca um valor na pilha
 * \1: elemento na pilha
 * \0: elemento não presente
 * */
int pilha_busca(Pilha* p, int v){
  if(pilha_vazia(p))return 0;
  for(int i = 0; i < p->c; i++){
    if(v == p->vals[i]){
      return 1;
    }
  }
  return 0;
}

/*
 * Libera a pilha
 * */
void pilha_libera(Pilha* p){
  free(p);
}

/*
 * Imprime todos os elementos da Pilha
 * */
void pilha_imprime(Pilha* p){
  for(int i = p->c-1; i >= 0; i--){
    printf("%i\n", p->vals[i]);
  }
}
