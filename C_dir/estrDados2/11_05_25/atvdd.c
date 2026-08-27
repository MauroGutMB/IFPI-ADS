#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main(){

  Node *a = criarNo('A');
  Node *b = criarNo('B');
  Node *c = criarNo('C');
  Node *d = criarNo('D');
  Node *e = criarNo('E');
  Node *f = criarNo('F');
  Node *g = criarNo('G');
  Node *h = criarNo('H');
  Node *i = criarNo('I');
  Node *j = criarNo('J');
  Node *k = criarNo('K');

  inserir(a, b);
  inserir(a, c);
  inserir(a, d);
  inserir(b, e);
  inserir(c, f);
  inserir(f, j);
  inserir(d, g);
  inserir(g, k);
  inserir(d, h);
  inserir(d, i);

  imprimir(a);

  printf("\n\n\n%i\n", buscabool(a, 'K'));

  liberar(a);

  return 0;
}
