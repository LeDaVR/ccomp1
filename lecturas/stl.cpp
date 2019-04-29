vector------------------------------------------------------------------------------------------------------
T front();
//retorna el primer elemento
T back();
//retorna el ultimo elemento
T at(int x);
//retorna un elemento en la poscicion x verificando previamente si existe
bool empty();
//retorna true si el vector esta vacio
int size();
//retorna la cantidad de elementos en el contenedor
max_size();
//retorna la cantidad maxima de elementos que puede almacenar
capacity();
//retorna la cantidad de elementos que se pueden almacenar con la memoria actual
void clear();
//borra todos los elementos
void insert(int poscicion,T elemento);
//inserta elemento en poscicion
void insert(int poscicion,x.begin(),x.end());//x es un vector
//agrega un vector desde su inicia hasta el final
void insert(int poscicion,T nveces,T elemento);
// inserta elemento en poscicion nveces
void insert(int poscicion,arr,arr+n);
//agrega los elementos de una array hasta el elemento numero n
erase(int poscicion);
// elimina el elemento en poscicion
erase(segundo.begin()+a, segundo.begin()+b);
// Eliminación de un intervalo
// El último elemento del intervalo no se borra
pop_back();
//elimina el ultimo elemento
push_back(T elemento);
//agrega elemento al final
resize(int x);
//cambia el tamaño a x si es menor se eleminan los restantes si es mayor los nuevos son 0



