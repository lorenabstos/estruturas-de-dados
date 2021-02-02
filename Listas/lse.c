#include "stdio.h"
#include "stdlib.h"

//lista simplesmente encadeada (inteiros)

typedef struct NO TNO;
struct NO{
	int dado;
	TNO *prox;
};

typedef struct LSE TLSE;
struct LSE{
	TNO *inicio, *fim;
	int tamanho;
};

TNO *criarNO(int info){
	TNO *no = malloc(sizeof(TNO));
	no -> prox = NULL;
	no -> dado = info;
	return no;
}

TLSE *criarLSE(){
	TLSE *lse = malloc(sizeof(TLSE));
	lse -> inicio = NULL;
	lse -> fim = NULL;
	lse -> tamanho = 0;
	return lse;
}

void inserirInicio(TLSE *lse, TNO *novo){
	if(lse->inicio == NULL){//lista vazia
		lse -> inicio = novo;
		lse -> fim = novo;
	}else{
		novo -> prox = lse -> inicio;
		lse -> inicio = novo;
	}
	lse -> tamanho++;
}

void inserirFim(TLSE *lse, TNO *novo){
	if(lse->inicio == NULL){
		lse -> inicio = novo;
		lse -> fim = novo;
	}else{
		TNO *ultimo = lse -> fim;
		ultimo -> prox = novo;
		lse -> fim = novo;
	}
	lse -> tamanho++;
}

void removerInicio(TLSE* lse){
	TNO *primeiro = lse -> inicio;
	if(primeiro != NULL){//caso único elemento
		if(lse->inicio == lse->fim){
			lse -> inicio = NULL;
			lse -> fim = NULL;
		}else{//caso geral
			lse -> inicio = primeiro -> prox;
		}
		free(primeiro);//libera memória
		lse -> tamanho--;
	}
}

void removerFim(TLSE *lse){
	TNO *aux = lse -> inicio;
	if(lse->inicio==NULL){ printf("lista vazia\n"); }
	else if(lse->inicio == lse->fim){//único elemento
		TLSE *tmp = criarLSE();
		free(aux);
	}else{//pelo menos dois elementos na lista
		while(aux->prox != lse->fim){ aux = aux -> prox; }
		free(lse->fim);
		lse -> fim = aux;
		aux -> prox = NULL;
		lse -> tamanho--;
	}
}

void removerPos(TLSE *lse, int pos){
	if(pos == 1){ removerInicio(lse); }
	else if(pos == lse->tamanho){ removerFim(lse); }
	else{
		TNO *aux = lse -> inicio;
		TNO *anterior = NULL;
		int contador = 1;
		while(pos > contador){
			anterior = aux;
			aux = aux -> prox;
			contador++;
		}
		anterior -> prox = aux -> prox;
		free(aux);
		lse -> tamanho--;
	}
}

TNO *acessar(TLSE *lse, int pos){
	TNO *aux = NULL;
	if((pos > 0) && (pos <= lse->tamanho)){
		aux = lse -> inicio;
		int contador = 1;
		while(contador < pos){
			aux = aux -> prox;
			contador++;
		}
	}
	return aux;
}

TNO *buscar(TLSE *lse, int info){
	TNO *aux = lse -> inicio;
	while((aux != NULL) && (aux->dado != info)){
		aux = aux -> prox;
	}
	return aux;
}

void imprimir(TLSE *lse){
	TNO *aux = lse -> inicio;
	printf("\nlista: ");
	while(aux!=NULL){
		printf("%d ", aux->dado);
		aux = aux -> prox;
	}
}

int main(int argc, char const *argv[]){
	TLSE *lista = criarLSE(); TNO *no;
	printf("escolha o modo de inserção de dados\n");
	printf("[1] Início\n[2] Fim\n\n> ");
	int long chave = 1;
	int modo, entrada; scanf("%d", &modo);
	switch(modo){
		case 1:
		printf("\npara encerrar a leitura dos dados digite 0.\n> ");
		scanf("%d", &entrada);
		while(entrada != 0){
			no = criarNO(chave, entrada);//cria instância tipo nó
			inserirInicio(lista, no);//insere elemento na lista
			chave++;
			scanf("%d", &entrada);
		}
		imprimir(lista);
		break;

		case 2:
		printf("\npara encerrar a leitura dos dados digite 0.\n> ");
		scanf("%d", &entrada);
		while(entrada != 0){
			no = criarNO(chave, entrada);//cria instância tipo nó
			inserirFim(lista, no);//insere elemento na lista
			chave++;
			scanf("%d", &entrada);
		}
		imprimir(lista);
		break;

		default: printf("opção inválida\n");
	}
	if(lista->inicio != NULL){
		int op; 
		do{
			printf("\n\nescolha uma das opções ou digite 0 para encerrar programa.\n\n");
			printf("[3] Acessar Posição\n");
			printf("[4] Buscar Elemento\n");
			printf("[5] Remover Elemento (Início)\n");
			printf("[6] Remover Elemento (Fim)\n");
			printf("[7] Remover Elemento (Posição)\n\n> ");
			scanf("%d", &op);
			switch(op){
				case 0: printf("\naté logo :)\n"); break;
		
				case 3:
				printf("\ndigite uma posição para acessar\n> ");
				int pos_acessado; scanf("%d", &pos_acessado);
				TNO *tmp = acessar(lista, pos_acessado);
				printf("\n-----acessando posição %d-----", pos_acessado);
				printf("\nelemento da posição %d: %d\n", pos_acessado, tmp->dado);
				break;
		
				case 4:
				printf("\ndigite o elemento buscado\n> ");	
				int buscado; scanf("%d", &buscado);
				if(buscar(lista, buscado)){
					printf("o elemento %d está presente na lista.\n", buscado);
				}else{
					printf("o elemento %d não está presente na lista.\n", buscado);
				}
				break;
		
				case 5:
				removerInicio(lista);
				printf("\n-----removendo do início-----");
				imprimir(lista);
				break;
		
				case 6:
				removerFim(lista);
				printf("\n-----removendo do fim-----");
				imprimir(lista);
				break;

				case 7:
				printf("\ndigite uma posição para remover\n> ");
				int pos; scanf("%d", &pos);
				removerPos(lista, pos);
				printf("\n-----removendo na posição %d-----", pos);
				imprimir(lista);
				break;

				default: printf("opção inválida.\n");
			}
		}while(op!=0);
	}
	return 0;
}
