typedef struct {
	int codG;
	int codD;
	int codLoc;
	char pago[10];
	char dataFimDeLocacao[30];
	char dataInicioDeLocacao[30];	
} Locacao;


int inicializarLocacoes();
int encerraLocacao();
int salvarLocacoes(Locacao l);
int QuantidadeLocados();
Locacao* obterLocacaoPeloIndice(int indice);
Locacao* obterLocacaoPeloCodigo(int codLoc);
int ApagarLocacaoPeloCodigo(int codLoc);
int VerificaCodigoLocacao(int codLoc);
int VerificaLocacaoGuerreiro(int codG);
int VerificaLocacaoDragao(int codD);
int DiminuirLocacaoArray();
void AumentarLocacaoArray(Locacao l);
int AtualizarLocacoes(Locacao l);
