#include <stdio.h>
#include <math.h>

double f(double x){
	return (x*x*x)-5;
}

void secant(double (*f)(double),double x0,double x1,int n){
	int i;
	for(i=0;i<n;i++){
		double fx0=f(x0);
		double fx1=f(x1);
		if(fx0==fx1){
			printf("Divisao por zero");
			return;
		}
		double x2;
		x2=(x0*fx1-x1*fx0)/(fx1-fx0);
		x0=x1;
		x1=x2;
		printf("x_%d = %.16f\n",i+2,x2);
	}
}

int main(){
	double x0=2.02675;
	double x1=2.6423;
	int max_iter=4;
	secant(f,x0,x1,max_iter);
}
