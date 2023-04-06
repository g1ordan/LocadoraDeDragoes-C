typedef struct {
	int codigoEle;
	char nome[30];
	char vulnerabilidade[30];	
} Elemento;


int inicializarElementos();
int encerraElementos();
int salvarElementos(Elemento e);
int QuantidadeElementos();
Elemento* obterElementoPeloIndice(int indice);
Elemento* obterElementoPeloCodigo(int codigoElemento);
int ApagarElementoPeloCodigo(int codigoElemento);
int VerificaCodigoElemento(int codigoEle);
int DiminuirElementoArray();
void AumentarElementoArray(Elemento e);
int AtualizarElementos(Elemento e);
