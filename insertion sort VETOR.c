//INSERTION-SORT com VETOR
#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,j,n,qtde,chave,escolha;
	do{
		printf("Digite o tamanho da sequencia:");
		scanf("%d",&qtde);
		qtde=qtde+1;
		int A[qtde];
		printf("\n____________________MENU_______________________\n");
		printf("1-Adicionar uma sequencia e ordenar com o INSERTION-SORT\n");
		printf("2-sair\n");
		printf("Digite uma opcao do menu:");
		scanf("%d",&escolha);
		//system("cls");
		if(escolha==1){
			printf("Digite uma sequencia de numeros:\n");
			for(i=1;i<qtde;i++){
				printf("Digite um numero:");
				scanf("%d",&A[i]);
			}
			//MOSTRA A SEQUENCIA DESORDENADA
			printf("\nA sequencia desordenada e:");
			for(i=1;i<qtde;i++){
				printf("%d ",A[i]);
			}
			//ORDENANDO A SEQUENCIA DE NUMEROS
			for(j=2;j<=qtde;j++){
				chave=A[j];
				i=j-1;
				while((i>0)&&(A[i]>chave)){
					A[i+1]=A[i];
					i--;
				}
				A[i+1]=chave;
			}
			//MOSTRA A SEQUENCIA ORDENADA
			printf("\nA sequencia    ordenada e:");
			for(i=1;i<qtde;i++){
				printf("%d ",A[i]);
			}
		}else{
			printf("DIGITE UM NUMERO DO MENU\n");
		}
	}while(escolha!=2);

	system("pause");
	return 0;
}
