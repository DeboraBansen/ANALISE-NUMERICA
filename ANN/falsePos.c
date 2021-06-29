#include <stdio.h>
#include<math.h>
double f(double x){
	return (x*x*x)-5;
}

void false_position(double (*f)(double),double a, double b, double tol,int n){
	if(f(a)*f(b)<0){
		int i;
		for(i=0;i<n;i++){
			double fa=f(a);
			double fb=f(b);
			double c;
			c=(a*fb-b*fa)/(fb-fa);
			if(f(c)==0){
				printf("voce encontrou ima raiz para f. Ela e: %.16f",c);
				return;
			}
		/*	if(abs(f(c))<tol){
				printf("O numero %.16f esta perto o suficiente da raiz");
				return;
			}*/
			printf("x_%d = %.15f\n",i+1,c);
			if(fa*f(c)<0){
				b=c;
			}else{
				a=c;
			}
		}
	}else{
		printf("Oi! sou o bolzano. O intervalo[%.16f, %.16f] nao serve",a,b);
	}
}

int main(){
	double a=0.31057;
	double b=2.3736;
	int max_iter=4;
	double tol=0.00000000001;
	
	false_position(f,a,b,tol,max_iter);
}
