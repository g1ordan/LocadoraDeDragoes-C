typedef struct {
	int codigoGuerreiro;
	char nome[30];
	char titulo[30];
	char reino[30];
} Guerreiro;


int inicializarGuerreiros();
int encerraGuerreiros();
int salvarGuerreiro(Guerreiro g);
int QuantidadeGuerreiros();
Guerreiro* obterGuerreiroPeloIndice(int indice);
Guerreiro* obterGuerreiroPeloCodigo(int codigoGuerreiro);
int ApagarGuerreiroPeloCodigo(int codigoGuerreiro);
int VerificarGuerreiroPeloCodigo(int codigoGuerreiro);
int DiminuirGuerreiroArray();
void AumentarGuerreiroArray(Guerreiro g);
int AtualizarGuerreiros(Guerreiro g);
