//nome:José Geraldo Campos Moraes matrícula:2705
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "agendaTelefonica.h"
//=====Função Main()================================================
int main(){
	int opcao,posicao;
	Elemento novo;
	Elemento elementoRetornado;
	Celula*ptrPilha;

	inicializar(&ptrPilha);
	vazia(&ptrPilha);

	do{
		printf("\n_____________________MENU______________________");
		printf("\n 0-SAIR");
		printf("\n 1-Empilhar");
		printf("\n 2-Desempilhar");
		printf("\n 3-Imprimir o elemento que esta no topo");
		printf("\n 4-Imprimir a pilha completa(impressao classica)");
		printf("\ndigite uma opcao do menu:");
		scanf("%d",&opcao);
		if(opcao==0){
			continue;
		}
		fflush(stdin);
		system("cls");
		switch(opcao){
			case 1://inserir o elemento no topo da pilha
				printf("\ndigite o nome do elemento:");
				scanf("%s",novo.nome);
				printf("digite o numero:");
				scanf("%s",novo.numero);
				empilhar(&ptrPilha,novo);
			break;

			case 2://remover o elemento no topo da pilha
				elementoRetornado=desempilhar(&ptrPilha);
				if(strcmp(elementoRetornado.nome,"")==0){
					break;
				}
					printf("\nelemento removido foi:");
					printf("\nnome:%s",elementoRetornado.nome);
					printf("\nnumero:%s",elementoRetornado.numero);
			break;

			case 3:
				imprimirTopo(&ptrPilha);
			break;

			case 4:
				imprimir(&ptrPilha);
			break;

			default:
				printf("\n!!!!!ENTRADA INVALIDA!!!!!");
			break;
		}
	}while(opcao!=0);



		
	
	system("pause");
	return 0;
}
