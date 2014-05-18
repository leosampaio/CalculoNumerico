/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *
 * 1º Trabalho Prático - Mét. Iterativos Sist. Lineares
 * Prof. Murilo Francisco Tomé
 *
 * Desenvolvido por:
 * Antônio Carlos                       NUSPº
 * Gabriela Duque                       NUSPº
 * Leonardo Sampaio Ferraz Ribeiro      NUSPº 8532300
 *
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

#ifndef SMA0104_functions_h
#define SMA0104_functions_h

#define DIVERGIU 1
#define SUCESSO 0

/*!
 * Calcula a solução de um sistema linear Ax = b através
 * do método iterativo de Gauss-Seidel
 *
 * @param A
 * matriz real A do sistema linear
 *
 * @param b
 * vetor real b do sistema linear
 *
 * @param n
 * ordem da matriz A
 *
 * @param e
 * tolerancia desejada (erro máximo)
 *
 * @param itmax
 * número máximo de iterações permitidas
 *
 * @param x
 * vetor solução (será preenchido pela função)
 * 
 * @param iter
 * iteração atual (utilizado pela recursão)
 *
 * @return
 * vetor x, solução do sistema linear
 */
int gaussSeidel(double **A, double *b, int n, double e, int itmax, double *x, int iter);

/*!
 * Aloca memória para uma matriz quadrada nxn
 *
 * @param n
 * ordem da matriz
 *
 * @return
 * ponteiro para matriz alocada
 */
double** reservaMemoriaParaA(int n);

/*!
 * Libera espaço alocado para matriz de ordem n
 *
 * @param A
 * matriz de ordem n
 *
 * @param n
 * ordem da matriz
 */
void liberaMemoriaDeA(double** A, int n);

/*!
 * Aloca memória para um vetor de tamanho n
 *
 * @param n
 * tamanho do vetor
 *
 * @return
 * ponteiro para o vetor alocado
 */
double* reservaMemoriaParaVetorDeTamanhoN(int n);

/*!
 * Gera matriz pentadiagonal A, como especificada
 * em http://goo.gl/sFb5HT
 *
 * @param A
 * matriz que será preenchida
 *
 * @param n
 * ordem da matriz A
 */
void preencheAParaExercicioC(double **A, int n);

/*!
 * Gera matriz A preenchida com 1's
 *
 * @param A
 * matriz que será preenchida
 *
 * @param n
 * ordem da matriz A
 */
void preencheAParaExercicioB(double **A, int n);

/*!
 * Gera vetor B como especificado em
 * http://goo.gl/sFb5HT para o exercício b
 *
 * @param A
 * matriz A da equação Ax = B
 *
 * @param b
 * vetor B que será preenchida
 *
 * @param n
 * ordem da matriz A (tamanho do vetor B)
 */
void preencheBParaExercicioB(double **A, double *b, int n);

/*!
 * Gera vetor B como especificado em
 * http://goo.gl/sFb5HT para o exercício c
 *
 * @param b
 * vetor B que será preenchida
 *
 * @param n
 * tamanho do vetor B
 */
void preencheBParaExercicioC(double *b, int n);

/*!
 * Inicializa um vetor X com 0's
 *
 * @param x
 * vetor que será inicializado
 *
 * @param n
 * tamanho do vetor
 */
void inicializaX(double *x, int n);

/*!
 * Calcula o valor do erro utilizando utlizando a fórmula
 * ||x(k+1) - x(k)||∞
 *
 * @param x0
 * vetor x(k) da fórmula
 *
 * @param x1
 * vetor x(k+1) da fórmula
 *
 * @param n
 * tamanho dos vetores
 *
 * @return
 * resultado do calculo do erro
 */
double calculaErro(double *x0, double *x1, int n);

/*!
 * Compara os resltados esperados com aqueles obtidos
 * pela solução de Ax = B
 *
 * @param A
 * matriz A da equação Ax = B
 *
 * @param b
 * vetor B da equação Ax = B
 *
 * @param x
 * vetor solução de Ax = B
 *
 * @param n
 * ordem da matriz A
 */
void verifica(double **A, double *b, double *x, int n);


/*!
 * Imprime menu do programa principal
 */
void imprimeMenu();

/*!
 * Testa o programa com entradas do usuário
 */
void testarComEntradasDoUsuario();

/*!
 * Testa o programa como proposto pelo exercício b)
 * em http://goo.gl/sFb5HT
 */
void testarComExercicioB();

/*!
 * Testa o programa como proposto pelo exercício c)
 * em http://goo.gl/sFb5HT
 */
void testarComExercicioC();


#endif
