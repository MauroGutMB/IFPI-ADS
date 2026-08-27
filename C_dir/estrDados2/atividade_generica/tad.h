typedef struct arvvar ArvVar;
ArvVar *arv_cria(char c);
void arv_insere(ArvVar *pai, ArvVar *filho);
void arv_imprime(ArvVar *a);
int arv_pertence(ArvVar *a, char c);
int altura_arv(ArvVar *a);
int contar_nos(ArvVar *a);
int contar_folhas(ArvVar *a);
void arv_libera(ArvVar *a);
