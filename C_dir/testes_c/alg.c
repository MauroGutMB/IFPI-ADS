#include <stdio.h>

int main() {

  int numero;

  // NUMEROS: int, float, double
  // CARACTERES char, char[] 'string'

  printf("Insira o número 8 -> ");

  while (numero != 8) {
    scanf("%i", &numero);

    if(numero == 8){
      printf("O número inserido foi 8.");
      break;
    } else{
      printf("O número inserido num foi 8 :c\n");
    }
  }

  return 0;
}
