#include <stdio.h>
#include <math.h>

double f(double x){
	return (x*x*x)-5;
}

double df(double x){
	return 3*pow(x,2);
}

void newton(double (*f)(double),double (*df)(double), double x0,int n){
	int i;
	for(i=0;i<n;i++){
		double xn;
		xn=x0-f(x0)/df(x0);
		x0=xn;
		printf("x_%d = %.16f\n",i+1,xn);
	}
}

int main(){
	int max_iter=4;
	double x0=2.02175;
	
	newton(f,df,x0,max_iter);
}
