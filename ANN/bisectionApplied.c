#include <stdio.h>
#include <math.h>
double f(double x){
	return ((double)9.81*70.85/(double)x)*(1-exp(-((double)x/(double)70.85)*9.26))-55.18;
}

void bisection(double (*f)(double),double a,double b,int n){
	if(f(a)*f(b)<0){
		double m=0;
		int i;
	    for(i=0;i<n;i++){
			m=(a+b)/2;
			if(f(m)==0){
				printf("A raiz procurada é %.14f\n",m);
				return;
			}
			printf("x_%d = %.14f\n",i+1,m);
			if(f(a)*f(m)<0){
				b=m;
			}else{
				a=m;
			}
     	}
    }else{
    	printf("O Teorema de Bolzano nada sabe dizer se existe raiz para esse intervalo");
	}
}

int main(){
	int max_iter=10;
	double a=1;
	double b=100;
	
	bisection(f,a,b,max_iter);
}
