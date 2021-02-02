typedef struct NO TNO;
struct NO{//estrutura tipo nó da árvore 
    int dado;//a árvore é de inteiros
    TNO *direita, *esquerda;//ponteiros tipo nó para sub-árvores direita(sad) e esquerda(sae)
};

TNO *criarVazia();
TNO *criarABB(int info, TNO *sad, TNO *sae);
int ABBVazia(TNO *raiz);
TNO *inserirELE(TNO *raiz, int info);
void largura(TNO *raiz);
int contarfolhas(TNO *raiz);
void espelho(TNO *raiz);
int buscarELE(TNO *raiz, int info);
void minimo(TNO *raiz);
int negativo(TNO *raiz);
int min(TNO *raiz);
int max(TNO *raiz);
int abb(TNO *raiz);
void preOrdem(TNO *raiz);
void ordem(TNO *raiz);
void posOrdem(TNO *raiz);