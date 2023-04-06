#include <stdio.h>
#include <stdlib.h>
#include "Guerreiro.h"
#include "Dragao.h"
#include "Elemento.h"
#include "Locacao.h"

void ImprimirMenu()
{
	printf("\nMENU:\n");
	printf("0 - Sair.\n");
	printf("1 - Guerreiros.\n");
	printf("2 - Dragoes.\n");
	printf("3 - Elementos do Dragao.\n");
	printf("4 - Locacoes.\n");	
}

void ImprimirSubMenu()
{
	printf("\nSUB MENU:\n");
	printf("0 - Sair.\n");
	printf("1 - Listar.\n");
	printf("2 - Cadastrar.\n");
	printf("3 - Atualizar.\n");
	printf("4 - Pesquisar.\n");
	printf("5 - Excluir.\n");	
}

void ListarGuerreiros(){
	printf("\nLista Dos Guerreiros:\n");
	int i;
	for(i = 0; i < QuantidadeGuerreiros(); i++)
	{
		Guerreiro* g = obterGuerreiroPeloIndice(i);
		if (g->codigoGuerreiro > 0)
			printf("\nCodigo: %d - Nome: %s - Titulo: %s - Reino: %s\n", 
				g->codigoGuerreiro, 
				g->nome,
				g->titulo,
				g->reino);
				free(g);
	}
	
	if (QuantidadeGuerreiros()==0)
		printf("\nNao ha guerreiros cadastrados.\n");
	
	printf("\n");
	}
 
void CadastrarGuerreiros(){
	Guerreiro g;
	//g.codigoGuerreiro = codigoAtual++;
	printf("Digite o nome: ");
	scanf("%s", g.nome);
	printf("Digite o titulo: ");
	scanf("%s", g.titulo);
	printf("Digite o Reino: ");
	scanf("%s", g.reino);
	
	if (salvarGuerreiro(g)==1)
		printf("\nGuerreiro cadastrado com sucesso!\n\n");
	else
		printf("\nFalha ao cadastrar Guerreiro!\n\n");
}

void pesquisarGuerreiro(){
	Guerreiro* g;
//	if (QuantidadeGuerreiros()==0)
//		printf("\nNao ha guerreiros cadastrados.\n");
//		
//	else{
	int codigo;
	printf("\nDigite o Codigo do Guerreiro:\n ");
	scanf("%d", &codigo);
	
	g = obterGuerreiroPeloCodigo(codigo);
	
	if(codigo == g->codigoGuerreiro){
		//	g = obterGuerreiroPeloCodigo(codigo);
//	if (g.codigoGuerreiro > 0)

	printf("Guerreiro Selecionado:\n");
	printf("\nCodigo: %d - Nome: %s - Titulo: %s - Reino: %s\n", 
				g->codigoGuerreiro, 
				g->nome,
				g->titulo,
				g->reino);	
	}
	else{
		printf("\nNao ha guerreiro cadastrado.\n");
	}
}
	
	
void ApagarGuerreiro() {
	
	ListarGuerreiros();
	int codigo;

	printf ("Digite o codigo do Guerreiro a ser apagado:");
	scanf("%d", &codigo);
	int retorno = ApagarGuerreiroPeloCodigo(codigo);

	if (retorno == 1) 
		printf ("\nGuerreiro apagado com sucesso.\n");
	else if(retorno == 0)
		printf ("Falha ao apagar o guerreiro.\n");
	else if (retorno == 2){
		printf ("Falha ao apagar o guerreiro, pois possue uma locacao.\n");
	}	
}

void AlterarGuerreiros(){
	int codigo;
	int cod;
	Guerreiro* found;
	
	printf("\nDigite o Codigo do Guerreiro:\n ");
	scanf("%d", &codigo);
	found = obterGuerreiroPeloCodigo(codigo);
	
	if(found!=NULL){
	
	found->codigoGuerreiro = codigo;
	
	system("cls");
	printf("\nNome do Guerreiro eh: %s\n", found->nome);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao:\n");
	scanf("\n%d", &cod);
	
	if(cod == 1){
		printf("\nDigite o nome: ");
		scanf("\n%s", found->nome);
	}
	
	system("cls");
	printf("\nTitulo do Guerreiro eh: %s\n", found->titulo);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao:\n");
	scanf("\n%d", &cod);
	
	if(cod == 1){
	printf("\nDigite o titulo: ");
	scanf("\n%s", found->titulo);
	}
	
	system("cls");
	printf("\nReino do Guerreiro eh: %s\n", found->reino);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao:\n");
	scanf("\n%d", &cod);
	
	if(cod == 1){
	printf("\nDigite o Reino: ");
	scanf("\n%s", found->reino);
	}
	
	if (AtualizarGuerreiros(*found)==1)
		printf("\nGuerreiro alterado com sucesso!\n\n");
	else
		printf("\nFalha ao alterar Guerreiro!\n\n");
}else
 printf("\nCodigo invalido.\n");
	}	
	
//--------------------------------------------------------------------------//

void ListarDragoes(){
	printf("\nLista Dos Dragoes:\n");
	int i;
	for(i = 0; i < QuantidadeDragoes(); i++)
	{
		Dragao* d = obterDragaoPeloIndice(i);
		if (d->codigoDragao > 0)
			printf("\nCodigo: %d - Nome: %s - Idade: %d - Valor Diario: %d - Unidade Em Estoque: %d - Elemento: %s\n", 
				d->codigoDragao, 
				d->nome,
				d->idade,
				d->valorDiario,
				d->unidadesEmEstoque,
				obterElementoPeloCodigo(d->codElemento)->nome);
				free(d);
	}
	if (QuantidadeDragoes()==0)
		printf("\nNao ha Dragoes cadastrados.\n");
	
	printf("\n");
	}

void CadastrarDragoes(){
	Dragao d;
	//g.codigoDragao = codigoAtual++;
	printf("Digite o nome: ");
	scanf("%s", d.nome);
	printf("Digite a idade: ");
	scanf("%d", &d.idade);
	printf("Digite o Valor Diário: ");
	scanf("%d", &d.valorDiario);
	printf("Digite A unidade a cadastrar: ");
	scanf("%d", &d.unidadesEmEstoque);
	ListarElementos();
	printf("Digite o codigo do Elemento do Dragao: ");
	scanf("%d", &d.codElemento);
	
	int retorno = salvarDragoes(d);
	if(retorno == 2){
		printf("\nCodigo Invalido.\n");
	}
	else if (retorno == 1)
		printf("\nDragao cadastrado com sucesso!\n\n");
	else
		printf("\nFalha ao cadastrar dragao!\n\n");
}

void pesquisarDragao(){
	Dragao* d;
	int codigo;
	
	printf("\nDigite o Codigo do Dragao: ");
	scanf("%d", &codigo);
	
	d = obterDragaoPeloCodigo(codigo);
	if (codigo == d->codigoDragao){
		printf("\nDragao Selecionado:\n");
//		if (d.codigoDragao > 0)
			printf("Codigo: %d - Nome: %s - Idade: %d - Valor Diario: %d - Unidade Em Estoque: %d\n", 
				d->codigoDragao, 
				d->nome,
				d->idade,
				d->valorDiario,
				d->unidadesEmEstoque);
	}else{
		printf("\nNao ha Dragao cadastrado.\n");
	}		
}

void ApagarDragao() {
	int i;
	
	ListarDragoes();
	int codigo;

	printf ("Digite o codigo do Dragao a ser apagado:");
	scanf("%d", &codigo);
	int retorno = ApagarDragaoPeloCodigo(codigo);

	if (retorno == 1) 
		printf ("\nDragao apagado com sucesso.\n");
	else if(retorno == 0)
		printf ("Falha ao apagar o dragao.\n");
	else if (retorno == 2){
		printf ("Falha ao apagar o Dragao, pois possue uma locacao.\n");
	}	
}

void AlterarDragoes(){
	int codigo;
	int cod;
	Dragao* found;
	
	printf("\nDigite o Codigo do Dragao:\n ");
	scanf("%d", &codigo);
	found = obterDragaoPeloCodigo(codigo);
	
	if(found!=NULL){
	
	found->codigoDragao = codigo;
	
	system("cls");
	printf("\nNome do Dragao: %s\n", found->nome);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao:");
	scanf("%d", &cod);
	
	if(cod == 1){
		printf("\nDigite o nome: ");
		scanf("%s", found->nome);
	}
	
	system("cls");
	printf("\nIdade do Dragao eh: %d\n", found->idade);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao: ");
	scanf("%d", &cod);
	
	if(cod == 1){
	printf("\nDigite a idade do Dragao: ");
	scanf("%d", &found->idade);
	}
	
	system("cls");
	printf("\nAs unidades em estoque sao: %d\n", found->unidadesEmEstoque);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao: ");
	scanf("%d", &cod);
	
	if(cod == 1){
	printf("\nDigite as unidades em estoque: ");
	scanf("%d", &found->unidadesEmEstoque);
	}
	
	system("cls");
	printf("\nO valor diario eh: %d\n", found->valorDiario);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao: ");
	scanf("%d", &cod);
	
	if(cod == 1){
	printf("\nDigite o valor diario: ");
	scanf("%d", &found->valorDiario);
	}
	
	if (AtualizarDragoes(*found)==1)
		printf("\nDragao alterado com sucesso!\n\n");
	else
		printf("\nFalha ao alterar Dragao!\n\n");
}else
 printf("\nCodigo invalido.\n");
	}	
	

//--------------------------------------------------------------------------//

void ListarElementos(){
	printf("\nLista Dos Elementos:\n");
	int i;
	for(i = 0; i < QuantidadeElementos(); i++)
	{
		Elemento* e = obterElementoPeloIndice(i);
		if (e->codigoEle > 0)
			printf("\nCodigo: %d - Nome: %s - Vulnerabilidade: %s\n", 
				e->codigoEle,
				e->nome,
				e->vulnerabilidade);
				free(e);
	}
	if (QuantidadeElementos()==0)
		printf("\nNao ha Elementos cadastrados.\n");
	
	printf("\n");
	}

void CadastrarElementos(){
	Elemento e;
	//g.codigoDragao = codigoAtual++;
	printf("Digite o nome: ");
	scanf("%s", e.nome);
	printf("Digite a vulnerabilidade: ");
	scanf("%s", e.vulnerabilidade);
	
	
	if (salvarElementos(e)==1)
		printf("\nElemento cadastrado com sucesso!\n\n");
	else
		printf("\nFalha ao cadastrar Elemento!\n\n");
}

void pesquisarElemento(){
	Elemento* e;
	int codigo;
	
	printf("\nDigite o Codigo do Elemento: ");
	scanf("%d", &codigo);
	
	e = obterElementoPeloCodigo(codigo);
	
	if (codigo == e->codigoEle){
		printf("\nDragao Selecionado:\n");
//		if (d.codigoDragao > 0)
		printf("\nCodigo: %d - Nome: %s - Vulnerabilidade: %s", 
				e->codigoEle,
				e->nome,
				e->vulnerabilidade);	
	}else{
		printf("\nNao ha Elemento cadastrado.\n");
	}		
}

void ApagarElemento() {
	int i;
	
	ListarElementos();
	int codigo;
	

	printf ("Digite o codigo do Elemento a ser apagado:\n");
	scanf("%d", &codigo);
	int retorno = ApagarElementoPeloCodigo(codigo);
	
	if(retorno == 2){
		printf ("\nJa existe um dragao com esse elemento. Impossivel apagar.\n");
	}	

	else if (retorno == 1) 
		printf ("\nElemento apagado com sucesso.\n");
	else if (retorno ==0)
		printf ("Falha ao apagar o Elemento.\n");
}

void AlterarElementos(){
	int codigo;
	int cod;
	Elemento* found;
	
	printf("\nDigite o Codigo do Elemento:\n ");
	scanf("%d", &codigo);
	found = obterElementoPeloCodigo(codigo);
	
	if(found!=NULL){
	
	found->codigoEle = codigo;
	
	system("cls");
	printf("\nNome do Elemento eh: %s\n", found->nome);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao:\n");
	scanf("\n%d", &cod);
	
	if(cod == 1){
		printf("\nDigite o nome: ");
		scanf("\n%s", found->nome);
	}
	
	system("cls");
	printf("\nVulnerabilidade do Elemento: %s\n", found->vulnerabilidade);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao:\n");
	scanf("\n%d", &cod);
	
	if(cod == 1){
	printf("\nDigite a vulnerabilidade: ");
	scanf("\n%s", found->vulnerabilidade);
	}
	
	
	if (AtualizarElementos(*found)==1)
		printf("\nElemento alterado com sucesso!\n\n");
	else
		printf("\nFalha ao alterar Elemento!\n\n");
}else
 printf("\nCodigo invalido.\n");
	}	
	
	
//--------------------------------------------------------------------------//

void ListarLocacoes(){
	printf("\nLista Dos Locados:\n");
	int i;
	for(i = 0; i < QuantidadeLocados(); i++)
	{
		Locacao* l = obterLocacaoPeloIndice(i);
		if (l->codLoc > 0)
			printf("\nCodigoLoc: %d - NomeGuerreiro: %s - NomeDragao: %s - Pagamento: %s - Inicio da Locacao: %s - Fim da Locacao: %s\n", 
				l->codLoc,
				obterGuerreiroPeloCodigo(l->codG)->nome,
				obterDragaoPeloCodigo(l->codD)->nome,
				l->pago,
				l->dataInicioDeLocacao,
				l->dataFimDeLocacao);
				free(l);
	}
	if (QuantidadeLocados()==0)
		printf("\nNao ha Locacoes cadastradas.\n");
	
	printf("\n");
	}

void CadastrarLocacoes(){
	Locacao l;
	
	//g.codigoDragao = codigoAtual++;
	printf("Digite o codigo do Guerreiro: ");
	scanf("%d", &l.codG);
	printf("Digite o cod. do Dragao: ");
	scanf("%d", &l.codD);
	printf("Data Inicio da locacao: ");
	scanf("%s", l.dataInicioDeLocacao);
	printf("Data Fim da locacao: ");
	scanf("%s", l.dataFimDeLocacao);
	printf("Pagamento: ");
	scanf("%s", l.pago);
 	
 	int retorno = salvarLocacoes(l);
	
	if(retorno==2){
		printf("\nGuerreiro Nao encontrado!\n\n");
	}
	else if(retorno==3){
		printf("\nDragao Nao encontrado!\n\n");
	}
	
	else if (retorno==4){
		printf("\nNao ha dragoes para locar!\n\n");
	}
	else if (retorno==1){
		printf("\nLocacao cadastrada com sucesso!\n\n");
	}
		
	else
	printf("Ocorreu um erro, tente novamente.");
	}
	
void pesquisarLocacoes(){
	Locacao* l;
	int codigo;
	
	printf("\nDigite o Codigo da Locacao: ");
	scanf("%d", &codigo);
	
	l = obterLocacaoPeloCodigo(codigo);
	
	if (codigo == l->codLoc){
		printf("\nLocacao Selecionada:\n");
//		if (d.codigoDragao > 0)
		printf("\nCodigoLoc: %d - NomeGuerreiro: %s - NomeDragao: %s - Pagamento: %s - Inicio da Locacao: %s - Fim da Locacao: %s\n", 
				l->codLoc,
				obterGuerreiroPeloCodigo(l->codG)->nome,
				obterDragaoPeloCodigo(l->codD)->nome,
				l->pago,
				l->dataInicioDeLocacao,
				l->dataFimDeLocacao);	
	}else{
		printf("\nNao ha Locacoes cadastradas.\n");
	}		
}

void ApagarLocacoes() {
	int i;
	
	ListarLocacoes();
	int codigo;
	int cod;

	printf ("Digite o codigo da Locacao a ser apagada:\n");
	scanf("%d", &codigo);
	
	printf ("O Guerreiro devolveu o Dragao? 1 para sim e 0 para nao.\n");
	scanf("%d", &cod);
	
	if(cod == 1 && ApagarLocacaoPeloCodigo(codigo)==1)
	printf ("\nLocacao apagada com sucesso.\n");
	else if(cod == 0)
	printf ("\nLocacao ainda em aberto.\n");
	else
	printf ("\nNao foi possivel identificar o comando. Tente novamente.\n");
}

void AlterarLocacoes(){
	int codigo;
	int cod;
	Locacao* found;
	
	printf("\nDigite o Codigo da Locacao:\n ");
	scanf("%d", &codigo);
	found = obterLocacaoPeloCodigo(codigo);
	
	if(found!=NULL){
	
	found->codLoc = codigo;
	
	system("cls");
	printf("\nForma de pagamento: %s\n", found->pago);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao:\n");
	scanf("\n%d", &cod);
	
	if(cod == 1){
	printf("\nDigite a nova forma: ");
	scanf("\n%s", found->pago);
	}
	
	system("cls");
	printf("\nInicio da Locacao: %s\n", found->dataInicioDeLocacao);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao:\n");
	scanf("\n%d", &cod);
	
	if(cod == 1){
	printf("\nDigite a nova data: ");
	scanf("\n%s", found->dataInicioDeLocacao);
	}
	
		system("cls");
	printf("\nFim da Locacao: %s\n", found->dataFimDeLocacao);
	printf("\nCaso queira alterar digite 1 para sim e 0 para nao:\n");
	scanf("\n%d", &cod);
	
	if(cod == 1){
	printf("\nDigite a nova data: ");
	scanf("\n%s", found->dataFimDeLocacao);
	}
	
	
	if (AtualizarLocacoes(*found)==1)
		printf("\nLocacao alterada com sucesso!\n\n");
	else
		printf("\nFalha ao alterar Locacao!\n\n");
}else
 printf("\nCodigo invalido.\n");
	}

//--------------------------------------------------------------------------//	
	
int main(int argc, char *argv[]) {
inicializarDragoes();
inicializarGuerreiros();
inicializarElementos();	
inicializarLocacoes();
int opcao;
int subOpcao;
	
	
do{
	ImprimirMenu();
	printf("\nSelecione a opcao:\n");
	scanf("%d", &opcao);
	do{
	
		switch(opcao)
		{
			case 0:
				subOpcao = 0;
		    	printf ("Programa encerrado.\n"); 
		    	break;	
			case 1:
				ImprimirSubMenu();
				printf ("\nGuerreiros!\n\n"); 
				scanf("%d", &subOpcao);
				
					switch(subOpcao){
					case 0:
					printf ("\nOperacao Encerrada.\n"); 
					break;

					case 1:
					printf ("\nListar Guerreiros:\n"); 
					ListarGuerreiros();
					break;

					case 2:
					printf ("\nCadastrar Guerreiros:\n"); 
					CadastrarGuerreiros();
					break;
					
					case 3:
					printf ("\nAtualizar Guerreiros:\n"); 
					AlterarGuerreiros();
					break;
					
					case 4:
					printf ("\nPesquisa Guerreiros:\n");
					pesquisarGuerreiro();				
					break;
								
					case 5:
					printf ("\nApagar Guerreiro pelo codigo:\n");
					ApagarGuerreiro();		
					break;
															
					default:
					printf ("\nErro.");	
				}
				break; 
				
			case 2:
				ImprimirSubMenu();
				printf ("\nDragoes!\n\n"); 
				scanf("%d", &subOpcao);
				
					switch(subOpcao){
					case 0:
					printf ("\nOperacao Encerrada.\n"); 
					break;

					case 1:
					printf ("\nListar Dragoes:\n"); 
					ListarDragoes();
					break;

					case 2:
					printf ("\nCadastrar Dragoes:\n"); 
					CadastrarDragoes();
					break;

					case 3:
					printf ("\nAtualizar Dragoes:\n"); 
					AlterarDragoes();
					break;
								
					case 4:
					printf ("\nPesquisa Dragoes:\n");
					pesquisarDragao();				
					break;
					
					case 5:
					printf ("\nApagar Dragao pelo codigo:\n");
					ApagarDragao();		
					break;
															
					default:
					printf ("\nErro.");	
				}
				break;
			case 3:
				ImprimirSubMenu();
				printf ("\nElementos!\n\n"); 
				scanf("%d", &subOpcao);
				
				switch(subOpcao){
					case 0:
					printf ("\nOperacao Encerrada.\n"); 
					break;

					case 1:
					printf ("\nListar Elementos:\n"); 
					ListarElementos();
					break;

					case 2:
					printf ("\nCadastrar Elementos:\n"); 
					CadastrarElementos();
					break;

					case 3:
					printf ("\nAtualizar Elementos:\n"); 
					AlterarElementos();
					break;
								
					case 4:
					printf ("\nPesquisar Elementos:\n");
					pesquisarElemento();				
					break;
					
					case 5:
					printf ("\nApagar Elemento pelo codigo:\n");
					ApagarElemento();		
					break;
															
					default:
					printf ("\nErro.");	
				}
				break;
			case 4:
				ImprimirSubMenu();
				printf ("\nLocacoes!\n\n"); 
				scanf("%d", &subOpcao);
				
				switch(subOpcao){
					case 0:
					printf ("\nOperacao Encerrada.\n"); 
					break;

					case 1:
					printf ("\nListar Locacoes:\n"); 
					ListarLocacoes();
					break;

					case 2:
					printf ("\nCadastrar Locacoes:\n"); 
					CadastrarLocacoes();
					break;
					
					case 3:
					printf ("\nAtualizar Locacoes:\n"); 
					AlterarLocacoes();
					break;
								
					case 4:
					printf ("\nPesquisar Locacoes:\n");
					pesquisarLocacoes();				
					break;
					
					case 5:
					printf ("\nApagar Locacoes pelo codigo:\n");
					ApagarLocacoes();		
					break;
															
					default:
					printf ("\nErro.");	
				}
				break;
		}	
	}while(subOpcao != 0);
		
	

}while(opcao !=0 ); 
	
	encerraDragoes();
	encerraGuerreiros();
	encerraElemento();	
	encerraLocacao();		
	return 0;
}
