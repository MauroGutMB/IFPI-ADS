#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define N 100

/*
 * \int vals[100]
 * \int c
 * \int ini
 * */
typedef struct fila {
  int vals[N];
  int n;
  int ini;
} Fila;

/*
 * Criar uma nova fila.
 * */
Fila* fila_cria(){
  Fila* f = (Fila*) malloc(sizeof(Fila)); 
  if(f == NULL)return NULL;
  f->n = 0;
  f->ini = 0;

  return f;
}

/*
 * Verificar se a fila está vazia
 * \1: true
 * \0: false
 * */
int fila_vazia(Fila* f){
  if(f == NULL || f->n == 0)return 1; return 0;
}

/*
 * Adicionar um elemento na fila
 * */
void fila_add(Fila* f, int v){
  if(f->n == 100){
    printf("Estouro de fila.\n");
    return;
  } 
  int index = (f->ini + f->n) % N;
  f->vals[index] = v;
  f->n++;
}

/*
 * Remover um elemento da fila
 * \return valor removido
 * */
int fila_remove(Fila* f){
  if(fila_vazia(f)){
    printf("Fila vazia.\n");
    return 0;
  }
  int v = f->vals[f->ini];
  f->vals[f->ini] = 0;

  f->ini++;
  f->n--;

  return v;
}

/*
 * Imprime todos os valores da fila
 * */
void fila_imprime(Fila* f){
  for(int i = f->ini; i < (f->ini + f->n); i++){
    printf("%i ", f->vals[i%N]);
  }
}

/*
 * Libera uma fila
 * */
void fila_libera(Fila* f){
  free(f);
}
