#include "stdio.h"
#include "stdlib.h"
#include "fila.h"

//fila de inteiros

TNO *criarNO(int info){//cria/retorna ponteiro com informações do nó 
	TNO *no = malloc(sizeof(TNO));
	no -> dado = info;
	no -> tamanho = 0; 
	no -> prox = NULL;
	return no;
}

int vazia(TNO *fila){//caso de fila vazia
	if(fila->prox == NULL){ return 1; }
	else{ return 0; }
}

void enfileirar(TNO *fila, int info){//insere elemento na fila 
	TNO *novo = criarNO(info);
	novo -> prox = NULL;
	if(vazia(fila)){ fila -> prox = novo; }
	else{
		TNO *aux = fila -> prox;
		while(aux->prox != NULL){ aux = aux -> prox; }
		aux -> prox = novo;
	}
    fila ->	tamanho++;
}

TNO *desenfileirar(TNO *fila){//retira elemento da fila (first in-first out)
	if(fila->prox == NULL){
		printf("fila vazia\n");
		return NULL;
	}else{
		TNO *aux = fila -> prox;
		fila -> prox = aux -> prox;
		fila -> tamanho--;
		return aux;
	}
}

void imprimir(TNO *fila){//imprime fila 
	if(vazia(fila)){ printf("fila vazia\n"); }
	else{
		TNO *aux = fila -> prox;
		printf("\nfila: ");
		while(aux != NULL){
			printf("%d ", aux->dado);
			aux = aux -> prox;
		}
	}
}

void liberar(TNO *fila){//limpa fila
	if(!vazia(fila)){
		TNO *atual, *prox;
		atual = fila -> prox;
		while(atual != NULL){
			prox = atual -> prox;
			liberar(atual);
			atual = prox;
		}
	}
}

