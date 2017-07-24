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
char p20[]="p/ 20 p/cent BOM";
char p50[]="p/ 50 p/cent BOM";
char p80[]="p/ 80 p/cent BOM";
int n,f20=0,f50=0,f80=0,flag20=0,flag50=0,flag80=0;
bool teclas[256];

//Matrizes para realizar as iterações, sugiro que nao sejam globais
individuo **ma;
individuo **ma1;
individuo **ma2;
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
void drawFinalM ();
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
void tituloIni(int valor);
void copiaAuxFinal50(void);
void copiaAuxFinal80(void);