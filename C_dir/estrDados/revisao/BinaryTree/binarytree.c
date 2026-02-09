#include <stdio.h>
#include <stdlib.h>

// Estrutura de BT
typedef struct Node {
  int valor;
  struct Node *left;
  struct Node *right;
} Node;

/*
 * Lógica de BST (binary search tree): 
 * - Menores á esquerda
 * - Maiores à direita
 */


// ---------------------------------------- //


Node* criarNode(int v){
  Node *newNode = (Node*) malloc(sizeof(Node));
  newNode->valor = v;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* inseriorNode(Node* root, int v){
  if(root == NULL){
    return criarNode(v);
  }

  if(v < root->valor){
    root->left = inseriorNode(root->left, v);
  }

  if(v > root->valor){
    root->right = inseriorNode(root->right, v);
  }

  return root;
}

Node* buscar(Node* root, int v){
  if(root == NULL || root->valor == v)
    return root;

  if(v < root->valor)
    return buscar(root->left, v);
  else 
    return buscar(root->right, v);

}

Node* encontrarMinimo(Node *root){
  Node* atual = root;

  while(atual && atual->left != NULL)
    atual = atual->left;
  return atual;
}

Node* encontrarMaximo(Node *root){
  Node *atual = root;

  while(atual && atual->right != NULL)
    atual = atual->right;
  return atual;
}

Node* remover(Node *root, int v){
  if(root == NULL) return root;

  if(v < root->valor){
    root->left = remover(root->left, v);
  } else if(v > root->valor){
    root->right = root->right;
  } else {
    // nó folha ou apenas 1 filho
    if(root->left == NULL){
      Node *temp = root->right;
      free(root);
      return temp;
    } else if(root->right == NULL){
      Node *temp = root->left;
      return temp;
    }

    Node *temp = encontrarMinimo(root->right);
    root->valor = temp->valor;
    root->right = remover(root, temp->valor);
  }
  return root;
}

// ...
