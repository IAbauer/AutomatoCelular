#include "automatos.h"
#include "var.h"

int main (){

	int n;

	//Alocacao das Matrizes
	individuo ma = AlocMat(TAM_MATRIZ);
	individuo maAux  = AlocMat(TAM_MATRIZ)

	//Obter a % de individuos bons
	//scanf("",n);

	//Inicializar a matriz principal
	ma = iniciPMatriz(n)

	//Essa eh a matriz inicial do problema, ela nunca serah mudada
	maInicial = ma;

	executaAlgortimo(ma,maAux);
}

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
		calculaInfluencia(ma);

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
				for(l = i-1;l<i+1){
					for(m = j-1;m<j+1){
						ma.individuo[i][j].vizinhosVal[k] = ma.individuo[l][m].valor;
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
				if(ma.individuo[i][j].vizinhos[k] == 1){
					ativos++;
					//Se vizinho for bom incrementa a var bom
					if(ma.individuo[i][j].vizinhosVal[k] == 2) bom++;

					//Se vizinho for ruim incrementa a var ruim
					if(ma.individuo[i][j].vizinhosVal[k] == 0) ruim++
				}
			}

			//Calcular o novo valor do individuo na matriz auxiliar

			//Se a maiora é bom e correponde a mais que 50% dos vizinhos ativos
			if(bom > ruim && bom >= int(ativos/2)){

				//Se o individuo era ruim, vira influenciavel
				if(ma.individuo[i][j] == 0) maAux.individuo[i][j] = 1;

				//Se o individuo era influenciavel, vira bom
				if(ma.individuo[i][j] == 1) maAux.individuo[i][j] = 2;
			}

			//Se a maiora é ruim e correponde a mais que 50% dos vizinhos ativos
			if(ruim > bom && ruim >= int(ativos/2)){

				//Se o individuo era bom, vira influenciavel
				if(ma.individuo[i][j] == 2) maAux.individuo[i][j] = 1;

				//Se o individuo era influenciavel, vira ruim
				if(ma.individuo[i][j] == 1) maAux.individuo[i][j] = 0;

			}

		}
	}	
}