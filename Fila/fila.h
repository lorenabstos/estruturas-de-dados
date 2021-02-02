typedef struct NO TNO;
struct NO{//estrutura nó da fila
	int dado, tamanho;
	TNO *prox;
};

TNO *criarNO(int info);
int vazia(TNO *fila);
void enfileirar(TNO *fila, int info);
TNO *desenfileirar(TNO *fila);
void imprimir(TNO *fila);
void liberar(TNO *fila);