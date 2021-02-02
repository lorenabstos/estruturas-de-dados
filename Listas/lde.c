#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Lista Duplamente Encadeada (inteiros)

typedef struct ELO TELO;
struct ELO{//estrutura elo da lista
   int dado;
   TELO *anterior, *proximo;
};

typedef struct LDE TLDE;
struct LDE{//estrutura lista duplamente encadeada 
   int tamanho;
   TELO *inicio, *fim;
};

TELO *criarELO(int info){//cria/retorna ponteiro elo
   TELO *elo = malloc(sizeof(TELO));
   elo -> dado = info;
   elo -> anterior = NULL;  
   elo -> proximo = NULL;
   return elo;
}

TLDE *criarLDE(){//cria/retorna ponteiro lista
   TLDE *lde = malloc(sizeof(TLDE));
   lde -> inicio = NULL;
   lde -> fim = NULL;
   lde -> tamanho = 0;
   return lde;
}

void inserirInicio(TLDE *lde, TELO *ELO){
  if(lde->inicio == NULL){
    lde -> inicio = ELO;
    lde -> fim = ELO;
  }else{
    ELO -> anterior = NULL;
    ELO -> proximo = lde -> inicio;
    lde -> inicio -> anterior = ELO;
    lde -> inicio = ELO;
  }
  lde -> tamanho++;
}

void inserirFim(TLDE *lde, TELO *ELO){
  if(lde->inicio == NULL){
    lde -> inicio = ELO;
    lde -> fim = ELO;
  }else{
    ELO -> proximo = NULL;
    ELO -> anterior = lde -> fim;
    lde -> fim -> proximo = ELO;
    lde -> fim = ELO;
  }
  lde -> tamanho++;
}

TELO *buscarPI(TLDE *lde, TELO *dot){//função para inserção ordenada, busca ponto de inserção
   int achou = 0;
   while(dot != NULL && achou == 0){
      if(dot->dado > dot->dado){ achou = 1; }
      else{ dot = dot -> proximo; }
   }
   if(achou == 0){ return lde -> fim; }
   else{ return dot -> anterior; }
}

void inserirOrdenado(TLDE *lde, TELO *dot){
   TELO *aux = buscarPI(lde, dot);
   if(lde->inicio == NULL){
      lde -> inicio = dot;
      lde -> fim = dot;
   }else{
      if(aux == NULL){
         lde -> inicio -> anterior = dot;
         dot -> proximo = lde -> inicio; 
         lde -> inicio = dot;
      }else{
         dot -> proximo = aux -> proximo;
         dot -> anterior = aux;
         if(aux->proximo != NULL){ aux -> proximo -> anterior = dot; }
         aux -> proximo = dot;
         if(lde->fim == aux){ lde -> fim = dot; }
      }
   }
   lde -> tamanho++;
}

void removerInicio(TLDE *lde){
  TELO *primeiro = lde -> inicio;
  if(primeiro != NULL){
    if(lde->inicio == lde->fim){
      lde -> inicio = NULL;
      lde -> fim = NULL;
    }else{ lde -> inicio = primeiro -> proximo; }
    free(primeiro);
    lde -> tamanho--;
  }
}

void removerFim(TLDE *lde){
    TELO *aux = lde -> inicio;
    if(lde->inicio == NULL){ printf("lista vazia\n"); }
    else if(lde->inicio == lde->fim){
      TLDE *tmp = criarLDE();
      free(aux);
    }else{
      while(aux->proximo != lde->fim){ aux = aux -> proximo; }
      free(lde->fim);
      lde -> fim = aux;
      aux -> proximo = NULL;
      lde -> tamanho--;
    }
}

void removerPos(TLDE *lde, int pos){
  if(pos == 1){ removerInicio(lde); }
  else if(pos == lde->tamanho){ removerFim(lde); }
  else{
    int contador = 1;
    TELO *aux = lde -> inicio, *anterior = NULL;
    while(pos > contador){
      anterior = aux;
      aux = aux -> proximo;
      contador++;
    }
    anterior -> proximo = aux -> proximo;
    free(aux);
    lde -> tamanho--;
  }
}

TELO *buscar(TLDE *lde, int info){
  TELO *primeiro = lde -> inicio; 
  TELO *ultimo = lde -> fim;
  if(lde->inicio == NULL){ return NULL; } //lista vazia
  else if(lde->inicio == lde->fim){ return lde -> inicio; } //um elemento
  while(&primeiro != &ultimo){//dois ou mais elementos
    if(primeiro != NULL || primeiro->dado == info){ return primeiro; }
    else if(ultimo != NULL || ultimo->dado == info){ return ultimo; }

    primeiro = primeiro -> proximo;
    ultimo = ultimo -> anterior;
  }
  return NULL;
}

TELO *acessar(TLDE *lde, int pos){
  TELO *aux = NULL; 
  if((pos > 0) && (pos <= lde->tamanho)){
    aux = lde -> inicio;
    int contador = 1;
    while(contador < pos){
      aux = aux -> proximo;
      contador++;
    }
  }
  return aux;
}

void imprimir(TLDE *lde){
   TELO *aux = lde -> inicio;
   printf("\nlista: ");
   while(aux != NULL){
      printf("%d ", aux->dado);
      aux = aux -> proximo;
   }
	 printf("\n");
}

int main(int argc, char const *argv[]){
  setlocale(LC_ALL, "Portuguese_Brazil");

	TLDE *lista = criarLDE(); TELO *no;
	printf("escolha o modo de inserção de dados\n");
	printf("[1] Início\n[2] Fim\n[3] Ordenado\n\n> ");
	int modo, entrada; scanf("%d", &modo);
	switch(modo){
		case 1:
		printf("\npara encerrar a leitura dos dados digite 0.\n> ");
		scanf("%d", &entrada);
		while(entrada != 0){
			no = criarELO(entrada);//cria instância tipo nó
			inserirInicio(lista, no);//insere elemento na lista
			scanf("%d", &entrada);
		}
		imprimir(lista);
		break;

		case 2:
		printf("\npara encerrar a leitura dos dados digite 0.\n> ");
		scanf("%d", &entrada);
		while(entrada != 0){
			no = criarELO(entrada);//cria instância tipo nó
			inserirFim(lista, no);//insere elemento na lista
			scanf("%d", &entrada);
		}
		imprimir(lista);
		break;

    case 3:
		printf("\npara encerrar a leitura dos dados digite 0.\n\n> ");
		scanf("%d", &entrada);
		while(entrada != 0){
			no = criarELO(entrada);//cria instância tipo nó
			inserirOrdenado(lista, no);//insere elemento na lista
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
			printf("[4] Acessar Posição\n");
			printf("[5] Buscar Elemento\n");
			printf("[6] Remover Elemento (Início)\n");
			printf("[7] Remover Elemento (Fim)\n");
			printf("[8] Remover Elemento (Posição)\n\n> ");
      scanf("%d", &op);
			switch(op){
				case 0: printf("\naté logo :)\n"); break;
		
				case 4:
				printf("\ndigite uma posição para acessar\n> ");
				int pos_acessada; scanf("%d", &pos_acessada);
				TELO *tmp = acessar(lista, pos_acessada);
				printf("\n-----acessando posição %d-----", pos_acessada);
				printf("\nelemento da posição %d: %d\n", pos_acessada, tmp->dado);
				break;
		
				case 5:
				printf("\ndigite o elemento buscado\n> ");	
				int buscado; scanf("%d", &buscado);
				if(buscar(lista, buscado)){
					printf("\no elemento %d está presente na lista.\n", buscado);
				}else{
					printf("\no elemento %d não está presente na lista.\n", buscado);
				}
				break;
		
				case 6:
				removerInicio(lista);
				printf("\n-----removendo do início-----");
				imprimir(lista);
				break;
		
				case 7:
				removerFim(lista);
				printf("\n-----removendo do fim-----");
				imprimir(lista);
				break;

				case 8:
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