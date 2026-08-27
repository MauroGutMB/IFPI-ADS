#include "tad.h"
#include <stdio.h>

int main() {

  Produto *raiz = NULL;
  int opcao;
  char nome[50];
  float preco;
  int estoque;

  do {
    opcao = 0;
    printf("\n=== Gerenciador de Produtos ===\n");
    printf("1. Cadastrar Produto\n");
    printf("2. Consultar Produto\n");
    printf("3. Mostrar Quantidade de Produtos\n");
    printf("4. Atualizar Estoque\n");
    printf("5. Listar Produtos Folha\n");
    printf("6. Remover Produto\n");
    printf("7. Verificar Altura de um Produto\n");
    printf("8. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Digite o nome do produto: ");
      scanf("%s", nome);
      printf("Digite o preço do produto: ");
      scanf("%f", &preco);
      printf("Digite a quantidade em estoque: ");
      scanf("%d", &estoque);
      raiz = criarProduto(nome, preco, estoque);
      break;
    case 2:
      printf("Digite o nome do produto para consulta: ");
      scanf("%s", nome);
      Produto *produto = consultarProduto(raiz, nome);
      if (produto != NULL) {
        printf("Produto encontrado: Nome: %s, Preço: %.2f, Estoque: %d\n",
               getNome(produto), getPreco(produto), getEstoque(produto));
      } else {
        printf("Produto não encontrado.\n");
      }
      break;
    case 3:
      printf("Quantidade total de produtos: %d\n", contarNos(raiz));
      break;
    case 4:
      printf("Digite o nome do produto para atualizar: ");
      scanf("%s", nome);
      printf("Digite o novo preço do produto: ");
      scanf("%f", &preco);
      printf("Digite a nova quantidade em estoque: ");
      scanf("%d", &estoque);
      atualizarProduto(raiz, nome, preco, estoque);
      break;
    case 5:
      listarFolhas(raiz);
      break;
    case 6:
      printf("Digite o nome do produto para remover: ");
      scanf("%s", nome);
      raiz = removerProduto(raiz, nome);
      break;
    case 7:
      printf("Digite o nome do produto para verificar a altura: ");
      scanf("%s", nome);
      Produto *produtoAltura = consultarProduto(raiz, nome);
      if (produtoAltura != NULL) {
        printf("Altura do produto '%s': %d\n", calcularAltura(produtoAltura) == -1 ? "Produto não encontrado" : nome,
               calcularAltura(produtoAltura));
      } else {
        printf("Produto não encontrado.\n");
      }
      break;
    case 8:
      liberarMemoria(raiz);
      printf("Saindo do programa...\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 8);
}
