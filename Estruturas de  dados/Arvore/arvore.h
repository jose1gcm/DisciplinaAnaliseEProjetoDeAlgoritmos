#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct Pessoa{
	char nome[60];
	char telefone[16];
}Elemento;
typedef struct no{
	Elemento info;
	struct no*esq;
	struct no*dir;
}No;
typedef struct arvore{
	No*raiz;
}ArvBinPesq;
//inicializar
void inicializar(No**raiz){
	(*raiz)=NULL;
}
//verificar se esta vazia
int vazia(No**raiz){
	if((*raiz)==NULL){
		return 1;
	}
	return 0;
}
//criar um no
No*criarNo(){
	No*novo=(No*)malloc(sizeof(No));
	return novo;
}
//criar um elemento
Elemento criarElemento(char nome[],char telefone[]){
	Elemento elemento;
	strcpy(elemento.nome,nome);
	strcpy(elemento.telefone,telefone);
	return elemento;
}
//comparar elemento
int compararElemento(Elemento e1,Elemento e2){
	return strcmp(e1.nome,e2.nome);
}
//inserir
int inserir(No**raiz,Elemento novoElemento){
	No*aux=(*raiz);
	No*anteAux=NULL;
	No*novoNo;
	novoNo=criarNo();
	if(novoNo==NULL){
		printf("\nERRO.Memoria nao alocada");
		return 0;
	}
	novoNo->info=novoElemento;
	novoNo->esq=NULL;
	novoNo->dir=NULL;
	if(vazia(raiz)){
		(*raiz)=novoNo;
		return 1;
	}
	while(aux!=NULL){
		anteAux=aux;
		if(compararElemento(novoElemento,aux->info)<0){
			aux=aux->esq;
		}else{
			aux=aux->dir;
		}
	}
	if(compararElemento(novoElemento,anteAux->info)<0){
		(anteAux)->esq=novoNo;
	}else{
		(anteAux)->dir=novoNo;
	}
	return 1;
}

//inserir recursivo
int inserirRecursivo(No**raiz,Elemento novo){
	No*novoNo=criarNo();
	
	if(novoNo==NULL){
		printf("Erro.Memoria cheia\n");
		return 0;
	}
	
	novoNo->info=novo;
	novoNo->esq=NULL;
	novoNo->dir=NULL;
	
	if(vazia((raiz))){//if(vazia(&(*raiz))){
		(*raiz)=novoNo;
		return 1;
	}
	
	if(((*raiz)->esq==NULL)&&((*raiz)->dir==NULL)){
		if(compararElemento(novo,(*raiz)->info)<0){
			(*raiz)->esq=novoNo;
			return 1;
		}else{
			(*raiz)->dir=novoNo;
			return 1;
		}
	}
	
	if(compararElemento(novo,(*raiz)->info)<0){
		return inserirRecursivo(&(*raiz)->esq,novo);
	}else{
		return inserirRecursivo(&(*raiz)->dir,novo);
	}
}
//pesquisar
No*pesquisar(No*raiz,Elemento pesquisado){
	int comparacao;
	if(raiz==NULL){
		return NULL;
	}
	comparacao=compararElemento(pesquisado,raiz->info);
	if(comparacao==0){
		return raiz;
	}else{
		if(comparacao<0){
			return pesquisar(raiz->esq,pesquisado);
		}else{
			return pesquisar(raiz->dir,pesquisado);
		}
	}
}
void visita(Elemento novo){
	printf("nome:%s  telefone:%s\n",novo.nome,novo.telefone);
}
//pre_ordem
void pre_ordem(No*raiz){
	if(raiz!=NULL){
		visita(raiz->info);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}
//em_ordem
void em_ordem(No*raiz){
	if(raiz!=NULL){
		em_ordem(raiz->esq);
		visita(raiz->info);
		em_ordem(raiz->dir);
	}	
}
//pós_ordem
void pos_ordem(No*raiz){
	if(raiz!=NULL){
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		visita(raiz->info);
	}
}
/*
//remover um no
Elemento remover(No**raiz,Elemento pesquisado){
	No*novaRaiz;
	No*anteNovaRaiz;
	Elemento removido=criarElemento("","");
	if(vazia(raiz)){
		return removido;
	}
	if(compararElemento((*raiz)->info,pesquisado)==0){
		removido=(*raiz)->info;
		if((*raiz)->esq==NULL&&(*raiz)->dir==NULL){
			free((*raiz));
			return removido;
		}
		if((*raiz)->esq==NULL){
			novaRaiz=(*raiz)->dir;
			free((*raiz));
			(*raiz)=novaRaiz;
			return removido;
		}
		if((*raiz)->dir==NULL){
			novaRaiz=(*raiz)->esq;
			free((*raiz));
			(*raiz)=novaRaiz;
			return removido;
		}
		if(((*raiz)->esq!=NULL)&&((*raiz)->dir)!=NULL){
			novaRaiz=(*raiz)->dir;
			anteNovaRaiz=NULL;
			while(novaRaiz->esq!=NULL){
				anteNovaRaiz->esq=novaRaiz;
				novaRaiz=novaRaiz->esq;
			}
			if(anteNovaRaiz!=NULL){
				anteNovaRaiz->esq=novaRaiz->dir;
				novaRaiz->dir=(*raiz)->dir;
			}
			novaRaiz->esq=(*raiz)->esq;
			free((*raiz));
			(*raiz)=novaRaiz;
			return removido;
		}
	}
	if(compararElemento(pesquisado,(*raiz)->info)<0){
		return remover(&(*raiz)->esq,pesquisado);
	}else{
		return remover(&(*raiz)->esq,pesquisado);
	}
}
*/
int vis(int novo){
	novo=novo+1;
	return novo;
}
int tam(No*raiz,int tamanho){
	
	if(raiz!=NULL){
		em_ordem(raiz->esq);
		visita(raiz->info);
		em_ordem(raiz->dir);
	}
	return tamanho;
}
int numMaxNosArvBin(int altura){
	int num;
	num=(pow(2,altura))-1;
	return num;
}
int numMaxFolhasArvBin(int altura){
	int num;
	num=(pow(2,altura-1));
	return num;
}
int numNosArvBin(No*raiz,int novo){
	if(raiz!=NULL){
		numNosArvBin(raiz->esq,novo);
		novo=novo+1;
		numNosArvBin(raiz->dir,novo);
	}
	return novo;
}
int alt(No*raiz){
	int he=0;
	int hd=0;
	if(vazia(&raiz)){
		return 0;
	}else{
		 he=alt(raiz->esq);
		 hd=alt(raiz->dir);
		if(he<hd){
			return hd+1;
		}else{
			return he+1;
		}
	}
}



























