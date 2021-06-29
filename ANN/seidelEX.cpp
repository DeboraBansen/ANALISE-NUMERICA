#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **alocarMatriz(int n);
double *alocarV(int n);
void lerMatriz(int n, double **p, double *B);
void lerValoresIniciais(int n, double *k);
void Calcular(int n, double **m, double *b, double *kant, double *k);
void imprimeCabecalho(int n);
void imprimeIteracao(int n, double *k, double *kant, int i);
double maiorParada(int n, double *k, double *kant);
void imprimeResultado(int n, double *r);
void imprimeMatriz(int n, double **p);
void imprimeMatrizB(int n, double **p, double *B);
void desalocaM(int n, double **p);
void desalocaV(double *r);

//MATRIZ 3x3 DE TESTES
//  10  2  1  | 7
//   1  5  1  |-8 
//   2  3  10 | 6
// M: 10 2 1 1 5 1 2 3 10
// B: 7 -8 6
// X0: 0 0 0
// INPUT: 3 10 2 1 1 5 1 2 3 10 7 -8 6 0 0 0 0.001
//RESULTADO ESPERADO
// 1 -2 1

int main(){
	double **m, *b, *kant, *k;
	int n;
int rows=4;
	double chute[4]={-0.24231, 1.80339, -0.45671, -2.25491};
	
	double matrizb[1][4]={-1.38689, -1.88578, 0.06499, -0.44081};
	double matrix[4][4]={{6.16292, 2.11138, -2.2101, -0.2207},{-1.3606, 4.71751, -0.41424, -1.32193},{0.02409, 0.14373, 2.97293, 1.18437},{-1.00232, 2.80456, -0.82541, 6.25303}};
	m=matrix;
	k=matrix;
	int max_iter=4;
	
	printf ( " Dimensão da matriz: " );
	scanf ( " % d " , & n);

	m = alocarMatriz (4);
	b = alocarV (4);
	kant = alocarV (4);
	k = alocarV (4);

	//lerMatriz (4, m, b);
	//lerValoresIniciais (4, kant);

	Calcular (4, m, b, kant, k);

	dessalocaM (4, m);
	dessalocaV (b);
	dessalocaV (kant);
	dessalocaV (k);
}

double **alocarMatriz(int n){
	int i,j; 

	double **m = (double**) malloc(n * sizeof(double*)); // Aloca um vetor de ponteiros

	for (i = 0; i < n; i++)
		m[i] = (double*) malloc(n * sizeof(double));  // Aloca um vetor de valores double
	
	return m;
}

double *alocarV(int n){
	double *m = (double *) malloc(n * sizeof(double));
	return m;
}

void lerMatriz(int n, double **p, double *B){
	int i,j;

	printf("Valores da matriz M:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < (n); j++){
			scanf("%lf", &p[i][j]);
		}
	}

	printf("Valores da matriz B:\n");
	for(i = 0; i < n; i++){
		scanf("%lf", &B[i]);
	}
}

void Calcular(int n, double **m, double *b, double *kant, double *k){
	int i, count = 0;
	int j;
	double e;
	double sum;

	printf("Critério de parada: ");
	scanf("%lf", &e);

	imprimeCabecalho(n);
	imprimeIteracao(n,kant,kant, count++);

	//Primeira iteração
	for(i = 0; i < n; i++){
		sum = 0;
		for(j = 0; j < n; j++){
			if(i!=j)
				sum += m[i][j]*k[j];
		}
		k[i] = (b[i] - (sum)) / (m[i][i]);
	}

	imprimeIteracao(n,k,kant, count++);

	while(maiorParada(n,k,kant) >  e){

		for(i = 0; i < n; i++){//Atualiza os valores de kant
			kant[i] = k[i];
		}

		for(i = 0; i < n; i++){//Calcula as iterações e guarda os resultados em k
			sum = 0;
			for(j = 0; j < n; j++){
				if(i!=j){
					sum += m[i][j]*k[j];
				}
			}
			k[i] = (b[i] - (sum)) / (m[i][i]);
		}

		imprimeIteracao(n,k,kant,count++);

	}

	imprimeResultado(n,k);

}

void imprimeResultado(int n, double *r){
	int i;
	for(i = 0; i < n; i++){
		printf("Resultado de x%2d: %+3.3lf\n", i+1, r[i]);
	}
}


void imprimeCabecalho(int n){
	int i;
	
	printf("MÉTODO DE GAUSS-SEIDEL\n");

	printf("K\t|");

	for(i = 1; i <= n; i++){
		printf("x%02d\t|", i);
	}

	printf(" max|k - kant|\n");
}

void imprimeIteracao(int n, double *k, double *kant, int i){
	int j;
	
	printf("%02d\t|", i);

	for(j = 0; j < n; j++){
		printf("%2.3lf\t|", k[j]);
	}

	printf("   %2.4lf\n", maiorParada(n, k, kant));

}

double maiorParada(int n, double *k, double *kant){
	int i;
	double maior = fabs(k[0] - kant[0]);
	
	for(i = 0; i < n; i++){
		if(fabs(k[i]-kant[i]) > maior)
			maior = fabs(k[i]-kant[i]);
	}

	return maior;
}

void imprimeMatrizB(int n, double **p, double *B){
	int i,j;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%+3.3lf\t", p[i][j]);
		}
		printf("|\t%+3.3lf", B[i]);
		putchar('\n');
	}

	putchar('\n');
}

void lerValoresIniciais(int n, double *k){
	int i;
	printf("Valores Iniciais:\n");
	for(i = 0; i < n; i++){
		printf("x%d: ", i);
		scanf("%lf", &k[i]);
	}
}

void desalocaM(int n, double **p){
	int i;

	for(i = 0; i < n; i++){
		free(p[i]);//Desaloca vetor de números
	}

	free(p);//Desaloca vetor de ponteiros
}

void desalocaV(double *r){
	free(r);
}
