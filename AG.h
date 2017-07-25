
float numIndividuos = pow(TAM_MATRIZ,2);

int qtdIndividuosDiferentes(int ind, individuo **ma){

	int i,j;
	float qtd = 0;
	float pct = 0;
	for(i=0; i<TAM_MATRIZ; i++){
		for(j=0; j<TAM_MATRIZ; j++){
			if(ma[i][j].valor != ind) qtd++;
		}
	}

	return qtd;
}

int qtdVizinhosDiferentes(Individuo ind){

	int i,j,k;
	float qtd = 0;
	float pct = 0;

	for(k = 0; k< NUM_VIZINHOS; k++){
		if(ind.vizinhosVal[k] != ind.valor && ind.vizinhosVal[k] != -1) qtd++;
	}


	return qtd;

}

float traduzFormula(int ident){
	
	float formula;

	if(ident == 0){
		formula = 0.8;
	}
	else if(ident == 1){
		formula = 0.65;
	}
	else if(ident == 2){
		formula = 0.5;
	}

	return formula;

}

//Funcao para calcular a aptidao da populacao
float calculaAptidao(Individuo ind, individuo **ma){

	float aptidao = 0;

	float indOpostos = qtdIndividuosDiferentes(ind.valor,ma);

	float vizOpostos = qtdVizinhosDiferentes(ind);

	float formula = traduzFormula(ind.formula);

	aptidao = ((1 - formula) + ((vizOpostos/NUM_VIZINHOS)/2.0) + (indOpostos/100.0))/2.0;

	return aptidao;
}


individuo **geraFormacaoIndividuo(individuo **ma){
	int i,j,k,count;

	//Percore os individuos
	for(i=0;i<TAM_MATRIZ;i++){
		for(j=0;j<TAM_MATRIZ;j++){

			do{
				count = 0;

				//Faz a ativação dos vizinhos
				for(k = 0; k< NUM_VIZINHOS; k++){ 
					ma[i][j].vizinhos[k] = rand()%2;
					if(ma[i][j].vizinhos[k] == 1) count++;
				}

			//Garante que pelo menos 25% dos vizinhos estarão ativos
			}while(count >= 3);

			//Define a formula de mudanca de estado do individuo
			ma[i][j].formula = rand()%3;

		}
	}
    return ma;
}


void normalizaAptidao(individuo **maIndividuo){

	int i,j;

	for(i=0; i<TAM_MATRIZ; i++){
		for(j=0; j<TAM_MATRIZ; j++){
			ma[i][j].aptidao /= 3;
		}
	}
}

/*
void selecionaPopulacao(individuo **maIndividuo){
	
}

void CrossOver(individuo **maIndividuo){

}

void Mutacao(individuo **maIndividuo){

}

//Esboco da Rotina do AG
void executaAlgoritmoGenetico(individuo ** maIndividuo){
	
	normalizaAptidao(maIndividuo);

	selecionaPopulacao(maIndividuo);

	CrossOver(maIndividuo);

	Mutacao(maIndividuo);
}
*/