#include "stdio.h"
#include "stdlib.h"
#include "abb.h"

TNO *criarVazia(){//cria árvore vazia
  return NULL;
}

TNO *criarABB(int info, TNO *sad, TNO *sae){//cria árvore, nó raiz c/ dado e 2 sub-árvores (dir(sad) | esq(sae))
    TNO *no = malloc(sizeof(TNO));//aloca espaço na memória
    //inicia ponteiros do nó da árvore
    no -> dado = info;
    no -> direita = sad;
    no -> esquerda = sae;
    return no;//retorna endereço do nó raiz criado
}

int ABBVazia(TNO *raiz){//verifica se árvore é vazia
    return raiz == NULL;
}

TNO *inserirELE(TNO *raiz, int info){//insere elemento no nó da árvore 
  if(ABBVazia(raiz)){ raiz = criarABB(info, criarVazia(), criarVazia()); }//se a árvore for vazia, cria árvore
  else if(info < raiz->dado){ raiz -> esquerda = inserirELE(raiz->esquerda, info); }//se não, insere elementos a esquerda quando menores que a raiz
  else if(info >= raiz->dado){ raiz -> direita = inserirELE(raiz->direita, info); }//se não, insere elementos a direita quando maiores que a raiz
  return raiz;
}

//PERCURSO EM LARGURA | entrada-teste: 15 6 3 7 2 5 1 4 20 22 25 23 
void largura(TNO *raiz){//impreme árvore em largura (nível a nível) da esquerda p/ direita
    TNO *aux, *v[50];
    int inicio, fim;
    v[0] = raiz; inicio = 0; fim = 1;
    while(inicio < fim){
        aux = v[inicio]; 
        inicio++;
        printf("%d ", aux->dado);
        if(aux->esquerda != NULL){
            v[fim] = aux -> esquerda;
            fim++;
        }
        if(aux->direita != NULL){
            v[fim] = aux -> direita;
            fim++;
        }
    }
}

//CONTAGEM DE FOLHAS
int contarfolhas(TNO *raiz){//conta o número de folhas da árvore (nó sem filhos/sub-árvores)
    if(ABBVazia(raiz)){ return 0; }//caso base: árvore vazia
    else if(raiz->esquerda == NULL && raiz->direita == NULL){ return 1; }//hipótese de indução
    return contarfolhas(raiz->esquerda) + contarfolhas(raiz->direita);//número total de folhas
} 

//ESPELHAMENTO DE ÁRVORE
void espelho(TNO *raiz){//espelha árvore
    if(raiz != NULL){
      TNO *aux;//ponteiro auxiliar
        //recursão função espelho
        espelho(raiz->esquerda); 
        espelho(raiz->direita);
        //troca de elementos
        aux = raiz -> esquerda;
        raiz -> esquerda = raiz -> direita;
        raiz -> direita = aux;
    }
}

//BUSCA DE ELEMENTO 
int buscarELE(TNO *raiz, int info){//busca de valor/elemento na árvore
  if(ABBVazia(raiz)){ return 0; }//árvore vazia
  else if(raiz->dado == info){ return 1; }//valor encontrado
  else if(buscarELE(raiz->esquerda, info)){ return 1; }//valor encontrado à esquerda
  else{ return buscarELE(raiz->direita, info); }//valor encontrado à direita
}

//BUSCA DE VALOR MÍNIMO
void minimo(TNO *raiz){//busca valor mínimo
  while(raiz->esquerda != NULL){//percorre árvore, lado esquerdo
    raiz = raiz -> esquerda; 
  }
  printf("  %d", raiz->dado);//valor mínimo
}

//BUSCA DE VALOR NEGATIVO
int negativo(TNO *raiz){//busca valor negativo
    if(ABBVazia(raiz)){ return 0; }//árvore vazia
    else if(raiz->dado < 0){ return 1; }//valor encontrado
    else if(negativo(raiz->esquerda)){ return 1; }//valor encontrado à esquerda
    else{ return negativo(raiz->direita); }//valor encontrado à direita
}

//ÁRVORE BINÁRIA DE BUSCA VÁLIDA 
int min(TNO *raiz){//nó minimo
  TNO *aux = raiz;
  while(aux->esquerda != NULL){//percorre sub-árvore esquerda
    aux = aux -> esquerda;
  }
  return(aux->dado);
}

int max(TNO *raiz){//nó maximo
  TNO *aux = raiz;
    while(aux->direita != NULL){//percorre sub-árvore direita
      aux = aux -> direita;
    }
    return(aux->dado);
}

int abb(TNO *raiz){//verifica se árvore é válida
 if(ABBVazia(raiz)){ return 0; }
 if(raiz->esquerda != NULL && min(raiz->esquerda) > raiz->dado){ return 1; }
 if(raiz->direita != NULL && max(raiz->direita) <= raiz->dado){ return 1; }
 if(!abb(raiz->esquerda) || !abb(raiz->direita)){ return 1; }
 return 0;
}

//PERCURSOS EM PROFUNDIDADE
void preOrdem(TNO *raiz){
    if(raiz == NULL){ return; }
    printf("%d ", raiz -> dado);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void ordem(TNO *raiz){
    if(raiz == NULL){ return; }
    ordem(raiz->esquerda);
    printf("%d ", raiz->dado);
    ordem(raiz->direita);
}

void posOrdem(TNO *raiz){
    if(raiz == NULL){ return; }
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
    printf("%d ", raiz->dado);
}

/* ÁRVORE-TESTE
  TNO *arvoreBB = criarABB(8, criarABB(4, criarABB(2, criarABB(1, criarVazia(), criarVazia()), 
  criarABB(3, criarVazia(), criarVazia())), 
  criarABB(6, criarABB(5, criarVazia(), criarVazia()),
  criarABB(7, criarVazia(), criarVazia()))), 
  criarABB(10, criarABB(9, criarVazia(), criarVazia()),
  criarABB(11, criarVazia(), criarVazia()))); 
*/