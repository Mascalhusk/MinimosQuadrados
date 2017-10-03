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

void coef(double *x, double *y)
{	int i;
	double a0, a1, somax, somay, somax2, somaxy;
	
	somax=somax2=somay=somaxy=0;
	printf("Os Resultados são:\n");
	for(i=0; i<tam; i++)
	{	
		somax=somax + x[i];
		somax2=somax2 + pow(x[i], 2);
		somay=somay + y[i];
		somaxy=somaxy + x[i]*y[i];
		
	}
	printf("Soma X = %lf, Soma X² = %lf ,Soma Y = %lf , Soma XY = %lf \n", somax, somax2, somay,somaxy);
	
	a0=(somax2*somay - somaxy*somax)/(tam*somax2 -pow(somax, 2));
	a1=(tam*somaxy - somax*somay)/(tam*somax2 -pow(somax, 2));
	printf("Os coeficientes são:\n A0 = %lf, A1 = %lf \n", a0, a1);
	
}

int main(int argc, char *argv[])
{	int i;
 	double x[tam], y[tam];
 	
 	FILE *leitura;
 	leitura = fopen(argv[1],"r");
 	
    ler(x, y,leitura);
 	printf ("\nOs dados fornecidos são:\n");
 	imprime(x, y);
 	coef(x, y);
 	
}
