
float numIndividuos = pow(TAM_MATRIZ,2);

//Calcula a porcentagem de individuos bons na matriz final
float percentBons(individuo **mat){
	int i,j;
	float qtd = 0;
	float pct = 0;
	for(i=0; i<TAM_MATRIZ; i++){
		for(j=0; j<TAM_MATRIZ; j++){
			if(mat[i][j].valor == 2) qtd++;
		}
	}
	pct = qtd/numIndividuos;

	return pct;
}

//Funcao para calcular a aptidao da populacao
float calculaAptidao(individuo **mat){

	//Calcula a quantidade de individuos bons
	float pct = percentBons(mat);
	float qtdBons = numIndividuos*pct;

	float aptidao = 0;

	//Se bons forem maioria (aptidao ALTA)
	if(pct >= 55){
		aptidao = 1 - (qtdBons/numIndividuos);
	}
	//Se nao houver maioria clara
	else if(pct >45 && pct < 55){
		aptidao = 1- abs( ((2*qtdBons)/numIndividuos) - 1);
	}

	//Se bons forem minoria (aptidao BAIXA)
	else if(pct <= 45){
		aptidao = (qtdBons/numIndividuos);
	}

	return aptidao;
}


void defineAtivacaoVizinhos(){
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
			}while(count >= (NUM_VIZINHOS/4));
		}
	}
}