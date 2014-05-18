/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *
 * 1º Trabalho Prático - Mét. Iterativos Sist. Lineares
 * Prof. Murilo Francisco Tomé
 *
 * Desenvolvido por:
 * Antonio Carlos Moreira Lopes Júnior  NUSPº 7987290
 * Gabriela Pinto Cesar Duque           NUSPº 7694220
 * Leonardo Sampaio Ferraz Ribeiro      NUSPº 8532300
 *
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "functions.h"

/*!
 * Calcula a solução de um sistema linear Ax = b através
 * do método iterativo de Gauss-Seidel
 */
int gaussSeidel(double **A, double *b, int n, double e, int itmax, double *x, int iter) {
    
    // auxiliares
    int i, j;
    double soma1 = 0.0, soma2 = 0.0;
    double x0[n], x1[n];
    
    while (iter < itmax) {
        // copiar o vetor x para x0, para poder computar a norma
        for (i = 0; i < n; i++)
            x0[i] = x[i];
        
        for (i = 0; i < n; i++) {
            for (j = 0; j <= i-1; j++)
                soma1 += A[i][j] * x[j];
            
            for (j = i+1; j < n; j++)
                soma2 += A[i][j] * x[j];
            
            x[i] = (b[i] - soma1 - soma2)/A[i][i];
            
            soma1 = soma2 = 0;
        }
        
        // depois de x ser alterado, copiar para x1, para computar a norma
        for (i = 0; i < n; i++) {
            x1[i] = x[i];
        }
        
        iter++;
        
        // computar a norma, caso seja menor que o erro, parar as iterações
        // e exibir o vetor x(k+1)
        if (calculaErro(x0, x1, n) <= e) {
            printf("Converge na iteracao %d\n", iter);
            printf("X = [");
            for (i = 0; i < n; i++)
                printf("%f, ", x[i]);
            printf("]\n");
            
            // o método convergiu!
            return SUCESSO;
        }
        
    }
    
    // se a norma do vetor diferença não for menor que o erro máximo depois do Nº máximo de iterações
    // o método divergiu
    return DIVERGIU;
}

/*!
 * Aloca memória para uma matriz quadrada nxn
 */
double** reservaMemoriaParaA(int n) {
    
    // auxiliares
    int i;
    
    // ponteiro inicial
    double** A = (double**)malloc(n * sizeof(double *));
    
    // linhas da matriz
    for (i = 0; i < n; i++)
        A[i] = (double *)malloc(n * sizeof(double));
    
    return A;
}

/*!
 * Libera espaço alocado para matriz de ordem n
 */
void liberaMemoriaDeA(double** A, int n) {
    
    // auxiliares
    int i;
    
    // libera linhas da matriz
    for (i = 0; i < n; i++)
        free(A[i]);
    
    // libera ponteiro inicial
    free(A);
}

/*!
 * Aloca memória para um vetor de tamanho n
 */
double* reservaMemoriaParaVetorDeTamanhoN(int n) {
    return (double *)malloc(n * sizeof(double));
}

/*!
 * Gera matriz pentadiagonal A, como especificado
 * em http://goo.gl/sFb5HT
 */
void preencheAParaExercicioC(double **A, int n) {
    
    // auxiliares
    int i, j;
    
    // como há regras diferentes pra preencher a matriz
    // o melhor foi dividir o preenchimento em partes
    
    // inicialmente preencher a matriz toda com 0s, seguindo a sexta regra
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    
    // preencher a diagonal com a primeira regra
    for (i = 0; i < n; i++)
        A[i][i] = 4;
    
    // preencher as células com a segunda e terceira regras
    for (i = 0; i < n-1; i++) {
        A[i][i+1] = -1;
        A[i+1][i] = -1;
    }
    
    // preencher as células com a quarta e quinta regras
    for (i = 0; i < n-3; i++) {
        A[i][i+3] = -1;
        A[i+3][i] = -1;
    }
}

/*!
 * Gera matriz A preenchida com 1's
 */
void preencheAParaExercicioB(double **A, int n) {
    
    // auxiliares
    int i, j;
    
    // itera por todas as células da matriz
    // e preenche com 1
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = 1;
        }
    }
}

/*!
 * Gera vetor B como especificado em
 * http://goo.gl/sFb5HT para o exercício b
 */
void preencheBParaExercicioB(double **A, double *b, int n) {
    
    // auxiliares
    int i, j;
    double soma = 0;
    
    // itera através do vetor b
    for (i = 0; i < n; i++) {
        
        // soma = ∑[j=0->n-1](aij)
        for (j = 0; j < n; j++) {
            soma += A[i][j];
        }
        
        // bi = ∑[j=0->n-1](aij)
        b[i] = soma;
        
        // reinicia soma
        soma = 0;
    }
    
}

/*!
 * Gera vetor B como especificado em
 * http://goo.gl/sFb5HT para o exercício c
 */
void preencheBParaExercicioC(double *b, int n) {
    
    // auxiliar
    int i;
    
    // itear através do vetor b e preenche os valores de
    // acordo com e especificação
    for (i = 0; i < n; i++) {
        b[i] = 1.0/(i+1);
    }
    
}

/*!
 * Inicializa um vetor X com 0's
 */
void inicializaX(double *x, int n) {
    
    // auxiliar
    int i;
    
    // itera através do vetor x e inicializa seus valores com 0
    for (i = 0; i < n; i++) {
        x[i] = 0;
    }
}

/*!
 * Calcula o valor do erro utilizando utlizando a fórmula
 * ||x(k+1) - x(k)||∞
 */
double calculaErro(double *x0, double *x1, int n) {
    
    // auxiliares
    int i;
    double maior = 0, aux;
    
    // subtrai x1 de x0 e já computa qual é o maior índice
    // (norma infinita do vetor diferença)
    for (i = 0; i < n; i++) {
        
        aux = fabs(x1[i] - x0[i]);
        
        if (maior < aux )
            maior = aux;
    }
    
    return maior;
}

/*!
 * Compara os resltados esperados com aqueles obtidos
 * pela solução de Ax = B
 */
void verifica(double **A, double *b, double *x, int n) {
    
    // auxiliares
    int i, j;
    double resultadoEquacao;
    
    // itera através das matrizes e calcula os
    // resultados da equação
    for (i = 0; i < n; i++) {
        
        // reinicia valor da equacao
        resultadoEquacao = 0;
        
        for (j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                printf("+ %.2f*%.2f ", A[i][j], x[j]);
                resultadoEquacao += A[i][j] * x[j];
            }
        }
        
        // compara resultados obtidos com os esperados
        printf("= %.2f =~ %.2f?\n", resultadoEquacao, b[i]);
    }
}

/*!
 * Imprime menu do programa principal
 */
void imprimeMenu() {
    
    printf("\n1º Trabalho - Mét. Iterativos Sist. Lineares\n");
    printf("                    \n\
1) Entrar com as matries A e B  \n\
2) Testar com exercício b)      \n\
3) Testar com exercício c)      \n\
4) Sair                         \n\n");
    printf("Escolha uma das opções: ");
}

/*!
 * Testa o programa com entradas do usuário
 */
void testarComEntradasDoUsuario() {
    
    // auxiliares
    int i,j,n, itmax;
    double e, *b, *x, **A;
    char verificar;
    
    // recebe parametros do usuário
    printf("Digite a ordem do sistema: ");
    scanf("%d",&n);
    printf("Digite o quantidade máxima de iterações: ");
    scanf("%d", &itmax);
    printf("Digite o erro máximo: ");
    scanf("%lf", &e);
    
    // aloca espaço para matriz e os vetores
    A = reservaMemoriaParaA(n);
    b = reservaMemoriaParaVetorDeTamanhoN(n);
    x = reservaMemoriaParaVetorDeTamanhoN(n);
    
    // inicializa vetor x
    inicializaX(x, n);
    
    // recebe valores para matriz A do usuário
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            
            printf("Digite o elemento A(%d, %d): ", i+1, j+1);
            scanf("%lf", &A[i][j]);
        }
    }
    
    // recebe valores para o vetor B do usuário
    for(i=0;i<n;i++) {
        printf("Digite o elemento %d do vetor B: ",i+1);
        scanf("%lf", &b[i]);
    }
    
    // aplicar o método e checa se divergiu
    if (gaussSeidel(A, b, n, e, itmax, x, 0) == DIVERGIU) {
        printf("O método divergiu!\n");
    }
    else {
        
        printf("Deseja verificar a corretude da solução(S ou N)? ");
        scanf(" %c", &verificar);
        getchar();
        if (verificar == 'S' || verificar == 's') {
            verifica(A, b, x, n);
        }
    }
    
    // libera o espaço alocado na memória
    liberaMemoriaDeA(A, n);
    free(b);
    free(x);
}

/*!
 * Testa o programa como proposto pelo exercício b)
 * em http://www.lcad.icmc.usp.br/~mftome/SME104/SME104-1oTrab-2014.pdf
 */
void testarComExercicioB() {
    
    // auxiliares
    int n, itmax;
    double e;
    double **A;
    double *b, *x;
    char verificar;
    
    printf("Exercício B)\n");
    n = 100;
    itmax = 10000;
    e = 0.0001;
    
    // aloca o espaço para a matriz e os vetores
    A = reservaMemoriaParaA(n);
    b = reservaMemoriaParaVetorDeTamanhoN(n);
    x = reservaMemoriaParaVetorDeTamanhoN(n);
    
    // preencher a matriz e os vetores
    preencheAParaExercicioC(A, n);
    preencheBParaExercicioB(A, b, n);
    inicializaX(x, n);
    
    // aplicar o método e checa se divergiu
    if (gaussSeidel(A, b, n, e, itmax, x, 0) == DIVERGIU) {
        printf("O método divergiu!\n");
    }
    else {
        
        printf("Deseja verificar a corretude da solução(S ou N)? ");
        scanf(" %c", &verificar);
        if (verificar == 'S' || verificar == 's') {
            verifica(A, b, x, n);
        }
    }
    
    // libera o espaço alocado na memória
    liberaMemoriaDeA(A, n);
    free(b);
    free(x);
}

/*!
 * Testa o programa como proposto pelo exercício c)
 * em http://www.lcad.icmc.usp.br/~mftome/SME104/SME104-1oTrab-2014.pdf
 */
void testarComExercicioC() {
    
    // auxiliares
    int n, itmax;
    double e;
    double **A;
    double *b, *x;
    char verificar;
    
    printf("Exercício c)\n");
    n = 40;
    itmax = 10000;
    e = 0.000001;
    
    // aloca espaço para a matriz e os vetores
    A = reservaMemoriaParaA(n);
    b = reservaMemoriaParaVetorDeTamanhoN(n);
    x = reservaMemoriaParaVetorDeTamanhoN(n);
    
    preencheAParaExercicioC(A, n);
    preencheBParaExercicioC(b, n);
    inicializaX(x, n);
    
    // aplicar o método e checa se divergiu
    if (gaussSeidel(A, b, n, e, itmax, x, 0) == DIVERGIU) {
        printf("O método divergiu!\n");
    }
    else {
        
        printf("Deseja verificar a corretude da solução(S ou N)? ");
        scanf(" %c", &verificar);
        if (verificar == 'S' || verificar == 's') {
            verifica(A, b, x, n);
        }
    }
    
    // libera o espaço alocado na memória
    liberaMemoriaDeA(A, n);
    free(b);
    free(x);
}








