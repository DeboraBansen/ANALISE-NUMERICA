# include <stdio.h>
# include <stdlib.h>
# include <math.h>

double ** alocarMatriz ( int n);
double * alocarV ( int n);
void  lerMatriz ( int n, double ** p, double * B);
void  lerValoresIniciais ( int n, double * k);
void  Calcular ( int n, double ** m, duplo * b, duplo * kant, duplo * k);
void  imprimeCabecalho ( int n);
void  imprimeIteracao ( int n, double * k, double * kant, int i);
double  maiorParada ( int n, double * k, double * kant);
void  imprimeResultado ( int n, double * r);
void  imprimeMatriz ( int n, double ** p);
void  imprimeMatrizB ( int n, double ** p, double * B);
void  dessalocaM ( int n, double ** p);
void  dessalocaV ( double * r);

// MATRIZ 3x3 DE TESTES
//   10 2 1 | 7
//    1 5 1 | -8
//    2 3 10 | 6
// M: 10 2 1 1 5 1 2 3 10
// B: 7 -8 6
// X0: 0 0 0
// ENTRADA: 3 10 2 1 1 5 1 2 3 10 7 -8 6 0 0 0 0,001
// RESULTADO ESPERADO
// 1 -2 1

int  main () {
	duplo ** m, * b, * kant, * k;
	int n;
	
		int rows=4;
	double chute[4]={-0.24231, 1.80339, -0.45671, -2.25491};
	
	double matrizb=[1][4]={-1.38689, -1.88578, 0.06499, -0.44081};
	double matrix[4][4]={{6.16292, 2.11138, -2.2101, -0.2207},{-1.3606, 4.71751, -0.41424, -1.32193},{0.02409, 0.14373, 2.97293, 1.18437},{-1.00232, 2.80456, -0.82541, 6.25303}};
	p=matrix;
	k=matrix;
	int max_iter=4;
	
	printf ( " Dimensão da matriz: " );
	scanf ( " % d " , & n);

	m = alocarMatriz (4);
	b = alocarV (4);
	kant = alocarV (4);
	k = alocarV (4);

	lerMatriz (4, m, b);
	lerValoresIniciais (4, kant);

	Calcular (4, m, b, kant, k);

	dessalocaM (4, m);
	dessalocaV (b);
	dessalocaV (kant);
	dessalocaV (k);
}

double ** alocarMatriz ( int n) {
	int i, j;

	double ** m = ( double **) malloc (n * sizeof ( double *)); // Aloca um vetor de ponteiros

	para (i = 0 ; i <n; i ++)
		m [i] = ( duplo *) malloc (n * sizeof ( duplo ));  // Aloca um vetor de valores double
	
	return m;
}

double * alocarV ( int n) {
	double * m = ( duplo *) malloc (n * sizeof ( duplo ));
	return m;
}

void  lerMatriz ( int n, double ** p, double * B) {
	int i, j;

	printf ( " Valores da matriz M: \ n " );
	para (i = 0 ; i <n; i ++) {
		para (j = 0 ; j <(n); j ++) {
			scanf ( " % lf " , & p [i] [j]);
		}
	}

	printf ( " Valores da matriz B: \ n " );
	para (i = 0 ; i <n; i ++) {
		scanf ( " % lf " , & B [i]);
	}
}

vazio  Calcular ( int n, duplo ** m, duplo * b, duplo * kant, duplo * k) {
	int i, contagem = 0 ;
	int j;
	duplo e=4;
	soma dupla ;

	//printf ( " Critério de parada: " );
	//scanf ( " % lf " , & e);

	imprimeCabecalho (n);
	imprimeIteração (n, kant, kant, contagem ++);

	// Primeira iteração
	para (i = 0 ; i <n; i ++) {
		soma = 0 ;
		para (j = 0 ; j <n; j ++) {
			if (i! = j)
				soma + = m [i] [j] * k [j];
		}
		k [i] = (b [i] - (soma)) / (m [i] [i]);
	}

	imprimeIteração (n, k, kant, contagem ++);

	enquanto ( maiorParada (n, k, kant)> e) {

		para (i = 0 ; i <n; i ++) { // Atualiza os valores de kant
			kant [i] = k [i];
		}

		for (i = 0 ; i <n; i ++) { // Calcula as iterações e guarda os resultados em k
			soma = 0 ;
			para (j = 0 ; j <n; j ++) {
				if (i! = j) {
					soma + = m [i] [j] * k [j];
				}
			}
			k [i] = (b [i] - (soma)) / (m [i] [i]);
		}

		imprimeIteração (n, k, kant, contagem ++);

	}

	imprimeResultado (n, k);

}

void  imprimeResultado ( int n, double * r) {
	int i;
	para (i = 0 ; i <n; i ++) {
		printf ( " Resultado de x % 2d : % + 3,3lf \ n " , i + 1 , r [i]);
	}
}


void  imprimeCabecalho ( int n) {
	int i;
	
	printf ( " MÉTODO DE GAUSS-SEIDEL \ n " );

	printf ( " K \ t | " );

	para (i = 1 ; i <= n; i ++) {
		printf ( " x % 02d \ t | " , i);
	}

	printf ( " max | k - kant | \ n " );
}

void  imprimeIteracao ( int n, double * k, double * kant, int i) {
	int j;
	
	printf ( " % 02d \ t | " , i);

	para (j = 0 ; j <n; j ++) {
		printf ( " % 2.3lf \ t | " , k [j]);
	}

	printf ( "    % 2.4lf \ n " , maiorParada (n, k, kant));

}

double  maiorParada ( int n, double * k, double * kant) {
	int i;
	double maior = fabs (k [ 0 ] - kant [ 0 ]);
	
	para (i = 0 ; i <n; i ++) {
		if ( fabs (k [i] -kant [i])> maior)
			maior = fabs (k [i] -kant [i]);
	}

	return maior;
}

void  imprimeMatrizB ( int n, double ** p, double * B) {
	int i, j;

	para (i = 0 ; i <n; i ++) {
		para (j = 0 ; j <n; j ++) {
			printf ( " % + 3,3lf \ t " , p [i] [j]);
		}
		printf ( " | \ t % + 3,3lf " , B [i]);
		putchar ( ' \ n ' );
	}

	putchar ( ' \ n ' );
}

void  lerValoresIniciais ( int n, double * k) {
	int i;
	printf ( " Valores Iniciais: \ n " );
	para (i = 0 ; i <n; i ++) {
		printf ( " x % d : " , i);
		scanf ( " % lf " , & k [i]);
	}
}

void  dessalocaM ( int n, double ** p) {
	int i;

	para (i = 0 ; i <n; i ++) {
		livre (p [i]); // Desaloca vetor de números
	}

	livre (p); // Desaloca vetor de ponteiros
}

void  dessalocaV ( double * r) {
	livre (r);
}
