#ifndef LISTA
#define LISTA

typedef struct produto {
  int id;
  char nome[30];
  int preco;
} Produto;

typedef struct no {
  Produto produto;
  struct no *proximo;
} No;

typedef struct {
  No *inicio;
  No *fim;
  int tam;
} Lista;

void criar_lista(Lista *lista);

void inserir_inicio(Lista *lista, Produto produto);

void inserir_fim(Lista *lista, Produto produto);

void inserir_ordenado(Lista *lista, Produto produto);

No *remover(Lista *lista);

No *buscar(Lista *lista);

void imprimir(Lista lista);

#endif