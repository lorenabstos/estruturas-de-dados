#include "stdio.h"
#include "stdlib.h"
#include "pilha.h"

int main(int argc, char const *argv[]){
    TNO *aux, *pilha = malloc(sizeof(TNO));
    printf("digite 0 para encerrar a leitura dos dados.\n\n> ");
	int entrada, op; scanf("%d", &entrada);
	while(entrada != 0){
        empilhar(pilha, entrada);
		scanf("%d", &entrada);
	}
	imprimir(pilha);
    printf("\ndigite 1 para desempilhar elemento (LIFO) ou 0 para encerrar programa.\n\n> ");
	scanf("%d", &op);
    switch(op){
		case 0: printf("ate logo :)\n"); break;
        case 1:
		aux = desempilhar(pilha);
		if(aux != NULL){ printf("\nelemento retirado: %d\n", aux->dado); }
		break;
		default: printf("comando inválido");
    }
	liberar(pilha);
	return 0;
}