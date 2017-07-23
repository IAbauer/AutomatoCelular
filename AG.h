#include "var.h"
#include "automatos.h"

int numIndividuos = pow(TAM_MATRIZ,2);


//Funcao para calcular a aptidao da populacao
float calculaAptidao(individuo **mat, float pct){

	//Calcula a quantidade de individuos bons
	float qtdBons = numIndividuos*(pct/100);

	float aptidao = 0;

	//Se bons forem maioria (aptidao ALTA)
	if(pct >= 55){
		aptidao = (bons/numIndividuos);
	}
	//Se nao houver maioria clara
	else if(pct >45 && pct < 55){
		aptidao = 1- abs( ((2*bons)/numIndividuos) - 1);
	}

	//Se bons forem minoria (aptidao BAIXA)
	else if(pct <= 45){
		aptidao = 1 - (bons/numIndividuos);
	}
}


void defineAtivacaoVizinhos(){

}