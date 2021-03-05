/* ADIVINIUM
Es un juego en el que se tiene que adivinar un n�mero de 4 cifras, es decir entre 1000 y 9999. El programa escoge este n�mero al principio del partido y estar�
formado por d�gitos del 1 al 9. En el n�mero, cada d�gito aparece una vez como m�ximo.
El jugador tendr� 10 intentos, y si no lo descubre se le muestra un mensaje indicando cu�l era el n�mero que ten�a que adivinar. En cada intento el jugador ingresa
un n�mero y el programa devuelve una respuesta. Dicha respuesta consiste en indicar:
1. cu�ntos d�gitos se adivinaron en la posici�n correcta, y
2. cu�ntos d�gitos se adivinaron, pero est�n en una posici�n diferente.
Utilizando la informaci�n de las respuestas que se van dando, hay que adivinar el n�mero, en la menor cantidad de intentos posibles. No se tendr�n en cuenta 
entradas que no est�n en el rango.
Puntaje: El puntaje obtenido depende de la cantidad de intentos: si lo adivin� en el primer intento, obtiene 10 puntos, si lo acierta en el segundo obtiene 9 
puntos, y as� sucesivamente. Si no acierta, saca 0 puntos y se informa cu�l era el n�mero para adivinar.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void separar(int n, int &d1, int &d2, int &d3, int &d4);


main(){
	int i=1, n, d1, d2, d3, d4;
	int numIngresado, numSecreto, numMismaPos=0, numIgual=0;
	int n1=0, n2=0,n3=0,n4=0;
	int puntuacion=10;
	srand(time(NULL));   // Genera un numero aleatorio

	do{
		numSecreto= 1000 + rand() % (9999);
	    separar(numSecreto, d1, d2, d3, d4);   
	    
	    
	}while(d1 == d2 || d1 == d3 || d1 == d4 || d2 == d3 || d2 == d4 || d3 == d4 || d1 == 0 || d2 == 0 || d3 == 0 || d4 == 0);
	
	
	printf("*************************************************************************\n");
	printf("******************BIENVENIDOS AL JUEGO  A D I V I N U M******************\n");
	printf("*************************************************************************\n");
	system("PAUSE");
    system("CLS");
    printf("RECORDAR...\n *El numero ingresado tiene que ser de 4 cifras*");
    
    
		
	for(int i=1; i < 11; i++){
		printf("\n\nIntento numero %d => ", i);
		scanf("%d",&numIngresado);
		if(numIngresado>=1000 && numIngresado<10000){ 
			separar(numIngresado,n1,n2,n3,n4);
			if(d1==n1){
				numMismaPos++;
			}
			if(d2==n2){
				numMismaPos++;
			}
			if(d3==n3){
				numMismaPos++;
			}
			if(d4==n4){
				numMismaPos++;
			}
			
			if(d1==n1 || d2==n1 || d3==n1 || d4==n1){
				numIgual++;
			}
			if(d1==n2 || d2==n2 || d3==n2 || d4==n2){
				numIgual++;
			}
			if(d1==n3 || d2==n3 || d3==n3 || d4==n3){
				numIgual++;
			}
			if(d1==n4 || d2==n4 || d3==n4 || d4==n4){
				numIgual++;
			}
		printf("\nCantidad misma posicion  [%d]",numMismaPos);
		printf("\nNumeros ingresados iguales [%d]\n\n",numIgual);
		if(numMismaPos==4){
			
			printf("\n*FELICIDADES HA GANADO*\n\nPuntuacion [%d]\n\n",puntuacion);
			i=11;
		}
		else{
			puntuacion--;
		}
		if(puntuacion==0){
			
		printf("\n*JUEGO TERMINADO*\n");
		printf("\nRespuesta [%d]\n", numSecreto);	
		}
		
		numIgual=0;
		numMismaPos=0;
		
		}
		else{
			printf("\n--ERROR--\n");
			printf("\nIngrese un numero de 4 cifras");
			i--;
		}
		
}


}
void separar(int n, int &d1, int &d2, int &d3, int &d4){
	d4 = n % 10;
	n = (n - d4) / 10;
	d3 = n % 10;
	n = (n - d3)/ 10;
	d2= n % 10;
	n = (n - d2) / 10;
	d1 = n;
	

}
