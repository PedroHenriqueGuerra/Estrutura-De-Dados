#include <stdio.h>
#include <stdlib.h>

typedef struct no no;

struct no {
  int valor;
  no* esq;
  no* dir;
};

no* criaNovo(int v, no* e, no* d);

no* insertValue(no* raiz, int v);

no* findValue(no* raiz, int v);

void printTree(no* raiz);

int getHeight(no* raiz);

no* removeValue(no* raiz, int v);

int size(no* raiz);

int sumX(no* raiz, int x);