typedef struct Node Node;
int isset(Node *root);
Node* criarNo(char info);
void inserir(Node *raiz, Node* prox);
void imprimir(Node *raiz);
void liberar(Node *raiz);
Node* busca(Node *root, char c);
int buscabool(Node *root, char c);
