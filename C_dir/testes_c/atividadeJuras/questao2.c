/*
2) Crie um programa que use um ponteiro para alterar o valor de uma variável inteira.
*/

#include <stdio.h>

int main(){

  int x = 5;
  int *px = &x;

  printf("%i\n", x);
  printf("VALOR ALTERADO: ");
  *px = 10;
  printf("%i\n", x);

  return 0;
}
