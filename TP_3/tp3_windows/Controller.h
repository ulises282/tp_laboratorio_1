int controller_loadIdFromBinary(char* path, int* ultimoId);
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee,int* ultimoId);
int controller_editEmployee(LinkedList* pArrayListEmployee, int* ultimoId);
int controller_removeEmployee(LinkedList* pArrayListEmployee,int* ultimoId);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_saveIdAsBinary(char* path, int* ultimoId);


