typedef struct NO TNO;
struct NO{//estrutura tipo nó árvore 234
	TNO *pai, *ponteiros[5];
	int dado[4], tamanho;
};

typedef struct A234 T234;
struct A234{//estrutura tipo árvore 234 para raiz árvore
	TNO *root;
};

//funções 
TNO *criarNO(TNO *pai);
T234 *criar234();
int raiz(TNO**);
int folha(TNO**);
void auxInserir(TNO**, int, T234*);
void inserir(T234*, int);
TNO* buscarFilho(TNO**, int);
void buscarValor(T234*, int);
void dividir(TNO**, T234*);
void auxImprimir(TNO*, int);
void imprimir(T234*);