#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jugar1(int min, int max, int A, int B);
void jugar2(int min, int max, int A, int B);

main(){
	int min, max, A, B, cant, comp;
	
	printf("\nCantidad minima de monedas para sacar: ");
	scanf("%d", &min);
	printf("\nCantidad maxima de monedas para sacar: ");
	scanf("%d", &max);
	
	
	srand(time(NULL));
	A=(rand()%50+10);
	printf("\nCantidad inicial de monedas que tendra la pila: %d\n\n", A);
	
	system("\npause");
	system("cls");
	
	{
	srand(time(NULL));
	B=(rand()%2+1);
	if(B=1){
	printf("\nComienza primero el usuario");
	jugar1(min,max,A,B);
	}else{
	printf("\nComienza primero la computadora");
	jugar2(min,max,A,B);
	}
	}
	
};

void jugar1(int min, int max, int A, int B){
	int a, cant;
	a=A;
	do{
		{
		do{
		printf("\nIngrese la cantidad de monedas a eliminar: ");
		scanf("%d", &cant);
		}while(cant<=min || cant>=max);
		a=a-cant;
		printf("\nQuedan %d monedas", a);
		}
		
		if(a<min)
		printf("\n\nLa computadora gano!! Puntaje obtenido = 0");
		
		{
		srand(time(NULL));
		cant=(rand()%max,min);
		printf("\nLa computadora saco %d monedas", cant);
		a=a-cant;
		printf("\nQuedan %d monedas", a);
		}
		
		if(a<min)
		printf("\n\nEl usuario gano!! Puntaje obtenido = 5");
		
	}while(B=1 && a>0);	
	
};

void jugar2(int min, int max, int A, int B){
	int a, cant;
	a=A;
	do{
		{
		srand(time(NULL));
		cant=(rand()%max,min);
		printf("\nLa computadora saco %d monedas", cant);
		a=a-cant;
		printf("\nQuedan %d monedas", a);
		}
		
		if(a<min)
		printf("\nEl usuario gano!! Puntaje obtenido = 5");
		
		{
		do{
		printf("\nIngrese la cantidad de monedas a eliminar: ");
		scanf("%d", &cant);
		}while(cant<=min || cant>=max);
		
		a=a-cant;
		printf("\nQuedan %d monedas", a);
		}
		
		if(a<min)
		printf("\nLa computadora gano!! Puntaje obtenido = 0");
		
	}while(B=1 && a>0);	
	
};
