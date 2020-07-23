#include <stdio.h>
#include <stdlib.h>

typedef struct no no;

struct no {
  int valor;
  no* esq;
  no* dir;
};

no* criaNovo(int v, no* e, no* d){
  no* novo = malloc(sizeof(no));
  novo->valor = v;
  novo->esq = e;
  novo->dir = d;
  return novo;
}

no* insertValue(no* raiz, int v){
  if(raiz == NULL){
    raiz = (no*)malloc(sizeof(no));
    raiz->valor = v;
    raiz->esq = NULL;
    raiz->dir = NULL;
  }
  else if(v < raiz->valor){
    raiz->esq = insertValue(raiz->esq, v);
  }
  else{
    raiz->dir = insertValue(raiz->dir, v);
  }
  return raiz;
}

no* findValue(no* raiz, int v){
  if(raiz == NULL || raiz->valor == v) return raiz;
  else if(v < raiz->valor) return findValue(raiz->esq, v);
  else return findValue(raiz->dir, v);
}

void printTree(no* raiz){
  if(raiz != NULL){
    printTree(raiz->esq);
    printf("%d ", raiz->valor);
    printTree(raiz->dir);

  }
}

int getHeight(no* raiz){
  if(raiz == NULL) return -1;
  else{
    int ae = getHeight(raiz->esq);
    int ad = getHeight(raiz->dir);
    if(ae > ad) return 1+ae;
    else return 1+ad;
  }
}

no* removeValue(no* raiz, int v){
  if(raiz == NULL) return NULL;
  else if(v < raiz->valor)raiz->esq = removeValue(raiz->esq,v);
  else if(v > raiz->valor)raiz->dir = removeValue(raiz->dir, v);
  else{
    //Nó sem filhos
    if(raiz->esq == NULL && raiz->dir == NULL){
      free(raiz);
      return NULL;
    }
    //Um filho a esquerda
    else if(raiz->dir == NULL){
      no *t = raiz;
      raiz = raiz->esq;
      free(t);
    }
    //Um filho a direita
    else if(raiz->esq == NULL){
      no *t = raiz;
      raiz = raiz->dir;
      free(t);
    }
    //Dois filhos
    else{
      no* f = raiz->esq;//Buscar nó mais a direita da sub-árvore a esquerda
      while(f->dir != NULL)f = f->dir;
      raiz->valor = f->valor;
      f->valor = v;
      raiz->esq = removeValue(raiz->esq, v);
    }
  }
  return raiz;
}

int size(no* raiz){
  if(raiz == NULL) return 0;
  else return 1+size(raiz->esq)+size(raiz->dir);
}

int sumX(no* raiz, int x){
  if(raiz == NULL) return 0;
  if(raiz->valor > x){
    return raiz->valor+sumX(raiz->esq,x)+sumX(raiz->dir,x);
  }
  else{
    return sumX(raiz->dir,x);
  }
}

int main(void) {
  no* raiz = criaNovo(10,
  criaNovo(5,NULL,NULL),
  criaNovo(20,NULL,NULL)
  );
  no* novo = insertValue(raiz,40);
  printTree(raiz);
  int altura = 0;
  altura = getHeight(raiz);
  printf("\naltura = %d\n", altura);
  int aux = 0;
  aux = size(raiz);
  printf("size = %d\n", aux);
  int somaX = 0;
  somaX = sumX(raiz,20);
  printf("soma maiores que 20 = %d\n", somaX);
  removeValue(raiz,10);
  return 0;
}