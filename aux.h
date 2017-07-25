
individuo **copiaMatriz(individuo **maInicial, individuo **ma){
	for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                 maInicial[i][j].valor =ma[i][j].valor;
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

void criaLog(individuo **ma, individuo **maIndividuo, char *nome){
	
	int i,j,k;
    FILE* file = fopen(nome,"w");
	if(file){
		for(i=0; i<TAM_MATRIZ; i++){
			fprintf(file,"\n");
			for(j=0; j<TAM_MATRIZ; j++){
				float apt = calculaAptidao(ma[i][j],ma);
                ma[i][j].aptidao = apt;
                maIndividuo[i][j].aptidao += apt;
				fprintf(file,"%.3f, ",apt);
			}
		}
	}
	fclose(file);
}	