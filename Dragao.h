typedef struct {
	int codigoDragao;
	char nome[30];
	int idade;
	int valorDiario;
	int unidadesEmEstoque;
	int codElemento;
} Dragao;


int inicializarDragoes();
int encerraDragoes();
int salvarDragoes(Dragao d);
int QuantidadeDragoes();
Dragao* obterDragaoPeloIndice(int indice);
Dragao* obterDragaoPeloCodigo(int codigoDragao);
//Dragao obterDragaoPeloCodigoElemento(int codigoEle);
int ApagarDragaoPeloCodigo(int codigoDragao);
int VerificarDragaoPeloCodigoEle(int codElemento);
int VerificarDragaoPeloCodigo(int codigoDragao);
int DiminuirDragaoArray();
void AumentarDragaoArray(Dragao d);
int AtualizarDragoes(Dragao d);
void decrementarDragao(int codigoDragao);
