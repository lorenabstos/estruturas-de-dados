#include "stdio.h"
#include "stdlib.h"
#include "vetordinamico.h"

//vetor dinâmico 

TVD *criarVD(int qtde){//cria/inicializa ponteiros vetor 
	TVD *cvd = malloc(sizeof(TVD));
	cvd -> pos = 0;
	cvd -> tamanho = qtde;
	cvd -> armazenador = malloc(sizeof(TD)*cvd->tamanho);
	return cvd; //retorna ponteiro
}

void inserirVD(TVD *vd, TD valor){//insere valores no vetor
	if(vd->pos+1 == vd->tamanho){
		vd -> tamanho = vd -> tamanho*2;
		vd -> armazenador = realloc(vd->armazenador, sizeof(TD)*vd->tamanho);
	}
	vd -> armazenador[vd->pos] = valor;
	vd -> pos++;
}

void destruirVD(TVD *dvd){//libera memória
	free(dvd->armazenador);
}

void imprimirVD(TVD *vd){
	for(int i=0; i<vd->pos; i++){
		printf("%d ", vd->armazenador[i].dado);
	}
}

