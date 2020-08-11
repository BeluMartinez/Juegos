#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool busqueda(int a);

main()
{
	int A,n,c;
	
	srand(time(NULL));
	A=(rand()%999);
	
	if(busqueda(A))
	printf("\nAcertaste! Puntaje obtenido: %d", c-1);
	else
	printf("\nEl numero secreto era %d", A);
	
}

bool busqueda(int a)
{
	int c=0,n;
	for(int i=0;i<10;i++)
	{
		printf("\nIntento %d:", i+1);
		scanf("%d",&n);
		if(a==n)
		{
		return true;
		}
		
		if(n<a)
		printf("El numero secreto es mayor y se encuentra entre %d y %d", n+1,999 );
		else
		printf("El numero secreto es menor y se encuentra entre %d y %d", 0, n-1);
		
		
		c++;
	}
	return false;
}
