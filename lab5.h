#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _arbol{
    int valor;
    struct _arbol *hijoizq,*hijoder;
    }abb;

int esArbolVacio(abb *arbol){
    if(arbol == NULL){
        return 0;
    }
    return 1;
}

abb *iniciaArbol(){
    abb *aux = NULL;
    return aux;
}

abb *InsertarValorArbol(abb *arbol,int valor){
    if(esArbolVacio(arbol) == 1){
        if(valor < arbol->valor){
            arbol->hijoizq = InsertarValorArbol(arbol->hijoizq,valor);
        }else if(valor > arbol->valor){
            arbol->hijoder = InsertarValorArbol(arbol->hijoder,valor);
        }
    }else{
        arbol = malloc(sizeof(abb));
        arbol->valor = valor;
        arbol->hijoder = NULL;
        arbol->hijoizq = NULL;
        }
    return(arbol);
}

void eliminarArbol(abb *arbol){
    if(esArbolVacio(arbol) == 1){
        eliminarArbol(arbol->hijoizq);
        eliminarArbol(arbol->hijoder);
        printf("se libero de la memoria el valor %d\n",arbol->valor);
        free(arbol);
        arbol = NULL;
    }
}

int recorreArbol(abb *arbol,int *cantidad){
    if(esArbolVacio(arbol) == 1){
        (*cantidad)++;
        recorreArbol(arbol->hijoizq,cantidad);
        recorreArbol(arbol->hijoder,cantidad);
    }
    return(*cantidad);
}

int obtenerCantidad(abb *arbol){
    int cantidad = 0;
    cantidad = recorreArbol(arbol,&cantidad);
    return(cantidad);
}

char *escribe(char *valor,char *arreglo){
    strcat(arreglo,valor);
    return(arreglo);
}

void creaArbolEnArreglo(abb *arbol,char arreglo[]){
    if(esArbolVacio(arbol) == 1){
        char *valor;
        valor = (char *)malloc(sizeof(char)*2);
        sprintf(valor,"%i",arbol->valor);  //converti el entero a char
        printf("\nDATO DEL ARBOL %s",valor);
        escribe(valor,arreglo);
        creaArbolEnArreglo(arbol->hijoizq,arreglo);
        creaArbolEnArreglo(arbol->hijoder,arreglo);
    }else{
        escribe("N",arreglo);
    }
}

void espaciado(char n,int nivel){
    int espacio;

    for(espacio = 0; espacio < nivel; espacio++){
        printf("%c",n);
    }
}

void muestraArbolEnTerminal(abb *arbol, int nivel){
    if(esArbolVacio(arbol) == 1){
        muestraArbolEnTerminal(arbol->hijoder,nivel+1);
        espaciado('\t',nivel);
        printf("%d\n",arbol->valor);
        muestraArbolEnTerminal(arbol->hijoizq,nivel+1);
    }else{
        espaciado('\t',nivel);
        printf("N\n");
    }
}
