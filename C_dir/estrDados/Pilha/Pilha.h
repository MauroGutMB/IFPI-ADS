typedef struct pilha Pilha;
Pilha* pilha_cria();
int pilha_vazia(Pilha* p);
void pilha_add(Pilha* p, int v);
int pilha_remove(Pilha* p);
int pilha_busca(Pilha* p, int v);
