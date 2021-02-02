//estrutura de dados p/ árvore AVL
typedef struct NO TNO;
struct NO{//estrutura tipo nó da árvore
  int dado, alt;//a árvore é de inteiros, alt:altura árvore
  TNO *esq, *dir;//ponteiros tipo nó p/ sub-árvores esquerda e direita
}; 

TNO *criarNO(int info);//inicia ponteiros do nó da árvores
int altura(TNO *raiz);//calcula a altura dos filhos(sub-ávores) da árvore

//procedimentos de rotação da árvore
TNO *RD(TNO *p);//rotação direita
TNO *RE(TNO *p);//rotação esquerda
TNO *ED(TNO *raiz);//rotação esquerda-direita
TNO *DE(TNO *raiz);//rotação direita-esquerda

int FB(TNO *raiz);//calcula fator de balanceamento
TNO *inserirELE(TNO *raiz, int info);//insere elementos na árvore

//procedimentos para impressão da árvore (percursos de profundidade)
void preOrdem(TNO *raiz);
void ordem(TNO *raiz);
void posOrdem(TNO *raiz);