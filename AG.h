
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

double fncAleatorios_AleatorioReal(double low , double high) {
	
	return((fncAleatorios_AleatorioRealEntre_0_e_1() * (high - low)) + low);
}

int fncAG_SelecionaIndividuoPelaRoletaComNormalizacaoLinear(long int tam_Pop) {
	int K;
	
	// Gera um # aleatorio real.
	double num_Aleat = fncAleatorios_AleatorioReal(0.0, 1.0);
	
	// Constantes da eguacao de segundo grau.
	double a, b, c;
	
	// Procura o individuo referente ao # aleatorio gerado.
	a = fator_L - 1;
	b = (3 * fator_L) - (2 * fator_L * tam_Pop) - 1;
	c = (2 * fator_L) - (2 * fator_L * tam_Pop) + (((tam_Pop * fator_L) - fator_L + tam_Pop - 1) * tam_Pop * num_Aleat);
	
	K = (unsigned int) floor(((-b) - sqrt(pow(b,2) - (4*a*c)))/(2*a));
	
	return K + 1;
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
bool fncInd_MeuComparador(tipo_Individuo i1, tipo_Individuo i2) {
	return i1.aptidao > i2.aptidao;
}
bool fncInd_OrdenacaoDecrescenteDaPopulacaoAtual() {
	// Executa o sort do c++.
	std::sort(pop, pop+TAM_POP, fncInd_MeuComparador);
	
	return true;
}

void selecionaPopulacao(individuo **maIndividuo){
		int elite,rand1,rand2,entrou=0;
	// Ordena decrescente da populacao de individuos.
	fncInd_OrdenacaoDecrescenteDaPopulacaoAtual();
	
	// Seleciona a elite que passa pra proxima geracao sem modificacao.
	// Ou seja, copia os individuos mais aptos para a nova geracao.
	elite = int(TAM_POP * 0.5);
	if(entrou==0){
		for (int i =0; i<elite; i++) {
				for (int g=0; g<TAM_POP; g++) {
					popAUce[i].genes[g] = pop[i].vizinhos[g];
				}
				popAuce[i].geracao = pop[i].geracao;
				popAuce[i].aptidao = pop[i].aptidao;
		}
	}else if(entrou==1){
		for (int i =0; i<elite; i++) {
			for (int g=0; g<TAM_POP; g++) {
				pop[i].genes[g] = popAuce[i].vizinhos[g];
			}
			pop[i].geracao = popAuce[i].geracao;
			pop[i].aptidao = popAuce[i].aptidao;
		}
	}
	
	// Ate formar a nova geracao realiza a roleta.
	while (elite < TAM_POP) {
		// Captura dois individuos na roleta com Normalizacao Linear
		rand1 = fncAG_SelecionaIndividuoPelaRoletaComNormalizacaoLinear(TAM_POP);
		rand2 = fncAG_SelecionaIndividuoPelaRoletaComNormalizacaoLinear(TAM_POP);
		// Crossover e Mutacao
		if (elite < (TAM_POP-1)) { // Se faltam 2 ou mais individuos para serem gerados.
			
			// Realiza o crossover
			if(entrou==0)Crossover(pop[rand1], pop[rand2], popAuce[elite], popAuce[elite+1]);
			else if (entrou==1)Crossover(popAuce[rand1], popAuce[rand2], pop[elite], pop[elite+1]);
			
			// Realiza a mutacao nos novos individuos.
			Mutacao(elite,entrou);
			Mutacao(elite+1entrou);
			if(entrou==0){
				popAuce[elite].geracao = geracao;
				popAuce[elite].aptidao = APTDINICIAL;
				elite++;
				
				popAuce[elite].geracao = geracao;
				popAuce[elite].aptidao = APTDINICIAL;
				elite++;
			}else if(entrou==1){
				pop[elite].geracao = geracao;
				pop[elite].aptidao = APTDINICIAL;
				elite++;

				pop[elite].geracao = geracao;
				pop[elite].aptidao = APTDINICIAL;
				elite++;
			}
		}
		else { // Caso falte somente um individuo para ser gerado
			// Realiza o crossover
			fncAG_Crossover2cortes(ind1, ind2, aux_TamPop, -1);
			
			// Realiza a mutacao no novo individuo.
			fncAG_Mutacao(elite,entrou);
			if(entrou==0){
				popAuce[elite].geracao = geracao;
				popAuce[elite].aptidao = APTDINICIAL;
				elite++;
			}
			else if(entrou==1){
				pop[elite].geracao = geracao;
				pop[elite].aptidao = APTDINICIAL;
				elite++;
			}
		}
	}
	if(entrou==0)entrou=1;
	else if(entrou==1)=0;
}

void CrossOver(individuo pai1,invidivuo pai2, individuo filho1, individuo filho2){

		// Copia os genes que ficam antes do ponto de corte.
		filho1.formula = pai1.formula;
		filho2.formula = pai2.formula;
		for( int i =0 ; i < NUM_VIZINHOS ; i++){
			filho1.vizinhos[i] = pai2.vizinhos[i];
			filho2.vizinhos[i] = pai1.vizinhos[i];
		}
}
		

	

void Mutacao(int filho,int valor,individuo **popAuce,individuo **pop){
	int g, novo,rand,mutacao;
		mutacao = rand()%10;
	// Sorteia a escolha por realizar mutacao.
	//if (fncAleatorios_Probabilidade(0.5)) {
		// Sorteia o gene que sofrerah mutacao.
		g = rand()%NUM_VIZINHOS;
		if(mutacao<5){
		// Sorteia o novo valor do gene, que deve ser diferente do atual.
			if(valor==0){
				do {
					novo = rand()%2;
				} while (novo == popAuce[filho].vizinho[g]);
				
				// Realiza a mutacao do gene.
				popAuce[filho].genes[g] = novo;
			}else if(valor==1){
				do {
					novo = rand()%2;
				} while (novo == pop[filho].vizinhos[g]);

				// Realiza a mutacao do gene.
				pop[filho].vizinhos[g] = novo;
			}
	}else if(mutacao==5){
				if(valor==0){
				do {
					novo = rand()%3;
				} while (novo == popAuce[filho].formula);
				
				// Realiza a mutacao do gene.
				popAuce[filho].formula = novo;
			}else if(valor==1){
				do {
					novo = rand()%3;
				} while (novo == pop[filho].formula);

				// Realiza a mutacao do gene.
				pop[filho].formula = novo;
			}
	}
}

//Esboco da Rotina do AG
void executaAlgoritmoGenetico(void calculaAptidaoPopulacao(individuo *pop, individuo **mIndividuo, individuo **mAux, individuo **m, individuo **m1, individuo **m2)){

	calculaAptidaoPopulacao(pop,maIndividuo,maAux,ma,ma1,ma2);

	selecionaPopulacao(maIndividuo);

}
