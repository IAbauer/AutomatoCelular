#include <GL/glut.h>
#include <string>
#include <string.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>

typedef struct Individuo{
	float valor;
	int formula;
	int vizinhos[8];
    int vizinhosVal[8];
    float aptidao;
    int geracao;
}individuo;

int flag_Pop = 0;
//int x,y;
char ruim[]="RUIM";
char influ[]="INFLUENCIAVEL";
char bom[]="BOM";
char ini[]="POPULACAO INICIAL";
char final[]="POPULACAO FINAL";
char titulo[]="Simulador de populacao";
char by[]="Desenvolvido por Gabriel Moura & Thaylo Guizani";
char p20[]="p/ 20 p/cent BOM";
char p50[]="p/ 50 p/cent BOM";
char p80[]="p/ 80 p/cent BOM";
char nome[]="aptidaoIndividuosP20.txt";
char nome1[]="aptidaoIndividuosP50.txt";
char nome2[]="aptidaoIndividuosP80.txt";
int n,f20=0,f50=0,f80=0,flag20=0,flag50=0,flag80=0,aloca=0;
bool teclas[256];

//Matrizes para realizar as iterações, sugiro que nao sejam globais
individuo **ma;
individuo **ma1;
individuo **ma2;
individuo **maAux;
individuo **maInicial;
individuo **maIndividuo;

//Matriz Original que será mostrada graficamente no OpenGL, deixar apenas essa ser global (e futuramente a maFinal)
//individuo **maInicial;

//indiviuo populacao[10][10];

//Inves de passar linha e coluna como parametros, defini um variavel correspondente para as duas, ja que a matriz h sempre quadrada
#define TAM_MATRIZ 10
#define TAM_POP 50
#define NUM_VIZINHOS 8
#define NUM_ITERACOES 20
#define NUM_GERACOES 10
#define fator_L 5.00
#define APTDINICIAL 0

int iter=0,iter1=0,iter2=0;
void init(void);
void display();
void keyPressed (unsigned char key, int x, int y);
void keyUp (unsigned char key, int x, int y);
void keyOperations();
void escreveTitulo(void);
void tituloIni(int valor);
void desenhaCirculo(GLint x, GLint y, int linhas, int raio, float r, float g, float b);
void DesenhaTextoStroke(void *font, char *string) ;
individuo **iniciPMatriz(int n,individuo **ma);
void drawFirstM (individuo **maInicial);
void drawFinalM (individuo **ma);
void drawFinalM50 (individuo **ma1);
void drawFinalM80 (individuo **ma2);
individuo **executaAlgortimoAutomato(individuo **ma,individuo **maAux);
individuo **armazenaVizinhos(individuo **ma);
individuo **mudaEstado(individuo **ma,individuo **maAux);
int calculaInfluencia(int valor, int bom, int ruim, int ativos, float pct);
individuo **copiaMatriz(individuo **maInicial, individuo **ma);
individuo **copiaAuxFinal(individuo **maAux, individuo **ma);
individuo **copiaMatrizIndividuo(individuo **maIndividuo, individuo **ma);
void criaLog(individuo **pop);
void calculaAptidaoPopulacao(individuo **pop, individuo *mIndividuo, individuo **mAux, individuo **m, individuo **m1, individuo **m2);
individuo **geraFormacaoIndividuo(individuo **pop);
individuo **AlocMat(void);
individuo **AlocaVet(void);
int **FreeMat(int **mat);
void executaAlgoritmoGenetico(individuo **pop, individuo **mIndividuo, individuo **mAux, individuo **m, individuo **m1, individuo **m2);
void Mutacao(individuo **pop, int filho);
void CrossOver(individuo **pop, int pai1,int pai2, int filho1, int filho2);
void selecaoPopulacao(individuo **populacao, long int geracao);
//funcs aleatorio
double fncAleatorios_AleatorioRealEntre_0_e_1();
long int fncAleatorios_AleatorioInteiro(long int low, long int high);
double fncAleatorios_AleatorioReal(double lo , double hi);
void QuicksortDecrescente(individuo **populacao, long int esq, long int dir);
