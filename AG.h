
float numIndividuos = pow(TAM_MATRIZ,2);

int calculaIndividuosBons(individuo **ma){

	int i,j;
	float qtd = 0;
	float pct = 0;
	for(i=0; i<TAM_MATRIZ; i++){
		for(j=0; j<TAM_MATRIZ; j++){
			if(ma[i][j].valor == 2) qtd++;
		}
	}

	return qtd;
}

individuo *geraFormacaoIndividuo(individuo *pop){
	int i,k,count;

	//Percore os individuos
	for(i=0;i<TAM_POP;i++){
		do{
			count = 0;

			//Faz a ativação dos vizinhos
			for(k = 0; k< NUM_VIZINHOS; k++){ 
				pop[i].vizinhos[k] = rand()%2;
				if(pop[i].vizinhos[k] == 1) count++;
			}

		//Garante que pelo menos 3 dos 8 vizinhos estarão ativos
		}while(count >= 3);

		//Define a formula de mudanca de estado do individuo
		pop[i].formula = rand()%3;

	}
    return pop;
}

individuo **geraMatrizIndividuo(individuo **ma, individuo pop){

	int i, j, k;

	for(i=0;i<TAM_MATRIZ;i++){
		for(j=0;j<TAM_MATRIZ;j++){
			ma[i][j] = pop;
		}
	}

	return ma;
}

void normalizaAptidao(individuo *pop){

	int i;

	for(i=0; i<TAM_POP; i++){		
			pop[i].aptidao = pop[i].aptidao/3.0;
	}
}

void calculaAptidaoPopulacao(individuo *pop, individuo **mIndividuo, individuo **mAux, individuo **m, individuo **m1, individuo **m2){

	for(int i=0;i<TAM_POP;i++){
		geraMatrizIndividuo(mIndividuo,pop[i]);
		for(int j = 0;j<3;j++){
			//Numero baixo de bons
			if(j==0){

				copiaMatriz(m,mIndividuo);
				iniciPMatriz(20,m);
				for (int k = 0; k<NUM_ITERACOES; k++) m = executaAlgortimoAutomato(m, mAux);
				float qtdBons = calculaIndividuosBons(m);
				printf("it(%d):%f\n",j,qtdBons);
				float apt = (1-(qtdBons/numIndividuos));
				pop[i].aptidao += apt;
				printf("ind[%d]:%f\n",i,apt);
			}
			//populacao bem dividida
			else if(j==1){

				copiaMatriz(m1,mIndividuo);
				iniciPMatriz(50,m1);
				for (int k = 0; k<NUM_ITERACOES; k++) m1 = executaAlgortimoAutomato(m1, mAux);
				float qtdBons = calculaIndividuosBons(m1);
				printf("it(%d):%f\n",j,qtdBons);
				float modulo = (2*qtdBons/numIndividuos) - 1;
				if (modulo <0) modulo = -modulo;
				float apt = 1 - modulo;
				pop[i].aptidao += apt;

				printf("ind[%d]:%f\n",i,apt);
			}
			//Numero alto de bons
			else if(j==2){

				copiaMatriz(m2,mIndividuo);
				iniciPMatriz(80,m2);
				for (int k = 0; k<NUM_ITERACOES; k++) m2 = executaAlgortimoAutomato(m2, mAux);
				float qtdBons = calculaIndividuosBons(m2);
				printf("it[%d]:%f\n",j,qtdBons);
				float apt = qtdBons/numIndividuos;
				pop[i].aptidao += apt;

				printf("ind(%d):%f\n",i,apt);
			}

		}

		normalizaAptidao(pop);
		printf("ind[%d]:normalizado%f\n",i,pop[i].aptidao);
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
	
	calculaAptidaoPopulacao();

	selecionaPopulacao(maIndividuo);

	CrossOver(maIndividuo);

	Mutacao(maIndividuo);
}
*/