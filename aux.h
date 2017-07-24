
void copiaMatriz(){
	for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                 maInicial[i][j].valor =ma[i][j].valor;
                 //for(int k=0;k<8;k++)
                 	//ma[i][j].valor=1;
            }
        }
}
void copiaAuxFinal(){
	for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                 ma[i][j].valor =maAux[i][j].valor;
                 //for(int k=0;k<8;k++)
                 	//ma[i][j].valor=1;
            }
        }
}
void copiaAuxFinal50(){
    for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                 ma1[i][j].valor =maAux[i][j].valor;
                 //for(int k=0;k<8;k++)
                    //ma[i][j].valor=1;
            }
        }
}
void copiaAuxFinal80(){
    for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                 ma2[i][j].valor =maAux[i][j].valor;
                 //for(int k=0;k<8;k++)
                    //ma[i][j].valor=1;
            }
        }
}
