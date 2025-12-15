#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#define N 100

typedef struct pilha {
  int vals[N];
  int contador;
  int inicio;
} Pilha;
