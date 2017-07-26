
individuo **copiaMatriz(individuo **maInicial, individuo **ma){
	for (int i = 0 ; i < TAM_MATRIZ ; i++){
            for (int j = 0 ; j < TAM_MATRIZ ; j++){
                 maInicial[i][j] =ma[i][j];
                 //for(int k=0;k<8;k++)
                 	//ma[i][j].valor=1;
            }
        }
    return maInicial;
}

individuo **copiaMatrizIndividuo(individuo **maIndividuo, individuo **ma){
    for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                 ma[i][j] =maIndividuo[i][j];
                 //for(int k=0;k<8;k++)
                    //ma[i][j].valor=1;
            }
        }
    return ma;
}

individuo **copiaAuxFinal(individuo **maAux, individuo **ma){
	for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                 ma[i][j].valor =maAux[i][j].valor;
                 //for(int k=0;k<8;k++)
                 	//ma[i][j].valor=1;
            }
        }
    return ma;
}

void criaLog(individuo **pop){
	
	int i,j;
    FILE* file = fopen("resultadoAG.txt","w");
	if(file){
		for(i=0; i<TAM_POP; i++){
            fprintf(file,"G:%d",pop[flag_Pop][i].geracao);
            fprintf(file,"   ");
            fprintf(file,"F:%d ",pop[flag_Pop][i].formula);
            fprintf(file,"Vizinhos: ");
            for(j = 0; j< NUM_VIZINHOS; j++) fprintf(file,"%d, ",pop[!flag_Pop][i].vizinhos[j]);
			fprintf(file,"%.3f\n",pop[flag_Pop][i].aptidao);
		}
	}
	fclose(file);
}	