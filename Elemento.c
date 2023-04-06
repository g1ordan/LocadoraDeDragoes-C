#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Elemento.h"
#include "Dragao.h"


int MAX_ELEMENTO = 5;
FILE* arquivoElemento;
int qtdElemento = 0;
int codigoAtuale = 0;


int inicializarElementos(){
	arquivoElemento = fopen("ElementoTXT.txt", "r+b");
	if(arquivoElemento == NULL){
		return 0;
	}
	fseek(arquivoElemento,0, SEEK_END);
	int tamanho = ftell(arquivoElemento);
	qtdElemento = tamanho/sizeof(Elemento);
	fseek(arquivoElemento, 0, SEEK_SET);
	int i;
	Elemento e;
	for(i = 0; i <qtdElemento; i++){
		fread(&e,sizeof(Elemento),1,arquivoElemento);
		if(e.codigoEle > codigoAtuale)
		codigoAtuale = e.codigoEle;
	}
	codigoAtuale++;
	printf("codigoatualElemento %d\n", codigoAtuale);
	printf("qtdElemento %d\n", qtdElemento);
	return 1;
}

int encerraElemento(){
	fclose(arquivoElemento);
}

int salvarElementos(Elemento e){
	e.codigoEle = codigoAtuale++;
	fseek(arquivoElemento,0, SEEK_END);
	fwrite(&e,sizeof(Elemento),1, arquivoElemento);	
	qtdElemento++;
	return 1;	
}

int QuantidadeElementos(){
	return qtdElemento;
}
	
Elemento* obterElementoPeloIndice(int indice){
	Elemento* e = (Elemento*) malloc(sizeof(Elemento));
	fseek(arquivoElemento, indice * sizeof(Elemento), SEEK_SET);
	fread(e, sizeof(Elemento), 1, arquivoElemento);
	rewind(arquivoElemento);
	
	return e;
}

Elemento* obterElementoPeloCodigo(int codigoEle){
	int i;
	Elemento* e = (Elemento*) malloc(sizeof(Elemento));

	if(e == NULL) {
		return NULL;
	}

	for(i = 0; i < qtdElemento; i++) {
		fseek(arquivoElemento, i * sizeof(Elemento), SEEK_SET);
		fread(e, sizeof(Elemento), 1, arquivoElemento);
		rewind(arquivoElemento);
		if(e->codigoEle == codigoEle) {
			return e;
		}
	}
	return NULL;
}

int ApagarElementoPeloCodigo(int codigo){
	FILE *ApagarEle;
	Elemento e;
	
	
	ApagarEle = fopen("apagandoEle.txt", "w+b");
	
	rewind(arquivoElemento);
	
		if(arquivoElemento == NULL || ApagarEle == NULL)
		{
			return 0;
			printf("Erro na abertura do arquivo!");
			system("pause");
		}
		
		else
		{	
			while(fread(&e, sizeof(Elemento), 1, arquivoElemento) == 1)
			{
				if(codigo != e.codigoEle)
				{
					fwrite(&e, sizeof(Elemento), 1, ApagarEle);
					codigoAtuale--;
					qtdElemento--;
				}
			}
		}
		
		fclose(arquivoElemento);
		fclose(ApagarEle);
		remove("ElementoTXT.txt");
		rename("apagandoEle.txt", "ElementoTXT.txt");
		arquivoElemento = fopen("ElementoTXT.txt", "r+b");
		
	return 1;
}

int VerificaCodigoElemento(int codigoEle){
	Elemento* e = (Elemento*)malloc(sizeof(Elemento));
		if(e == NULL){
		return 0;	
	}
	
	int i;
	for(i=0; i < qtdElemento; i++){
	fseek(arquivoElemento,sizeof(Elemento) * i, SEEK_SET);
	fread(e, sizeof(Elemento), 1, arquivoElemento);
	}
	return 0;
}

//void AumentarElementoArray(Elemento e){
//	MAX_ELEMENTO ++;
//	Elemento * eTeste = (Elemento*)realloc(Elementos, MAX_ELEMENTO * sizeof(Elemento));
//	if(eTeste != NULL){
//		Elementos = eTeste;
//	}
//	else
//	MAX_ELEMENTO--;
//}
//
//int DiminuirElementoArray(){
//	if(qtdElemento <=(MAX_ELEMENTO * 0.4)){
//		Elemento * eTeste = (Elemento*)realloc(Elementos, (MAX_ELEMENTO-1) * sizeof(Elemento));	
//		
//		if(eTeste != NULL)
//			Elementos = eTeste;
//			MAX_ELEMENTO--;
//			return 1;
//		}
//		else{
//			return 0;
//		}
//	}
		
int AtualizarElementos(Elemento e){
	Elemento Lido;
	FILE* Percorrer = fopen("PercorrerEleTXT.txt", "w+b");
	
	rewind(arquivoElemento);
	while(fread(&Lido, sizeof(Elemento), 1, arquivoElemento)==1){
//		printf("veio da main o codigo: %d\n", l.codLoc);
//		printf("codigo lido do arquivo: %d\n\n", Lido.codLoc);
//		system("pause");
		if(Lido.codigoEle != e.codigoEle){
			fwrite(&Lido, sizeof(Elemento), 1, Percorrer);
		}else{
			fwrite(&e, sizeof(Elemento), 1, Percorrer);
//			printf("alterou o arquivo:\n\n");
//			system("pause");
		}
	}
	fclose(arquivoElemento);
	fclose(Percorrer);
	remove("ElementoTXT.txt");
	rename("PercorrerEleTXT.txt", "ElementoTXT.txt");
	
	arquivoElemento = fopen("ElementoTXT.txt", "r+b");
	
	return 1;
}


