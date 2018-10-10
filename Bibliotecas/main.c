#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define TAM 2


int main()
{
    Employee employees[TAM];
    char name[50];
    char lastname[50];
    float salary;
    int sector;
    int opcion;
    int flag=-1;
    int id=0;
    initEmployees(employees,TAM);
    do
    {

        printf("1.Alta\n");
        printf("2.Baja\n");
        printf("3.Modificar\n");
        printf("4.Mostrar\n");
        printf("5.Salir\n");
        opcion=getValidInt("Ingrese una opcion\n","ERROR solo puede ingresar numeros!!!!\n");

        switch(opcion)
        {
        case 1:
            if(addEmployee(employees, TAM, id)==0)
                {
                    printf("Dato cargado con exito\n");
                    flag=1;
                    id++;
                }
                else
                {
                    printf("No existe espacio disponible\n");
                }

                break;

            case 2:

                break;


            case 3:


                break;


            case 4:
                mostrarId(employees,TAM);

                break;


            default:

                break;
            }




            system("pause");
            system("cls");
        }
        while(opcion!=5);



        return 0;
    }
