//Árvore Binária de Busca

#include "stdio.h"
#include "stdlib.h"
#include "abb.h"

int main(){ 
  printf("\n(digite 0 para encerrar a leitura dos dados)\n");//mensagem para o usuário
  printf("\n -> "); int no_raiz; scanf("%d", &no_raiz);//ler primeiro valor (raiz)
  TNO *arvoreBB = criarABB(no_raiz, criarVazia(), criarVazia());//cria árvore a partir da raiz
  int elemento; scanf("%d", &elemento);//ler os demais elementos
  while(elemento != 0){//enquanto elemento for diferente de 0
    inserirELE(arvoreBB, elemento);//insere elemento na árvore
    scanf("%d", &elemento);//repete o laço
  }
  printf("\n ________________________________________________________________ ");
  printf("\n                      ARVORE BINARIA DE BUSCA                     ");
  printf("\n ________________________________________________________________ ");
  printf("\n          FUNCAO        |                RESULTADO                ");
  printf("\n _______________________|________________________________________ ");
  printf("\n        ABB VALIDA      |"); if(abb(arvoreBB)){ printf("  SIM"); }else{ printf("  NAO"); }
  printf("\n _______________________|________________________________________ ");
  printf("\n       VALOR MINIMO     |"); minimo(arvoreBB);
  printf("\n _______________________|________________________________________ ");
  printf("\n     TOTAL DE FOLHAS    |"); printf("  %d", contarfolhas(arvoreBB)); 
  printf("\n _______________________|________________________________________ ");
  printf("\n  VALOR(ES) NEGATIVO(S) |");
  if(negativo(arvoreBB)){ printf("  a arvore possui valor(es) negativo(s)."); }
  else{ printf("  a arvore nao possui valores negativos."); } 
  printf("\n _______________________|________________________________________ ");
  printf("\n   PERCURSO EM LARGURA  |"); printf("  "); largura(arvoreBB);
  printf("\n _______________________|________________________________________ ");
  printf("\n    ARVORE ESPELHADA    |"); printf("  "); espelho(arvoreBB); ordem(arvoreBB);
  printf("\n _______________________|________________________________________ ");
  printf("\n     BUSCAR ELEMENTO    |"); printf("digite 1 para efetuar busca na arvore");
  printf("\n _______________________|________________________________________ \n");
  printf("\n               _______________________________________                ");
  printf("\n              |   digite 0 para finalizar o programa  |                ");
  printf("\n              |_______________________________________|              \n");
  int op, buscado; printf("-> ");scanf("%d", &op);
  switch(op){
    case 0:
      printf("\nFIM :)\n");
      break;
    case 1:
      printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=BUSCA=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
      printf("elemento: "); scanf("%d", &buscado);
      while(buscado != 0){
        if(buscarELE(arvoreBB, buscado)){ printf("o elemento buscado esta presente na arvore\n"); }
        else{ printf("o elemento buscado nao esta presente na arvore\n"); }
        printf("elemento: "); scanf("%d", &buscado);
      }
      printf("\nFIM :)\n");
      break;
    default:
      printf("comando invalido.\n");
  }
  return 0;
}