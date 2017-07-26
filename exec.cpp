#include "var.h"
#include "funcs.h"
#include "alocacao.h"
#include "automatos.h"
#include "aux.h"
#include "AG.h"

int main(int argc, char *argv[])
{		
		srand(time(NULL));

    ma = AlocMat();
    ma1 = AlocMat();
    ma2 = AlocMat();
    maAux = AlocMat();
    maInicial=AlocMat();
    maIndividuo=AlocMat();
    individuo **pop = AlocaVet();
    maAux1 = AlocMat();
    maAux2 = AlocMat();
    maInicial1 = AlocMat();
    maInicial2 =AlocMat();
    //Cria a populacao inicial
    pop = geraFormacaoIndividuo(pop);


    executaAlgoritmoGenetico(pop,maIndividuo,maAux,ma,ma1,ma2);

    criaLog(pop);


 ////OPENGL FUNCS 
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize( 800, 600 );
    glutInitWindowPosition( 70, 75 );
    glutCreateWindow("Simulador de populacao IA 2017/1");
    init();
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyUp);
  	glutDisplayFunc( display );
  	glutMainLoop();
  	return 0;
}