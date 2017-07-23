#include "AG.h"
//Exemplo Rotina
void executaAlgortimo(){

	int i;
	
	//Inicia Algoritimo
	//for(i = 0; i<NUM_ITERACOES;i++){

		//Atribuir os vizinhos
		armazenaVizinhos();

		//Definir ativacao dos vizinhos (AG)
		//defineAtivacaoVizinhos();
		//ativacaoTeste();

		//Calcular a Influencia
		calculaInfluencia();

		//Atribuir a matriz resultado para a matriz principal
		copiaAuxFinal();
		//memcpy ( ma , maAux , sizeof ( ma ) );

    	float aptPop  = calculaAptidao(ma);
    	printf("Aptidao da populacao:%f\n",aptPop);

		glutPostRedisplay();
		
	
	//}
}

void ativacaoTeste(){
		int i,j,k,random,count,flag=0;
				
		for(i=0;i<TAM_MATRIZ;i++){
			for(j=0;j<TAM_MATRIZ;j++){
				do{
					count = 0;
					for(k = 0; k< NUM_VIZINHOS; k++){ 
						ma[i][j].vizinhos[k] = rand()%2;
						if(ma[i][j].vizinhos[k] == 1) count++;
					}

				}while(count >= (NUM_VIZINHOS/4));
				/*		
				if(flag<3){
					//do{
						random=rand()%8;
					//}while(ma[i][j].vizinhosVal[random]!=0);
					flag++;
					ma[i][j].vizinhos[random]=1;
				
				}
				*/
			}
		}
		/*
		for ( i = 0 ; i < TAM_MATRIZ ; i++) {
      			for (j = 0 ; j < TAM_MATRIZ ; j++) {
         			//printf("valor do indiviuo = %f\n",matriz[i][j].valor);
         			for(int k=0;k<8;k++){
         				if(ma[i][j].vizinhosVal[k]!=0)
         					printf("\n individuo %i tem valor de vizinho %i =%i\n",j,k,ma[i][j].vizinhosVal[k]);
         			}
         		}
      	}
  		*/
}

//Funciona LISO
void armazenaVizinhos(){
	int i,j,k,l,c,n;

	//Percorre cada individuo
	for(i = 0; i < TAM_MATRIZ; i++){
		for(j = 0; j < TAM_MATRIZ; j++){

			//Inicia todos com -1
			for(k = 0; k< NUM_VIZINHOS; k++) ma[i][j].vizinhosVal[k] = -1;
			n = 0;

			//Percorre todos os vizinhos
			for(l = i-1;l<i+2;l++){
				for(c = j-1;c<j+2;c++){

					//Tratamento das bordas
					if((l>=0 && l<TAM_MATRIZ) && (c>=0  && c <TAM_MATRIZ)){

						//Ignora o proprio individuo
						if(!(l==i && c==j)){

							//Atribui o valor do vizinho
							ma[i][j].vizinhosVal[n] = ma[l][c].valor;
							//printf("individuo [%d][%d]: valorVizinho[%d](%d,%d):%d\n",i,j,n,l,c,ma[i][j].vizinhosVal[n]);
							n++;
						}
					}

				}

			}
			
		}
	}
	
}

//Funciona LISO
void calculaInfluencia(){
	int i,j,k;

	//Variaveis para controlar a quantidade de cada tipo de vizinho
	int bom, ruim;
	//Guarda o numero de vizinhos ativos de cada individuo
	int ativos;
	for(i = 0; i < TAM_MATRIZ; i++){
		for(j = 0; j < TAM_MATRIZ; j++){
			ativos = 0;
			bom = 0;
			ruim = 0;
			for(k = 0; k< NUM_VIZINHOS; k++){
				if(ma[i][j].vizinhosVal[k] != -1){
					if(ma[i][j].vizinhos[k] == 1){

						ativos++;
						//Se vizinho for bom incrementa a var bom
						if(ma[i][j].vizinhosVal[k] == 2) bom++;

						//Se vizinho for ruim incrementa a var ruim
						if(ma[i][j].vizinhosVal[k] == 0) ruim++;
					}
				}
			}
			
			//Calcular o novo valor do individuo na matriz auxiliar

			//Se a maiora é bom 
			if(bom > ruim){

				//Se o individuo era ruim
				if(ma[i][j].valor == 0){
					//Se os vizinhos bons forem GRANDE maioria, vira influenciavel
					if(float(bom/ativos) > 0.75) maAux[i][j].valor = 1;

				}
				//Se o individuo era influenciavel
				else if(ma[i][j].valor == 1){
					//Se vizinhos bons forem maioria, individuo vira bom
					if(bom > int(ativos/2)) maAux[i][j].valor = 2;
				} 

				//Se nao mudou de estado, copia o mesmo para na nova matriz
				else maAux[i][j].valor = ma[i][j].valor;
			}

			//Se a maiora é ruim
			else if(ruim > bom){

				//Se o individuo era bom
				if(ma[i][j].valor == 2){
					//Se os vizinhos ruins forem grande maioria, vira influenciavel
					if(float(ruim/ativos) > 0.75) maAux[i][j].valor = 1;
				}

				//Se o individuo era influenciavel
				else if(ma[i][j].valor == 1){
					//Se vizinhos ruins forem maioria, individuo vira ruim
					if(ruim > int(ativos/2)) maAux[i][j].valor = 0;
				}
				//Se nao mudou de estado, copia o mesmo para na nova matriz
				else maAux[i][j].valor = ma[i][j].valor;

			}
			else maAux[i][j].valor = ma[i][j].valor;

		}
	}	
}