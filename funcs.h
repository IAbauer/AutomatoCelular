
void init()
{
    //Selecionar cor de fundo preto
    	glClearColor( 0, 0, 0, 0.0 );
			//glClear( GL_COLOR_BUFFER_BIT );
    	//glMatrixMode( GL_PROJECTION );
    	gluOrtho2D(0,500,0,500 );
}

void display()
{

	glClear( GL_COLOR_BUFFER_BIT );
	keyOperations();
 	escreveTitulo();
 	drawFirstM();
 	drawFinalM();
 	//if(teclas['a']==true)
 	
 	//glPushMatrix();
		//glTranslatef(, ,0 );
		//drawQuads(1,1,1);
	//glPopMatrix();


    glFlush();
}

void keyPressed (unsigned char key, int x, int y) {
    teclas[key] = true; // altera pra true a posicao da tecla pressionada
    }
void keyUp (unsigned char key, int x, int y){
    teclas[key] = false;// altera pra false a posicao da tecla pressionada

}
void keyOperations(){
	if(iter<NUM_ITERACOES){
 		//if (teclas[13]==true){
 			executaAlgortimoAutomato();
 			iter++;
 		//}
 	}
 	glutPostRedisplay();

}

//Funcao utilizada para escrever tudo que se encontra no console
void escreveTitulo(void){
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(110,460,0);
		glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,titulo);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(110,400,0);
		glScalef(0.09, 0.09, 0.09); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,by);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,0,0);
		glTranslatef(20,20,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,ruim);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(200,20,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,influ);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(0,1,0);
		glTranslatef(450,20,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,bom);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(40,330,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,ini);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(290,330,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,final);
	glPopMatrix();

}

void desenhaCirculo(GLint x, GLint y, int linhas, int raio, float r, float g, float b){
	int i = 0;
		glColor3f(r,g,b);
	float angulo;
	glBegin(GL_POLYGON);
		for(i=0;i<linhas;i++){
			angulo = 2*M_PI*i/linhas;
			glVertex2f(x + (cos(angulo)*raio),y + (sin(angulo)*raio));
		}
	glEnd();
}

void DesenhaTextoStroke(void *font, char *string) 
{  
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++); 
}
//onde a matriz inicial é feita atravez do "random", o parametro N é a porcentagem de inimigos bons na populacao
individuo **iniciPMatriz(int n){
	int i,j,r1,r2,k,flag=0,qtdBranco;
	float percent=0;
	qtdBranco=(100-n)*10/100;
    //seta todos os individuos como -1
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			ma[i][j].valor=-1;

	for(i=0;i<10;i++){
		//calcula a quantidade de individuos "bom" na matriz atravez da porcentagem
		percent=(10*(n/100));
		for(j=0;j<10;j++){
			//bug da comparacao de int/float, fiz a gamb pra quando a porcentagem for entre 0 e 1
			if(percent<1&&flag==0){
				for(k=0;k<n;k++){
				//joga os individuos "bom" em posicoes aleatorias na matriz, desde que tenha -1 la, ou seja,vazi0
				do{
					r1=rand()%10;
					r2=rand()%10;
				}while(ma[r1][r2].valor!=-1);
				ma[r1][r2].valor=2;	
				}
				//flag pra n deixar entrar aqui infinito
				flag=1;
			}else
				//todos os outros casos normais
				if(i<percent){
					//joga os individuos "bom" em posicoes aleatorias na matriz, desde que tenha -1 la, ou seja,vazi0
					do{
						r1=rand()%10;
						r2=rand()%10;
					}while(ma[r1][r2].valor!=-1);
					ma[r1][r2].valor=2;
				}
		}
		//le wild gamb pra valores de % entre 0 e 10, tipo um 99=90+9;
		n-=1;
	}

	//mesma coisa pra influenciaveis
	for(i=0;i<10;i++){
		//calcula a quantidade de individuos "bom" na matriz atravez da porcentagem
		flag=0;
		for(j=0;j<10;j++){
				//bug da comparacao de int/float, fiz a gamb pra quando a porcentagem for entre 0 e 1
				if(qtdBranco<1&&flag==0){
					for(k=0;k<qtdBranco;k++){
					//joga os individuos "bom" em posicoes aleatorias na matriz, desde que tenha -1 la, ou seja,vazi0
					do{
						r1=rand()%10;
						r2=rand()%10;
					}while(ma[r1][r2].valor!=-1);
					ma[r1][r2].valor=1;	
					}
					//flag pra n deixar entrar aqui infinito
					flag=1;
				}else
					//todos os outros casos normais
					if(i<qtdBranco){
						//joga os individuos "bom" em posicoes aleatorias na matriz, desde que tenha -1 la, ou seja,vazi0
						do{
							r1=rand()%10;
							r2=rand()%10;
						}while(ma[r1][r2].valor!=-1);
						ma[r1][r2].valor=1;
					}
					qtdBranco--;
			}
			//le wild gamb pra valores de % entre 0 e 10, tipo um 99=90+9;
			
	}
	
	// dps de ter colocado a % certa de individuos bons e influenciaveis, é so jogar o bad sobrou nas posicoes vazias
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)		
				if(ma[i][j].valor==-1){
						ma[i][j].valor=0;	
				}
//retorna a matriz, como eu setei ela global, nem sei se precisa, mas é nois
return ma;
}

//cidadao bom =2 cidadao ruim =0 cidadao influenciavel =1
void drawFirstM (void){
	int i,j,posx=22,posy=100,random=0;
    for(i=0;i<10;i++){
    	posy+=18;
    	for(j=0;j<10;j++){
    			posx+=18;
    			if(maInicial[i][j].valor==2)
    				desenhaCirculo(posx, posy, 360, 3, 0.3,1, 0.3);
    			else if(maInicial[i][j].valor==0)
    				desenhaCirculo(posx, posy, 360, 3, 1,0.3, 0.3);
    			else if(maInicial[i][j].valor==1)
    				desenhaCirculo(posx, posy, 360, 3, 1,1, 1);

    	}
    	posx=22;
    }		
}
// por enquanto essa aqui ta igual a inicial, mas a ideia é fazer a a evolucao da populacao nessa, e deixar a outra
// como comparacao.
void drawFinalM (void){
	int i,j,posx=270,posy=100,random=0;
    for(i=0;i<10;i++){
    	posy+=18;
    	for(j=0;j<10;j++){
    			posx+=18;
    			if(maAux[i][j].valor==2)
    				desenhaCirculo(posx, posy, 360, 3, 0.3,1, 0.3);
    			else if(maAux[i][j].valor==0)
    				desenhaCirculo(posx, posy, 360, 3, 1,0.3, 0.3);
    			else if(maAux[i][j].valor==1)
    				desenhaCirculo(posx, posy, 360, 3, 1,1, 1);

    	}
    	posx=270;
    }		
}

void copiaMatriz(){
	for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                 maInicial[i][j].valor =ma[i][j].valor;
                 //for(int k=0;k<8;k++)
                 	//ma[i][j].valor=1;
            }
        }
}
void copiaAuxFinal(){
	for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                 ma[i][j].valor =maAux[i][j].valor;
                 //for(int k=0;k<8;k++)
                 	//ma[i][j].valor=1;
            }
        }
}
