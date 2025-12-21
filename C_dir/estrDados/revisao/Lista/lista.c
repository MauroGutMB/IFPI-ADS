#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// CORRIGIR CODIGO DEPOIS

/*
 * Estrutura da lista encadeada
 * */
typedef struct Lista {
  struct Lista *prox;
  int val;
} Lista;

/*
 * Retorna uma nova lista encadeada de ponteiro null
 * */
Lista *lista_cria() { return NULL; }

/*
 * Verifica se a lista está vazia
 * \1: true
 * \0: false
 * */
int lista_vazia(Lista *l) { return (l == NULL); }

/*
 * Insere um novo nó na lista já existente
 * */
Lista *lista_insere(Lista *l, int v) {
  Lista *nl = (Lista *)malloc(sizeof(Lista));
  nl->val = v;
  nl->prox = l;
  return nl;
  ;
}

void lista_imprime(Lista *l) {
  Lista *aux = l;
  do {
    printf("%i ", aux->val);
    if (aux->prox->prox != NULL) {
      printf("-> ");
    }
    aux = aux->prox;
  } while (aux->prox != NULL);
}

/*
 * Busca um elemento da lista e retorna seu ponteiro. Retorna NULL caso não
 * encontre
 * */
Lista *lista_busca(Lista *l, int v) {
  Lista *aux;
  for (aux = l; aux != NULL; aux = aux->prox) {
    if (aux->val == v) {
      return aux;
    }
  }
  return NULL;
}

/*
 * Remove um valor da lista e retorna o seu ponteiro
 * */
Lista *lista_remove(Lista *l, int v) {
  Lista *ant = NULL;
  Lista *atual = l;

  while ((atual != NULL) && (atual->val != v)) {
    ant = atual;
    atual = atual->prox;
  }

  if (atual == NULL)
    return l;
  if (ant == NULL)
    l = atual->prox;
  else
    ant->prox = atual->prox;

  free(atual);
  return ant;
}

/*
 * Libera a lista completamente
 * */
void lista_libera(Lista *l) {
  while (l->prox != NULL)
    lista_libera(l->prox);
  free(l);
}
