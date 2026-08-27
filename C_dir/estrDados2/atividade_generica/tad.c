#include <stdio.h>
#include <stdlib.h>

typedef struct arvvar ArvVar;
struct arvvar {
  char info;
  ArvVar *prim;
  ArvVar *prox;
};
ArvVar *arv_cria(char c) {
  ArvVar *a = (ArvVar *)malloc(sizeof(ArvVar));
  a->info = c;
  a->prim = NULL;
  a->prox = NULL;
  return a;
}
void arv_insere(ArvVar *pai, ArvVar *filho) {
  if (pai->prim == NULL) {
    pai->prim = filho;
  } else {
    ArvVar *aux = pai->prim;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = filho;
  }
}
void arv_imprime(ArvVar *a) {
  if (a != NULL) {
    printf("%c ", a->info);
    ArvVar *aux = a->prim;
    while (aux != NULL) {
      arv_imprime(aux);
      aux = aux->prox;
    }
  }
}
int arv_pertence(ArvVar *a, char c) {
  if (a == NULL) {
    return 0;
  }
  if (a->info == c) {
    return 1;
  }
  ArvVar *aux = a->prim;
  while (aux != NULL) {
    if (arv_pertence(aux, c)) {
      return 1;
    }
    aux = aux->prox;
  }
  return 0;
}

int altura_arv(ArvVar *a) {
  if (a == NULL) {
    return -1;
  }
  int max_altura = -1;
  ArvVar *aux = a->prim;
  while (aux != NULL) {
    int altura_filho = altura_arv(aux);
    if (altura_filho > max_altura) {
      max_altura = altura_filho;
    }
    aux = aux->prox;
  }
  return max_altura + 1;
}

int contar_nos(ArvVar *a) {
  if (a == NULL) {
    return 0;
  }
  int count = 1; // Contar o nó atual
  ArvVar *aux = a->prim;
  while (aux != NULL) {
    count += contar_nos(aux); // Contar os nós dos filhos
    aux = aux->prox;
  }
  return count;
}

int contar_folhas(ArvVar *a) {
  if (a == NULL) {
    return 0;
  }
  if (a->prim == NULL) {
    return 1; // Nó folha
  }
  int count = 0;
  ArvVar *aux = a->prim;
  while (aux != NULL) {
    count += contar_folhas(aux); // Contar as folhas dos filhos
    aux = aux->prox;
  }
  return count;
}

void arv_libera(ArvVar *a) {
  if (a != NULL) {
    ArvVar *aux = a->prim;
    while (aux != NULL) {
      ArvVar *prox_aux = aux->prox; // Salvar o próximo antes de liberar
      arv_libera(aux); // Liberar o filho
      aux = prox_aux; // Avançar para o próximo filho
    }
    free(a); // Liberar o nó atual
  }
}
