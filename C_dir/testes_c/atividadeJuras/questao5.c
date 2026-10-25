/*
5) Crie uma função que receba um ponteiro para inteiro e multiplique o valor por 2.
*/

#include <stdio.h>

void multPorDois(int *x){
  *x *= 2;
}

int main(){

  int inteiro = 2;

  printf("Número: %i\n", inteiro);
  multPorDois(&inteiro);
  printf("Número após a multiplicação: %i", inteiro);

  return 0;
}
