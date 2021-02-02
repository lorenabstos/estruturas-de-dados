//Árvore Binária AVL 

#include "stdio.h"
#include "stdlib.h"
#include "avl.h"

TNO *criarNO(int info){//inicia ponteiros do nó
  TNO *no = malloc(sizeof(TNO));
  no -> dado = info;
  no -> esq = NULL;
  no -> dir = NULL;
  no -> alt = 0;
  return no;
}

int altura(TNO *raiz){//calcula a altura das sub-árvores (sae, sad)
  int sae, sad;
  if(raiz == NULL){ return 0; }
  if(raiz->esq == NULL){ sae = 0; }
  else{ sae = 1 + raiz -> esq -> alt; }   
  if(raiz->dir == NULL){ sad = 0; }
  else{ sad = 1 + raiz -> dir -> alt; }
  if(sae > sad){ return sae; }
  return sad;
}

//ROTAÇÕES
TNO *RD(TNO *rot){//rotação direita
  TNO *aux = rot -> esq;
  rot -> esq = aux -> dir;
  aux -> dir = rot;
  rot -> alt = altura(rot);
  aux -> alt = altura(aux);
	printf("%d com %d, a direita\n", rot->dado, aux->dado);
  return aux;
}
 
TNO *RE(TNO *rot){//rotação esquerda
  TNO *aux = rot -> dir;
  rot -> dir = aux -> esq;
  aux -> esq = rot;
  rot -> alt = altura(rot);
  aux -> alt = altura(aux);
	printf("%d com %d, a esquerda\n", rot->dado, aux->dado);
  return aux;
}
 
TNO *ED(TNO *raiz){//rotação esquerda-direita
  raiz -> esq = RE(raiz->esq);
  raiz = RD(raiz);
  return raiz;
}
 
TNO *DE(TNO *raiz){//rotação direita-esquerda
  raiz -> dir = RD(raiz->dir);
  raiz = RE(raiz);
  return raiz;
}

int FB(TNO *raiz){//calcula fator de balanceamento
  int sae, sad;//sae - altura subarvore esquerda | sad - altura subarvore direita
  if(raiz == NULL){ return 0; }
  if(raiz->esq == NULL){ sae = 0; }
  else{ sae = 1 + raiz -> esq -> alt; }
  if(raiz->dir == NULL){ sad = 0; }
  else{ sad = 1 + raiz -> dir -> alt; }
  return(sae-sad);
}

TNO *inserirELE(TNO *raiz, int info){//insere elementos na árvore
  if(raiz == NULL){ raiz = criarNO(info); }
  else{
    if(info > raiz->dado){
      raiz -> dir = inserirELE(raiz->dir, info);
      if(FB(raiz) == -2){
        if(info > raiz->dir->dado){ raiz = RE(raiz); }
        else{ raiz = DE(raiz); }
      }
    }else{
      if(info < raiz->dado){
        raiz -> esq = inserirELE(raiz->esq, info);
        if(FB(raiz) == 2){
          if(info < raiz->esq->dado){ raiz = RD(raiz); }
          else{ raiz = ED(raiz); }
        }
      }
    }
  }
  raiz -> alt = altura(raiz);
  return raiz;
}

//percursos de profundidade p impressão de árvores com fb 
void preOrdem(TNO *raiz){
  if(raiz != NULL){
    printf("%d\t(%d)\n", raiz->dado, FB(raiz));
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
  }
} 

void ordem(TNO *raiz){
  if(raiz != NULL){
    ordem(raiz->esq);
    printf("%d\t(%d)\n", raiz->dado, FB(raiz));
    ordem(raiz->dir);
  }
}

void posOrdem(TNO *raiz){
  if(raiz != NULL){
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d\t(%d)\n", raiz->dado, FB(raiz));
  }
} 

