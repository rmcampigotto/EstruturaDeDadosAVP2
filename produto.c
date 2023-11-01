#include "produto.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void cadastrar_produto(Lista *lista) {

  Produto produto;

  printf("Digite o nome do produto: ");
  scanf("%s", produto.nome);

  printf("Digite o preço do produto: ");
  scanf("%d", &produto.preco);

  // condição para saber se a lista esta vazia, caso esteja o id recebe 1, caso
  // não, ele olha o último da lista e adiciona + 1

  if (lista == NULL) {
    produto.id = 1;
  } else {
    produto.id = lista->tam + 1;
  }

  inserir_inicio(lista, produto);
}

// void consultar_pedido(Lista *lista) { buscar(lista); }

// void excluir_pedido(Lista *lista) { remover(lista); }

// void imprimir_lista(Lista lista) { imprimir(lista); }