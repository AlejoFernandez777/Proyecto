#include <stdio.h> 

#include <time.h> 

 

int esBisiesto(int anio) { 

    if (anio % 400 == 0) { 

        return 1; 

    } else if (anio % 100 == 0) { 

        return 0; 

    } else if (anio % 4 == 0) { 

        return 1; 

    } else { 

        return 0; 

    } 

} 

 

int calcularDiaSemana(int dia, int mes, int anio) { 

    int a = (14 - mes) / 12; 

    int y = anio - a; 

    int m = mes + 12 * a - 2; 

    int d = (dia + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7; 

    return d; 

} 

 

int main() { 

    int anio; 

    printf("Ingrese el año (2010-2050): "); 

    scanf("%d", &anio); 

 

    if (anio < 2010 || anio > 2050) { 

        printf("El año ingresado no está en el rango permitido.\n"); 

        return 0; 

    } 

 

    int mesesTrimestrales[] = {1, 4, 7, 10}; 

    for (int i = 0; i < 4; i++) { 

        int mes = mesesTrimestrales[i]; 

        int diasEnMes = (mes == 2 && esBisiesto(anio)) ? 29 : 28; 

        for (int dia = 1; dia <= diasEnMes; dia++) { 

            if (calcularDiaSemana(dia, mes, anio) == 1) { 

                printf("La reunión del trimestre %d será el %02d/%02d/%04d\n", i + 1, dia, mes, anio); 

                break; 

            } 

        } 

    } 

 

    return 0; 

} 

 