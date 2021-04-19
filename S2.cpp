//Estudiantes

//Jhoan Sebastian Pabon			(2172775)
//Dylan Yesid Villalba Roa		(2172303)
//Carlos Daniel Peñaloza Torres (2172336)

#include "Header.h" // Incluir el Header

int main () {
	
	Plano();		// Graficar ejes
	Unidad();		// Poner las unidades
	oculPunt();		// Ocultar puntero del terminal
	LimiteTemp();	// Graficar caja de temperatura
	LimiteHora();	// Graficar caja de hora
	TituloTemp();	// Escribir titulo de temp
	TituloHora();   // Escribir titulo de hora actual
	LimitePlano();  // Graficar caja del plano
	TituloGrafica();// Escribir titulo del plano
	LimiteGrafica();// Graficar caja del programa
	
	Punto obj; // Un objeto de la clase punto
	
	obj.tituloFichero(); // Titulo prinsipal del fichero
	obj.x = 6;
	obj.y = 8;
	
	Serial* Arduino = new Serial("COM3"); // Definiendo puerto del arduino

	
    while(Arduino->IsConnected()){  // Verificar si el Arduino está conectado
                
		Arduino->ReadData(palabra,sizeof(palabra)-1); // Capturar valor del puerto serial
			
			dato++;
			
			if(cont > 60){
				obj.borrar();// Borrar puntos 		
				cont = 3;	 // Reiniciar contador
			}
				
    		Hora();			 // Graficar hora
    		MostrarTemp();	 // Graficar temperatura
    		
			cont+=4;		 
			obj.dato = dato; // Contador de datos
    		obj.x = cont;	 // Posicion x para desplazar los puntos
    		obj.y = c;		 // Amplitud del punto menos 10
			obj.temp = c+10; // Temperatura exacta
			obj.graficar();  // Graficar puntos
			obj.calificarClima(); // Clasificar temperatura
			obj.guardarDatos();   // Guardar datos en txt
			Sleep(1000);
	}
}
