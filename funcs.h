
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
 	escreveTitulo();
 	drawFirstM();
 	drawFinalM();
 	//glPushMatrix();
		//glTranslatef(, ,0 );
		//drawQuads(1,1,1);
	//glPopMatrix();


    glFlush();
}
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

void iniciPMatriz(int n){
	int i,j,r1,r2,r3,k,flag=0;
	float percent=0;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			ma[i][j]=-1;

	for(i=0;i<10;i++){
		percent=(10*(n/100));
		for(j=0;j<10;j++){
			if(percent<1&&flag==0){
				for(k=0;k<n;k++){
				do{
					r1=rand()%10;
					r2=rand()%10;
				}while(ma[r1][r2]!=-1);
				ma[r1][r2]=2;	
				}
				flag=1;
			}else
				if(i<percent){
					do{
						r1=rand()%10;
						r2=rand()%10;
					}while(ma[r1][r2]!=-1);
					ma[r1][r2]=2;
				}
		}
		n-=1;
	}
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)		
				if(ma[i][j]==-1){
					r3=rand()%2;
					if(r3==0)
						ma[i][j]=1;
					else if(r3==1)
						ma[i][j]=0;	
				}
}

//cidadao bom =2 cidadao ruim =0 cidadao influenciavel =1
void drawFirstM (void){
	int i,j,posx=22,posy=100,random=0;
    for(i=0;i<10;i++){
    	posy+=18;
    	for(j=0;j<10;j++){
    			posx+=18;
    			if(ma[i][j]==2)
    				desenhaCirculo(posx, posy, 360, 3, 0.3,1, 0.3);
    			else if(ma[i][j]==0)
    				desenhaCirculo(posx, posy, 360, 3, 1,0.3, 0.3);
    			else if(ma[i][j]==1)
    				desenhaCirculo(posx, posy, 360, 3, 1,1, 1);

    	}
    	posx=22;
    }		
}

void drawFinalM (void){
	int i,j,posx=270,posy=100,random=0;
    for(i=0;i<10;i++){
    	posy+=18;
    	for(j=0;j<10;j++){
    			posx+=18;
    			if(ma[i][j]==2)
    				desenhaCirculo(posx, posy, 360, 3, 0.3,1, 0.3);
    			else if(ma[i][j]==0)
    				desenhaCirculo(posx, posy, 360, 3, 1,0.3, 0.3);
    			else if(ma[i][j]==1)
    				desenhaCirculo(posx, posy, 360, 3, 1,1, 1);

    	}
    	posx=270;
    }		
}