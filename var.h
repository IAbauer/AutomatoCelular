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

}individuo;

//int x,y;
char ruim[]="RUIM";
char influ[]="INFLUENCIAVEL";
char bom[]="BOM";
char ini[]="POPULACAO INICIAL";
char final[]="POPULACAO FINAL";
char titulo[]="Simulador de populacao";
char by[]="Desenvolvido por Gabriel Moura & Thaylo Guizani";
int n;
bool teclas[256];

//Matrizes para realizar as iterações, sugiro que nao sejam globais
individuo **ma;
individuo **maAux;

//Matriz Original que será mostrada graficamente no OpenGL, deixar apenas essa ser global (e futuramente a maFinal)
individuo **maInicial;

//indiviuo populacao[10][10];

//Inves de passar linha e coluna como parametros, defini um variavel correspondente para as duas, ja que a matriz h sempre quadrada
#define TAM_MATRIZ 10
#define NUM_VIZINHOS 8
#define NUM_ITERACOES 50

int iter=0;
void init();
void display();
void drawQuads(float r,float g, float b);
void drawFirstM (individuo **mat);
void desenhaCirculo(GLint x, GLint y, int linhas, int raio, float r, float g, float b);
void DesenhaTextoStroke(void *font, char *string);
void escreveTitulo(void);
individuo **iniciPMatriz(int n);
void drawFinalM (void);
int **FreeMat(int **mat);
individuo **AlocMat();
void drawFirstM (void);
void mudaEstado(void);
int calculaInfluencia(int valor, int bom, int ruim, int ativos, float pct); 
void armazenaVizinhos(void);
void geraFormacaoIndividuo(void);
void copiaMatriz(void);
void copiaAuxFinal(void);
void keyPressed (unsigned char key, int x, int y);
void keyUp (unsigned char key, int x, int y);
void keyOperations(void);
void executaAlgortimoAutomato(void);
int qtdIndividuosDiferentes(int ind);
int qtdVizinhosDiferentes(Individuo ind);
float traduzFormula(int ident);
float calculaAptidao(Individuo ind);
void geraFormacaoIndividuo();
void criaLog();