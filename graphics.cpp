#include "var.h"
#include "funcs.h"
#include "automatos.h"
int main(int argc, char *argv[])
{		
		 srand(time(NULL));
		printf("\nInsira a porcentagem de inimigos bons inicial!\n");
    	scanf("%i",&n);

        individuo **matriz;
        matriz= AlocMat(10, 10);
        //FreeMat(linhas, colunas, matriz);
        /* Ta Bugando a fodeno alocacao de memoria
    	for (x = 0 ; x < 10 ; x++){
            for (y = 0 ; y < 10 ; y++){
                 matriz[x][y].valor =1;
                 matriz[x][y].vizinhos[x]=1;
            }
        }

        for (x=0;x<10;x++){
              for (y=0;y<10;y++){
                 printf("\n valor do individuo =%p\n",&matriz[x][y].valor);
                 printf("\n valor do vizinho %i =%p\n",x,&matriz[x][y].vizinhos[x]);
              }
           }
        */
        ////OPENGL FUNCS
        iniciPMatriz(n);
        glutInit( &argc, argv );
    	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    	glutInitWindowSize( 500, 500 );
    	glutInitWindowPosition( 70, 75 );
    	glutCreateWindow("Simulador de populacao IA 2017/2");
    	init();
    	glutDisplayFunc( display );
    	glutMainLoop();
    	return 0;
}