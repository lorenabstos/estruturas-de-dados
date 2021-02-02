#include "stdio.h"
#include "stdlib.h"
#include "vetordinamico.h"

int main(int argc, char const *argv[]){
	TD valor; 
	TVD *vd = criarVD(10);
    printf("digite 0 para encerrar a leitura dos dados.\n\n> ");
    scanf("%d", &valor.dado);
    while(valor.dado != 0){
	 	inserirVD(vd, valor);
	 	scanf("%d", &valor.dado);
	 }
	 printf("\nvetor: ");
   imprimirVD(vd); printf("\n");
	 destruirVD(vd);
	 return 0;
}	