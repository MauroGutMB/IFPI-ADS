#include <stdio.h>
#include <stdlib.h>

typedef struct ArvVar {
  char info;
  struct ArvVar *prim;
  struct ArvVar *prox;
} ArvVar;

ArvVar *arv_cria(char c){
  ArvVar *a = (ArvVar *) malloc(sizeof(ArvVar));
  a->info = c;
  a->prim = NULL;
  a->prox = NULL;

  return a;
}

void arv_insere(ArvVar *pai, ArvVar *filho){
  if(pai->prim == NULL){
    pai->prim = filho;
  } else {
    ArvVar *aux = pai->prim;
    while (aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = filho;
  }
}

void arv_imprime(ArvVar *a){
  if(a != NULL){
    printf("%c ", a->info);
    ArvVar *aux = a->prim;
    while (aux != NULL) {
      arv_imprime(aux);
      aux = aux->prox;
    }
  }
}
