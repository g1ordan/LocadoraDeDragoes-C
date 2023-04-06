#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Locacao.h"
#include "Dragao.h"
#include "Guerreiro.h"
#include "Elemento.h"

int MAX_LOCACAO = 5;
FILE* arquivoLocacao;
int qtdLocados = 0;
int codigoAtualL = 0;


int inicializarLocacoes(){
	
	arquivoLocacao = fopen("LocacaoTXT.txt", "r+b");
	if(arquivoLocacao == NULL){
		return 0;
	}
	fseek(arquivoLocacao,0, SEEK_END);
	int tamanho = ftell(arquivoLocacao);
	qtdLocados = tamanho/sizeof(Locacao);
	fseek(arquivoLocacao, 0, SEEK_SET);
	int i;
	Locacao l;
	for(i = 0; i <qtdLocados; i++){
		fread(&l,sizeof(Locacao),1,arquivoLocacao);
		if(l.codLoc > codigoAtualL)
		codigoAtualL = l.codLoc;
	}
	codigoAtualL++;
	printf("codigoatualLocacao %d\n", codigoAtualL);
	printf("qtdLocados %d\n", qtdLocados);
	
//	---2 LINHAS DE CIMA = DEBUG---
	
	return 1;
}

int encerraLocacao(){
	fclose(arquivoLocacao);
}

int salvarLocacoes(Locacao l){
	l.codLoc = codigoAtualL++;
	fseek(arquivoLocacao,0, SEEK_END);
	fwrite(&l,sizeof(Locacao),1, arquivoLocacao);	
	qtdLocados++;
	
	return 1;
}	

int QuantidadeLocados(){
	return qtdLocados;
}
	
Locacao* obterLocacaoPeloIndice(int indice){
	
	Locacao* l = (Locacao*) malloc(sizeof(Locacao));
	fseek(arquivoLocacao, indice * sizeof(Locacao), SEEK_SET);
	fread(l, sizeof(Locacao), 1, arquivoLocacao);
	rewind(arquivoLocacao);
	
	return l;
}

Locacao* obterLocacaoPeloCodigo(int codLoc){
	int i;
	Locacao* l = (Locacao*) malloc(sizeof(Locacao));

	if(l == NULL) {
		return NULL;
	}

	for(i = 0; i < qtdLocados; i++) {
		fseek(arquivoLocacao, i * sizeof(Locacao), SEEK_SET);
		fread(l, sizeof(Locacao), 1, arquivoLocacao);
		rewind(arquivoLocacao);
		if(l->codLoc == codLoc) {
		return l;
		}
	}
	return NULL;
}

int ApagarLocacaoPeloCodigo(int codigo){
	FILE *ApagarLoc;
	Locacao l;
	
	
	ApagarLoc = fopen("apagandoLoc.txt", "w+b");
	
	rewind(arquivoLocacao);
	
		if(arquivoLocacao == NULL || ApagarLoc == NULL)
		{
			return 0;
			printf("Erro na abertura do arquivo!");
			system("pause");
		}
		
		else
		{	
			while(fread(&l, sizeof(Locacao), 1, arquivoLocacao) == 1)
			{
				if(codigo != l.codLoc)
				{
					fwrite(&l, sizeof(Locacao), 1, ApagarLoc);
					codigoAtualL--;
					qtdLocados--;
				}
			}
		}
		
		fclose(arquivoLocacao);
		fclose(ApagarLoc);
		remove("LocacaoTXT.txt");
		rename("apagandoLoc.txt", "LocacaoTXT.txt");
		arquivoLocacao = fopen("LocacaoTXT.txt", "r+b");
		
		return 1;
	
}

int VerificaCodigoLocacao(int codLoc){
	Locacao* l = (Locacao*)malloc(sizeof(Locacao));
		if(l == NULL){
		return 0;	
	}
	
	int i;
	for(i=0; i < qtdLocados; i++){
	fseek(arquivoLocacao,sizeof(Locacao) * i, SEEK_SET);
	fread(l, sizeof(Locacao), 1, arquivoLocacao);
	}
	return 0;
}

int VerificaLocacaoGuerreiro(int codG){
	Locacao* l = (Locacao*)malloc(sizeof(Locacao));
		if(l == NULL){
		return 0;	
	}
	
	int i;
	for(i=0; i < qtdLocados; i++){
	fseek(arquivoLocacao,sizeof(Locacao) * i, SEEK_SET);
	fread(l, sizeof(Locacao), 1, arquivoLocacao);
	}
	return 0;
}

int VerificaLocacaoDragao(int codD){
	Locacao* l = (Locacao*)malloc(sizeof(Locacao));
		if(l == NULL){
		return 0;	
	}
	
	int i;
	for(i=0; i < qtdLocados; i++){
	fseek(arquivoLocacao,sizeof(Locacao) * i, SEEK_SET);
	fread(l, sizeof(Locacao), 1, arquivoLocacao);
	}
	return 0;
}

//void AumentarLocacaoArray(Locacao l){
//	MAX_LOCACAO ++;
//	Locacao * lTeste = (Locacao*)realloc(Locacoes, MAX_LOCACAO * sizeof(Locacao));
//	if(lTeste != NULL){
//		Locacoes = lTeste;
//	}
//	else
//	MAX_LOCACAO--;
//}
//
//int DiminuirLocacaoArray(){
//	if(qtdLocados <=(MAX_LOCACAO * 0.4)){
//		Locacao * lTeste = (Locacao*)realloc(Locacoes, (MAX_LOCACAO-1) * sizeof(Locacao));	
//		
//		if(lTeste != NULL)
//			Locacoes = lTeste;
//			MAX_LOCACAO--;
//			return 1;
//		}
//		else{
//			return 0;
//		}
//	}

int AtualizarLocacoes(Locacao l){
	Locacao Lido;
	FILE* Percorrer = fopen("PercorrerLocTXT.txt", "w+b");
	
	rewind(arquivoLocacao);
	while(fread(&Lido, sizeof(Locacao), 1, arquivoLocacao)==1){
//		printf("veio da main o codigo: %d\n", l.codLoc);
//		printf("codigo lido do arquivo: %d\n\n", Lido.codLoc);
//		system("pause");
		if(Lido.codLoc != l.codLoc){
			fwrite(&Lido, sizeof(Locacao), 1, Percorrer);
		}else{
			fwrite(&l, sizeof(Locacao), 1, Percorrer);
//			printf("alterou o arquivo:\n\n");
//			system("pause");
		}
	}
	fclose(arquivoLocacao);
	fclose(Percorrer);
	remove("LocacaoTXT.txt");
	rename("PercorrerLocTXT.txt", "LocacaoTXT.txt");
	
	arquivoLocacao = fopen("LocacaoTXT.txt", "r+b");
	
	return 1;
}

