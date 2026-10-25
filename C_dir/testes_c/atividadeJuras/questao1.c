/*
1) Escreva um programa que declare uma variável inteira, um ponteiro para inteiro, atribua o endereço da variável ao ponteiro e imprima:
      a) O valor da variável.
      b) O endereço da variável.
      c) O valor armazenado no ponteiro.
*/

#include <stdio.h>

int main(){

  int x = 5;
  int *px = &x; // recebe um ponteiro

  printf("%i, %p, %i", x, px, *px);

  // int = %i ou %d -- acesso via variavel
  // char = %c acesso via variavel 
  // float %.2f acesso via variavel 
  // ponteiro %p -- acesso via variavel direta do ponteiro

  return 0;
}
