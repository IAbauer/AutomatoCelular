

individuo **AlocMat(int linhas, int colunas){
	// declara a variável 'x' que servirá como contador, e um ponteiro
   // para ponteiros '**v' que receberá a matriz alocada e será o
   // valor de retorno da função.
   int x; 
   individuo **mat;
   // aloca espaço para as linhas, que será vetores para vetores, por
   // isso é necessário a conversão (int **).
   mat = (individuo **)calloc(linhas, sizeof(individuo*));
   // checa se as linhas foram alocadas corretamente e caso não trenham
   // sido, aborta a execução do programa.
   if (mat == NULL) {
      printf("\nFatal Error! (function: AlocMat)\n");
      exit(1);
   }
   // percorre as linhas alocadas na matriz
   for (x = 0 ; x < linhas ; x++) {
      // em cada linha, aloca um vetor/ponteiro para inteiros
      // com tamanho definido pelo usuário
      mat[x] = (individuo *)calloc(colunas, sizeof(individuo));
      // checa se o vetor/ponteiro foi alocado corretamente, caso não
      // tenha sido, aborta a execução do programa
      if (mat[x] == NULL) {
         printf("\nFatal Error! (function: AlocMat)\n");
         exit(1);
      }
   }
   // retorna o ponteiro de ponteiros(matriz).
   return mat;
}


int **FreeMat(int linhas, int colunas, int **mat) {
   // variável 'x' que servirá como contador.
   int x;
   // checa se os argumentos passados são válidos e caso não sejam,
   // a execução do programa é abortada.
   if ((linhas < 1) || (colunas < 1)) {
      printf("\nFatal Error! (function: FreeMat)\n");
      exit(1);
   }
   // se a matriz passada como parâmetro for NULL, então a função
   // retorna NULL.
   if (mat == NULL) return NULL;
   // percorre as linhas da matriz, liberando o espaço das 
   // colunas(vetores/ponteiros) em cada linha.
   for (x = 0 ; x < linhas ; x++) free(mat[x]);
   // libera a matriz em si.
   free(mat);
   // retorna NULL.
   return NULL;   
}
