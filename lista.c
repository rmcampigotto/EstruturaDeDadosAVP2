#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criar_lista(Lista *lista) {
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->tam = 0;
}

void inserir_inicio(Lista *lista, Produto produto) {
  No *novo = malloc(sizeof(No));
  if (novo) {
    novo->produto = produto;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    if (lista->fim == NULL)
      lista->fim = novo;
    lista->fim->proximo = lista->inicio;
    lista->tam++;
  } else {
    printf("Erro ao alocar memória.\n");
  }
}

void inserir_fim(Lista *lista, Produto produto) {
  No *aux, *novo = malloc(sizeof(No));

  if (novo) {
    novo->produto = produto;
    if (lista->inicio == NULL) {
      lista->inicio = novo;
      lista->fim = novo;
      lista->fim->proximo = lista->inicio;
    } else {
      lista->fim->proximo = novo;
      lista->fim = novo;
      novo->proximo = lista->inicio;
    }
    lista->tam++;
  } else {
    printf("Erro ao alocar memória.\n");
  }
}

void inserir_ordenado(Lista *lista, Produto produto) {
  No *aux, *novo = malloc(sizeof(No));

  if (novo) {
    novo->produto = produto;
    if (lista->inicio == NULL) {
      inserir_inicio(lista, produto);
    } else if (novo->produto.nome < lista->inicio->produto.nome) {
      inserir_inicio(lista, produto);
    } else {
      aux = lista->inicio;
      while (aux->proximo != lista->inicio &&
             novo->produto.nome > aux->proximo->produto.nome)
        aux = aux->proximo;
      if (aux->proximo == lista->inicio) {
        inserir_fim(lista, produto);
      } else {
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        lista->tam++;
      }
    }
  } else {
    printf("Erro ao alocar memória.\n");
  }
}

No *remover(Lista *lista) {
  No *aux, *no = NULL;
  int num;
  printf("Qual o id que deseja excluir?");
  scanf("%d", &num);

  if (lista->inicio) {
    if (lista->inicio == lista->fim && lista->inicio->produto.id == num) {
      no = lista->inicio;
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->tam--;
    } else if (lista->inicio->produto.id == num) {
      no = lista->inicio;
      lista->inicio = no->proximo;
      lista->fim->proximo = lista->inicio;
      lista->tam--;
    } else {
      aux = lista->inicio;
      while (aux->proximo != lista->inicio && aux->proximo->produto.id != num)
        aux = aux->proximo;
      if (aux->proximo->produto.id == num) {
        if (lista->fim == aux->proximo) {
          no = aux->proximo;
          aux->proximo = no->proximo;
          lista->fim = aux;
        } else {
          no = aux->proximo;
          aux->proximo = no->proximo;
        }
        lista->tam--;
      }
    }
  }
  return no;
}

No *buscar(Lista *lista) {
  No *aux = lista->inicio;
  int id;
  printf("Qual ID do produto que deseja buscar?: ");
  scanf("%d", &id);

  if (aux) {
    do {
      if (aux->produto.id == id) {
        printf("\n");
        printf("Produto: \n");
        return aux;
        printf("\n");
      }
      aux = aux->proximo;
    } while (aux != lista->inicio);
  }
  return NULL;
}

void imprimir(Lista lista) {

  if (lista.inicio == NULL) {
    printf("Lista vazia!");
  } else {
    No *no = lista.inicio;
    if (no) {
      do {
        printf("ID: %d", no->produto.id);
        printf("\nNOME: %s", no->produto.nome);
        printf("\nPREÇO: R$%d", no->produto.preco);
        no = no->proximo;
      } while (no != lista.inicio);
    }
  }
  printf("\n\n");
}