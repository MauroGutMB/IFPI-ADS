#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  char info;
  struct Node *prim;
  struct Node *prox;
} Node;

int isset(Node *node){
  return node != NULL;
}

Node* criarNo(char info){
  Node *novo = (Node*)malloc(sizeof(Node));
  novo->info = info;
  novo->prim = NULL;
  novo->prox = NULL;
  return novo;
}

void inserir(Node *raiz, Node *prox){
  if(isset(raiz)){
    if(raiz->prim == NULL){
      raiz->prim = prox;
    } else {
      Node *aux = raiz->prim;
      while(aux->prox != NULL){
        aux = aux->prox;
      }
      aux->prox = prox;
    }
  }
}

void imprimir(Node *raiz){
  if(isset(raiz)){
    printf("<%c", raiz->info);
    Node *aux = raiz->prim;
    while(aux != NULL){
      imprimir(aux);
      aux = aux->prox;
    }
    printf(">");
  }
}

void liberar(Node *raiz){
  if(raiz->prim != NULL){
    Node *aux = raiz->prim;
    while(aux != NULL){
      liberar(aux);
      Node *temp = aux;
      aux = aux->prox;
      free(temp);
    }
  }
}

// retornar o ponteiro pro valor inserido
Node* busca(Node *root, char c){
  if(isset(root)){
    if(root->info == c){
      return root;
    } else {
      Node *aux = root->prim;
      while(aux != NULL){
        Node *res = busca(aux, c);
        if(isset(res)){
          return res;
        }
        aux = aux->prox;
      }
    }
  }
  return NULL;
}

int buscabool(Node *root, char c){
  if(isset(root)){
    if(root->info == c){
      return 1;
    } else {
      Node *aux = root->prim;
      while(aux != NULL){
        if(buscabool(aux, c)){
          return 1;
        }
        aux = aux->prox;
      }
    }
  }
  return 0;
}
