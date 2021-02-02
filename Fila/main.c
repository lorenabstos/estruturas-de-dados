#include "stdio.h"
#include "stdlib.h"
#include "fila.h"

int main(){
    TNO *aux, *fila = malloc(sizeof(TNO));
	printf("digite 0 para encerrar a leitura dos dados.\n\n> ");
    int elemento; scanf("%d", &elemento);
    while(elemento != 0){
		enfileirar(fila, elemento);
        scanf("%d", &elemento);
    }
    imprimir(fila);
	if(!vazia(fila)){
		printf("\n\ndigite 1 para desenfileirar elemento (FIFO) ou 0 para encerrar programa.\n\n> ");
		int op; scanf("%d", &op);
		switch(op){
			case 0: printf("\naté logo :)\n"); break;
			case 1: 
			aux = desenfileirar(fila);
			if(aux != NULL){
				printf("\nelemento retirado: %d\n", aux->dado);
				liberar(aux);
			}
			break;
			default: printf("\ncomando inválido.\n");
		}
	}
    liberar(fila);
    return 0;
}
