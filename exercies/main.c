#include <stdio.h>
#include "nodo.h"

void mostrarLista(Nodo* inicio) {
    Nodo *n = inicio;
    while (n != NULL) {
        printf("Dato: %d\n", n->dato);
        n = n->siguiente;
    }
}

int main() {
    int opcion;
    do {
        printf("\n===== Menu TAD Nodo =====\n");
        printf("1. Crear un nodo con valor\n");
        printf("2. Crear arreglo de nodos con calloc\n");
        printf("3. Agregar nodo con realloc\n");
        printf("4. Liberar memoria de nodos\n");
        printf("5. Construir tres nodos enlazados\n");
        printf("6. Contar nodos de una lista\n");
        printf("7. Crear nodos desde entrada\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: {
                int valor;
                printf("Ingresa el valor del nodo: ");
                scanf("%d", &valor);
                Nodo* n1 = crearNodo(valor);
                if (n1 != NULL) {
                    printf("Nodo creado con dato: %d\n", n1->dato);
                    liberarNodos(n1, 1);
                }
                break;
            }
            case 2: {
                int n;
                printf("Cuantos nodos quieres crear: ");
                scanf("%d", &n);
                Nodo* arreglo = crearArregloNodos(n);
                if (arreglo != NULL) {
                    printf("Arreglo de %d nodos creado (calloc):\n", n);
                    for (int i = 0; i < n; i++) {
                        printf("  arreglo[%d].dato = %d\n", i, (arreglo + i)->dato);
                    }
                    liberarNodos(arreglo, n);
                }
                break;
            }
            case 3: {
                int n = 3;
                Nodo* arreglo = crearArregloNodos(n);
                printf("Arreglo inicial de %d nodos:\n", n);
                for (int i = 0; i < n; i++) {
                    printf("  arreglo[%d].dato = %d\n", i, (arreglo + i)->dato);
                }
                int valor;
                printf("Ingresa el valor del nuevo nodo: ");
                scanf("%d", &valor);
                arreglo = agregarNodo(arreglo, &n, valor);
                printf("Arreglo actualizado con realloc:\n");
                for (int i = 0; i < n; i++) {
                    printf("  arreglo[%d].dato = %d\n", i, (arreglo + i)->dato);
                }
                liberarNodos(arreglo, n);
                break;
            }
            case 4: {
                int n = 3;
                Nodo* arreglo = crearArregloNodos(n);
                printf("Arreglo de %d nodos creado\n", n);
                liberarNodos(arreglo, n);
                printf("Memoria liberada correctamente\n");
                break;
            }
            case 5: {
                Nodo* inicio = construirTresNodos();
                printf("Nodos enlazados manualmente:\n");
                mostrarLista(inicio);
                liberarNodos(inicio, 1);
                break;
            }
            case 6: {
                Nodo* inicio = construirTresNodos();
                int total = contarNodos(inicio);
                printf("Lista de nodos:\n");
                mostrarLista(inicio);
                printf("Total de nodos: %d\n", total);
                liberarNodos(inicio, 1);
                break;
            }
            case 7: {
                Nodo* lista = crearNodosPorEntrada();
                printf("Lista creada desde entrada:\n");
                mostrarLista(lista);
                printf("Total de nodos: %d\n", contarNodos(lista));
                break;
            }
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opcion != 0);

    return 0;
}
