#include "Pilha.h"
#include <stdio.h>

int main(){

  Pilha* p = pilha_cria();

  pilha_add(p, 5);
  pilha_add(p, 5);
  pilha_add(p, 5);
  pilha_add(p, 10);
  pilha_add(p, 15);
  pilha_add(p, 20);
  pilha_add(p, 25);
  pilha_add(p, 10);
  pilha_add(p, 15);
  pilha_add(p, 20);
  pilha_add(p, 25);
  pilha_add(p, 30);
  pilha_add(p, 35);
  pilha_add(p, 40);
  pilha_add(p, 45);
  pilha_add(p, 50);
  pilha_add(p, 55);
  pilha_add(p, 60);
  pilha_add(p, 65);
  pilha_add(p, 10);
  pilha_add(p, 15);
  pilha_add(p, 20);
  pilha_add(p, 25);
  pilha_add(p, 30);
  pilha_add(p, 35);
  pilha_add(p, 40);
  pilha_add(p, 45);
  pilha_add(p, 50);
  pilha_add(p, 55);
  pilha_add(p, 60);
  pilha_add(p, 65);
  pilha_add(p, 70);
  pilha_add(p, 75);
  pilha_add(p, 80);
  pilha_add(p, 85);
  pilha_add(p, 90);
  pilha_add(p, 95);
  pilha_add(p, 100);
  pilha_add(p, 5);
  pilha_add(p, 10);
  pilha_add(p, 5);
  pilha_add(p, 10);
  pilha_add(p, 15);
  pilha_add(p, 20);
  pilha_add(p, 25);
  pilha_add(p, 30);
  pilha_add(p, 35);
  pilha_add(p, 40);
  pilha_add(p, 45);
  pilha_add(p, 50);
  pilha_add(p, 55);
  pilha_add(p, 60);
  pilha_add(p, 65);
  pilha_add(p, 70);
  pilha_add(p, 75);
  pilha_add(p, 80);
  pilha_add(p, 85);
  pilha_add(p, 90);
  pilha_add(p, 95);
  pilha_add(p, 100);
  pilha_add(p, 5);
  pilha_add(p, 10);
  pilha_add(p, 15);
  pilha_add(p, 20);
  pilha_add(p, 25);
  pilha_add(p, 30);
  pilha_add(p, 35);
  pilha_add(p, 40);
  pilha_add(p, 45);
  pilha_add(p, 50);
  pilha_add(p, 55);
  pilha_add(p, 60);
  pilha_add(p, 65);
  pilha_add(p, 70);
  pilha_add(p, 75);
  pilha_add(p, 80);
  pilha_add(p, 85);
  pilha_add(p, 90);
  pilha_add(p, 95);
  pilha_add(p, 100);
  pilha_add(p, 5);
  pilha_add(p, 10);
  pilha_add(p, 15);
  pilha_add(p, 20);
  pilha_add(p, 25);
  pilha_add(p, 30);
  pilha_add(p, 35);
  pilha_add(p, 40);
  pilha_add(p, 45);
  pilha_add(p, 50);
  pilha_add(p, 55);
  pilha_add(p, 60);
  pilha_add(p, 65);
  pilha_add(p, 70);
  pilha_add(p, 75);
  pilha_add(p, 80);
  pilha_add(p, 85);
  pilha_add(p, 90);
  pilha_add(p, 95);
  pilha_add(p, 100);
  pilha_add(p, 5);
  pilha_add(p, 10);
  pilha_add(p, 15);
  pilha_add(p, 20);
  pilha_add(p, 25);
  pilha_add(p, 30);
  pilha_add(p, 35);
  pilha_add(p, 40);
  pilha_add(p, 45);
  pilha_add(p, 50);
  pilha_add(p, 55);
  pilha_add(p, 60);
  pilha_add(p, 65);
  pilha_add(p, 70);
  pilha_add(p, 75);
  pilha_add(p, 80);
  pilha_add(p, 85);
  pilha_add(p, 90);
  pilha_add(p, 95);
  pilha_add(p, 100);

  // int x = 7;
  // if(pilha_busca(p, x)){
  //   printf("O valor %i está presente na pilha.\n", x);
  // } else{
  //   printf("O valor %i não está presente na pilha.\n", x);
  // }

  pilha_imprime(p);

  pilha_libera(p);

  return 0;
}
