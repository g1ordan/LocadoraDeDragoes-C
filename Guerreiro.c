#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Guerreiro.h"
#include "Locacao.h"


int MAX_GUERREIRO = 5;
FILE* arquivoGuerreiro;
int qtdGuerreiro = 0;
int codigoAtual = 0;


int inicializarGuerreiros(){
	arquivoGuerreiro = fopen("GuerreiroTXT.txt", "r+b");
	if(arquivoGuerreiro == NULL){
		return 0;
	}
	fseek(arquivoGuerreiro,0, SEEK_END);
	int tamanho = ftell(arquivoGuerreiro);
	qtdGuerreiro = tamanho/sizeof(Guerreiro);
	fseek(arquivoGuerreiro, 0, SEEK_SET);
	int i;
	Guerreiro g;
	for(i = 0; i <qtdGuerreiro; i++){
		fread(&g,sizeof(Guerreiro),1,arquivoGuerreiro);
		if(g.codigoGuerreiro > codigoAtual)
		codigoAtual = g.codigoGuerreiro;
	}
	codigoAtual++;
	printf("codigoatualGuerreiro %d\n", codigoAtual);
	printf("qtdGuerreiro %d\n", qtdGuerreiro);
	
//	---2 LINHAS DE CIMA = DEBUG---
	
	return 1;
}

int encerraGuerreiros(){
	fclose(arquivoGuerreiro);
}


int salvarGuerreiro(Guerreiro g){
		
//	if(qtdGuerreiro == MAX_GUERREIRO){
//		AumentarGuerreiroArray(g);
//	}
//		//vai cadastrar
	g.codigoGuerreiro = codigoAtual++;
//	Guerreiros[qtdGuerreiro] = g;
	fseek(arquivoGuerreiro,0, SEEK_END);
	fwrite(&g,sizeof(Guerreiro),1, arquivoGuerreiro);	
	qtdGuerreiro++;
	return 1;
}	

int QuantidadeGuerreiros(){
	return qtdGuerreiro;
}
	
	
Guerreiro* obterGuerreiroPeloIndice(int indice){
	Guerreiro* g = (Guerreiro*) malloc(sizeof(Guerreiro));
	fseek(arquivoGuerreiro, indice * sizeof(Guerreiro), SEEK_SET);
	fread(g, sizeof(Guerreiro), 1, arquivoGuerreiro);
	rewind(arquivoGuerreiro);
 
//	Guerreiro g;
//		fread(&g,sizeof(Guerreiro),1,arquivoGuerreiro);
//		if(g.codigoGuerreiro > codigoAtual)
//		codigoAtual = g.codigoGuerreiro;
//	}
//	codigoAtual++;
//	fread(indice,sizeof(1),1, arquivoGuerreiro);
//	if(arquivoGuerreiro == NULL){
//	return 0;
//	}
//	Guerreiro* g = (Guerreiro*)malloc(sizeof(Guerreiro));
//	if(g == NULL){
//		return NULL;
//	}
//	*g = Guerreiros[indice];
	return g;
}

Guerreiro* obterGuerreiroPeloCodigo(int codigoGuerreiro){
	
	int i;
	Guerreiro* g = (Guerreiro*) malloc(sizeof(Guerreiro));

	if(g == NULL) {
		return NULL;
	}

	for(i = 0; i < qtdGuerreiro; i++) {
		fseek(arquivoGuerreiro, i * sizeof(Guerreiro), SEEK_SET);
		fread(g, sizeof(Guerreiro), 1, arquivoGuerreiro);
		rewind(arquivoGuerreiro);
		if(g->codigoGuerreiro == codigoGuerreiro) {
			return g;
		}
	}
	return NULL;
}

int ApagarGuerreiroPeloCodigo(int codigo){
	FILE *ApagarGue;
	Guerreiro g;
	
	
	ApagarGue = fopen("apagandoGue.txt", "w+b");
	
	rewind(arquivoGuerreiro);
	
		if(arquivoGuerreiro == NULL || ApagarGue == NULL)
		{
			printf("Erro na abertura do arquivo!");
			system("pause");
		}
		
		else
		{	
			while(fread(&g, sizeof(Guerreiro), 1, arquivoGuerreiro) == 1)
			{
				if(codigo != g.codigoGuerreiro)
				{
					fwrite(&g, sizeof(Guerreiro), 1, ApagarGue);
					codigoAtual--;
					qtdGuerreiro--;
				}
			}
		}
		
		fclose(arquivoGuerreiro);
		fclose(ApagarGue);
		remove("GuerreiroTXT.txt");
		rename("apagandoGue.txt", "GuerreiroTXT.txt");
		arquivoGuerreiro = fopen("GuerreiroTXT.txt", "r+b");
		
	return 1;
}

int VerificarGuerreiroPeloCodigo(int codigoGuerreiro){
	
	Guerreiro* g = (Guerreiro*)malloc(sizeof(Guerreiro));
		if(g == NULL){
		return 0;	
	}
	
	int i;
	for(i=0; i < qtdGuerreiro; i++){
	fseek(arquivoGuerreiro,sizeof(Guerreiro) * i, SEEK_SET);
	fread(g, sizeof(Guerreiro), 1, arquivoGuerreiro);
	}
	
	
//	int i;
//	for(i=0; i < qtdGuerreiro; i++){
//		if(Guerreiros[i].codigoGuerreiro == codigoGuerreiro)
//		return 1;

	return 0;	
}

//void AumentarGuerreiroArray(Guerreiro g){
//	MAX_GUERREIRO ++;
//	Guerreiro * gTeste = (Guerreiro*)realloc(Guerreiros, MAX_GUERREIRO * sizeof(Guerreiro));
//	if(gTeste != NULL){
//		Guerreiros = gTeste;
//	}
//	else
//	MAX_GUERREIRO--;
//}

//int DiminuirGuerreiroArray(){
//	if(qtdGuerreiro <=(MAX_GUERREIRO * 0.4)){
//		Guerreiro * gTeste = (Guerreiro*)realloc(Guerreiros, (MAX_GUERREIRO-1) * sizeof(Guerreiro));	
//		
//		if(gTeste != NULL)
//			Guerreiros = gTeste;
//			MAX_GUERREIRO--; 
//			return 1;
//		}
//		else{
//			return 0;
//		}
//	}
//		
int AtualizarGuerreiros(Guerreiro g){
	Guerreiro Lido;
	FILE* Percorrer = fopen("PercorrerGueTXT.txt", "w+b");
	
	rewind(arquivoGuerreiro);
	while(fread(&Lido, sizeof(Guerreiro), 1, arquivoGuerreiro)==1){
//		printf("veio da main o codigo: %d\n", g.codigoGuerreiro);
//		printf("codigo lido do arquivo: %d\n\n", Lido.codigoGuerreiro);
//		system("pause");
		if(Lido.codigoGuerreiro != g.codigoGuerreiro){
			fwrite(&Lido, sizeof(Guerreiro), 1, Percorrer);
		}else{
			fwrite(&g, sizeof(Guerreiro), 1, Percorrer);
//			printf("alterou o arquivo:\n\n");
//			system("pause");
		}
	}
	fclose(arquivoGuerreiro);
	fclose(Percorrer);
	remove("GuerreiroTXT.txt");
	rename("PercorrerGueTXT.txt", "GuerreiroTXT.txt");
	
	arquivoGuerreiro = fopen("GuerreiroTXT.txt", "r+b");

	return 1;
}



