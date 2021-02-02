typedef struct Dados TD;
struct Dados{//estrutura dados
    int dado;
	//double dado;
};

typedef struct VD TVD;
struct VD{//estrutura vetor dinâmico
	int pos, tamanho;
    TD *armazenador;
};

//funções
TVD *criarVD(int qtde);//cria/inicializa ponteiros vetor 
void inserirVD(TVD *vd, TD valor);//insere valores no vetor
void destruirVD(TVD *dvd);//libera memória
void imprimirVD(TVD *vd);
