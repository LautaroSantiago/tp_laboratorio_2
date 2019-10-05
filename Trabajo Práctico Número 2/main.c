
/*****************************************************
*                                                    *
*  Alumno: Lautaro Santiago Subeldia                 *
*                                                    *
*  https://github.com/LautaroSantiago                *
*                                                    *
*  \brief Sistema administrador para 1000 empleados  *
*                                                    *
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define ELEMENT 1000


int main()
{
    int opcion;
    int opcion2;
    int id;
    int index;
    int contador = 0;
    float suma = 0;
    float promedio = 0;
    char seguir;

    Employee listEmployee[ELEMENT];
    initEmployees(listEmployee, ELEMENT);

        do
        {
            printf("\tMENU: \n\n");
            printf(" 1. ALTA \n");
            printf(" 2. MODIFICAR \n");
            printf(" 3. BAJA \n");
            printf(" 4. INFORMES \n");
            printf(" 5. SALIR \n\n");
            scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    uppEmployee(listEmployee, ELEMENT);
                    break;
                case 2:
                    if(findEmployeeById(listEmployee, ELEMENT, selectId(listEmployee, ELEMENT)) != -1)
                    {
                        printf("\t MODIFICAR: \n\n");
                        printf("  1. NOMBRE\n");
                        printf("  2. APELLIDO\n");
                        printf("  3. SALARIO\n");
                        printf("  4. SECTOR\n\n");
                        scanf("%d", &opcion2);

                        switch(opcion2)
                        {
                            case 1:
                                index = findEmployeeById(listEmployee, ELEMENT, selectId(listEmployee, ELEMENT));
                                theString(listEmployee[index].name, "\n-Ingrese el nuevo nombre: ");
                                break;
                            case 2:
                                index = findEmployeeById(listEmployee, ELEMENT, selectId(listEmployee, ELEMENT));
                                theString(listEmployee[index].lastName, "\n-Ingrese el nuevo apellido: ");
                                break;
                            case 3:
                                index = findEmployeeById(listEmployee, ELEMENT, selectId(listEmployee, ELEMENT));
                                printf("\n-Ingrese nuevo salario: ");
                                scanf("%f", &listEmployee[index].salary);
                                break;
                            case 4:
                                index = findEmployeeById(listEmployee, ELEMENT, selectId(listEmployee, ELEMENT));
                                printf("\n-Ingrese nuevo sector");
                                scanf("%d", &listEmployee[index].sector);
                                break;
                            default:
                            printf("\nOpcion no valida\n");
                        }
                    }
                    else
                    {
                        printf("\nNo hay empleados ingresados\n");
                    }
                    break;
                case 3:
                    id = selectId(listEmployee, ELEMENT);

                    if((removeEmployee(listEmployee , ELEMENT, id)) == -1)
                    {
                        printf("\nNo hay empleados ingresados con ese id\n");
                    }
                    break;
                case 4:
                    sortEmployees(listEmployee, ELEMENT, UPP);

                    if((printEmployees(listEmployee, ELEMENT)) == -1)
                    {
                        printf("\nNo hay empleados ingresados\n");
                    }
                    else
                    {
                        contador = totalSalary(listEmployee, ELEMENT, &promedio, &suma);
                        printf("\n-Suma de los salarios: %.2f\n", suma);
                        printf("\n-Promedio de los salarios: %.2f\n", promedio);
                        printf("\n-Cantidad de empleados que superan el salario promedio: %d\n", contador);
                    }
                    break;
                case 5:
                    printf("\nPara salir oprima 's'\n");
                    fflush(stdin);
                    scanf("%c", &seguir);
                    break;
                default:
                    printf("\n\nOpcion invalida\n\n");
            }
            system("pause");
            system("cls");
        }
        while(seguir != 's');
}
