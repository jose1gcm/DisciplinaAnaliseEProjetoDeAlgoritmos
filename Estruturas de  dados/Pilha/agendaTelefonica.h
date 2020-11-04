//nome:José Geraldo Campos Moraes matrícula:2705
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct agenda{
	char nome[40];
	char numero[15];
}Elemento;
typedef struct celula{
	Elemento info;
	struct celula*prox;
}Celula;
//inicializar
void inicializar(Celula**pilha){
	(*pilha)=NULL;
}
//verificar se a lista está vazia
int vazia(Celula**pilha){
	if(*pilha==NULL){
		return 1;
	}else{
		return 0;
	}
}
//criar celula
Celula*criarCelula(){
	return(Celula*)malloc(sizeof(Celula));
}
//comparar elemento
int compararElemento(Elemento e1,Elemento e2){
	return strcmp(e1.nome,e2.nome);
}
//criar elemento
Elemento criarElemento(char nome[],char numero[]){
	Elemento elemento;
	strcpy(elemento.nome,nome);
	strcpy(elemento.numero,numero);
	return elemento;
}
//inserir um elemento no inicio da lista
int empilhar(Celula**pilha,Elemento novo){
	Celula*novaCelula;
	novaCelula=criarCelula();
	if(novaCelula==NULL){
		printf("\nERRO.memoria cheia");
		return 0;
	}
	novaCelula->info=novo;
	novaCelula->prox=(*pilha);
	(*pilha)=novaCelula;
	return 1;
}
//remover um elemento no inicio da lista
Elemento desempilhar(Celula**pilha){
	Celula*aux;
	Elemento vazio;
	strcpy(vazio.nome,"");
	strcpy(vazio.numero,"");
	if(vazia(pilha)){
		printf("\nERRO.lista vazia");
		return vazio;
	}
	aux=(*pilha)->prox;
	vazio=(*pilha)->info;
	free((*pilha));
	(*pilha)=aux;
	return vazio;
}
//imprime o Elemento 
void imprimirElemento(Elemento novo){
	printf("\nnome:%s-numero:%s",novo.nome,novo.numero);
}

//imprimir a lista
void imprimir(Celula**pilha){
	Elemento troca;
	Celula*pilha2;
	inicializar(&pilha2);
	if(vazia(pilha)){
		printf("ERRO.pilha vazia");
		return;
	}
	while(!vazia(pilha)){
		troca=desempilhar(pilha);
		empilhar(&pilha2,troca);
	}
	while(!vazia(&pilha2)){
		troca=desempilhar(&pilha2);
		imprimirElemento(troca);
		empilhar(pilha,troca);
	}	
}


//imprime o elemento no topo da pilha
void imprimirTopo(Celula**pilha){
	Celula*aux;
	if(vazia(pilha)){
		printf("nao temos elementos");
		return;
	}
	aux=(*pilha);
	printf("\nnome:%s-numero:%s",aux->info.nome,aux->info.numero);
}
