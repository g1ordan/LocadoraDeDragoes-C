#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Dragao.h"
#include "Locacao.h"
#include "Elemento.h"


int MAX_DRAGAO = 5;
FILE* arquivoDragao;
int qtdDragao = 0;
int codigoAtuald = 0;


int inicializarDragoes(){
	arquivoDragao = fopen("DragaoTXT.txt", "r+b");
	if(arquivoDragao == NULL){
		return 0;
	}
	fseek(arquivoDragao,0, SEEK_END);
	int tamanho = ftell(arquivoDragao);
	qtdDragao = tamanho/sizeof(Dragao);
	fseek(arquivoDragao, 0, SEEK_SET);
	int i;
	Dragao d;
	for(i = 0; i <qtdDragao; i++){
		fread(&d,sizeof(Dragao),1,arquivoDragao);
		if(d.codigoDragao > codigoAtuald)
		codigoAtuald = d.codigoDragao;
	}
	codigoAtuald++;
	printf("codigoatualDragao %d\n", codigoAtuald);
	printf("qtdDragao %d\n", qtdDragao);
	
//	---2 LINHAS DE CIMA = DEBUG---
	
	return 1;	
}

int encerraDragoes(){
	fclose(arquivoDragao);
}

int salvarDragoes(Dragao d){
	d.codigoDragao = codigoAtuald++;
	fseek(arquivoDragao,0, SEEK_END);
	fwrite(&d,sizeof(Dragao),1, arquivoDragao);	
	qtdDragao++;
	
	return 1;			
}

int QuantidadeDragoes(){
	return qtdDragao;
}
	
Dragao* obterDragaoPeloIndice(int indice){
	
	Dragao* d = (Dragao*) malloc(sizeof(Dragao));
	fseek(arquivoDragao, indice * sizeof(Dragao), SEEK_SET);
	fread(d, sizeof(Dragao), 1, arquivoDragao);
	rewind(arquivoDragao);
	
	return d;
}

Dragao* obterDragaoPeloCodigo(int codigoDragao){
	int i;
	Dragao* d = (Dragao*)malloc(sizeof(Dragao));

	if(d == NULL) {
		return NULL;
	}

	for(i = 0; i < qtdDragao; i++) {
		fseek(arquivoDragao, i * sizeof(Dragao), SEEK_SET);
		fread(d, sizeof(Dragao), 1, arquivoDragao);
		rewind(arquivoDragao);
		if(d->codigoDragao == codigoDragao) {
			return d;
		}
	}
	return NULL;
}

int ApagarDragaoPeloCodigo(int codigo){
	FILE *ApagarDra;
	Dragao d;
	
	
	ApagarDra = fopen("apagandoDra.txt", "w+b");
	
	rewind(arquivoDragao);
	
		if(arquivoDragao == NULL || ApagarDra == NULL)
		{
			printf("Erro na abertura do arquivo!");
			system("pause");
		}
		
		else
		{	
			while(fread(&d, sizeof(Dragao), 1, arquivoDragao) == 1)
			{
				if(codigo != d.codigoDragao)
				{
					fwrite(&d, sizeof(Dragao), 1, ApagarDra);
					codigoAtuald--;
					qtdDragao--;
				}
			}
		}
		
		fclose(arquivoDragao);
		fclose(ApagarDra);
		remove("DragaoTXT.txt");
		rename("apagandoDra.txt", "DragaoTXT.txt");
		arquivoDragao = fopen("DragaoTXT.txt", "r+b");
		
	return 1;
}

int VerificarDragaoPeloCodigoEle(int codElemento){
	Dragao* d = (Dragao*)malloc(sizeof(Dragao));
		if(d == NULL){
		return 0;	
	}
	
	int i;
	for(i=0; i < qtdDragao; i++){
	fseek(arquivoDragao,sizeof(Dragao) * i, SEEK_SET);
	fread(d, sizeof(Dragao), 1, arquivoDragao);
	}
	return 0;	
}

int VerificarDragaoPeloCodigo(int codigoDragao){
	Dragao* d = (Dragao*)malloc(sizeof(Dragao));
		if(d == NULL){
		return 0;	
	}
	
	int i;
	for(i=0; i < qtdDragao; i++){
	fseek(arquivoDragao,sizeof(Dragao) * i, SEEK_SET);
	fread(d, sizeof(Dragao), 1, arquivoDragao);
	}
	return 0;	
}

//void AumentarDragaoArray(Dragao d){
//	MAX_DRAGAO ++;
//	Dragao * dTeste = (Dragao*)realloc(Dragoes, MAX_DRAGAO * sizeof(Dragao));
//	if(dTeste != NULL){
//		Dragoes = dTeste;
//	}
//	else
//	MAX_DRAGAO--;
//}

//int DiminuirDragaoArray(){
//	if(qtdDragao <=(MAX_DRAGAO * 0.4)){
//		Dragao * dTeste = (Dragao*)realloc(Dragoes, (MAX_DRAGAO-1) * sizeof(Dragao));	
//		
//		if(dTeste != NULL)
//			Dragoes = dTeste;
//			MAX_DRAGAO--;
//			return 1;
//		}
//		else{
//			return 0;
//		}
//	}

int AtualizarDragoes(Dragao d){
	Dragao Lido;
	FILE* Percorrer = fopen("PercorrerDraTXT.txt", "w+b");
	
	rewind(arquivoDragao);
	while(fread(&Lido, sizeof(Dragao), 1, arquivoDragao)==1){
//		printf("veio da main o codigo: %d\n", l.codLoc);
//		printf("codigo lido do arquivo: %d\n\n", Lido.codLoc);
//		system("pause");
		if(Lido.codigoDragao != d.codigoDragao){
			fwrite(&Lido, sizeof(Dragao), 1, Percorrer);
		}else{
			fwrite(&d, sizeof(Dragao), 1, Percorrer);
//			printf("alterou o arquivo:\n\n");
//			system("pause");
		}
	}
	fclose(arquivoDragao);
	fclose(Percorrer);
	remove("DragaoTXT.txt");
	rename("PercorrerDraTXT.txt", "DragaoTXT.txt");
	
	arquivoDragao = fopen("DragaoTXT.txt", "r+b");
	
	return 1;
}		

void decrementarDragao(int codigoDragao){
//	int i;
//	for(i = 0; i < qtdDragao; i++){
//		if(Dragoes[i].codigoDragao == codigoDragao){
//			Dragoes[i].unidadesEmEstoque--;
//		}
//	}
}	



