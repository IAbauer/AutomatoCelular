#include <GL/glut.h>
#include <string>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>





int x,y;
char ruim[]="RUIM";
char influ[]="INFLUENCIAVEL";
char bom[]="BOM";
char ini[]="POPULACAO INICIAL";
char final[]="POPULACAO FINAL";
char titulo[]="Simulador de populacao";
char by[]="Desenvolvido por Gabriel Moura & Thaylo Guizani";
int ma[10][10];
int n;





void init();
void display();
void drawQuads(float r,float g, float b);
void drawFirstM (void);
void desenhaCirculo(GLint x, GLint y, int linhas, int raio, float r, float g, float b);
void DesenhaTextoStroke(void *font, char *string);
void escreveTitulo(void);
void iniciPMatriz(int n);
void drawFinalM (void);