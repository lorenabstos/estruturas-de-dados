#include "stdio.h"
#include "stdlib.h"
#include "234.h"

int main(){
  T234 *arvore234 = criar234();//cria árvore
  int i, elemento;
  for(i=0; i<300; i++){//gera 300 números aleatórios
  	elemento = rand() % 100;
    inserir(arvore234, elemento);//insere elementos na árvore
  }	  
  printf("      ARVORE 2-3-4\n");
  printf("| NIVEL | POS |  CHAVE  |\n");
  imprimir(arvore234);//imprime nível, posição e elemento
  printf("\nnumeros gerados para verificacao:\n");
  for(i=0; i<80; i++){//gera 80 números aleatórios p verificação
	  elemento = rand() % 100;
	  buscarValor(arvore234, elemento);//busca de valores e verificação de pertinência
  }
  return 0;
}