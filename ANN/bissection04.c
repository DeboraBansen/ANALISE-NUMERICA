#include <stdio.h>
#include <math.h>
double f(double x){
	return 1-((pow(159.86,2)/(9.81*pow((8.47*x+(pow(x,2)/2)),3)))*(8.47+x));
}

void bisection(double (*f)(double),double a,double b,int n){
	if(f(a)*f(b)<0){
		double m=0;
		int i;
	    for(i=0;i<n;i++){
			m=(a+b)/2;
			if(f(m)==0){
				printf("A raiz procurada � %.14f\n",m);
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
	double a=0.1;
	double b=8;
	
	bisection(f,a,b,max_iter);
}
