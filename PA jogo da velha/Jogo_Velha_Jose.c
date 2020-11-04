
#include <stdio.h>
#include <stdlib.h>

int vez;

typedef struct sjogada{
    int l;
    int c;
    int ponto;
}jog;


void disponivel(int*array){
	int indice=0;
	for(indice=0;indice<9;indice++){
		array[indice]=indice;
	}
}
int* diminuir_disponivel(int* array,int lin, int col){
	int l=0;
	int c=0;
	int i=0;
	for(l=0;l<3;l++){
		for(c=0;c<3;c++){
			if(lin==l && col==c){
				array[i]=-1;
				return array;
			}
			i=i+1;
		}
	}
	return array;
}

void inicializar(int t[3][3]){
    int lin,col;
    for(lin=0;lin<3;lin++){
        for(col=0;col<3;col++){
            t[lin][col]=0;
        }
    }
}

void exibir_jogo(int t[3][3],int*dis){
    int lin, col;
    
    printf("\n________________\n");
    printf("| %d   %d   %d |\n",t[0][0],t[0][1],t[0][2]);
    printf("| %d   %d   %d |\n",t[1][0],t[1][1],t[1][2]);
    printf("| %d   %d   %d |\n",t[2][0],t[2][1],t[2][2]);
    printf("_______________\n");
    int i=0;
    for(i=0;i<9;i++){
    	if(dis[i]!=-1){
    		printf("  %d",dis[i]);
		}
	}
	
    printf("\n__ ___ __\n");
    for(lin=0;lin<3;lin++){
        for(col=0;col<3;col++){
            if(t[lin][col]==0) {
                printf(" ");
            }else{
                if(t[lin][col]==1){
                    printf("X");
                }else {
                	if(t[lin][col]==-1){
                		printf("O");
					}
                }
            }
            if(col!=2) {
                printf(" | ");
            }
        }
        printf("\n__|___|__\n");
        //printf("\n");
    }
}


int verifica_empate(int t[3][3]){
    int lin,col;
    for(lin=0;lin<3;lin++){
        for(col=0;col<3;col++){
            if(t[lin][col]==0){
                return 0;
            }
        }
    }
    return 1;
}

int verifica_vencedor(int t[3][3]){
    int lin,col,soma,somad1=0,somad2=0;
    for(lin=0;lin<3;lin++){
        soma=0;
        somad1=somad1+t[lin][lin];
        somad2=somad2+t[lin][2-lin];
        for(col=0;col<3;col++){
            soma=soma+t[lin][col];
        }
        if(soma==3 || soma==-3 || somad1==3 || somad1==-3 || somad2==3 || somad2==-3){
            return 1;
        }
    }

    for(col=0;col<3;col++){
        soma=0;
        for(lin=0;lin<3;lin++){
            soma=soma+t[lin][col];
        }
        if(soma==3 || soma==-3){
            return 1;
        }
    }
    return 0;
}
int verifica_final_jogo(int t[3][3], int vez, int*dis){
    if(verifica_empate(t)){
        printf("Resultado: Empate\n");
        exibir_jogo(t,dis);
        return 1;
    }else{
        if(verifica_vencedor(t)) {
            if(vez%2==1){
                printf("Resultado: Jogador venceu\n");
                exibir_jogo(t,dis);
                return 1;
            }else{
                printf("Resultado: Computador venceu\n");
                exibir_jogo(t,dis);
                return 1;
            }
        }
    }
    return 0;
}

int verifica_posicao(int t[3][3],int lin,int col){
    if(lin<0 || lin>2 || col<0 || col>2 || t[lin][col]!=0) {
        return 0;
    }else {
        return 1;
    }
}



int pontos(){
	
	
	
}



/*jog simular1(int t[3][3],int*dis,int posicao,int soma[3][3],int vez){
	jog pjog;
	vez=vez+1;
	printf("jogador 0. computador 1. atual:%d  vez: %d \n",vez%2,vez);
	if(vez==11){
		//return soma;
	}
	int lin,col;
	int l,c;
	//do{
        //printf("linha: ");      
        //scanf("%d",pjog.l);
        //printf("coluna: ");
        //scanf("%d",pjog.c);
        //lin--;
        //col--;
        int i;
       // for(i=vez;i<11;i++){
		//}
        int verifica=0;
    	for(lin=0;lin<3;lin++){
    		for(col=0;col<3;col++){
    			if(verifica_posicao(t,lin,col)==0&&verifica==0) {
		            printf("Posicao indisponivel\n");
		        }else{
		        	if(verifica==0){
		        		printf(" LC\n");
		        		pjog.l=lin;
			        	pjog.c=col;
			        	diminuir_disponivel(dis,pjog.l,pjog.c);
			        	verifica=1;
		        	}
				}
			}
		}
		printf("l=%d ,c=%d\n",pjog.l,pjog.c);
		if(vez%2==0){
	    	t[pjog.l][pjog.c]=0;
	    	//soma[l][c]=(11-vez)*
		}else{
			t[pjog.l][pjog.l]=-1;
		}
		//if()
		
        printf(" aaa\n");
    //}while(verifica_posicao(t,pjog.l,pjog.c)==0);
    
    
	vez=vez-1;
    //return soma[lin][col];
    return pjog;
}
*/
jog simular(int t[3][3],int*dis,int posicao,int soma[3][3],int vez){
	jog pjog;
	//vez=vez+1;
	//printf("jogador 0. computador 1. atual:%d  vez: %d \n",vez%2,vez);
	printf("SIMULA - VEZ: %d - (0jogador; 1computador) quem joga:%d\n",vez,vez%2);
	if(vez==4){
		printf("fim\n");
		//return soma;
	}
	int lin,col;
	int l,c;
	//do{
        //printf("linha: ");      
        //scanf("%d",pjog.l);
        //printf("coluna: ");
        //scanf("%d",pjog.c);
        //lin--;
        //col--;
        int i;
       // for(i=vez;i<11;i++){
		//}
        int verifica=0;
    	for(lin=0;lin<3;lin++){
    		for(col=0;col<3;col++){
    			if(verifica_posicao(t,lin,col)==0&&verifica==0) {
		            printf("Posicao indisponivel\n");
		        }else{
		        	if(verifica==0){
		        		printf(" LC\n");
		        		pjog.l=lin;
			        	pjog.c=col;
			        	diminuir_disponivel(dis,pjog.l,pjog.c);
			        	verifica=1;
		        	}
				}
			}
		}
		printf("l=%d ,c=%d\n",pjog.l,pjog.c);
		if(vez%2==0){//jogador
	    	t[pjog.l][pjog.c]=1;
	    	//soma[l][c]=(11-vez)*
		}else{//computador
			t[pjog.l][pjog.l]=-1;
		}
		vez=vez+1;
		//simula();
		
		
		printf("tf[%d][%d]\n",pjog.l,pjog.c);
		printf("(%d)",t[0][0]);
	    t[pjog.l][pjog.c]=0;
		
		//if()
		
        printf(" aaa\n");
    //}while(verifica_posicao(t,pjog.l,pjog.c)==0);
    
    
	vez=vez-1;
	exibir_jogo(t,dis);
    //return soma[lin][col];
    return pjog;
}

void jogada(int t[3][3],int*dis){
    int lin,col;
    printf("VEZ: %d - (0 jogador; 1computador) quem joga:%d  ",vez,vez%2);
    if((vez%2)==0){
        printf("Jogador\n");
        do{
            printf("linha: ");
            scanf("%d",&lin);
            printf("coluna: ");
            scanf("%d",&col);
            if(verifica_posicao(t,lin,col)==0) {
                printf("Posicao indisponivel\n");
            }else{
            	diminuir_disponivel(dis,lin,col);
			}
        }while(verifica_posicao(t,lin,col)==0);
        t[lin][col]=1;
    }else{
        printf("Computador\n");
        do{
            printf("linha: ");
            scanf("%d",&lin);
            printf("coluna: ");
            scanf("%d",&col);
            if(verifica_posicao(t,lin,col)==0) {
                printf("Posicao indisponivel\n");
            }else{
            	diminuir_disponivel(dis,lin,col);
			}
        }while(verifica_posicao(t,lin,col)==0);
        t[lin][col]=-1;
//        int posicao=0;
        //int dis1=dis;
//        jog proxima_jogada;
//        int soma[3][3];      
//        proxima_jogada=simular(t,dis,posicao,soma,vez);
//        printf("\nL=%d  C=%d\n",proxima_jogada.l,proxima_jogada.c);
//        t[proxima_jogada.l][proxima_jogada.c]=-1;
    }
	vez++;
}
void jogar(int t[3][3], int*dis){
    inicializar(t);
    do{
        exibir_jogo(t,dis);
        jogada(t,dis);
    }while(verifica_final_jogo(t,vez,dis)==0);
}


int main(){
    printf("Jogo da Velha");
    int t[3][3];
    vez=0;
    int dis[9];
	disponivel(dis);
    
    jogar(t,dis);

    system("pause");
    return 0;
}














