#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arvore.h"

int main(){
	int opcao,posicao,tamanho=0,altura=0;
	Elemento elemento;
	Elemento novo;
	Elemento elementoRetornado;
	ArvBinPesq arvore;
	ArvBinPesq pesquisado;
	inicializar(&arvore.raiz);
	

	do{
		printf("\n_____________________MENU______________________");
		printf("\n 0-SAIR");
		printf("\n 1-inserir um elemento na arvore");
		printf("\n 2-remover um elemento na arvore");
		printf("\n 3-Imprimir usando o metodo pre-ordem");
		printf("\n 4-Imprimir usando o metodo  em-ordem");
		printf("\n 5-Imprimir usando o metodo pos_ordem");
		printf("\n 6-Ver a altura da arvore");
		printf("\n 7-Ver  o  grau da arvore");
		printf("\n 8-Ver quantos nos tem a arvore");
		printf("\n 9-Ver quantos nos esta arvore pode ter");
		printf("\n10-ver quantos nos folhas  esta arvore pode ter");
		printf("\n11-pesquisar um elemento");
		printf("\ndigite uma opcao do menu:");
		scanf("%d",&opcao);
		if(opcao==0){
			continue;
		}
		fflush(stdin);
		system("cls");
		switch(opcao){
			case 1:
				printf("\ndigite o nome do elemento:");
				scanf("%s",novo.nome);
				printf("digite o numero:");
				scanf("%s",novo.telefone);
				//inserir(&arvore.raiz,novo);
				inserirRecursivo(&arvore.raiz,novo);
			break;

			case 2:
			/*	printf("digite o elemento que sera removido");
				scanf("%s",&elemento.nome);
				elementoRetornado=remover(&arvore.raiz,elemento.nome);
				if(strcmp(elementoRetornado.nome,"")==0){
					break;
				}
					printf("\nelemento removido foi:");
					printf("\nnome:%s",elementoRetornado.nome);
					printf("\nnumero:%s",elementoRetornado.numero);*/
			break;

			case 3:
				pre_ordem(arvore.raiz);
			break;
			case 4:
				em_ordem(arvore.raiz);
			break;
			case 5:
				pos_ordem(arvore.raiz);
			break;
            case 6:
            	tamanho=alt(arvore.raiz);
            	printf("a altura da arvore e:%d",tamanho);
            break;
            
            case 7:
            	
            break;
            
            case 8:
            	tamanho=numNosArvBin(arvore.raiz,altura);
            	printf("esta arvore tem:%d nos",tamanho);
            break;
            
            case 9:
            	altura=alt(arvore.raiz);
            	tamanho=numMaxNosArvBin(altura);
            	printf("o Numero Maximo de nos que esta arvore pode ter e:%d nos",tamanho);
            break;
            
            case 10:
            	altura=alt(arvore.raiz);
            	tamanho=numMaxFolhasArvBin(altura);
            	printf("o Numero Maximo de nos folhas que esta arvore pode ter e:%d nos folhas",tamanho);
            break;
            
            case 11:
            	printf("digite o nome do elemento que quer pesquisar:");
            	scanf("%s",elemento.nome);
            	pesquisado.raiz=pesquisar(arvore.raiz,elemento);
            	if(pesquisado.raiz==NULL){
            		printf("Elemento nao encontrado");
            	}else{
    				printf("\nElemento pesquisado :");
    				visita(pesquisado.raiz->info);
    		    }
            break;
			default:
				printf("\n!!!!!ENTRADA INVALIDA!!!!!");
			break;
		}
	}while(opcao!=0);

}
