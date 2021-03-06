#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double *GaussSeidel(double **, double *, int, double, int);
double normaInfinita (double **, int);

void testarComEntradasDoUsuario() {

    int i,j,n, itmax;
    double tolerancia, *b, **A;

    printf("Digite o tamanho do vetor:'\n");
    scanf("%d",&n);
    printf("Digite o quantidade máxima de iterações\n");
    scanf("%f",&tolerancia);

    b = (double *) malloc(n*sizeof(double));
    A = (double **) malloc(n*sizeof(double *));
    for(i=0;i<n;i++)
        A[i]= (double *) malloc(sizeof(double));

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Digite o elemento A[%d][%d]: ",i,j);
            printf("\n");
            scanf("%f",&A[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        printf("Digite o elemento %d do vetor B: ",i);
        printf("\n");
        scanf("%f",&b[i]);
    }


}

double *GaussSeidel(double **A, double *b, int n, double tolerancia, int itmax)
{
    double *xAtual = (double *) calloc(n,sizeof(double)); //x(k+1)
    double *xAnterior = (double *) calloc (n,sizeof(double)); //x(k)
    double sum1, sum2;
    int i,j,k;
    for(k=0;k<itmax;k++)
    {
        for(i=0;i<n;i++) //calculo de uma iteração xi
        {
            sum1=0; sum2=0;
            for(j=0;j< i;j++) //j de 1 até i-1
            {
                sum1+= A[i][j]*xAtual[j];
            }
            for(j=i+1;j<n;j++)
            {
                sum2+= A[i][j]*xAnterior[j];
            }
            xAtual[i] = (b[i] -sum1 - sum2)/A[i][i];
        }
        
        if(abs(normaInfinita(xAtual,n) - normaInfinita(xAnterior,n)) < tolerancia)
            break;
        
        for(i=0;i<n;i++)
            xAnterior[i] = xAtual[i]; //atualizo x(0) = x(1) pra ser usado na proxima iteração
                                     //por exemplo, na 2a iteração do for de variavel k, o xAnterior será o calculado na primeira iteração
        
    }                                 


    return xAtual;
}

double normaInfinita (double **A, int n){

    int i,j;
    double max =0,aux;
    for(i=0;i<n;i++)
    {
        aux =0;
        for(j=0;j<n;j++)
            aux+= abs(A[i][j]);
        if(max < aux)
            max = aux;
    }
    return max;
}
