/*
3) Crie uma função que troque o valor de duas variáveis inteiras usando ponteiros.
*/

#include <stdio.h>

void trocaValor(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){

  int x = 5;
  int y = 10;

  printf("%i - %i\n", x, y);
  printf("TROCANDO VALORES...\n");
  trocaValor(&x, &y);
  printf("%i - %i\n", x, y);

  return 0;
}
