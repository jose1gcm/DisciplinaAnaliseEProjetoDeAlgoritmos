//nome:José Geraldos
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_TAM 5
typedef struct agenda{
	char nome[40];
	char numero[15];
}Elemento;
typedef struct estrutura{
	Elemento elemento[MAX_TAM];
	int ultimo;
	int cabecalho;
}Fila;
//inicializar
void inicializar(Fila*fila){
	fila->ultimo=0;
	fila->cabecalho=fila->ultimo;
}
//verificar se está vazia
int vazia(Fila*fila){
	return (fila->ultimo==fila->cabecalho);
}
//verificar se esta cheio
int cheia(Fila*fila){
	int proxi=(fila->ultimo+1)%MAX_TAM;
	return (proxi==fila->cabecalho);
}
//inserir um elemento na fila
int empilhar(Fila*fila,Elemento elemento){
	int proxi;
	if(cheia(fila)){
		printf("\nERRO.fila cheia");
		return 0;
	}
	proxi=(fila->ultimo+1)%MAX_TAM;
	fila->elemento[proxi]=elemento;
	fila->ultimo=proxi;
	return 1;
}
//remover um elemento na fila
Elemento desempilhar(Fila*fila){
	Elemento vazio;
	strcpy(vazio.nome,"");
	strcpy(vazio.numero,"");
	if(vazia(fila)){
		printf("\nERRO.fila vazia");
		return vazio;
	}
	fila->cabecalho=(fila->cabecalho+1)%MAX_TAM;
	return fila->elemento[fila->cabecalho];
}
//imprime o Elemento 
void imprimirElemento(Elemento elemento){
	printf("\nnome:%s-numero:%s",elemento.nome,elemento.numero);
}
//imprimir a fila
void imprimir(Fila*fila){
	Elemento troca;
	Fila fila2;
	inicializar(&fila2);
	if(vazia(fila)){
		printf("ERRO.fila vazia");
	}else{
		while(!vazia(fila)){
			troca=desempilhar(fila);
			imprimirElemento(troca);
			empilhar(&fila2,troca);
		}
		while(!vazia(&fila2)){
			empilhar(fila,desempilhar(&fila2));
		}
	}
}
