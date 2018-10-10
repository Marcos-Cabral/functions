#define OCUPADO 0
#define VACIO 1
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;
/** \brief inicia la empleados en true
 *
 * \param recibe un puntero al array de empleado
 * \param recibe la cantidad de empleados
 * \return -1 si hay error 0 si esta bien
 *
 */

int initEmployees(Employee*, int);

/** \brief carga un empleado si encuentra espacio, carga y valida los campos y los pasa a la estructura
 * \param len int cantidad
 * \param id int  recibe la id del empleado
 *
 */

 int addEmployee(Employee list[],int len, int id);
//int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief busca a un empleado por su ID
 *
 * \param Employee* recibe un array de empleados
 * \param int recibe la cantidad de empleados
 * \param int recibe la id del empleado
 * \return -1 si no encontro el empleado, 0 si lo encontro
 *
 */

int findEmployeeById(Employee*,int, int);

/** \brief pide el ingreso de la id, y llama a la funcion borrar
 *
 * \param Employee* recibe un array de empleados
 * \param int recibe el tamaño de empleados
 * \return int 1 si pudo borrar el empleado, 0 si no lo borro
 *
 */
int removeEmployee(Employee*, int);

/** \brief busca si el id coincide con un usuario, si lo encuentra pregunta si esta seguro de eliminarlo, si la respuesta es S le cambia el estado a VACIO (1)
 *
 * \param Employee* recibe un puntero al array de empleado
 * \param int recibe el id del empleado
 * \param int recibe la cantidad de empleados
 * \return int int 1 si pudo borrar el empleado, 0 si no lo borro
 *
 */
int borrar(Employee*, int, int);

/** \brief ordena los elementos de la estructura por apellido de menor a mayor, si son iguales llama a la funcion sortEmployeeBySector para ordenarlos por sectores
 *
 * \param list Employee* recibe un puntero al array de empleado
 * \param  int recibe la cantidad
 * \param  int recibe el orden para ordenar
 * \return int Return (-1) si no se pudo ordenar, 0 si salio bien
 *
 */
int sortEmployee(Employee*, int,int);

/** \brief ordena los elementos de la estructura por sectores
 *
 * \param list Employee* recibe un puntero al array de empleado
 * \param len int recibe la cantidad
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) si no se pudo ordenar, 0 si salio bien
 *
 */
int sortEmployeeBySector(Employee *, int );

/** \brief muestra el contenido del empleado
 *
 * \param list Employee* recibe un puntero al array de empleado
 * \param len int recibe la cantidad
 *
*/
void printEmployees(Employee*, int);

/** \brief permite editar un empleado pidiendo el ingreso de la id, si la id existe llama a la funcion modificarEmployee
 *
 * \param Employee* recibe un puntero al array de empleado
 * \param int recibe la cantidad de empleados
 * \return int retorna -1 si no se modifico nada, 0 si algo fue modificado
 *
 */
int editEmployee(Employee*, int);

/** \brief entra a un menu donde pregunta al usuario que desea modificar, y valida los datos
 *
 * \param Employee* recibe un puntero al array de empleado
 * \param recibe la posicion donde se encontro el usuario a modificar
 * \return retorna -1 si no se modifico nada, 0 si algo fue modificado
 *
 */

int modificarEmployee(Employee*, int);

/** \brief busca si existe espacio disponible para cargar un empleado nuevo
 *
 * \param Employee* recibe un puntero al array de empleado
 * \param int recibe la cantidad del array
 * \return int retorna -1 si no hay espacio, sino retorna el indice donde existe espacio para cargar
 *
 */
int findSpace(Employee*, int);

/** \brief muestra la id y nombre del usuario, son usadas al modificar o eliminar un empleado
 *
 * \param Employee* recibe un puntero al array de empleado
 * \param int recibe la cantidad de empleados
 * \return
 *
 */
void mostrarId(Employee*, int);

/** \brief calcula el salario maximo, si hay usuarios cargados calcula el promedio
 *
 * \param Employee* recibe un puntero al array de empleado
 * \param int recibe la cantidad del array
 *
 */
void findSalaryMax(Employee*, int);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char []);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param  Es el mensaje a ser mostrado
 * \param  Array donde se cargará el texto ingresado
 * \return void
 */
int esSoloLetras(char []);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char[],char[]);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param Es el mensaje a ser mostrado
 * \param Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */

int getStringLetras(char[],char[]);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param  Es el mensaje a ser mostrado
 * \param  Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char [],char []);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param Es el mensaje a ser mostrado
 * \param Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char [],char[]);
/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param  Es el mensaje a ser mostrado para solicitar el dato
 * \param  Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char [],char[]);

/**
 * \brief Solicita un string
 * \param  Es el mensaje a ser mostrado para solicitar el dato
 * \param  Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char[],char[], char[]);
/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param  Es el mensaje a ser mostrado para solicitar el dato
 * \param  Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidFloat(char[],char[]);

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param  Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoFlotante(char[]);


/** \brief pide el orden para ordenar la lista 1) para ordenar ascendentemente o 0) para ordenar descendentemente
 *
 * \return int retorna el orden
 *
 */
int darOrden();

