#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Declaración de funciones
void pause();
void IngresarDatos(double ingresos[], int tamano);
double CalcularPromedio(double ingresos[], int tamano);
void CalcularCrecimiento(double ingresos[], int tamano);

int main() {
    int op;
    const int MESES = 2;
    double ingresos[MESES];

    // Do While
    do {
        // Menú del programa
        system("clear"); // Limpiar pantalla
        printf("****************************************************************************************\n");
        printf("\n-----Registro de ingreso de una empresa-----\n\n");
        printf("\n------------- MENU -------------\n\n");
        printf("\n\u27a4 [1] Registrar los ingresos de los ultimos 2 meses de la empresa.\n");
        printf("\n\u27a4 [2] Calcular el promedio de los ingresos.\n");
        printf("\n\u27a4 [3] Calcular el crecimiento.\n");
        printf("\n\u27a4 [4] Terminar\n");
        printf("\n****************************************************************************************\n");
        printf("\nIngrese una opcion: ");
        scanf("%d", &op);
        if (op > 4)
            fflush(stdin);
        switch (op) {
            case 1: // Registrar ingresos
                system("clear");
                printf("------------------------------------------------------------------------------------\n\n");
                IngresarDatos(ingresos, MESES);
                pause();
                printf("------------------------------------------------------------------------------------\n");
                break;
            case 2: // Calcular promedio
                system("clear");
                printf("------------------------------------------------------------------------------------\n\n");
                double promedio;
                promedio = CalcularPromedio(ingresos, MESES);
                printf("El promedio de los ingresos es: %.2f\n", promedio);
                pause();
                printf("------------------------------------------------------------------------------------\n");
                break;
            case 3: // Calcular el crecimiento
                system("clear");
                printf("------------------------------------------------------------------------------------\n\n");
                CalcularCrecimiento(ingresos, MESES);
                pause();
                printf("------------------------------------------------------------------------------------\n");
                break;
            case 4: // Terminar el programa
                system("clear");
                printf("\n****Gracias por utilizar****\n");
                break;
        }
    } while (op != 4);

    return 0;
}

// Función para ingresar datos
void IngresarDatos(double ingresos[], int tamano) 
{
    // Ingresar los ingresos de los últimos 2 meses
    for (int i = 0; i < tamano; ++i) 
    {
        printf("Digite los ingresos del mes %d: ", i + 1);
        scanf("%lf", &ingresos[i]);
    }
    // Mostrar los ingresos ingresados
    printf("\nIngresos de los últimos 2 meses:\n");
    for (int i = 0; i < tamano; ++i) 
    {
        printf("Mes %d: %.2f\n", i + 1, ingresos[i]);
    }
}

// Función para calcular el promedio de los ingresos
double CalcularPromedio(double ingresos[], int tamano) 
{
    double suma = 0;
    for (int i = 0; i < tamano; ++i) 
    {
        suma += ingresos[i];
    }
    return suma / tamano;
}

// Función para calcular el crecimiento de los ingresos
void CalcularCrecimiento(double ingresos[], int tamano) 
{
    printf("\nCrecimiento de los ingresos:\n");
    for (int i = 1; i < tamano; ++i) 
    {
        double crecimiento = ((ingresos[i] - ingresos[i - 1]) / ingresos[i - 1]) * 100;
        printf("Crecimiento del mes %d al mes %d: %.2f%%\n", i, i + 1, crecimiento);
    }
}

// Función que pausa la pantalla del usuario
void pause() {
    printf("\n\u27a4 Presione enter para continuar...");
    getchar();
    getchar();
}
