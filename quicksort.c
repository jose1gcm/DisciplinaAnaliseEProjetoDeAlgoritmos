#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void swap(int a[],int i,int j){
	int t;
	t=a[i];
	a[i]=a[j];
	a[j]=t;
}

int particiona(int a[],int p,int r){
	int pivot,i,j,t;
	pivot=a[p];
	i=p;
	j=r+1;
	while(1){
		do{
			i++;
		}while(a[i]<=pivot&&i<=r);
		do{
			j--;
		}while(a[j]>pivot);
		if(i>=j){
			break;
		}
		swap(a,i,j);
		//t=a[i];
		//a[i]=a[j];
		//a[j]=t;
	}
	swap(a,p,j);
	//t=a[p];
	//a[p]=a[j];
	//a[j]=t;
	return j;	
}


int particiona2(int a[],int p, int r){//ESTA OCORRENDO ERRO NESTA FUNÇÃO
	int j;
	int x=a[r];
	int i=p-1;
	for(j==p;j<(r-1);j++){
	    do{
			if(a[j]<=x){
				i=i+1;
			    //a[i]=a[j];
			    swap(a,i,j);
			}
			//a[i]=a[j];
		}while(1);
		//a[r]=a[i+1];
		//swap(a,r,i+1);
	}
	swap(a,r,i+1);
	return i+1;
}
void quickSort(int a[],int p,int r){
	int q;
	if(p<r){
		//divide and conquer
		q=particiona(a,p,r);
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
	}
}


void salvar(char escolha2[],int qtde,int A[],int verifica,double tempogasto){
	int a,i,erro;
	char num[10];
	char arquivo[100];
	FILE*pFile;
	strcpy(arquivo,"");
	printf("\n...SALVAR PROGRESSO...\n");
	
	
	if(verifica==1){
		if(strcmp(escolha2,"r")==0){
			strcat(arquivo,"entrada random ");
		}
		if(strcmp(escolha2,"c")==0){
			strcat(arquivo,"entrada crescente ");
		}
		if(strcmp(escolha2,"d")==0){
			strcat(arquivo,"entrada decrescente ");
		}
	}else{
		if(verifica==2){
			if(strcmp(escolha2,"r")==0){
				strcat(arquivo,"saida random ");
			}
			if(strcmp(escolha2,"c")==0){
				strcat(arquivo,"saida crescente ");
			}
			if(strcmp(escolha2,"d")==0){
				strcat(arquivo,"saida decrescente ");
			}
		}else{
			if(verifica==3){
				if(strcmp(escolha2,"r")==0){
			 		strcat(arquivo,"tempo random ");
			    }
				if(strcmp(escolha2,"c")==0){
					strcat(arquivo,"tempo crescente ");
				}
				if(strcmp(escolha2,"d")==0){
					strcat(arquivo,"tempo decrescente ");
				}
			}
		}
		
	}
	
	if(qtde==10){
		strcat(arquivo,"10");
	}else{
		if(qtde==100){
			strcat(arquivo,"100");
		}else{
			if(qtde==1000){
				strcat(arquivo,"1000");
			}else{
				if(qtde==10000){
					strcat(arquivo,"10000");
				}else{
					if(qtde==100000){
						strcat(arquivo,"100000");
					}
				}
			}
		}
	}
	//	scanf("%d",&a);
	strcat(arquivo,".txt");
	pFile=fopen(arquivo,"w");
	printf("%s\n\n",arquivo);

	if(pFile!=NULL){
		fprintf(pFile,"%d\n",qtde);
		if(verifica==3){
			fprintf(pFile,"%lf\n",tempogasto);
		}else{
			for(i=0;i<qtde;i++){
				fprintf(pFile,"%d\n",A[i]);
			}
		}
		erro=fclose(pFile);
		if(erro!=0){
			printf("Erro no fechamento do arquivo.\n");
		}
		printf("...PROGRESSO  SALVO...\n");
	}else{
		printf("Erro na abertura do arquivo\n");
		
	}	
	fclose(pFile);	
}



int main(){
	clock_t t0,tf;
	double tempogasto;
	
	int i,opcoes,qtde,verifica;
	int escolha,n,a,erro;
	char escolha2[20];
	char arquivo[100],num[10];
	FILE*pFile;
	srand((unsigned)time(NULL));

	printf("\n____________________MENU_______________________\n");
	printf("1-Quick Sort particiona 1\n");
	printf("2-Quick Sort particiona 2\n");
	printf("3-Quick sort particiona 3\n");
	printf("4-Sair\n");
	printf("Digite uma opcao do menu:");
	scanf("%d",&escolha);
	system("cls");
	do{
		printf("\nQuick Sort em vetor\n");
		printf("r -para numero randomicos\n");
		printf("c -para numero crescente\n");
		printf("d -para numero decrescente\n");
		printf("Digite uma opcao do menu:");
		scanf("%s",&escolha2);
		if(strcmp(escolha2,"4")==0){
			break;
	    }
		for(opcoes=0;opcoes<5;opcoes++){
			if(opcoes==0){
				qtde=10;
			}else{
				if(opcoes==1){
					qtde=100;
				}else{
					if(opcoes==2){
						qtde=1000;
					}else{
						if(opcoes==3){
							qtde=10000;
						}else{
							if(opcoes==4){
								qtde=100000;
							}else{
								if(opcoes==5){
									qtde=1000000;
								}
							}
						}
					}
				}
			}
			int A[qtde];
			if(strcmp(escolha2,"r")==0){//ENTRA SE ESCOLHER NÚMERO RANDÔMICO
				for(i=0;i<qtde;i++){//vai gerar os números randômicos 
					n=1+(rand()%100000);	
					A[i]=n;
				}
			}
			
			if(strcmp(escolha2,"c")==0){//ENTRA SE ESCOLHER NÚMERO CRESCENTE
				for(i=0;i<qtde;i++){//vai gerar números crescente
					A[i]=i+1;
				}
			}
			
			if(strcmp(escolha2,"d")==0){//ENTRA SE ESCOLHER NÚMERO DECRESCENTE
				for(i=0;i<qtde;i++){//vai gerar números decrescente
					n=qtde-i;
					A[i]=n;
				}
			}
			
			t0=clock();
			verifica=1;
			salvar(escolha2,qtde,A,verifica,tempogasto);
			
			
			
			printf("\n\nDesordenada:");
			for(i=0;i<qtde;i++){//imprime a sequencia desordenada
				printf("%d  ",A[i]);
			}
			
			quickSort(A,0,qtde-1);//chama a funçao quick sort
			tf=clock();
			tempogasto=((int)(tf-t0))/CLOCKS_PER_SEC;
			verifica=2;
			salvar(escolha2,qtde,A,verifica,tempogasto);
			
			
			printf("\n\nOrdenada:");
			for(i=0;i<qtde;i++){
				printf("%d  ",A[i]);
			}
			
			
			verifica=3;
			salvar(escolha2,qtde,A,verifica,tempogasto);
		}
	}while((strcmp(escolha2,"4")==0));
	
	system("pause");
	return 0;
}




