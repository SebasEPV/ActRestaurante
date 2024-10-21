#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char **alimentos = NULL;
    char nuevaComida[50] = "";
    char opcion = 's';
    int size = 0;
    float *precios = NULL;
    float precio = 0;
    int *cantidad = NULL;
    bool pedido = true;
    int tempCant = 0;
    float total = 0;

    printf("Que desea ordenar?\n");

    do {
        printf("Introduce el alimento: ");
        scanf("%s", nuevaComida);

        printf("Introduce el precio: ");
        scanf("%f", &precio);

        alimentos = (char **)realloc(alimentos, (size + 1) * sizeof(char *));
        precios = (float *)realloc(precios, (size + 1) * sizeof(float));
        cantidad = (int *)realloc(cantidad, (size + 1) * sizeof(int));

        if (alimentos == NULL || precios == NULL || cantidad == NULL) {
            printf("Error al asignar memoria.\n");
            return 1;
        }

        alimentos[size] = (char *)malloc((strlen(nuevaComida) + 1) * sizeof(char));
        strcpy(alimentos[size], nuevaComida);
        precios[size] = precio;
        cantidad[size] = 0;

        size++;

        printf("Quieres agregar otro alimento? (s/n): ");
        scanf(" %c", &opcion);

    } while (opcion == 's' || opcion == 'S');

    printf("\nMenu del restaurante SM41:\n");
    for (int i = 0; i < size; i++) {
        printf("%d.- %s (Precio: $%.2f)\n", i + 1, alimentos[i], precios[i]);
    }

    while (pedido) {
        printf("\nQue deseas ordenar? (Introduce la cantidad para cada alimento):\n");
        for (int i = 0; i < size; i++) {
            printf("%s: ", alimentos[i]);
            scanf("%d", &tempCant);
            cantidad[i] += tempCant;
        }

        printf("Desea ordenar algo mas? (s/n): ");
        scanf(" %c", &opcion);

        if (opcion == 'n' || opcion == 'N') {
            pedido = false;
        }
    }

    printf("\nPedido Total:\n");
    for (int i = 0; i < size; i++) {
        if (cantidad[i] > 0) {
            float subtotal = cantidad[i] * precios[i];
            printf("%s: %d x $%.2f = $%.2f\n", alimentos[i], cantidad[i], precios[i], subtotal);
            total += subtotal;
        }
    }

    printf("\nTotal a pagar: $%.2f\n", total);

    for (int i = 0; i < size; i++) {
        free(alimentos[i]);
    }
    free(alimentos);
    free(precios);
    free(cantidad);

    return 0;
}
