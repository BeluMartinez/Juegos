/*
1. Compilador
2. Entorno
3. Computadora
4. Estructura
5. Seleccion
6. Repeticion
7. Directiva
8. Algoritmo
9. Program
10.Ejecucion
11.Int
12.Float
13.Char
14.Double
15.Long
16.If
17.Else
18.For
19.While
20.Return
21.Break
22.Switch
23.Case
24.Main
25.Include
26.Define
27.Struct
28.Cin
29.Cout
30.Endl
*/


#include <stdio.h>               /*LIBRERIA STANDAR*/
#include <stdlib.h>              /*LIBRERIA PARA MANEJAR EL EXIT*/
#include <ctype.h>               /*LIBRERIA PARA MANEJAR EL ISALPHA*/
#include <conio.h>               /*LIBRERIA DE GRAFICOS*/
#include <string.h>              /*LIBRERIA PARA MANEJAR EL STRLEN*/
//#include <dos.h>                 /*LIBRERIA PARA MANEJAR EL DELAY (PAGINA DE PRESENTACIÓN Y DESPEDIDA*/
//#include <time.h>


void inicializacion(char jue[], int longitud);  //Funcion que da inicialización al juego
void mostrar(char vec[], int longitud, int intentos, char x, char ingresos[], int puntaje); //Funcion cuyo cometido es informar al usuario sobre sus pasos
int busqueda(int cantidad, char p[], char jue[], char x, int &in, char ing[]); //Esta funcion es importante ya que define si la letra ingresada es la correcta o no

bool bandera = true;

main(){
	
	char palabra[10], juego[10], ingresos[10];
	char x, palab;
	int c=0,j=0, i=0;   
	int puntaje;

	
/*	strcpy(palabras[0], "COMPILADOR");
	strcpy(palabras[1], "ENTORNO");
    strcpy(palabras[2], "COMPUTADORA");
	strcpy(palabras[3], "ESTRUCTURA");
	strcpy(palabras[4], "SELECCION");
	strcpy(palabras[5], "REPETICION");
	strcpy(palabras[6], "DIRECTIVA");
	strcpy(palabras[7], "ALGORITMO");
	strcpy(palabras[8], "PROGRAM");
	strcpy(palabras[9], "EJECUCION");
	strcpy(palabras[10], "INT");
	strcpy(palabras[11], "FLOAT");
	strcpy(palabras[12], "CHAR");
	strcpy(palabras[13], "DOUBLE");
	strcpy(palabras[14], "LONG");
	strcpy(palabras[15], "IF");
	strcpy(palabras[16], "ELSE");
	strcpy(palabras[17], "FOR");
	strcpy(palabras[18], "WHILE");
	strcpy(palabras[19], "RETURN");
	strcpy(palabras[20], "BREAK");
	strcpy(palabras[21], "SWITCH");
	strcpy(palabras[22], "CASE");
	strcpy(palabras[23], "MAIN");
	strcpy(palabras[24], "INCLUDE");
	strcpy(palabras[25], "DEFINE");
	strcpy(palabras[26], "STRUCT");
	strcpy(palabras[27], "CIN");
	strcpy(palabras[28], "COUT");
	strcpy(palabras[29], "ENDL");
	*/
//	int k=0;
   /* srand(time(NULL));
	k= 0 + rand()%30;
	strcpy(palabra, palabras[k]);
	longitud= strlen(palabra);*/
	
	
	//gotoxy(25,4);
	//textcolor(10);
	
	printf("*****************************************************************************\n");
	printf("******************BIENVENIDOS AL JUEGO  DEL A H O R C A D O******************\n");
	printf("*****************************************************************************\n");
	printf("RECORDAR...\n");
	//gotoxy(25,9);
	printf("\nEste juego cuenta con una base de palabras asociadas a la codificacion de algoritmos y al lenguaje de programacion C++.\n\n");
	system("PAUSE");
	system("CLS");
	
	
	printf("RECORDAR...");
	printf("\nLa palabra tiene que ser introducida por caracter de tal modo que estos queden en columna y debe terminar en un punto[.].\n\n");
	
	//gotoxy(28,12);
	printf("Introduzca una letra ==>\n");
	

	
	while(palab!='.')
		{
		scanf("%c",&palab);
			
			if (isalpha(palab)){
			
			
	    	if(palab != '.' ){
			_flushall();
	        palabra[i]= palab;
		    i++;
	        j++;
	    	}
	    	
			}
			
			else{
			
			  if(palab != '.'){
			   printf("*ERROR*\n Ingrese una letra\n");	
			  } 
		   }
		}
		
	inicializacion(juego,j);
	
	do
	{
		system("cls");		
		mostrar(juego, i, c, x, ingresos, puntaje);
		_flushall();
		
		scanf("%c", &x);
		
		if (isalpha(x))
		{
			if (busqueda(i, palabra, juego, x, c, ingresos) == 0) break;			
		}
		
		else 
		{
			printf("*ERROR*\n Ingrese una letra del ALFABETO\n ");
			system("PAUSE");
		}
		


		
	}while(c < 11);
	
	mostrar(juego, i, c, x, ingresos, puntaje);
	system("CLS");
	int punt;
	if (bandera){
		punt=50-(2*c);
		printf("Puntaje obtenido [%d]\n", punt);
		
		if(punt == 50){
			printf("\n*FELICIDADES, ACERTASTE*\n");
			printf("Gracias por jugar!\n\n");
		}
	}
	else{
		printf("\nPuntaje obtenido [0]\n");
		printf("\n**FIN DEL JUEGO**\n Gracias por jugar!\n");
		
	}
	

	system("PAUSE");
}



void inicializacion(char y[], int longitud){
	
	for(int i=0; i < longitud; i++){
		y[i] = '_'; 
	}
}


void mostrar(char vec[],int longitud,int intentos, char x, char ingresos[], int puntaje){
	
	
	
	for(int i=0; i < longitud; i++){
		
		vec[i]=toupper(vec[i]);
		printf("%c ", vec[i]);	
	}

	
	switch(intentos){

	case 1:	printf("\nEstado: [cabeza]\n");
			printf("El caracter ingresado no forma parte de la palabra.\n");
			break;
			
	case 2:	printf("\nEstado: [cabeza][tronco]\n"); 
			printf("El caracter ingresado no forma parte de la palabra.\n" );
			break;
			
	case 3:	printf("\nEstado: [cabeza] [tronco] [brazo izquierdo]\n");
			printf("El caracter ingresado no forma parte de la palabra.\n" );
			break;
			
	case 4:	printf("\nEstado: [cabeza] [tronco] [brazo izquierdo]  [brazo derecho]\n"); 
			printf("El caracter ingresado no forma parte de la palabra.\n" );
			break;
			
	case 5:	printf("\nEstado: [cabeza] [tronco] [brazo izquierdo] [mano izquierda]  [brazo derecho]\n");
			printf("El caracter ingresado no forma parte de la palabra.\n" );
			break;
			
	case 6:	printf("\nEstado: [cabeza] [tronco] [brazo izquierdo] [mano izquierda] [brazo derecho] [mano derecha]\n"); 
			printf("El caracter ingresado no forma parte de la palabra.\n");
			break;
			
	case 7:	printf("\nEstado: [cabeza] [tronco] [brazo izquierdo] [mano izquierda] [brazo derecho] [mano derecha]  [pierna izquierda]\n"); 
			printf("El caracter ingresado no forma parte de la palabra.\n");
			break;
			
	case 8:	printf("\nEstado: [cabeza] [tronco] [brazo izquierdo] [mano izquierda] [brazo derecho] [mano derecha] [pierna izquierda] [pierna derecha]\n");
			printf("El caracter ingresado no forma parte de la palabra.\n" );
			break;
			
	case 9:	printf("\nEstado: [cabeza] [tronco] [brazo izquierdo] [mano izquierda] [brazo derecho] [mano derecha] [pierna izquierda] [pierna derecha] [pie izquierdo]\n"); 
			printf("El caracter ingresado no forma parte de la palabra.\n" );
			break;
			
	case 10:printf("\nEstado: [cabeza] [tronco] [brazo izquierdo] [mano izquierda] [brazo derecho] [mano derecha] [pierna izquierda] [pierna derecha] [pie izquierdo] [pie derecho]\n");
	       	printf("El caracter ingresado no forma parte de la palabra.\n");
			bandera = false;
			break;
	}
	
	
	for (int i=0; i<intentos ; i++)
	{ 
	 printf("[%c]", ingresos[i]);
	}
	printf("\n");
	
}


int busqueda(int cant, char p[], char jue[], char x, int &in, char ing[]){
	bool b = false;
	int cont=0;
	for(int i=0; i < cant; i++){
		if (p[i] == x){
		 jue[i] = x;
		 b = true;
		}
		if (jue[i] == '_')cont++;
	}
	
		if (!b){
			
			ing[in] = x;
			in++;
			printf("La letra ingresada es incorrecta. Continue con otra... \n\n");
			system("PAUSE");
		}
	return cont;
}
