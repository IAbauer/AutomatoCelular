//#include "AG.h"
//Exemplo Rotina
void executaAlgortimoAutomato(){

	int i;
	
	//Inicia Algoritimo

	//Atribuir os vizinhos
	armazenaVizinhos();

	//Calcular os novos estados dos individuos apos uma iteracao
	mudaEstado();

	//Atribuir a matriz resultado para a matriz principal
	copiaAuxFinal();
	//memcpy ( ma , maAux , sizeof ( ma ) );		
	
	//}
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
void mudaEstado(){
	int i,j,k;
	float pct;
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

			//Verifica qual a formula do individuo
			if(ma[i][j].formula == 0){
				pct  = 0.8;
				int estado = calculaInfluencia(ma[i][j].valor, bom, ruim, ativos, pct);
				maAux[i][j].valor = estado;
				if(estado == -1) maAux[i][j].valor = ma[i][j].valor;
			}
			else if(ma[i][j].formula == 1){
				pct  = 0.65;
				int estado = calculaInfluencia(ma[i][j].valor, bom, ruim, ativos, pct);
				maAux[i][j].valor = estado;
				if(estado == -1) maAux[i][j].valor = ma[i][j].valor;		
			}
			else if(ma[i][j].formula == 2){
				pct  = 0.5;
				int estado = calculaInfluencia(ma[i][j].valor, bom, ruim, ativos, pct);
				maAux[i][j].valor = estado;
				if(estado == -1) maAux[i][j].valor = ma[i][j].valor;			
			}
		}
	}	
}

int calculaInfluencia(int valor, int bom, int ruim, int ativos, float pct){

	//Calcula o novo valor do individuo na matriz auxiliar
	int estado;

	//Se a maiora é bom 
	if(bom > ruim){

		//Se o individuo era ruim
		if(valor == 0){
			//Se os vizinhos bons forem GRANDE maioria, vira influenciavel
			if(float(bom/ativos) > pct) estado = 1;

		}
		//Se o individuo era influenciavel
		else if(valor == 1){
			//Se vizinhos bons forem maioria, individuo vira bom
			if(float(bom/ativos) > pct) estado = 2;
		} 

		//Se nao mudou de estado, copia o mesmo para na nova matriz
		else estado = -1;
	}

	//Se a maiora é ruim
	else if(ruim > bom){

		//Se o individuo era bom
		if(valor == 2){
			//Se os vizinhos ruins forem grande maioria, vira influenciavel
			if(float(ruim/ativos) > pct) estado = 1;
		}

		//Se o individuo era influenciavel
		else if(valor == 1){
			//Se vizinhos ruins forem maioria, individuo vira ruim
			if(float(ruim/ativos) > pct) estado = 0;
		}
		//Se nao mudou de estado, copia o mesmo para na nova matriz
		else estado = -1;

	}
	//Se não houver maioria, copia o valor do individuo para a nova matriz
	else estado = -1;

	return estado;

}