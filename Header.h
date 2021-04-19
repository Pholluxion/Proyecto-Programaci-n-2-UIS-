//Estudiantes

//Jhoan Sebastian Pabon			(2172775)
//Dylan Yesid Villalba Roa		(2172303)
//Carlos Daniel Peñaloza Torres (2172336)


#include <ctime>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "SerialClass.h"
#include "SerialClass.cpp"

    int c,d,u,cont=3,dato=0;
	char palabra[]="    ";
	
	void Hora();
	void Plano();
	void Unidad();
	void oculPunt();
	void TituloTemp();
	void LimiteTemp();
	void TituloHora();							// Prototipos de las funciones
	void LimiteHora();
	void MostrarTemp();
	void LimiteGrafica();
	void TituloGrafica();
	void gotoxy(int,int);
	void numero(int,int,int);
	
using namespace std;
	
	
class  Punto{

	public:
		int x,y,temp,dato;
		
	public:
		
		void graficar();							// Clase Punto sus parametros y  sus metodos
		void borrar();
		void calificarClima();
		void tituloFichero(); 
		void guardarDatos(); 
		
};
void Punto::tituloFichero(){
	
	ofstream archivo;
	archivo.open("temperatura.txt",ios::app);
	
	 archivo<<"---------------------------------------\n"
			<<"\tFichero de temperatura               \n"							// Escribir titulo del fichero
			<<"---------------------------------------\n";
	archivo<<setw(2)<<"Item"<<setw(15)<<"Temperatura"<<setw(10)<<"Hora"<<endl;
	
	archivo.close();
	
}

void Punto::guardarDatos(){
	
	ofstream archivo;
	archivo.open("temperatura.txt",ios::app);							// Guardar datos en la ultima linea del fihero
	
	time_t tSac = time(NULL);
	struct tm* tmP = localtime(&tSac);									// Capturar hora en el instante
	
	archivo<<setw(2)<<this->dato<<setw(15)<<this->temp<<"\t"<<setw(3)<<tmP->tm_hour<<":"<<setw(2)<<tmP->tm_min<<":"<<setw(2)<<tmP->tm_sec<<endl;
	
	archivo.close();
	
} 

void Punto::calificarClima(){
	
	if(this->temp <=29  && this->temp >= 24){
		gotoxy(78,18);printf("El clima esta caliente %c     ",2);
		
	}else if(this->temp < 24 && this->temp >= 18){
		gotoxy(78,18);printf("El clima esta comodo %c       ",2);
	
	}else if(this->temp < 18 && this->temp >= 13){									// Calificar clima
		gotoxy(78,18);printf("El clima esta fresco %c       ",1);
		
	}else if(this->temp <13 && this->temp >=0){
		gotoxy(78,18);printf("El clima esta frio   %c       ",1);
	}	
}

void Punto::borrar(){
	
	for(int i=6;i<=34;i++){
		gotoxy(7,i);cout<<setw(60)<<setfill(' ')<<'\n'<<setfill(' '); 					// Borra puntos 
	}
			
}

void Punto::graficar(){
	
	gotoxy(this->x,(35-this->y));cout<<setw(2)<<setfill(' ')<<this->temp; 				// Grafical valor discreto
	gotoxy(this->x,(35-this->y)+1);printf("%c",30);
	
	for(int i=(35-y)+2;i<35;i++){
		gotoxy(this->x,i);printf("%c",124);
	}	
}

void Hora(){
	
	time_t tSac = time(NULL);
	struct tm* tmP = localtime(&tSac);		 		// Capturar tiempo en el instante

	int aux=0;
	
	aux = tmP->tm_hour/10;
	numero(72,24,aux);
	aux = tmP->tm_hour%10;							// Dibujar Hora en la pantalla
	numero(81,24,aux);
	
	numero(90,25,98);
	
	aux = tmP->tm_min/10;
	numero(95,24,aux);
	aux = tmP->tm_min%10;							// Dibujar minutos en la pantalla
	numero(104,24,aux);
	
	aux = tmP->tm_sec/10;
	numero(82,30,aux);
	aux = tmP->tm_sec%10;							// Dibujar segundos en la pantalla
	numero(91,30,aux);
}
		
void oculPunt(){
	
	HANDLE hComun;
	
	hComun = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	
	cursor.dwSize = 100;
	cursor.bVisible = FALSE;							// Funcion para ocultar el puntero del terminal
	
	SetConsoleCursorInfo(hComun,&cursor);
}

void gotoxy(int xPos,int yPos){
	
	HANDLE hComun;
	hComun = GetStdHandle(STD_OUTPUT_HANDLE); 			// Funcion para ir al punto especificado por los parametros de entrada
	COORD hPos;
	
	hPos.X = xPos;
	hPos.Y = yPos;
	
	SetConsoleCursorPosition(hComun,hPos);
} 

void MostrarTemp(){
	
	c=atoi(palabra);
		d = (c+10)/10;
		u = (c+10)%10;													// Dibujar la temperatura en la pantalla
		
		if(c!=0){	
			
			numero(79,8,d);
			numero(89,8,u);
		}
}

void TituloGrafica(){
	
	gotoxy(15,5);printf("Grafica temperatura vs tiempo (valores discretos)"); 				// Escribir titulo
}
void TituloTemp(){
	
	gotoxy(76,4);printf("Temperatura actual en Bucaramanga"); 								// Escribir titulo
}
void TituloHora(){
	
	gotoxy(80,22);printf("Hora actual en Bucaramanga"); 									// Escribir titulo
}
void Unidad(){
	
	numero(99,7,99);
	gotoxy(99,13);printf("[ Celcius ]");	 												// Escribir Unidades (celcius) y °
	
}

void LimiteGrafica(){
	
	for(int i=0;i<=114;i++){
	   gotoxy(2+i,2);printf("%c",205);
	   gotoxy(2+i,38);printf("%c",205);
	}
		
	for(int j=0;j<=35;j++){	
		gotoxy(2,2+j);printf("%c",186);
		gotoxy(116,2+j);printf("%c",186);								// Dibujar Caja
	}	
	
	gotoxy(2,2);printf("%c",201);
	gotoxy(116,2);printf("%c",187);
	gotoxy(2,38);printf("%c",200);
	gotoxy(116,38);printf("%c",188);
}
void LimiteTemp(){
	
	for(int i=0;i<=44;i++){
	   gotoxy(70+i,3);printf("%c",205);
	   gotoxy(70+i,20);printf("%c",205);
	}
		
	for(int j=0;j<=17;j++){	
		gotoxy(70,3+j);printf("%c",186);
		gotoxy(114,3+j);printf("%c",186);									// Dibujar Caja
	}	
	
	gotoxy(70,3);printf("%c",201);
	gotoxy(114,3);printf("%c",187);
	gotoxy(70,20);printf("%c",200);
	gotoxy(114,20);printf("%c",188);
}

void LimiteHora(){
	
	for(int i=0;i<=44;i++){
	   gotoxy(70+i,21);printf("%c",205);
	   gotoxy(70+i,37);printf("%c",205);
	}
		
	for(int j=0;j<=16;j++){	
		gotoxy(70,21+j);printf("%c",186);
		gotoxy(114,21+j);printf("%c",186);									// Dibujar Caja
	}	
	
	gotoxy(70,21);printf("%c",201);
	gotoxy(114,21);printf("%c",187);
	gotoxy(70,37);printf("%c",200);
	gotoxy(114,37);printf("%c",188);
}

void LimitePlano(){
	
	for(int i=0;i<=64;i++){
	   gotoxy(4+i,3);printf("%c",205);
	   gotoxy(4+i,37);printf("%c",205);
	}
		
	for(int j=0;j<=33;j++){	
		gotoxy(4,4+j);printf("%c",186);
		gotoxy(68,4+j);printf("%c",186);									// Dibujar Caja
	}	
	
	gotoxy(4,3);printf("%c",201);
	gotoxy(68,3);printf("%c",187);
	gotoxy(4,37);printf("%c",200);
	gotoxy(68,37);printf("%c",188);
}

void Plano(){
	
	for(int i=0;i<=60;i++){
	   gotoxy(6+i,35);printf("%c",196);
	}
		
	for(int j=0;j<=29;j++){	
		gotoxy(6,5+j);printf("%c",179);								// Dibujar plano
	}	
	
	gotoxy(6,35);printf("%c",192);
	gotoxy(7,5);printf("[%cC]",167);
	gotoxy(64,36);printf("[t]");
}
    
void numero(int x,int y,int n){
	switch(n) {
		
		case 0:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(9)<<"  ___  "<<endl;
			gotoxy(x,y+1);
			cout<<setw(9)<<" / _ | "<<endl;
			gotoxy(x,y+2);
			cout<<setw(9)<<"| | | |"<<endl;
			gotoxy(x,y+3);							// Dibujar el 0
			cout<<setw(9)<<"| | | |"<<endl;
			gotoxy(x,y+4);
			cout<<setw(9)<<"| |_| |"<<endl;
			gotoxy(x,y+5);
			cout<<setw(9)<<" |___/ "<<endl;
			break;
			
		case 1:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(9)<<"  __ "<<endl;
			gotoxy(x,y+1);
			cout<<setw(9)<<" /_ |"<<endl;
			gotoxy(x,y+2);
			cout<<setw(9)<<"  | |"<<endl;
			gotoxy(x,y+3);							// Dibujar el 1
			cout<<setw(9)<<"  | |"<<endl;
			gotoxy(x,y+4);
			cout<<setw(9)<<"  | |"<<endl;
			gotoxy(x,y+5);
			cout<<setw(9)<<"  |_|"<<endl;
			break;
		case 2:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(9)<<"  ___  "<<endl;
			gotoxy(x,y+1);
			cout<<setw(9)<<" |__ | "<<endl;
			gotoxy(x,y+2);
			cout<<setw(9)<<"    ) |"<<endl;
			gotoxy(x,y+3);							// Dibujar el 2
			cout<<setw(9)<<"   / / "<<endl;
			gotoxy(x,y+4);
			cout<<setw(9)<<"  / /_ "<<endl;
			gotoxy(x,y+5);
			cout<<setw(9)<<" |____|"<<endl;
			break;
		case 3:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(9)<<"  ____  "<<endl;
			gotoxy(x,y+1);
			cout<<setw(9)<<" |___ | "<<endl;
			gotoxy(x,y+2);
			cout<<setw(9)<<"   __) |"<<endl;
			gotoxy(x,y+3);							// Dibujar el 3
			cout<<setw(9)<<"  |__ < "<<endl;
			gotoxy(x,y+4);
			cout<<setw(9)<<"  ___) |"<<endl;
			gotoxy(x,y+5);
			cout<<setw(9)<<" |____/ "<<endl;
			break;
		case 4:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(9)<<"  _  _   "<<endl;
			gotoxy(x,y+1);
			cout<<setw(9)<<" | || |  "<<endl;
			gotoxy(x,y+2);
			cout<<setw(9)<<" | || |_ "<<endl;
			gotoxy(x,y+3);							// Dibujar el 4
			cout<<setw(9)<<" |__   _|"<<endl;
			gotoxy(x,y+4);
			cout<<setw(9)<<"    | |  "<<endl;
			gotoxy(x,y+5);
			cout<<setw(9)<<"    |_|  "<<endl;
			break;
		case 5:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(9)<<"  _____ "<<endl;
			gotoxy(x,y+1);
			cout<<setw(9)<<" | ____|"<<endl;
			gotoxy(x,y+2);
			cout<<setw(9)<<" | |__  "<<endl;
			gotoxy(x,y+3);							// Dibujar el 5
			cout<<setw(9)<<" |___ | "<<endl;
			gotoxy(x,y+4);
			cout<<setw(9)<<"  ___) |"<<endl;
			gotoxy(x,y+5);
			cout<<setw(9)<<" |____/ "<<endl;
			break;
		case 6:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(9)<<"    __  "<<endl;
			gotoxy(x,y+1);
			cout<<setw(9)<<"   / /  "<<endl;
			gotoxy(x,y+2);
			cout<<setw(9)<<"  / /_  "<<endl;
			gotoxy(x,y+3);							// Dibujar el 6
			cout<<setw(9)<<" |  _ | "<<endl;
			gotoxy(x,y+4);
			cout<<setw(9)<<" | (_) |"<<endl;
			gotoxy(x,y+5);
			cout<<setw(9)<<"  |___/ "<<endl;
			break;
		case 7:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(9)<<"  ______ "<<endl;
			gotoxy(x,y+1);
			cout<<setw(9)<<" |____  |"<<endl;
			gotoxy(x,y+2);
			cout<<setw(9)<<"     / / "<<endl;
			gotoxy(x,y+3);
			cout<<setw(9)<<"    / /  "<<endl;
			gotoxy(x,y+4);							// Dibujar el 7
			cout<<setw(9)<<"   / /   "<<endl;
			gotoxy(x,y+5);
			cout<<setw(9)<<"  /_/    "<<endl;
			break;
		case 8:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(9)<<"   ___  "<<endl;
			gotoxy(x,y+1);
			cout<<setw(9)<<"  / _ | "<<endl;
			gotoxy(x,y+2);
			cout<<setw(9)<<" | (_) |"<<endl;
			gotoxy(x,y+3);							// Dibujar el 8
			cout<<setw(9)<<"  > _ < "<<endl;
			gotoxy(x,y+4);
			cout<<setw(9)<<" | (_) |"<<endl;
			gotoxy(x,y+5);
			cout<<setw(9)<<"  |___/ "<<endl;
			break;
		case 9:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(9)<<"   ___  "<<endl;
			gotoxy(x,y+1);
			cout<<setw(9)<<"  / _ | "<<endl;
			gotoxy(x,y+2);
			cout<<setw(9)<<" | (_) |"<<endl;
			gotoxy(x,y+3);
			cout<<setw(9)<<"  |__, |"<<endl;
			gotoxy(x,y+4);							// Dibujar el 9
			cout<<setw(9)<<"    / / "<<endl;
			gotoxy(x,y+5);
			cout<<setw(9)<<"   /_/  "<<endl;
			break;	

   		 case 98:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(5)<<"  _ "<<endl;
			gotoxy(x,y+1);
			cout<<setw(5)<<" (_)"<<endl;
			gotoxy(x,y+2);							// Dibujar :
			cout<<setw(5)<<"  _ "<<endl;
			gotoxy(x,y+3);
			cout<<setw(5)<<" (_)"<<endl;
			break;	
			
  		case 99:
			cout<<setfill(' ');
			gotoxy(x,y);
			cout<<setw(7)<<"   __  "<<endl;
			gotoxy(x,y+1);
			cout<<setw(7)<<"  /  | "<<endl;
			gotoxy(x,y+2);							// Dibujar °
			cout<<setw(7)<<" | () |"<<endl;
			gotoxy(x,y+3);
			cout<<setw(7)<<"  |__/ "<<endl;
			break;	

		}
}
