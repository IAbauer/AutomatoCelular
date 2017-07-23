
//Exemplo Rotina
void executaAlgortimo(){

	int i;

	//Inicia Algoritimo
	for(i = 0; i<NUM_ITERACOES; i++){

		//Atribuir os vizinhos
		//armazenaVizinhos();

		//Definir ativacao dos vizinhos (AG)
		//???
		ativacaoTeste();

		//Calcular a Influencia
		calculaInfluencia();

		//Atribuir a matriz resultado para a matriz principal
		copiaAuxFinal();
		//memcpy ( ma , maAux , sizeof ( ma ) );
	}
}
void ativacaoTeste(){
		int i,j,random,flag=0;		
		for(i=0;i<TAM_MATRIZ;i++)
			for(j=0;j<TAM_MATRIZ;j++){				
				if(flag<3){
					//do{
						random=rand()%8;
					//}while(ma[i][j].vizinhosVal[random]!=0);
					flag++;
					ma[i][j].vizinhosVal[random]=1;
				}
			}
		for ( i = 0 ; i < 10 ; i++) {
      			for (j = 0 ; j < 10 ; j++) {
         			//printf("valor do indiviuo = %f\n",matriz[i][j].valor);
         			for(int k=0;k<8;k++){
         				if(ma[i][j].vizinhosVal[k]!=0)
         					printf("\n individuo %i tem valor de vizinho %i =%i\n",j,k,ma[i][j].vizinhosVal[k]);
         			}
         		}
      	}
  		


}

//Nao trata os individuos das bordas
void armazenaVizinhos(){
	int i,j,k,l,m;

	//Percorre cada individuo
	for(i = 0; i < TAM_MATRIZ; i++){
		for(j = 0; j < TAM_MATRIZ; j++){
			//Percorre todos os vizinhos guardando o valor
			for(k = 0; k< NUM_VIZINHOS; k++){
				for(l = i-1;l<i+1;l++){
					for(m = j-1;m<j+1;m++){
						ma[i][j].vizinhosVal[k] = ma[l][m].valor;
					}
				}
			}
		}
	}
	
}


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
				if(ma[i][j].vizinhos[k] == 1){
					ativos++;
					//Se vizinho for bom incrementa a var bom
					if(ma[i][j].vizinhosVal[k] == 2) bom++;

					//Se vizinho for ruim incrementa a var ruim
					if(ma[i][j].vizinhosVal[k] == 0) ruim++;
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