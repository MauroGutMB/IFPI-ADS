/*j
4) Escreva um programa que mostre o valor e o endereço de uma variável float usando ponteiros.
*/

#include <stdio.h>

int main(){

  float z = 3.5;
  float *pz = &z;

  printf("%.2f - %p", *pz, pz);

  return 0;
}
