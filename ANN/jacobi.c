#include<stdio.h>

void jacobi(double *chute,int rows,double matrix[rows][rows+1],int n){
	double temp_arr[rows];
	int i,r,c,k;
	for(i=0;i<n;i++){
		for(r=0;r<rows;r++){
			double temp=0;
			temp+=matrix[r][rows];
			for(c=0;c<rows;c++){
				if(r!=c){
					temp-=(chute[c]*matrix[r][c]);
				}
			}
			temp/=matrix[r][r];
			printf("x_%d,%d = %.16f\n",r+1,i+1,temp);
			temp_arr[r]=temp;
		}
		printf("\n");
		for(k=0;k<rows;k++){
			chute[k]=temp_arr[k];
		}
	}
}

int main(){
	int rows=4;
	double chute[4]={-0.24231, 1.80339, -0.45671, -2.25491};
	double matrix[4][5]={{6.16292, 2.11138, -2.2101, -0.2207,-1.38689},{-1.3606, 4.71751, -0.41424, -1.32193,-1.88578},{0.02409, 0.14373, 2.97293, 1.18437,0.06499},{-1.00232, 2.80456, -0.82541, 6.25303,-0.44081}};
	int max_iter=4;
	
	jacobi(chute,rows,matrix,max_iter);
}
