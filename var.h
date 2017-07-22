#include <GL/glut.h>
#include <string>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>


struct individuo{
	float valor;
	int vizinhos[8];
    struct individuo *vizinhosVal[8];

};
typedef struct individuo individuo;

int x,y;
char ruim[]="RUIM";
char influ[]="INFLUENCIAVEL";
char bom[]="BOM";
char ini[]="POPULACAO INICIAL";
char final[]="POPULACAO FINAL";
char titulo[]="Simulador de populacao";
char by[]="Desenvolvido por Gabriel Moura & Thaylo Guizani";
int n;

//Matrizes para realizar as iterações, sugiro que nao sejam globais
individuo **ma;
individuo **maAux;

//Matriz Original que será mostrada graficamente no OpenGL, deixar apenas essa ser global (e futuramente a maFinal)
individuo **maInicial;
//indiviuo populacao[10][10];

//Inves de passar linha e coluna como parametros, defini um variavel correspondente para as duas, ja que a matriz h sempre quadrada
#define TAM_MATRIZ 10

#define NUM_VIZINHOS 8
#define NUM_ITERACOES 20

void init();
void display();
void drawQuads(float r,float g, float b);
void drawFirstM (individuo **mat);
void desenhaCirculo(GLint x, GLint y, int linhas, int raio, float r, float g, float b);
void DesenhaTextoStroke(void *font, char *string);
void escreveTitulo(void);
individuo **iniciPMatriz(int n);
void drawFinalM (individuo **mat);
int **FreeMat(int **mat);
individuo **AlocMat();
void drawFirstM (individuo **mat);
void calculaInfluencia(individuo **ma, individuo **maAux);
void armazenaVizinhos(individuo **ma);
