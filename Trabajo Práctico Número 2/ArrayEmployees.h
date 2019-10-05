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

 /*******************************************
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ********************************************/
int searchFree(Employee List[], int len);

 /*******************************************
 * \brief Carga datos del empleado
 *
 * \param
 * \param
 * \return
 *
 ********************************************/
int addEmployee(Employee List[], int len, int id, char name[], char lastName[], float salary, int sector);

 /*******************************************
 * \brief Crea id consecutivo para el empleado
 *
 * \param
 * \param
 * \return
 *
 ********************************************/
int selectId(Employee list[], int len);

 /*******************************************
 * \brief
 *
 * \param
 * \param
 * \return
 *
 ********************************************/
int uppEmployee(Employee List[], int len);

 /*******************************************
 * \brief Busca id igual
 *
 * \param
 * \param
 * \return
 *
 ********************************************/
int findEmployeeById(Employee List[], int len,int id);

 /*******************************************
 * \brief Muestra un empleado
 *
 * \param
 * \param
 * \return
 *
 ********************************************/
void printEmployee(Employee TheEmployee);

 /*******************************************
 * \brief Muestra todos los empleados
 *
 * \param
 * \param
 * \return
 *
 ********************************************/
int printEmployees(Employee List[], int length);

 /*******************************************
 * \brief Baja logica de un empleado
 *
 * \param
 * \param
 * \return
 *
 ********************************************/
int removeEmployee(Employee List[], int len, int id);

 /*******************************************
 * \brief Ordena alfabeticamente y por sector
 *
 * \param
 * \param
 * \return
 *
 ********************************************/
int sortEmployees(Employee List[], int len, int order);

 /*******************************************
 * \brief Realiza calculos del salario
 *
 * \param
 * \param
 * \return
 *
 ********************************************/
int totalSalary(Employee List[], int len, float* Promedy, float* Suma);

 /*******************************************
 * \brief Muestra el mensaje
 *
 * \param
 * \param
 * \return
 *
 ********************************************/
int theString(char elString[], char mensaje[]);
