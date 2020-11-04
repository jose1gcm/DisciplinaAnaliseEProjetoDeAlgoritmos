#include<stdio.h>
#include<stdlib.h>

//___________________________________
void inserir_heap(int*v, int pos, int valor)
{
    v[pos]=valor;
}
void imprimir(int*v, int tam)
{
    int i;
    for(i=1;i<=tam;i++)
    {
        printf("%d  ",v[i]);
    }
    printf("\n");
}
//___________________________________
int parent(int i)
{
    return (int) i/2;
}
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
void trocar(int*v,int i,int maior)
{
    int aux=v[i];
    v[i]=v[maior];
    v[maior]=aux;
}
void max_heapify(int*v, int i,int tam)
{
    int maior;
    int l=left(i);
    int r=right(i);
    printf("i=%d l=%d r=%d  A[%d]=%d A[%d]=%d A[%d]=%d \n",i,l,r,i,v[i],l,v[l],r,v[r]);
    if(l<=tam&&v[l]>v[i])
    {
        maior=l;
    }
    else
    {
        maior=i;
    }
    if(r<=tam&&v[r]>v[maior])
    {
        maior=r;
    }
    if(maior!=i)
    {
        trocar(v,i,maior);
        imprimir(v,tam);
        printf("\ni=%d maior=%d\n",i,maior);
        max_heapify(v,maior,tam);
        imprimir(v,tam);
    }
}
void build_max_heap(int*v, int tam)
{
    int i;
    for(i=(int)(tam/2);i>=1;i--)
    {
        printf("i=%d build\n",i);
        max_heapify(v,i,tam);
    }
}
void heap_sort(int*v,int tam)
{
    int tam_h=tam;
    int i;
    build_max_heap(v,tam);
    printf("\n___________________________________\n");
    for(i=tam_h;i>=2;i--)
    {
        trocar(v,1,i);
        tam_h=tam_h-1;
        max_heapify(v,1,tam_h);
    }
}
//___________________________________
int main()
{
int quantidade=0;
int i;
int valor;
printf("_____________HEAP SORT_____________\n");
printf("digite o tamanho do vetor:");
scanf("%d",&quantidade);

int vetor[quantidade];
printf("\nelementos numeros inteiros\n");
for(i=1;i<=quantidade;i++)
{
    scanf("%d",&valor);
    inserir_heap(vetor,i,valor);
    //imprimir(v,tam);
}

int tam=quantidade;
printf("_______________VETOR_______________\n");
imprimir(vetor,tam);


//max_heapify(vetor,1,tam);
//build_max_heap(vetor,tam);
//imprimir(vetor,tam);
printf("___________________________________\n");
heap_sort(vetor,tam);
printf("\n___________HEAP ORDENADO___________\n");
imprimir(vetor,tam);


system("pause");
return 0;
}


