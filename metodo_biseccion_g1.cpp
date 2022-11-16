#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

double F(double);
double round(double, int);
void setTabla(double [][7], double, double);
void imprimirMatriz(double [][7], int, int, double);

#define max 200

int main()
{
	int filaf = 0;
	double inter_inf = 0.55, inter_sup = 1.1, error = 0.0001;
	double tabla_biseccion[max][7];
	
	cout << "Ingrese el intervalo inferior: ";
	//cin >> inter_inf;

	cout << inter_inf;

	cout << "\nIngrese el intervalo superior: ";
	//cin >> inter_sup;
	
	cout << inter_sup;
	
	cout << "\nIngrese el error de convergencia: ";
	//cin >> error;
	
	cout << error << endl;  
	
	setTabla(tabla_biseccion, inter_inf, inter_sup);
	imprimirMatriz(tabla_biseccion, max, 7, error);
	
	for (int i = 1; i < max; i++) {
		if(tabla_biseccion[i][3] == error) {
			cout << "\n\nIteraciones: " << i + 1;
			cout << "\nRaiz: " << tabla_biseccion[i][0];
			break;
		}
	}
	
	
 	return 0;
}

//método bisección
void setTabla(double tabla[][7], double val1, double val2) {
	
	//inicialización de valores iniciales según método de bisección
	tabla[0][0] = val1;
	tabla[0][1] = val2;
	tabla[0][2] = round(((val1 + val2) / 2), 5);
	tabla[0][3] = 0;
	tabla[0][4] = round(F(val1), 5);
	tabla[0][5] = round(F(val2), 5);
	tabla[0][6] = round(F(tabla[0][2]), 5);
	

	for (int i = 1; i < max; i++) {
		
		for (int j = 0; j < 7; j++) {

			if (j == 0) {
			
				if (tabla[i - 1][4] * tabla[i - 1][6] < 0)
					tabla[i][j] = round(tabla[i - 1][j], 4);
					
				else
					tabla[i][j] = round(tabla[i - 1][2], 4);
					
			} 
			
			else if (j == 1) {
				
				if (tabla[i - 1][4] * tabla[i - 1][6] > 0)
					tabla[i][j] = round(tabla[i - 1][1], 4);
					
				else
					tabla[i][j] = round(tabla[i - 1][2], 4);
					
			}
			
			else if (j == 2)
				tabla[i][j] = round(((tabla[i][j - 2] + tabla[i][j - 1]) / 2), 4);
			
			else if (j == 3) {
				tabla[i][j] = round(((tabla[i][j - 1] - tabla[i - 1][j - 1]) / tabla[i][j - 1]), 4);
				
				if (tabla[i][j] < 0)
					tabla[i][j] = tabla[i][j] * -1;
					
			}
				
			else if (j == 4)
				tabla[i][j] = round((F(tabla[i][0])), 4);
			
			else if (j == 5)
				tabla[i][j] = round((F(tabla[i][1])), 4);
				
			else if (j == 6)
				tabla[i][j] = round((F(tabla[i][2])), 4);
				
		}
	}
			
}

//funcion del ejercicio
double F(double x) {
	return pow(x, 4) - (5 * pow(x, 3)) + (0.5 * pow(x, 2)) - (11 * x) + 10;
	
	//return (pow(x, 3)) - (4.236 * pow(x, 2)) - (2.7362 * x) - 13.09037;
}

//funcion para redondear a una cantidad específica de decimales (tomada de: https://stackoverflow.com/questions/25925290/c-round-a-double-up-to-2-decimal-places)
double round(double value, int decimal_places) {
    const double multiplier = pow(10.0, decimal_places);
    return ceil(value * multiplier) / multiplier;
}

//funcion para imprimir la matriz
void imprimirMatriz(double mm[][7], int f, int c, double error) {
	
    for (int i = 0; i < f; i++) {
        cout << endl;
        
       for (int j = 0; j < c; j++) {
           if(j == 0)
            cout << "{";
            
        	if(j < c)
        		cout << " [";
       		
            cout << mm[i][j];
           
            if(j < c)
                cout << "]";
               
            if(j == c - 1)
                cout << " }";
            		
            cout << " ";
       }
       
       if(mm[i][3] == error)
        	break;
    }
}
