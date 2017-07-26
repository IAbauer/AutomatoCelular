
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
double fncAleatorios_AleatorioRealEntre_0_e_1() {
	
	return((double) rand()/RAND_MAX);
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

individuo **geraFormacaoIndividuo(individuo **pop){
	int i,k,count;

	//Percore os individuos
	for(i=0;i<TAM_POP;i++){
		do{
			count = 0;

			//Faz a ativação dos vizinhos
			for(k = 0; k< NUM_VIZINHOS; k++){ 
				pop[flag_Pop][i].vizinhos[k] = rand()%2;
				if(pop[flag_Pop][i].vizinhos[k] == 1) count++;
			}

		//Garante que pelo menos 3 dos 8 vizinhos estarão ativos
		}while(count >= 3);

		//Define a formula de mudanca de estado do individuo
		pop[flag_Pop][i].formula = rand()%3;

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

void normalizaAptidao(individuo **pop){

	int i;

	for(i=0; i<TAM_POP; i++){		
			pop[flag_Pop][i].aptidao = pop[flag_Pop][i].aptidao/3.0;
	}
}

void calculaAptidaoPopulacao(individuo **pop, individuo **mIndividuo, individuo **mAux, individuo **m, individuo **m1, individuo **m2){

	for(int i=0;i<TAM_POP;i++){
		geraMatrizIndividuo(mIndividuo,pop[flag_Pop][i]);
		for(int j = 0;j<3;j++){
			//Numero baixo de bons
			if(j==0){

				copiaMatriz(m,mIndividuo);
				iniciPMatriz(20,m);
				for (int k = 0; k<NUM_ITERACOES; k++) m = executaAlgortimoAutomato(m, mAux);
				float qtdBons = calculaIndividuosBons(m);
				float apt = (1-(qtdBons/numIndividuos));
				pop[flag_Pop][i].aptidao += apt;
			}
			//populacao bem dividida
			else if(j==1){

				copiaMatriz(m1,mIndividuo);
				iniciPMatriz(50,m1);
				for (int k = 0; k<NUM_ITERACOES; k++) m1 = executaAlgortimoAutomato(m1, mAux);
				float qtdBons = calculaIndividuosBons(m1);
				float modulo = (2*qtdBons/numIndividuos) - 1;
				if (modulo <0) modulo = -modulo;
				float apt = 1 - modulo;
				pop[flag_Pop][i].aptidao += apt;
			}
			//Numero alto de bons
			else if(j==2){

				copiaMatriz(m2,mIndividuo);
				iniciPMatriz(80,m2);
				for (int k = 0; k<NUM_ITERACOES; k++) m2 = executaAlgortimoAutomato(m2, mAux);
				float qtdBons = calculaIndividuosBons(m2);
				float apt = qtdBons/numIndividuos;
				pop[flag_Pop][i].aptidao += apt;
			}

		}
	}
	normalizaAptidao(pop);
}

void QuicksortDecrescente(individuo **populacao, long int esq, long int dir) {
	long int i, j;
	float x;
	individuo aux_Ind;
	bool flag_Break;
	
	i = esq;
	j = dir;
	x = populacao[flag_Pop][(esq + dir) / 2].aptidao;
	
	do {
		flag_Break = false;
		while ((!flag_Break) && (i < dir)) {
			if (x < populacao[flag_Pop][i].aptidao) {
				i++;
			}
			else {
				flag_Break = true;
			}
		}
		flag_Break = false;
		while ((!flag_Break) && (j > esq)) {
			if (x > populacao[flag_Pop][j].aptidao) {
				j--;
			}
			else {
				flag_Break = true;
			}
		}
		if (i <= j) {
			aux_Ind = populacao[flag_Pop][i];
			populacao[flag_Pop][i] = populacao[flag_Pop][j];
			populacao[flag_Pop][j] = aux_Ind;
			
			i++;
			j--;
		}
	} while (i <= j);
	if (esq < j) {
		QuicksortDecrescente(populacao, esq, j);
	}
	if (i < dir) {
		QuicksortDecrescente(populacao, i, dir);
	}
}

void selecaoPopulacao(individuo **populacao, long int geracao) {
	long int i, g, ind1, ind2;
	long int aux_TamPop;
	
	// Ordena decrescente da populacao de individuos.
	QuicksortDecrescente(populacao,0,TAM_POP-1);
	
	// Seleciona a elite que passa pra proxima geracao sem modificacao.
	// Ou seja, copia os individuos mais aptos para a nova geracao.
	aux_TamPop = int(TAM_POP * 0.1);
	for (i=0; i<aux_TamPop; i++) {
		for (g=0; g<NUM_VIZINHOS; g++) {
			populacao[!flag_Pop][i].vizinhos[g] = populacao[flag_Pop][i].vizinhos[g];
		}
		populacao[!flag_Pop][i].formula = populacao[flag_Pop][i].formula;
		populacao[!flag_Pop][i].geracao = populacao[flag_Pop][i].geracao;
		populacao[!flag_Pop][i].aptidao = populacao[flag_Pop][i].aptidao;
	}
	
	// Ate formar a nova geracao realiza a roleta.
	while (aux_TamPop < TAM_POP) {
		// Captura dois individuos na roleta com Normalizacao Linear.
		ind1 = fncAG_SelecionaIndividuoPelaRoletaComNormalizacaoLinear(TAM_POP);
		ind2 = fncAG_SelecionaIndividuoPelaRoletaComNormalizacaoLinear(TAM_POP);
		
		// Crossover e Mutacao
		if (aux_TamPop < (TAM_POP-1)) { // Se faltam 2 ou mais individuos para serem gerados.
			// Realiza o crossover
			CrossOver(populacao,ind1, ind2, aux_TamPop, (aux_TamPop+1));
			
			// Realiza a mutacao nos novos individuos.
			Mutacao(populacao,aux_TamPop);
			Mutacao(populacao,aux_TamPop+1);
			
			populacao[!flag_Pop][aux_TamPop].geracao = geracao;
			populacao[!flag_Pop][aux_TamPop].aptidao = APTDINICIAL;
			aux_TamPop++;
			
			populacao[!flag_Pop][aux_TamPop].geracao = geracao;
			populacao[!flag_Pop][aux_TamPop].aptidao = APTDINICIAL;
			aux_TamPop++;
		}
		else { // Caso falte somente um individuo para ser gerado
			// Realiza o crossover
			CrossOver(populacao,ind1, ind2, aux_TamPop, -1);
			
			// Realiza a mutacao no novo individuo.
			Mutacao(populacao,aux_TamPop);
			
			populacao[!flag_Pop][aux_TamPop].geracao = geracao;
			populacao[!flag_Pop][aux_TamPop].aptidao = APTDINICIAL;
			aux_TamPop++;
		}
	}
	
	flag_Pop = !flag_Pop;
}

void CrossOver(individuo **pop, int pai1,int pai2, int filho1, int filho2){

		// Copia os vizinhos que ficam antes do ponto de corte.
		pop[!flag_Pop][filho1].formula = pop[!flag_Pop][pai1].formula;
		if(filho2 != -1) pop[!flag_Pop][filho2].formula = pop[!flag_Pop][pai2].formula;
		for( int i =0 ; i < NUM_VIZINHOS ; i++){
			pop[!flag_Pop][filho1].vizinhos[i] = pop[!flag_Pop][pai2].vizinhos[i];
			if(filho2 != -1) pop[!flag_Pop][filho2].vizinhos[i] = pop[!flag_Pop][pai1].vizinhos[i];
		}
}
		

	

void Mutacao(individuo **pop, int filho){
	int g, novo, mutacao, chance;

	mutacao=rand()%10;
	chance=rand()%100;

	g=rand()%NUM_VIZINHOS;

	// 
	if(chance < 1){
		if(mutacao <= 8){
			// Sorteia o novo valor do vizinho, que deve ser diferente do atual.
			do {
				novo=rand()%2;
			} while (novo == pop[!flag_Pop][filho].vizinhos[g]);
			
			// Realiza a mutacao do vizinho.
			pop[!flag_Pop][filho].vizinhos[g] = novo;

		}else if(mutacao > 8){
			// Sorteia a nova formula do individuo
			do {
				novo=rand()%3;
			} while (novo == pop[!flag_Pop][filho].formula);
			
			// Realiza a mutacao da formula.
			pop[!flag_Pop][filho].formula = novo;
				
		}
	}
}

// Rotina do AG
void executaAlgoritmoGenetico(individuo **pop, individuo **mIndividuo, individuo **mAux, individuo **m, individuo **m1, individuo **m2){

	for(int i=0;i<NUM_GERACOES;i++){
		//Calcula a aptidao da geracao atual
		calculaAptidaoPopulacao(pop,maIndividuo,maAux,ma,ma1,ma2);

		//Selecao dos pais para gerar os filhos da prox geracao
		selecaoPopulacao(pop, i );

	}

	//Calcular a aptidao da ultima geracao
	calculaAptidaoPopulacao(pop,maIndividuo,maAux,ma,ma1,ma2);
}