#include <stdio.h>  


int calcularDiaSemana(int dia, int mes, int anio) {  

 

    int a = (14 - mes) / 12;  

 

    int y = anio - a;  

 

    int m = mes + 12 * a - 2;  

 

    int d = (dia + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;  

 

    return d;  

 

}  

 

   

 

void calcularFechasReuniones(int anio) {  

 

    int primerMesTrimestres[] = {1, 4, 7, 10};  

 

    for (int i = 0; i < 4; i++) {  

 

        int mes = primerMesTrimestres[i];  

 

        for (int dia = 1; dia <= 7; dia++) {  

 

            if (calcularDiaSemana(dia, mes, anio) == 1) {  

 

                printf("La fecha de la reunión para el trimestre %d es: %d/%d/%d\n", i + 1, dia, mes, anio);  

 

                break;  

 

            }  

 

        }  

 

    }  

 

}  

 

   

 

int main() {  

 

    int anio;  

 

    printf("Ingrese el año: ");  

 

    scanf("%d", &anio);  

 

    calcularFechasReuniones(anio);  

 

    return 0;  

 

} 