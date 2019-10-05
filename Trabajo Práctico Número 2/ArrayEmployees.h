#define UPP 1
#define DOWN 0

 /*******************************************
 * \brief La estructura Employee que permiten trabajar con los datos almacenados
 *        la cual representa los datos de un empleado de la empresa
 *
 * \param id int          Numero de identidad
 * \param name[] char     Nombre del empleado
 * \param lastName[] char Apellido del empleado
 * \param salary float    Salario del empleado
 * \param sector int      Sector de trabajo del empleado(numero)
 * \param isEmpty int     Estado del array del empleado, si esta libre sera FREE y de lo contrario ocupado sera OCCUPIED
.*
 ********************************************/
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;


 /*******************************************
 * \brief  Indica posiciones del array que se encuentran vacias
 *
 * \param  List[]      Employee Array
 * \param  len int     Tamanio del array
 * \return returno int Si esta libre retorna FREE, de lo contrario retornara -1
 *
 ********************************************/
int initEmployees(Employee List[], int len);
int searchFree(Employee List[], int len);
int addEmployee(Employee List[], int len, int id, char name[], char lastName[], float salary, int sector);
int selectId(Employee list[], int len);
int uppEmployee(Employee List[], int len);
int findEmployeeById(Employee List[], int len,int id);
void printEmployee(Employee TheEmployee);
int printEmployees(Employee List[], int length);
int removeEmployee(Employee List[], int len, int id);
int sortEmployees(Employee List[], int len, int order);
int totalSalary(Employee List[], int len, float* Promedy, float* Suma);
int theString(char elString[], char mensaje[]);
