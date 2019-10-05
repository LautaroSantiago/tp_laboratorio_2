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
 * \brief  Busca que este vacio el estado
 *
 * \param  List[] Employee
 * \param  len int
 * \return returno int     Devuelve -1 si no encuentra lugar libre
 *
 ********************************************/
int searchFree(Employee List[], int len);

 /*******************************************
 * \brief Carga datos del empleado
 *
 * \param  List[] Employee
 * \param  len int
 * \param  id int
 * \param  name char[]
 * \param  lastName[] char
 * \param  salary float
 * \param  sector int
 * \return returno int
 *
 ********************************************/
int addEmployee(Employee List[], int len, int id, char name[], char lastName[], float salary, int sector);

 /*******************************************
 * \brief Crea id consecutivo para el empleado
 *
 * \param  list[] Employee
 * \param  len int
 * \return id int
 *
 ********************************************/
int selectId(Employee list[], int len);

 /*******************************************
 * \brief Alta del empleado
 *
 * \param  List[] Employee
 * \param  len int
 * \return index int
 *
 ********************************************/
int uppEmployee(Employee List[], int len);

 /*******************************************
 * \brief Busca id igual
 *
 * \param  List[] Employee
 * \param  len int
 * \param  id int
 * \return returno int
 *
 ********************************************/
int findEmployeeById(Employee List[], int len, int id);

 /*******************************************
 * \brief Muestra un empleado
 *
 * \param  TheEmployee Employee
 * \return printf void         Devuelve el mensaje con datos del empleado
 *
 ********************************************/
void printEmployee(Employee TheEmployee);

 /*******************************************
 * \brief Muestra todos los empleados cargados
 *
 * \param  List[] Employee
 * \param  length int
 * \return returno int
 *
 ********************************************/
int printEmployees(Employee List[], int length);

 /*******************************************
 * \brief Baja logica de un empleado
 *
 * \param  List[] Employee
 * \param  id int
 * \return returno int
 *
 ********************************************/
int removeEmployee(Employee List[], int len, int id);

 /*******************************************
 * \brief Ordena alfabeticamente y por sector
 *
 * \param  List[] Employee
 * \param  len int
 * \param  order int
 * \return returno int Devuelve 0 o -1
 *
 ********************************************/
int sortEmployees(Employee List[], int len, int order);

 /*******************************************
 * \brief Realiza calculos del salario
 *
 * \param  List[] Employee
 * \param  len int
 * \param  Promedy float*
 * \param  Suma float*
 * \return returno int
 *
 ********************************************/
int totalSalary(Employee List[], int len, float* Promedy, float* Suma);

 /*******************************************
 * \brief Muestra el mensaje
 *
 * \param  elString[] char
 * \param  mensaje[] char
 * \return (strlen(elString))
 *
 ********************************************/
int theString(char elString[], char mensaje[]);
