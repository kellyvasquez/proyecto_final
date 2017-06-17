#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Rango 10000
#define reservar_memoria (nodo*)malloc(sizeof(nodo))

struct nodo{
    int dato;
    nodo *siguiente;
    nodo *anterior;
    nodo *izq;
    nodo *der; };

nodo *cabeza=NULL, *cola=NULL, *arbol=NULL;

void menu();
void generar_archivo(); /**GENERAR RANDOM**/
void insertar_lista_archivo(nodo *&, nodo *&, int); /**INSERTAR EN LISTA**/
void imprimir_lista_archivo(nodo *); /**IMPRIMIR LISTA**/
int Busqueda_secuencial(nodo *, nodo *, int); /**METODO DE BUSQUEDA SECUENCIAL**/
void MetodoBurbuja(nodo *); /** METODO DE ORDENAMIENTO BURBUJA **/
void MetodoInserccion(nodo *&, nodo *&); /** METODO DE ORDENAMIENTO INSERCCION **/
void intercambio(nodo *&, nodo*&);
void MetodoSeleccion(nodo *); /** METODO DE ORDENAMIENTO SELECCION **/

void generar_archivo_arbol();
nodo *CrearNodo(int); /**CREAR NUEVO NODO EN EL ARBOL**/
void insertar_arbol_archivo(nodo *&, int); /**INSERTAR EN ARBOL**/
void imprimir_arbol_archivo(nodo *);

int main(){
    menu();
    return 0;
}

/**FUNCION QUE CONTIENE EL MENU**/
void menu(){

    int opc, k;

    printf("\n\n        MENU - METODOS DE ORDENAMIENTO \n\n");
    printf(" 1. Generar un archivo random en una lista\n");
    printf(" 2. Buscar un numero por el metodo secuencial\n");
    printf(" 3. Ordenar el archivo con el metodo burbuja\n");
    printf(" 4. Ordenar el archivo con el metodo inserccion\n");
    printf(" 5. Ordenar el archivo con el metodo seleccion\n");
    printf(" ------------------------------------------------\n");
    printf(" 6. Generar un archivo random en un arbol y mostrarlo ordenado\n");
    printf(" 0. Salir\n\n");
    printf("Opcion: "); scanf("%d", &opc);

    switch(opc){
        case 0:
            exit(0);
        break;

        case 1:
            generar_archivo();
            menu();
        break;

        case 2:
            printf("Ingrese el numero que desea buscar del random: "); scanf("%d", &k);
            printf("%d", Busqueda_secuencial(cabeza,cola,k));
            menu();
        break;

        case 3:
            MetodoBurbuja(cabeza);
        break;

        case 4:
            MetodoInserccion(cabeza, cola);
        break;

        case 5:
            MetodoSeleccion(cabeza);
        break;

        case 6:
            generar_archivo_arbol();
        break;

        default:
            printf("La opcion no es valida!!! \n");
            menu();
        break;
    }

}

void generar_archivo(){ /** GENERAR NUMEROS ALEATORIOS **/

    int i=0, n;
    char num[7];
    srand(time(NULL));
    FILE *archivo;
    archivo = fopen("copia_archivo.txt","w");
    printf("\n\n    Generando Lista... \n\n");
    while(i<Rango){
        n = (rand() % (1999998+1)) - 999999;
        sprintf(num,"%d", n);
        insertar_lista_archivo(cabeza, cola, n);
        fputs(num, archivo);
        putc(',', archivo);
        i++;
    }

    imprimir_lista_archivo(cabeza);
    system("pause");
}

void generar_archivo_arbol(){ /** GENERAR NUMEROS ALEATORIOS **/

    long inicio,fin;
    inicio = clock();
    int i=0, n;
    char num[7];
    srand(time(NULL));
    FILE *archivo;
    archivo = fopen("copia_archivo.txt","w");
    printf("\n\n    Generando Lista... \n\n");
    while(i<Rango){
        n = (rand() % (1999998+1)) - 999999;
        sprintf(num,"%d", n);
        insertar_arbol_archivo(arbol, n);
        fputs(num, archivo);
        putc(',', archivo);
        i++;
    }

    imprimir_arbol_archivo(arbol);
    system("pause");
    fin=clock();
    printf("\n\n Tiempo que tardo en segundos %f s\n\n",(fin-inicio)/(float)CLOCKS_PER_SEC);
}

/** FUNCION PARA INSERTAR ELEMENTOS EN UNA LISTA **/
void insertar_lista_archivo(nodo *&cabeza, nodo *&cola, int n){
    nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
    if(cabeza == NULL){
        cabeza = nuevo_nodo;
        cola = cabeza;
    }else{
        cola->siguiente = nuevo_nodo;
        cola = nuevo_nodo;
    }
}

/**  FUNCION PARA IMPRIMIR ELEMENTOS DE LA LISTA**/
void imprimir_lista_archivo(nodo *cabeza){
    if(cabeza != NULL){
        nodo *actual = reservar_memoria;
        actual = cabeza;
        while(actual != NULL){
            printf("%d, ", actual->dato);
            actual = actual->siguiente;
        }
    }else{
        printf("La lista esta vacia\n");
    }
}

/** METODO BUSQUEDA SECUENCIAL**/
int Busqueda_secuencial(nodo *cabeza, nodo *cola, int k){

    nodo *aux = cabeza;
    if( cabeza == NULL){//retorna 0 cuando no tiene elementos la lista
        return 0;
    }
    else{
        while(aux != NULL){

            if(aux ->dato == k){return 1;}
            aux = aux ->siguiente;

        }
        return 0;
    }
    return 0;
}

/** ORDENAR UNA LISTA POR EL METODO BURBUJA **/
void MetodoBurbuja (nodo *cabeza){

    long inicio,fin;
    inicio = clock();
    printf("\n\n\n   Ordenando por el metodo burbuja... \n");
    if(cabeza != NULL){
		nodo *p = reservar_memoria;
		nodo *j = reservar_memoria;
		int aux;
		p = cabeza;
		while(p != NULL){
			j = p->siguiente;
			while(j != NULL){
				if(p->dato > j->dato){
					aux = j->dato;
					j->dato = p->dato;
					p->dato = aux;
				}
				j = j->siguiente;
			}
			p = p->siguiente;
		}
    printf("\n\n");
    imprimir_lista_archivo(cabeza);
    fin=clock();
    printf("\n\n Tiempo que tardo en %f s\n\n",(fin-inicio)/(float)CLOCKS_PER_SEC);

	}
}

/** ¡¡CORREGIR!!  ORDENAR UNA LISTA POR EL METODO INSERCCION **/
void MetodoInserccion (nodo *&cabeza, nodo *&cola){

    long inicio,fin;
    inicio = clock();
    printf("\n\n\n   Ordenando por el metodo inserccion... \n");

    if(cabeza==cola || cabeza==NULL){return;}
    nodo *&aux=cabeza;

    while(aux!=NULL){
       nodo *&recorrer=aux;
       nodo *&pre=aux;
       int fin=0;

       while (recorrer->anterior !=NULL && fin!=0){
        pre=pre->anterior;
        if(recorrer->dato < pre->dato){
            intercambio(recorrer, pre);
            recorrer=pre;
        }else if(recorrer->dato > pre->dato){
                fin=1;}

        }aux=aux->siguiente;
    }

    printf("\n\n");
    imprimir_lista_archivo(cabeza);
    fin=clock();
    printf("\n\n Tiempo que tardo en segundos %f s\n\n",(fin-inicio)/(float)CLOCKS_PER_SEC);

}

void intercambio(nodo *&a, nodo *&b){
    int aa=a->dato;
    int bb=b->dato;

    a->dato=bb;
    b->dato=aa;

}

/** ORDENAR UNA LISTA POR EL METODO SELECCION **/
void MetodoSeleccion (nodo *cabeza){

    long inicio,fin;
    inicio = clock();
    printf("\n\n\n   Ordenando por el metodo seleccion... \n");
    if(cabeza != NULL){
		nodo *p = reservar_memoria;
		nodo *j = reservar_memoria;
		int aux, menor;
		p = cabeza;
		while(p != NULL){
			menor = p->dato;
			j = p;
			while(j != NULL){
				if(menor > j->dato){
					menor = j->dato;
					aux = p->dato;
					p->dato = menor;
					j->dato = aux;
				}
				j = j->siguiente;
			}
			p = p->siguiente;
		}
    printf("\n\n");
    imprimir_lista_archivo(cabeza);
    fin=clock();
    printf("\n\n Tiempo que tardo en segundos %f s \n\n",(fin-inicio)/(float)CLOCKS_PER_SEC);

	}
}

/** FUNCIÓN PARA CREAR UN NUEVO NODO DEL ARBOL **/
nodo *CrearNodo(int n){
    nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo->dato = n;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->der = NULL;

    return nuevo_nodo;
}

/** FUNCION PARA INSERTAR ELEMENTOS EN EL ARBOL  **/
void insertar_arbol_archivo(nodo *&arbol, int n){
    if(arbol == NULL){ //SI EL ARBOL ESTÁ VACIO
        nodo *nuevo_nodo = CrearNodo(n);
        arbol = nuevo_nodo;
    }else{ //SI EL ARBOL TIENE UN NODO O MÁS
        int valorRaiz = arbol->dato;
        if(n < valorRaiz){
            insertar_arbol_archivo(arbol->izq,n);
        }else{
            insertar_arbol_archivo(arbol->der,n); }
    }
}

/** MOSTRAR ARBOL COMPLETO EN ORDEN     **/
void imprimir_arbol_archivo(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        imprimir_arbol_archivo(arbol->izq);
        printf(" %d, ", arbol->dato);
        imprimir_arbol_archivo(arbol->der);
    }
}
