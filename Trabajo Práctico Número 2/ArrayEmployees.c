#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define FREE 1
#define OCCUPIED 0

int initEmployees(Employee List[], int len)
{
    int index;
    int returno = 1;

    if(len > 0)
    {
        for(index = 0; index < len; index++)
        {
            List[index].id = FREE;

            strcpy(List[index].name, "");

            strcpy(List[index].lastName, "");

            List[index].isEmpty = FREE;

            List[index].sector = FREE;

            List[index].salary = FREE;
        }
        returno = 0;
    }

    return returno;
}

int searchFree(Employee List[], int len)
{
    int index;
    int returno = -1;

    if(len > 0)
    {
        for(index = 0; index < len; index++)
        {
            if(List[index].isEmpty == FREE)
            {
                returno = index;
                break;
            }
        }
    }

    return returno;
}

int addEmployee(Employee List[], int len, int id, char name[], char lastName[], float salary, int sector)
{
    int index;
    int returno = -1;

    index = searchFree(List, len);

    if(index != -1)
    {
        List[index].id = id;

        strcpy(List[index].name, name);

        strcpy(List[index].lastName, name);

        List[index].salary = salary;

        List[index].isEmpty = OCCUPIED;

        List[index].sector = sector;
    }

    return returno;
}

int selectId(Employee list[], int len)
{
    int id = -1;

    if(printEmployees(list, len) != -1)
    {
        printf("Ingrese id: ");
        fflush(stdin);
        scanf("%d", &id);
    }

    return id;
}

int uppEmployee(Employee List[], int len)
{
    int index = -1;

    if(len > 0)
    {
        index = searchFree(List, len);

        if(index != -1)
        {
            printf("\n  Favor de ingresar\n");

            printf("\nNombre:   ");
            fflush(stdin);
            gets(List[index].name);

            printf("\nApellido: ");
            fflush(stdin);
            gets(List[index].lastName);

            printf("\nSalario:  ");
            scanf("%f", &List[index].salary);

            printf("\nSector:   ");
            scanf("%d", &List[index].sector);

            List[index].id = index + 1;
            List[index].isEmpty = OCCUPIED;
        }
    }

    return index;
}

int findEmployeeById(Employee List[], int len, int id)
{
    int index;
    int returno = -1;

    if(len > 0 )
    {
        for(index = 0; index < len; index++)
        {
            if(List[index].id == id)
            {
                returno = index;
                break;
            }
        }
    }

    return returno;
}

void printEmployee(Employee TheEmployee)
{

    if(TheEmployee.isEmpty == OCCUPIED)
    {
        printf(" EMPLEADO %s, %s\n\n", TheEmployee.lastName, TheEmployee.name);
        printf(" ID       ");
        printf("%d\n", TheEmployee.id);
        printf(" SALARIO  ");
        printf("%.2f\n", TheEmployee.salary);
        printf(" SECTOR   ");
        printf("%d\n\n", TheEmployee.sector);
    }
}

int printEmployees(Employee List[], int length)
{
    int index;
    int returno = -1;

    if(length > 0)
    {
        for(index = 0; index < length; index++)
        {
            printEmployee(List[index]);
            if(List[index].isEmpty == OCCUPIED)
            returno = 0;
        }
    }

    return returno;
}

int removeEmployee(Employee List[], int len, int id)
{
    int index;
    int returno = -1;
    char eliminar;

    if(id >= 0)
    {
        index = findEmployeeById(List, len, id);

        if(index != -1)
        {
            printEmployee(List[index]);
            printf("\nPara eliminar oprima 's'\n");
            fflush(stdin);
            scanf("%c", &eliminar);

            if(eliminar == 's')
            {
                List[index].isEmpty = FREE;
                returno = 1;
            }
        }
    }
    return returno;
}

int sortEmployees(Employee List[], int len, int order)
{
    Employee aux;
    int i;
    int j;
    int returno = -1;

    for(i = 0; i < len -1; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(order == DOWN && strcmp(List[i].lastName, List[j].lastName) > 0)
            {
                aux = List[i];
                List[i] = List[j];
                List[j] = aux;
            }

            if(order == UPP && strcmp(List[i].lastName, List[j].lastName) < 0)
            {
                aux = List[i];
                List[i] = List[j];
                List[j] = aux;
            }
            if(order == UPP && strcmp(List[i].lastName, List[j].lastName) == 0)
            {
                if(List[i].sector > List[j].sector)
                {
                    aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
            }

            if(order == DOWN && strcmp(List[i].lastName, List[j].lastName) == 0)
            {
                if(List[i].sector < List[j].sector)
                {
                    aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
            }

            returno = 0;
        }
    }

    return returno;
}

int totalSalary(Employee List[], int len, float* Promedy, float* Suma)
{
    int Counter = 0;
    int CounterMaxim = 0;
    int flag = 0;
    int index = 0;
    int returno = -1;
    float Acum = 0;

    for(index = 0; index < len; index++)
    {
        if(List[index].isEmpty == OCCUPIED)
        {
            Acum += List[index].salary;
            Counter++;
            returno = 0;
        }
    }

    *Promedy = Acum / Counter;

    *Suma = Acum;

    for(index = 0; index < len;  index++)
    {
        if(flag == 0 || List[index].salary > *Promedy)
        {
            CounterMaxim++;
            returno = 1;
        }
    }

    return returno;
}

int theString(char elString[], char mensaje[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", elString);

    return (strlen(elString));
}
