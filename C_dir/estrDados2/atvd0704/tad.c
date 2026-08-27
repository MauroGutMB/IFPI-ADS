#include "tad.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct prod {
  char nome[50];
  float preco;
  int estoque;
  struct prod *esq;
  struct prod *dir;
} Produto;

// criar um novo produto
Produto* criarProduto(char nome[], float preco, int estoque) {
  Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
  if (novoProduto != NULL) {
    strcpy(novoProduto->nome, nome);
    novoProduto->preco = preco;
    novoProduto->estoque = estoque;
    novoProduto->esq = NULL;
    novoProduto->dir = NULL;
  }
  return novoProduto;
}

//consultar um produto
Produto* consultarProduto(Produto* raiz, char nome[]) {
  if (raiz == NULL) {
    return NULL;
  }
  if (strcmp(nome, raiz->nome) == 0) { // caso encontre o produto
    return raiz;
  }
  if (strcmp(nome, raiz->nome) < 0) { // se o nome do produto for menor, procurar na subárvore esquerda
    return consultarProduto(raiz->esq, nome);
  } else {
    return consultarProduto(raiz->dir, nome); // se o nome do produto for maior, procurar na subárvore direita
  }
}

//atualizar um produto
void atualizarProduto(Produto* raiz, char nome[], float preco, int estoque) {
  Produto* produto = consultarProduto(raiz, nome);
  if (produto != NULL) {
    produto->preco = preco;
    produto->estoque = estoque;
  }
}

//remover um produto
Produto* removerProduto(Produto* raiz, char nome[]) {
  if (raiz == NULL) {
    return NULL;
  }
  if (strcmp(nome, raiz->nome) < 0) {
    raiz->esq = removerProduto(raiz->esq, nome);
  } else if (strcmp(nome, raiz->nome) > 0) {
    raiz->dir = removerProduto(raiz->dir, nome);
  } else {
    if (raiz->esq == NULL) {
      Produto* temp = raiz->dir;
      free(raiz);
      return temp;
    } else if (raiz->dir == NULL) {
      Produto* temp = raiz->esq;
      free(raiz);
      return temp;
    }
    Produto* temp = raiz->dir;
    while (temp->esq != NULL) {
      temp = temp->esq;
    }
    strcpy(raiz->nome, temp->nome);
    raiz->preco = temp->preco;
    raiz->estoque = temp->estoque;
    raiz->dir = removerProduto(raiz->dir, temp->nome);
  }
  return raiz;
}

//listar produtos
void listarProdutos(Produto* raiz) {
  if (raiz != NULL) {
    listarProdutos(raiz->esq);
    printf("Nome: %s, Preço: %.2f, Estoque: % d\n", raiz->nome, raiz->preco, raiz->estoque);
    listarProdutos(raiz->dir);
  }
} 

// ---------------------------------------------------------------------------------------- //
// operações de contagem de nós, listagem de folhas, cálculo de altura e liberação da memória
// ---------------------------------------------------------------------------------------- //

//contagem de nós
int contarNos(Produto* raiz) {
  if (raiz == NULL) {
    return 0;
  } else {
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
  }
}

//listagem de folhas
void listarFolhas(Produto* raiz) {
  if (raiz != NULL) {
    if (raiz->esq == NULL && raiz->dir == NULL) {
      printf("Nome: %s, Preço: %.2f, Estoque: % d\n", raiz->nome, raiz->preco, raiz->estoque);
    }
    listarFolhas(raiz->esq);
    listarFolhas(raiz->dir);
  }
}

//cálculo de altura
int calcularAltura(Produto* raiz) {
  if (raiz == NULL) {
    return -1;
  } else {
    int alturaEsq = calcularAltura(raiz->esq);
    int alturaDir = calcularAltura(raiz->dir);
    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
  }
}

//liberação da memória
void liberarMemoria(Produto* raiz) {
  if (raiz != NULL) {
    liberarMemoria(raiz->esq);
    liberarMemoria(raiz->dir);
    free(raiz);
  }
}

// --------------//
// getter e setter
// --------------//

char* getNome(Produto* produto) {
  return produto->nome;
}
void setNome(Produto* produto, char nome[]) {
  strcpy(produto->nome, nome);
}

float getPreco(Produto* produto) {
  return produto->preco;
}
void setPreco(Produto* produto, float preco) {
  produto->preco = preco;
}

int getEstoque(Produto* produto) {
  return produto->estoque;
}
void setEstoque(Produto* produto, int estoque) {
  produto->estoque = estoque;
} 

struct prod* getEsq(Produto* produto) {
  return produto->esq;
}
void setEsq(Produto* produto, Produto* esq) {
  produto->esq = esq;
}

struct prod* getDir(Produto* produto) {
  return produto->dir;
}
void setDir(Produto* produto, Produto* dir) {
  produto->dir = dir;
}


