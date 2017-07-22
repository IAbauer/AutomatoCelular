#include "var.h"
#include "funcs.h"

int main(int argc, char *argv[])
{		
		 srand(time(NULL));
		printf("\nInsira a porcentagem de inimigos bons inicial!\n");
    	scanf("%i",&n);
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