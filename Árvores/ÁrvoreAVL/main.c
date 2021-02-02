#include "stdio.h"
#include "stdlib.h"
#include "avl.h"

int main(){
  printf("\n                                   ARVORE BINARIA AVL                                ");
  printf("\n_____________________________________________________________________________________");
  printf("\n\nArvore AVL: 5 4 3 6 7 8");
  printf("\nrotacoes realizadas:\n");
  TNO *raiz = NULL;
  raiz = inserirELE(raiz, 5); 
  raiz = inserirELE(raiz, 4);
  raiz = inserirELE(raiz, 3);
  raiz = inserirELE(raiz, 6);
  raiz = inserirELE(raiz, 7);
  raiz = inserirELE(raiz, 8); 
  printf("______________________________________________________________________________________\n\n");
  printf("impressao da arvore em ordem infixada com formato n (FB):\n"); ordem(raiz);
  printf("______________________________________________________________________________________\n\n");
  printf("(digite 1 p/ testar com outro conjunto de dados ou 0 para finalizar programa.)\n\n>> ");
  TNO *arvore = NULL;
  int op, n, elemento; scanf("%d", &op);
  switch(op){
    case 0: 
      printf("\nate logo :)\n");
      break;
    case 1:
      printf("\n(digite -1 para encerrar a leitura dos dados.)\n\n>> ");
      scanf("%d", &elemento);
      while(elemento >= 0){
        arvore = inserirELE(arvore, elemento);
        scanf("%d", &elemento);
      }
      printf("(rotacoes realizadas nesta arvore)\n");
      printf("\nescolha o percurso para a impressao da arvore:");
      printf("\n[1] pre-ordem\n[2] em-ordem\n[3] pos-ordem\n\n>> ");
      scanf("%d", &n);
      switch(n){
        case 1: printf("\n=-=-=-=-=-=-=-=-=-=PRE-ORDEM=-=-=-=-=-=-=-=-=-=\n"); preOrdem(arvore); break;
        case 2: printf("\n=-=-=-=-=-=-=-=-=-=EM ORDEM=-=-=-=-=-=-=-=-=-=\n"); ordem(arvore); break;
        case 3: printf("\n=-=-=-=-=-=-=-=-=-=POS-ORDEM=-=-=-=-=-=-=-=-=-=\n"); posOrdem(arvore); break;
        default: printf("\npercurso invalido\n"); break;
      }
      break;   
  }  
  return 0;
}
