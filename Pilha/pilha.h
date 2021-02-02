typedef struct NO TNO;
struct NO{
	int dado, altura;
	TNO *prox;
};

TNO *criarNO(int info);
int pilhaVazia(TNO *pilha);
void empilhar(TNO *pilha, int info);
TNO *desempilhar(TNO *pilha);
void liberar(TNO *pilha);
void imprimir(TNO *pilha);