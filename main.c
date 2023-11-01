#include "lista.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int opcao;
  Lista lista;
  No *no;

  do {
    printf(
        "\n0 - Sair\n1 - Cadastrar\n2 - Imprimir\n3 - Buscar\n4 - Remover\nESCOLHA: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      cadastrar_produto(&lista);
      break;
    case 2:
      imprimir(lista);
      break;
    case 3:
      no = buscar(&lista);
      if (no) {
        printf("ID: %d", no->produto.id);
        printf("\nNOME: %s", no->produto.nome);
        printf("\nPREÇO: R$%d", no->produto.preco);
      } else
        printf("Elemento nao encontrado.\n");
      break;
    case 4:
      remover(&lista);
      break;
    default:
      if (opcao != 0)
        printf("Opcao invalida.\n");
    }
  } while (opcao != 0);
  return 0;
}