#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tam 10

void ler(double *x, double *y, FILE*leitura)
{	int i;
    double a, b;	 
 
 	i = 0;	
 	while(fscanf(leitura, "%lf \t %lf \t", &a, &b) != EOF) 
 	{
 		x[i] = a;	y[i] = b;	i++;	
 	}
}

void imprime(double *x, double *y)
{	int i;

	for(i=0; i<tam;i++)
	{
		printf("%lf \t %lf \n", x[i], y[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{	int i;
 	double x[tam], y[tam];
 	
 	FILE *leitura;
 	leitura = fopen(argv[1],"r");
 	
    ler(x, y,leitura);
 	printf ("\nOs dados fornecidos são:\n");
 	imprime(x, y);
}
