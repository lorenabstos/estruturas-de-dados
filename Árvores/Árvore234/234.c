//Árvore Multiway/2-3-4

//execução do código: https://youtu.be/esXFtGR1aF8

#include "stdio.h"
#include "stdlib.h"
#include "234.h"

TNO *criarNO(TNO *pai){//cria/inicializa nó
	TNO *no = malloc(sizeof(TNO));
	for(int i=0; i<5; i++){ no -> ponteiros[i] = NULL; }//nós filhos recebem null
  for(int i=0; i<4; i++){ no -> dado[i] = 0; }
	no -> tamanho = 0;
	no -> pai = pai;
  return no;
}

T234 *criar234(){//cria árvore
  T234 *arv = malloc(sizeof(T234));
  arv -> root = criarNO(NULL);//cria no raiz árvore
  return arv;
}
	
int raiz(TNO **raiz){//verifica no raiz com no pai (nulo)
    if((*raiz)->pai == NULL){ return 1; }
    else{ return 0; }
}

int folha(TNO **raiz){//verifica se no é folha (se o filho esq(pos 0) for nulo)
    if((*raiz)->ponteiros[0] == NULL){ return 1; }
    else{ return 0; }
}

void ordenar(int vetor[], int tam){//insertion sort
	for(int i=0; i<tam; i++){
		int aux = vetor[i];
		int j = i - 1;
		while(j >= 0 && vetor[j] > aux){
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = aux;
	}
}

void auxInserir(TNO **raiz, int valor, T234 *amw){//função auxiliar p inserção ordenada
	int tam = (*raiz) -> tamanho;
  	(*raiz) -> dado[tam] = valor;//insere elemento na raiz
  	(*raiz) -> tamanho++;//tamanho aumenta em 1
  	ordenar((*raiz)->dado, (*raiz)->tamanho);//ordenação de elementos inseridos
  	if((*raiz)->tamanho == 4){ dividir(raiz, amw); }//se nó filho está cheio (4 elementos), é dividido 
}

void inserir(T234 *amw, int valor){//função inserção de valores
  TNO *ant, *pres = amw -> root; //ant - anterior, pres - presente, amw - árvore multiway, root - raiz
  do{//não folha
    ant = pres; //nó anterior igual nó presente
    pres = buscarFilho(&ant, valor);
  }while(pres);
  auxInserir(&ant, valor, amw);//é folha
}

TNO *buscarFilho(TNO **raiz, int valor){//procura em qual filho do no está (possivelmente) o valor buscado
    int tam = (*raiz) -> tamanho;
    if(folha(raiz)){ return 0; } //se for folha não há filhos possíveis, retorna nulo
    else{ //buscar pos do possível filho
        int i=0;
        while(i<tam && valor > (*raiz)->dado[i]){ i++; }
        return (*raiz) -> ponteiros[i]; //caso valor buscado seja > que todos os elementos, retorna o último filho
    }
}

void auxBuscar(TNO *root, int valor, int nivel){//função auxiliar de busca
  int i; int tam = root -> tamanho;
  for(i=0; i<tam; i++){
    if(valor < root->dado[i]){ break; }
    else{
      if(valor == root->dado[i]){//elemento encontrado
        printf("o dado %d estava no nivel %d da arvore e na posicao %d do no\n", valor, nivel, i);
        return;
      }
    }
  }
  if(!root->ponteiros[0]){ printf("o valor %d nao encontra-se na arvore.\n", valor); }
  else{
    if(i == tam){ i--; }
    auxBuscar(root->ponteiros[i], valor, nivel+1);
  }
}

void buscarValor(T234 *a234, int valor){//função de busca de elemento na árvore
  auxBuscar(a234->root, valor, 0);
}

void trocarFilho(TNO *pai, TNO *filho){//função trocar filhos
  int i=0, j;
  while(pai -> ponteiros[i]){ i++; }
  TNO *aux;
  int tam = i+1;
  pai -> ponteiros[i] = filho;
  for(i=0; i<tam-1; i++){
    int auxi = pai -> ponteiros[i] -> tamanho-1;
    for(j=i+1; j<tam; j++){
      int auxj = pai -> ponteiros[j] -> tamanho-1;
      if(pai->ponteiros[j]->dado[auxj] < pai->ponteiros[i]->dado[auxi]){//ordenação e troca de nós filhos
        aux = pai -> ponteiros[j];
        pai -> ponteiros[j] = pai -> ponteiros[i];
        pai -> ponteiros[i] = aux;
      }
    }
  }
}

void dividir(TNO **fesq, T234 *amw){//divisão de nó filho
  TNO *aux, *pai, *fdir;//fdir - filho direito, fesq - filho esquerdo
  int i, dir, esq;
  int meio = (*fesq) -> dado[1];
  (*fesq) -> tamanho = 1; (*fesq) -> dado[1] = 0;
  if(!(*fesq)->pai){//se não for raiz
    pai = criarNO((*fesq)->pai);//cria novo nó (raiz)
    amw -> root = pai;//raiz árvore recebe nó pai
    pai -> ponteiros[0] = *fesq;//filho esquerdo recebe nó pai em filho (pos 0)  
  }else{ pai = (*fesq) -> pai; }//se for raiz
  (*fesq) -> pai = pai;
  fdir = criarNO(pai);//cria no irmão a direita de nó atual
  auxInserir(&fdir, (*fesq)->dado[2], amw);
  auxInserir(&fdir, (*fesq)->dado[3], amw);
  (*fesq) -> dado[2] = 0; 
  (*fesq) -> dado[3] = 0;
  trocarFilho(pai, fdir);
  auxInserir(&pai, meio, amw);
  i=0; esq=0; dir=0;
  aux = (*fesq) -> ponteiros[i];
  while(i<5 && aux){
  	(*fesq) -> ponteiros[i] = NULL;
    if(aux->dado[(aux->tamanho)-1] > meio){
    	fdir -> ponteiros[dir] = aux;
      	dir++;
    }else{
    	(*fesq)->ponteiros[esq] = aux;
        esq++;
    }
    i++;
    aux = (*fesq) -> ponteiros[i];
  }
}

void auxImprimir(TNO *raiz, int nivel){//função auxiliar de impressão
    int i, tam = raiz->tamanho;
    for(i=0; i<tam; i++){
      printf("    %d      %d      %d\n", nivel, i, raiz->dado[i]);
    }
    i=0;
    while(i < 4 && raiz->ponteiros[i]){
      auxImprimir(raiz->ponteiros[i], nivel+1);
      i++;
    }
}

void imprimir(T234 *a234){//imprime árvore 
  auxImprimir(a234->root, 0);
}