#include <GL/glut.h>
#include <string>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>



typedef struct{
	float valor;
	int vizinhos[8];

}individuo;


int x,y;
char ruim[]="RUIM";
char influ[]="INFLUENCIAVEL";
char bom[]="BOM";
char ini[]="POPULACAO INICIAL";
char final[]="POPULACAO FINAL";
char titulo[]="Simulador de populacao";
char by[]="Desenvolvido por Gabriel Moura & Thaylo Guizani";
int n;
individuo **matriz;
//indiviuo populacao[10][10];



void init();
void display();
void drawQuads(float r,float g, float b);
void drawFirstM (individuo **mat);
void desenhaCirculo(GLint x, GLint y, int linhas, int raio, float r, float g, float b);
void DesenhaTextoStroke(void *font, char *string);
void escreveTitulo(void);
individuo **iniciPMatriz(int n);
void drawFinalM (individuo **mat);
int **FreeMat(int linhas, int colunas, int **mat);
individuo **AlocMat(int linhas, int colunas);
void drawFirstM (individuo **mat);
