typedef struct Lista Lista;
Lista* lista_cria();
int lista_vazia(Lista* l);
Lista* lista_insere(Lista* l, int v);
void lista_imprime(Lista* l);
Lista* lista_busca(Lista* l, int v);
Lista* lista_remove(Lista* l, int v);
void lista_libera(Lista* l);
