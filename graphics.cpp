#include "var.h"
#include "funcs.h"
#include "automatos.h"
int main(int argc, char *argv[])
{		
		 srand(time(NULL));
		printf("\nInsira a porcentagem de inimigos bons inicial!\n");
    	scanf("%i",&n);
        //matriz= AlocMat(10, 10);
        matriz = iniciPMatriz(n);
        //FreeMat(linhas, colunas, matriz);
    	/*for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                 matriz[i][j].valor =1;
                 for(int k=0;k<8;k++)
                 	matriz[i][j].vizinhos[k]=0;
            }
        }
         for (int i = 0 ; i < 10 ; i++) {
      			for (int j = 0 ; j < 10 ; j++) {
         			printf("valor do indiviuo = %f\n",matriz[i][j].valor);
         			for(int k=0;k<8;k++)
         				printf("\n valor do vizinho %i =%i\n",i,matriz[i][j].vizinhos[k]);
      			}
   		}*/
        ////OPENGL FUNCS
        
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