//nome:José Geraldo
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "agendaTelefonicaestatica.h"
//=====Função Main()================================================
int main(){
	Fila fila;
	Elemento novo;
	Elemento elementoRetornado;
	int opcao;
	inicializar(&fila);

	do{
		printf("\n_____________________MENU______________________");
		printf("\n 0-SAIR");
		printf("\n 1-Empilhar");
		printf("\n 2-Desempilhar");
		printf("\n 3-Imprimir a fila completa(impressao classica)");
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
				scanf("%s",novo.numero);
				empilhar(&fila,novo);
			break;

			case 2:
				elementoRetornado=desempilhar(&fila);
				imprimirElemento(elementoRetornado);
			break;

			case 3:
				imprimir(&fila);
			break;

			default:
				printf("\n!!!!!ENTRADA INVALIDA!!!!!");
			break;
		}
	}while(opcao!=0);



		
	
	system("pause");
	return 0;
}
