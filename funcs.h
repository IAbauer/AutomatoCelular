
void init()
{
    //Selecionar cor de fundo preto
    	glClearColor( 0, 0, 0, 0.0 );
			//glClear( GL_COLOR_BUFFER_BIT );
    	//glMatrixMode( GL_PROJECTION );
    	gluOrtho2D(0,1400,0,500 );
    	
}

void display()
{

	glClear( GL_COLOR_BUFFER_BIT );
	keyOperations();
	if (zera==0){
		ma = zeraMatriz(ma);
		ma1 = zeraMatriz(ma1);
		ma2 = zeraMatriz(ma2);
		maInicial = zeraMatriz(maInicial);
		maInicial1 = zeraMatriz(maInicial1); 
		maInicial2 = zeraMatriz(maInicial2);
		zera=1;
	}
 	escreveTitulo();
 	drawFirstM(maInicial); 	
 	drawFirstM50(maInicial1);
 	drawFirstM80(maInicial2);
 	drawFinalM(ma);
 	drawFinalM50(ma1);
 	drawFinalM80(ma2);
    glFlush();
}

void keyPressed (unsigned char key, int x, int y) {
    teclas[key] = true; // altera pra true a posicao da tecla pressionada
    }
void keyUp (unsigned char key, int x, int y){
    teclas[key] = false;// altera pra false a posicao da tecla pressionada

}
void keyOperations(){
	 if(teclas['3']==true){
 		glutTimerFunc(150,Timer,0);
 	}
 	if(teclas['1']==true){
 		glutTimerFunc(150,Timer,1);
 	}
 	if(teclas['2']==true){
 		glutTimerFunc(150,Timer,2);;
 	}
 	if(teclas['4']==true){
 		glutTimerFunc(150,Timer,3);;
 	}	
 	glutPostRedisplay();

}

//Funcao utilizada para escrever tudo que se encontra no console
void escreveTitulo(void){
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(270,440,0);
		glScalef(0.6, 0.4, 0.3); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,titulo);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(370,385,0);
		glScalef(0.2, 0.12, 0.09); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,by);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,0,0);
		glTranslatef(20,20,0);
		glScalef(0.16, 0.16, 0.16); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,ruim);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(650,20,0);
		glScalef(0.16, 0.16, 0.16); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,influ);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(0,1,0);
		glTranslatef(1330,20,0);
		glScalef(0.16, 0.16, 0.16); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,bom);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(40,300,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,ini);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(500,300,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,ini);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(970,300,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,ini);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(250,300,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,final);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(720,300,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,final);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(1185,300,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,final);
	glPopMatrix();
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(90,90,0);
		glScalef(0.2, 0.1, 0.1); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,p20);
	glPopMatrix();

	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(550,90,0);
		glScalef(0.2, 0.1, 0.1); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,p50);
	glPopMatrix();
	
	glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(1025,90,0);
		glScalef(0.2, 0.1, 0.1); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,p80);
	glPopMatrix();
	

}
void tituloIni(int valor){
	if(valor==1){
		glPushMatrix();	
			glColor3f(1,1,1);
			glTranslatef(40,90,0);
			glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
			//glRotatef(15, 0,0,1); // rotaciona o texto
			glLineWidth(2); // define a espessura da linha
			DesenhaTextoStroke(GLUT_STROKE_ROMAN,p20);
		glPopMatrix();
	}else if(valor==2){
		glPushMatrix();	
			glColor3f(1,1,1);
			glTranslatef(40,90,0);
			glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
			//glRotatef(15, 0,0,1); // rotaciona o texto
			glLineWidth(2); // define a espessura da linha
			DesenhaTextoStroke(GLUT_STROKE_ROMAN,p50);
		glPopMatrix();
	}else if (valor==3){
		glPushMatrix();	
		glColor3f(1,1,1);
		glTranslatef(40,90,0);
		glScalef(0.13, 0.13, 0.13); // diminui o tamanho do fonte
		//glRotatef(15, 0,0,1); // rotaciona o texto
		glLineWidth(2); // define a espessura da linha
		DesenhaTextoStroke(GLUT_STROKE_ROMAN,p80);
	glPopMatrix();
	}
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
individuo **zeraMatriz(individuo **mt){
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			mt[i][j].valor=0;
	return mt;
}
//onde a matriz inicial é feita atravez do "random", o parametro N é a porcentagem de inimigos bons na populacao
individuo **iniciPMatriz(int n,individuo **ma){
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
void drawFirstM (individuo **maInicial){
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
void drawFirstM50 (individuo **maInicial){
	int i,j,posx=480,posy=100,random=0;
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
    	posx=480;
    }		
}
void drawFirstM80 (individuo **maInicial){
	int i,j,posx=950,posy=100,random=0;
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
    	posx=950;
    }		
}
// por enquanto essa aqui ta igual a inicial, mas a ideia é fazer a a evolucao da populacao nessa, e deixar a outra
// como comparacao.
void drawFinalM (individuo **ma){
	int i,j,posx=230,posy=100;
  
	    for(i=0;i<10;i++){
	    	posy+=18;
	    	for(j=0;j<10;j++){
	    			posx+=18;
	    			if(ma[i][j].valor==2)
	    				desenhaCirculo(posx, posy, 360, 3, 0.3,1, 0.3);
	    			else if(ma[i][j].valor==0)
	    				desenhaCirculo(posx, posy, 360, 3, 1,0.3, 0.3);
	    			else if(ma[i][j].valor==1)
	    				desenhaCirculo(posx, posy, 360, 3, 1,1, 1);

	    	}
	    	posx=230;
	    }	  
}
void drawFinalM50 (individuo **ma1){
 int posx=700,posy=100;	
	    for(int i=0;i<10;i++){
	    	posy+=18;
	    	for(int j=0;j<10;j++){
	    			posx+=18;
	    			if(ma1[i][j].valor==2)
	    				desenhaCirculo(posx, posy, 360, 3, 0.3,1, 0.3);
	    			else if(ma1[i][j].valor==0)
	    				desenhaCirculo(posx, posy, 360, 3, 1,0.3, 0.3);
	    			else if(ma1[i][j].valor==1)
	    				desenhaCirculo(posx, posy, 360, 3, 1,1, 1);

	    	}
	    	posx=700;
	    }
}
void drawFinalM80 (individuo **ma2){
 int posx=1170; 
 int posy=100;
	    for(int i=0;i<10;i++){
	    	posy+=18;
	    	for(int j=0;j<10;j++){
	    			posx+=18;
	    			if(ma2[i][j].valor==2)
	    				desenhaCirculo(posx, posy, 360, 3, 0.3,1, 0.3);
	    			else if(ma2[i][j].valor==0)
	    				desenhaCirculo(posx, posy, 360, 3, 1,0.3, 0.3);
	    			else if(ma2[i][j].valor==1)
	    				desenhaCirculo(posx, posy, 360, 3, 1,1, 1);

	    	}
	    	posx=1170;
	    }
}
int pPior=0,pMelhor=0;
void Timer(int value)
{
	if(value == 0){
		pPior = 0;
	}
	if(value == 3) pMelhor = 0;	
	else if(value == 1){
		//desenha o automato celular do pior individuo
		if(pPior==0){
			maIndividuoInicial = geraMatrizIndividuo(maIndividuoInicial, piorInd);

			maInicial = copiaMatriz(maInicial,maIndividuoInicial);
			maInicial = iniciPMatriz(20,maInicial);
			ma = copiaMatriz(ma,maInicial);

			maInicial1 = copiaMatriz(maInicial1,maIndividuoInicial);
			maInicial1 = iniciPMatriz(50,maInicial1);
			ma1 = copiaMatriz(ma1,maInicial1);

			maInicial2 = copiaMatriz(maInicial2,maIndividuoInicial);
			maInicial2 = iniciPMatriz(80,maInicial2);
			ma2 = copiaMatriz(ma2,maInicial2);

			pPior=1;

		}

		ma = executaAlgortimoAutomato(ma,maAux);
		ma1 = executaAlgortimoAutomato(ma1,maAux1);
		ma2 = executaAlgortimoAutomato(ma2,maAux2);
		if( it1<=NUM_ITERACOES){
			glutTimerFunc(100,Timer, 1);
			it1++;
		}
	}
	else if(value == 2){
		//desenha o automato celular do melhor individuo
		if(pMelhor==0){
			maIndividuoInicial = geraMatrizIndividuo(maIndividuoInicial, melhorInd);

			maInicial = copiaMatriz(maInicial,maIndividuoInicial);
			maInicial = iniciPMatriz(20,maInicial);
			ma = copiaMatriz(ma,maInicial);

			maInicial1 = copiaMatriz(maInicial1,maIndividuoInicial);
			maInicial1 = iniciPMatriz(50,maInicial1);
			ma1 = copiaMatriz(ma1,maInicial1);


			maInicial2 = copiaMatriz(maInicial2,maIndividuoInicial);
			maInicial2 = iniciPMatriz(80,maInicial2);
			ma2 = copiaMatriz(ma2,maInicial2);

			pMelhor=1;
		}
		ma = executaAlgortimoAutomato(ma,maAux);
		ma1 = executaAlgortimoAutomato(ma1,maAux1);
		ma2 = executaAlgortimoAutomato(ma2,maAux2);
		if( it2<=NUM_ITERACOES){
			glutTimerFunc(100,Timer, 2);
			it2++;
		}
	}
	glutPostRedisplay();
}