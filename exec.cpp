#include "var.h"
#include "funcs.h"
#include "alocacao.h"
#include "automatos.h"

int main(int argc, char *argv[])
{		
		srand(time(NULL));
        //Alocacao das Matrizes
        ma = AlocMat();
        maAux  = AlocMat();
        maInicial=AlocMat();

        //Obter a % de individuos bons
		printf("\nInsira a porcentagem de inimigos bons inicial!\n");
    	scanf("%i",&n);

        //matriz= AlocMat(10, 10);
        //Inicializar a matriz principal
        ma = iniciPMatriz(n);

        copiaMatriz();
        //Essa eh a matriz inicial do problema, ela nunca serah mudada
        //memcpy ( maInicial , ma , sizeof ( **ma ) );
        //memcpy(destino,origem,tamanho)
        //maInicial = ma;
        executaAlgortimo();
        //FreeMat(linhas, colunas, matriz);
    	/*for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                 ma[i][j].valor =1;
                 //for(int k=0;k<8;k++)
                 	//ma[i][j].valor=1;
            }
        }*/
        /* for (int i = 0 ; i < 10 ; i++) {
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