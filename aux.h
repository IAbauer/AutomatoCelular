
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

void criaLog(individuo **ma, char *nome){
	
	int i,j,k;
    FILE* file = fopen(nome,"w");
	if(file){
		for(i=0; i<TAM_MATRIZ; i++){
			fprintf(file,"\n");
			for(j=0; j<TAM_MATRIZ; j++){
				float apt = calculaAptidao(ma[i][j],ma);
				fprintf(file,"%.3f, ",apt);
			}
		}
	}
	fclose(file);
}	