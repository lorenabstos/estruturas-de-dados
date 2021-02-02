#include "stdio.h"
#include "stdlib.h"
#include "pilha.h"

//pilha de inteiros

TNO *criarNO(int info){//estrutura nó da pilha
    TNO *no = malloc(sizeof(TNO));
    no -> dado = info;
    no -> altura = 0;
    no -> prox = NULL;
    return no;
}

int pilhaVazia(TNO *pilha){//caso pilha vazia
	if(pilha->prox == NULL){ return 1; }
	else{ return 0; }
}

void empilhar(TNO *pilha, int info){//inserir elementos na pilha
	TNO *novo = criarNO(info);
	novo -> prox = NULL;
	if(pilhaVazia(pilha)){ pilha -> prox = novo; }
	else{
		TNO *aux = pilha -> prox;
		while(aux->prox != NULL){ aux = aux -> prox; }
		aux -> prox = novo;
	}
	pilha -> altura++;
}

TNO *desempilhar(TNO *pilha){//retirar elementos da pilha (LIFO)
	if(pilha->prox == NULL){
		printf("pilha vazia\n");
		return NULL;
	}else{
		TNO *ultimo = pilha -> prox, *penultimo = pilha;
		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo -> prox;
		}
		penultimo -> prox = NULL;
		pilha -> altura--;
		return ultimo;
	}
}

void liberar(TNO *pilha){//limpar pilha
    if(!pilhaVazia(pilha)){
        TNO *atual, *prox;
		while(atual != NULL){
            prox = atual -> prox;
			free(atual);
			atual = prox;
		}
	}
}

void imprimir(TNO *pilha){//imprimir pilha
	if(pilhaVazia(pilha)){
		printf("pilha vazia\n");
		return;
	}
	TNO *aux = pilha -> prox;
	printf("\npilha:\n");
	while(aux != NULL){
		printf("%d\n", aux->dado);
		aux = aux -> prox;
	}
}



