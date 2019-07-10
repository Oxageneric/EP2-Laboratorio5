#include "lab5.h"

void main(){
    abb *arbol;
    arbol = iniciaArbol();

    arbol = InsertarValorArbol(arbol,1);
    arbol = InsertarValorArbol(arbol,2);
    arbol = InsertarValorArbol(arbol,3);

    int cantidad = 0;

    cantidad = obtenerCantidad(arbol);
    printf("la cantidad de datos son %d\n",cantidad);

    char *arreglo = NULL;
    arreglo=(char *)malloc(sizeof(char)*(cantidad+1));

    creaArbolEnArreglo(arbol,arreglo);
    printf("\nRESULTADO FINAL: %s\n",arreglo);

    muestraArbolEnTerminal(arbol,0);
    eliminarArbol(arbol);
    free(arreglo);
}
