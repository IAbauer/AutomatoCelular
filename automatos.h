
//Exemplo Rotina
void executaAlgortimo(individuo **ma, individuo **maAux){

	int i;

	//Inicia Algoritimo
	for(i = 0; i<NUM_ITERACOES; i++){

		//Atribuir os vizinhos
		armazenaVizinhos(ma);

		//Definir ativacao dos vizinhos (AG)
		//???

		//Calcular a Influencia
		calculaInfluencia(ma,maAux);

		//Atribuir a matriz resultado para a matriz principal
		ma = maAux;
	}
}


//Nao trata os individuos das bordas
void armazenaVizinhos(individuo **ma){
	int i,j,k,l,m;

	//Percorre cada individuo
	for(i = 0; i < TAM_MATRIZ; i++){
		for(j = 0; j < TAM_MATRIZ; j++){
			//Percorre todos os vizinhos guardando o valor
			for(k = 0; k< NUM_VIZINHOS; k++){
				for(l = i-1;l<i+1;l++){
					for(m = j-1;m<j+1;m++){
						ma[i][j].vizinhosVal[k].valor = ma[l][m].valor;
					}
				}
			}
		}
	}
	
}


 void calculaInfluencia(individuo **ma, individuo **maAux){
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
				if(ma[i][j].vizinhos[k].valor == 1){
					ativos++;
					//Se vizinho for bom incrementa a var bom
					if(ma[i][j].vizinhosVal[k].valor == 2) bom++;

					//Se vizinho for ruim incrementa a var ruim
					if(ma[i][j].vizinhosVal[k].valor == 0) ruim++;
				}
			}

			//Calcular o novo valor do individuo na matriz auxiliar

			//Se a maiora é bom e correponde a mais que 50% dos vizinhos ativos
			if(bom > ruim && bom >= int(ativos/2)){

				//Se o individuo era ruim, vira influenciavel
				if(ma[i][j].valor == 0) maAux[i][j].valor = 1;

				//Se o individuo era influenciavel, vira bom
				if(ma[i][j].valor == 1) maAux[i][j].valor = 2;
			}

			//Se a maiora é ruim e correponde a mais que 50% dos vizinhos ativos
			if(ruim > bom && ruim >= int(ativos/2)){

				//Se o individuo era bom, vira influenciavel
				if(ma[i][j].valor == 2) maAux[i][j].valor = 1;

				//Se o individuo era influenciavel, vira ruim
				if(ma[i][j].valor == 1) maAux[i][j].valor = 0;

			}

		}
	}	
}