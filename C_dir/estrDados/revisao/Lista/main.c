#include "lista.h"
#include <stdio.h>

int main() {
  Lista *minha_lista = lista_cria();
  minha_lista = lista_insere(minha_lista, 10);

  printf("Conteúdo da lista:\n");
  lista_imprime(minha_lista);

  int valor_procurado = 20;
  Lista *resultado_busca = lista_busca(minha_lista, valor_procurado);
  if (resultado_busca != NULL) {
    printf("\nValor %d encontrado na lista.\n", valor_procurado);
  } else {
    printf("\nValor %d não encontrado na lista.\n", valor_procurado);
  }

  lista_libera(minha_lista);

  return 0;
}
