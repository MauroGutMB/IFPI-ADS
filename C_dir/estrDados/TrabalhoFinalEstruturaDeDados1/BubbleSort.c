#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(unsigned long* v, int s);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Please provide arguments.\n");
    return 0;
  }

  unsigned long *argsLu = malloc(sizeof(unsigned long) * (argc - 1));
  if (argsLu == NULL) {
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    argsLu[i - 1] = strtoul(argv[i], NULL, 10);
  }

  bubbleSort(argsLu, argc);

  for(int i = 0; i < argc-1; i++){
    printf("%lu\n", *(argsLu+i));
  }

  free(argsLu);

  return 0;
}

void bubbleSort(unsigned long* v, int s){
  for(int i = 0; i < s; i++){
    unsigned long x = *(v += i);
    for(int j = 0; j < s; j++){
      unsigned long y = *(v += j);
      if(x > y){
        unsigned long temp = x;
        *(v + i) = *(v + j);
        *(v + j) = x;
      }
    }
  }
}
