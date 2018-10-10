#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///CADENAS
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
void getValidString(char mensaje[],char mensajeError[], char input[])
{

    while(1)
    {
        if (!getStringLetras(mensaje,input))
        {
            printf ("%s\n",mensajeError);
            continue;
        }
        break;
    }

}
///ENTEROS
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getValidInt(char mensaje[],char mensajeError[])
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(mensaje,auxStr))
        {
            printf ("%s\n",mensajeError);
            continue;
        }
        auxInt = atoi(auxStr);

        return auxInt;
    }
}
///FLOTANTES
int esNumericoFlotante(char cadena[])
{
    int i=0;
    int cantidadPuntos=0;
    while(cadena[i] != '\0')
    {
        if (cadena[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(cadena[i] < '0' || cadena[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int getValidFloat(char mensaje[],char mensajeError[])
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(mensaje, auxStr))
        {
            printf ("%s\n",mensajeError);
            continue;
        }
        auxFloat = atof(auxStr);
        return auxFloat;
    }
}

void findSalaryMax(Employee *employees, int len)
{
    float promedio=0;
    int contador=0;
    int total=0;
    int cali=0;
    int cantidad=0;
    int i;
    int flag=0;

    for(i=0; i<len; i++)
    {
        if(employees[i].isEmpty==OCUPADO)
        {
            cali=employees[i].salary;
            total=cali+total;
            cantidad++;
            flag=1;
        }

    }
    if(flag==1)
    {
        promedio=total/cantidad;
        for(i=0; i<len; i++)
        {
            /*if(employees[i].salary>promedio && employees[i].isEmpty==OCUPADO)
                {
                    contador++;
                }*/
        }
        printf("El promedio de los salarios es: %.2f\n", promedio);
        printf("La cantidad de empleados que superan el salario promedio son: %d\n", contador);
    }

}
///****ABM
int initEmployees(Employee *employees, int len)
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {

        employees[i].isEmpty = VACIO;

    }
    if(len==i)
    {
        retorno=0;
    }

    return retorno;
}

///***** Cargar
int addEmployee(Employee list[],int len, int id)
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int indice;
    int retorno=-1;

    indice = findSpace(list,len);

    if(indice!=-1)
    {
        getValidString("Ingrese nombre: ","Error ingrese solo letras",name);
        getValidString("Ingrese apellido: ", "Error ingrese solo letras", lastName);
        sector=getValidInt("Ingrese sector", "Error ingrese solo numeros");
        salary=getValidFloat("Ingrese salario", "Error ingrese solo numeros");

        strcpy(list[id].name,name);
        strcpy(list[id].lastName,lastName);
        list[id].salary=salary;
        list[id].sector=sector;
        list[id].id=id;
        list[id].isEmpty=OCUPADO;
        retorno=0;
    }

    return retorno;
}


int findSpace(Employee *listado, int len) //-1 si no hay lugar
{
    int indice=-1;
    int i;

    for(i=0; i<len; i++)
    {
        if(listado[i].isEmpty==VACIO)
        {
            indice=i;
            break;
        }
    }

    return indice;
}


///****     Mostrar
void printEmployees(Employee * employees, int len)
{
    int i;
    printf("APELLIDO -- NOMBRE -- SECTOR -- ID -- SALARIO\n");
    for(i=0; i<len; i++)
    {
        if(employees[i].isEmpty==0)
        {
            printf("%6s %9s %9d %8d %.2f\n", employees[i].lastName, employees[i].name, employees[i].sector, employees[i].id, employees[i].salary);

        }
    }
}
void mostrarId(Employee *employees, int len)
{
    int i;
    printf("ID -- NOMBRE\n");

    for(i=0; i<len; i++)
    {
        if(employees[i].isEmpty==OCUPADO)
        {

            printf("%d--%s\n",employees[i].id, employees[i].name);
        }
    }

}
int findEmployeeById(Employee *employees, int len, int id) //-1 si no lo encontro
{
    int i;
    int retorno=-1;
    for(i=0; i<len; i++)
    {
        if(id==employees[i].id && employees[i].isEmpty==OCUPADO)
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

///******* Dar de baja
int removeEmployee(Employee *employees, int len)
{
    int id;
    int i;
    char resp;
    int encontro=0;
    mostrarId(employees,len);
    id=getValidInt("Ingrese ID\n","ERROR solo puede ingresar numeros!!!!\n");
    encontro=borrar(employees,id,len);

    return encontro;
}
int borrar(Employee *employees, int id, int len)
{
    int i;
    char respuesta;
    int encontro=0;
    for(i=0; i<len; i++)
    {
        if(id==employees[i].id && employees[i].isEmpty==OCUPADO)
        {
            printf("Esta seguro de eliminarlo? s/n");
            fflush(stdin);
            scanf("%c", &respuesta);
            if(respuesta=='s' || respuesta=='S')
            {
                employees[i].isEmpty=VACIO;
                encontro=1;
                break ;
            }

        }
    }

    return encontro;
}

///*** Editar
int editEmployee(Employee * employees, int len)
{
    int id;
    int i;
    int opcion;
    int retorno;
    int flag=-1;
    mostrarId(employees, len);
    id=getValidInt("Seleccione la id de los siguientes empleados que desea modificar: \n","ERROR solo puede ingresar numeros!!!!\n");

    for(i=0; i<len; i++)
    {
        if(id==employees[i].id && employees[i].isEmpty==OCUPADO)
        {
            retorno=modificarEmployee(employees,i);
            flag=0;
        }
    }
    if(flag!=0)
    {
        printf("No se encontro al empleado\n");
    }

    return retorno;
}
int modificarEmployee(Employee* list,int id)
{
    int opcion;
    int name[51];          //-1 si no modifico nada, 0 si modifico algo
    int lastName[51];
    int salary;
    int sector;
    int retorno=-1;
    do
    {
        printf("1. modificar nombre\n");
        printf("2. modificar apellido\n");
        printf("3. modificar sueldo\n");
        printf("4. modificar sector\n");
        printf("5. salir \n");
        opcion=getValidInt("Ingrese una opcion\n","ERROR solo puede ingresar numeros!!!!\n");

        switch(opcion)
        {
        case 1:
            getValidString("Ingrese nombre: ","Error ingrese solo letras",name);
            strcpy(list[id].name,name);
            printf("\nModifico el nombre\n");
            retorno=0;
            break;
        case 2:
            getValidString("Ingrese apellido: ", "Error ingrese solo letras", lastName);
            strcpy(list[id].lastName,lastName);
            printf("\nModifico el apellido\n");
            retorno=0;
            break;
        case 3:
            salary=getValidFloat("Ingrese salario", "Error ingrese solo numeros");
            list[id].salary=salary;
            printf("\nModifico el salario\n");
            retorno=0;
            break;

        case 4:
            sector=getValidInt("Ingrese sector", "Error ingrese solo numeros");
            list[id].sector=sector;
            printf("\nModifico el sector\n");
            retorno=0;
            break;
        case 5:
            opcion=5;
            break;
        default:
            break;

        }
    }
    while(opcion!=5);

    return retorno;
}

int darOrden()
{
    int orden;
    orden=getValidInt("Elija: 1) para ordenar ascendentemente o 0) para ordenar descendentemente\n", "Error ingrese solo numeros");

    return orden;
}

int sortEmployee(Employee *employees, int len, int orden)
{
    Employee temp;
    int i,j;
    int retorno=-1;

    if(orden==1)
    {
        for(i=0; i<len-1; i++)
        {

            for(j=i+1; j<len; j++)
            {
                if(employees[i].isEmpty==OCUPADO && employees[j].isEmpty==OCUPADO)
                {
                    if(strcmp(employees[i].lastName,employees[j].lastName)>0)
                    {
                        temp=employees[i];
                        employees[i]=employees[j];
                        employees[j]=temp;
                        retorno=0;
                    }
                    else
                    {
                        if(strcmp(employees[i].lastName,employees[j].lastName)==0)
                        {
                            sortEmployeeBySector(employees,len);
                        }
                    }
                }

            }
        }
    }
    else if(orden == 0)
    {
        for(i=0; i<len-1; i++)
        {

            for(j=i+1; j<len; j++)
            {
                if(employees[i].isEmpty==OCUPADO && employees[j].isEmpty==OCUPADO)
                {
                    if(strcmp(employees[i].lastName,employees[j].lastName)<0)
                    {
                        temp=employees[i];
                        employees[i]=employees[j];
                        employees[j]=temp;
                        retorno=0;
                    }
                    else
                    {
                        if(strcmp(employees[i].lastName,employees[j].lastName)==0)
                        {
                            sortEmployeeBySector(employees,len);
                        }
                    }
                }

            }
        }
    }
    else
    {
        printf("Ingreso una opcion invalida \n");
    }


    return retorno;
}

int sortEmployeeBySector(Employee *employees, int len)
{
    Employee temp;
    int i,j;
    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(employees[i].sector>employees[j].sector)
            {
                temp=employees[i];
                employees[i]=employees[j];
                employees[j]=temp;
            }
        }
    }
}
void mostrarUsuarioConSuSerie(eUsuario usu[], int tamU, eSerie ser[], int tamS,eSerieYUs ususer[], int tamUS)
{
    int i;
    int j;
    int k;
    for(i=0; i<tamUS; i++)
    {
        for(j=0;j<tamU;j++)
        {
            if(usu[i].estado==1 && ser[j].estado==1)
            {
                if(ususer[i].idUs==usu[j].idUsuario)
                {
                    for(k=0;k<tamS;k++)
                    {
                        if(ususer[k].estado==1)
                        {
                            if(ususer[i].idSerie==ser[j].idSerie)
                            {
                                printf("%s mira la serie: %s\n",usu[j].nombre,ser[k].nombre);
                            }else{

                                printf("US ID: %d ---- SERID: %d\n",ususer[i].idSerie,ser[k].idSerie);
                            }
                        }
                    }
                }
            }
        }
    }
}
void mostrarSerieConUsuario(eUsuario usuario[], eSerie serie[], eSerieYUs serieYUsuario[], int tamSerie,int tamUsuario, int cantidad)
{
    int i,j,k;
    int x=0;

    for(i=0;i<tamSerie;i++)
    {
        if(serie[i].estado==1 && usuario[i].estado==1)
        {
            printf("Nombre: %s--- ID: %d",serie[i].nombre,serie[i].idSerie);

            for(j=1;j<tamUsuario;j++)
            {
                if(serie[i].idSerie==usuario[j].idSerie)
                    {
                        printf("%s", usuario[j].nombre);
                    }

            }
             printf("\n");
        }
    }

}
