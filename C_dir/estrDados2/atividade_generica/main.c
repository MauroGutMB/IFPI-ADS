#include <stdio.h>
#include "tad.h"

int main() {

    ArvVar *C = arv_cria('C');
    ArvVar *D = arv_cria('D');
    ArvVar *I = arv_cria('I');
    ArvVar *W = arv_cria('W');
    ArvVar *T = arv_cria('T');
    ArvVar *P = arv_cria('P');
    ArvVar *V = arv_cria('V');
    ArvVar *F = arv_cria('F');

    arv_insere(C, D);
    arv_insere(C, I);
    arv_insere(C, W);
    arv_insere(D, T);
    arv_insere(D, P);
    arv_insere(I, V);
    arv_insere(I, F);

    printf("Árvore de pastas:\n");
    arv_imprime(C);

    printf("\nVerificando se 'V' pertence à árvore: %s\n", arv_pertence(C, 'V') ? "Sim" : "Não");
    printf("Verificando se 'X' pertence à árvore: %s\n", arv_pertence(C, 'X') ? "Sim" : "Não");

    printf("Altura da árvore: %d\n", altura_arv(C));
    printf("Quantidade total de nós: %d\n", contar_nos(C));
    printf("Quantidade de folhas: %d\n", contar_folhas(C));

    printf("\n\n");

    printf("Digite a pasta que deseja buscar: ");
    char busca;
    scanf(" %c", &busca);

    if (arv_pertence(C, busca)) {
        printf("A pasta %c encontrada.\n", busca);
    } else {
        printf("Pasta %c não encontrada.", busca);
    }

    arv_libera(C);

    // arvore desenhada
    // C
    // ├── D
    // │   ├── T
    // │   └── P
    // ├── I
    // │   ├── V
    // │   └── F
    // └── W

  return 0;
}

// atividade
/*
1 - Qual é a função do ponteiro prim e prox?
R: O ponteiro prim aponta para o primeiro filho de um nó, enquanto o ponteiro prox aponta para o próximo irmão do nó (ou nivel).

2 - Por que a função arv_pertence precisa usar recursão?
R: A função arv_pertence precisa usar recursão para percorrer toda a árvore, verificando se o caractere desejado pertence a algum dos nós. A recursão permite que a função explore cada ramo da árvore de forma eficiente, verificando cada nó e seus filhos até encontrar o caractere ou concluir que ele não está presente.

3 - Por que a função arv_libera não deve executar free(a) logo no início?
R: A função arv_libera não deve executar free(a) logo no início porque isso liberaria a memória do nó atual antes de liberar os nós filhos. Se o nó atual for liberado primeiro, os ponteiros para os filhos se tornariam inválidos, o que poderia levar a erros de acesso à memória ou vazamentos de memória. É importante liberar os filhos primeiro para garantir que toda a estrutura da árvore seja corretamente liberada antes de liberar o nó pai.

4 - Por que precisamos guardar o próximo irmão antes de liberar o nó atual?
R: Precisamos guardar o próximo irmão antes de liberar o nó atual porque, após liberar o nó atual, os ponteiros para os irmãos se tornam inválidos. Se tentarmos acessar o próximo irmão depois de liberar o nó atual, isso pode resultar em um erro de acesso à memória. Guardar o próximo irmão antes de liberar o nó atual garante que ainda tenhamos uma referência válida para continuar percorrendo a árvore e liberando os nós restantes.

5 - Na árvore de pastas, quais nós são folhas?
R: Na árvore de pastas, os nós que são folhas são T, P, V, F e W, pois eles não possuem filhos.

6 - Qual é a altura da árvore considerando que uma folha possui altura 0?
R: A altura da árvore é 2, considerando que as folhas (T, P, V, F e W) possuem altura 0, os nós D e I possuem altura 1, e o nó C possui altura 2.
*/
