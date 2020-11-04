#include<stdio.h>
#include<stdlib.h>

void inserir(int*v, int pos, int valor)
{
    v[pos]=valor;
}

void imprimir(int*v, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d  ",v[i]);
    }
    printf("\n");
}




int main()
{
int quantidade=0;
int i,valor;
int maior=1,posicao=0;

printf("___________________________________\n");
printf("digite o tamanho do vetor:");
scanf("%d",&quantidade);

int vetor[quantidade],f[quantidade],f_1[quantidade];

printf("\nelementos numeros inteiros\n");
for(i=0;i<quantidade;i++)
{
    scanf("%d",&valor);
    inserir(vetor,i,valor);
}


printf("_______________VETOR_______________\n");
imprimir(vetor,quantidade);



for(i=0;i<quantidade;i++)
{
    if(i==0)
    {
        f[0]=1;
    }
    else
    {
       if(vetor[i]>=vetor[i-1])
       {
           f[i]=f[i-1]+1;
           if(maior<f[i])
           {
               maior=f[i];
               posicao=i;
           }
       }
       else
       {
           f[i]=1;
       }
    }
}
printf("___________________________________\n");
imprimir(f,quantidade);
printf("___________________________________\n");
printf("tamanho da maior sequencia crescente: %d \n",maior);
printf("___________________________________\n");
printf("maior sequencia: ");
for(i=(posicao-maior+1);i<=(posicao);i++)
{
    printf("%d  ",vetor[i]);
}


maior=1;
posicao=0;
for(i=0;i<quantidade;i++)
{
    if(i==0)
    {
        f_1[0]=1;
    }
    else
    {
        int j=0;
        int maior_elem=1;
        for(j=0;j<i;j++){
           if(vetor[i]>=vetor[j])
           {
               if(maior_elem<=f_1[j])
               {
                   maior_elem=f_1[j]+1;
               }
           }
        }
        f_1[i]=maior_elem;
        if(maior<f_1[i])
        {
           maior=f_1[i];
           posicao=i;
        }
    }
}
printf("\n\n___________________________________\n");
imprimir(f_1,quantidade);
printf("___________________________________\n");
printf("tamanho da sequencia nao continua crescente: %d \n",maior);
printf("___________________________________\n");






    system("pause");
    return 0;
}




