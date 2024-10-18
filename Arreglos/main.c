#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CANTIDAD 4 //Tamaño de los arreglos que usare
int main()
{
    char *alimentos[CANTIDAD] = {"Tacos", "Tortas", "Refrescos", "Boing"};
    float precios[CANTIDAD] = {20.00, 45.00, 25.00, 22.00};
    int cantidad[CANTIDAD] = {0};
    bool pedido = true;
    int tempCant = 0;
    char resp = "";
    float total = 0;

    printf("Bienvenidos al restaurante SM41 \nMenu: \n");
    for (int i = 0; i < CANTIDAD; i++)
    {
        printf("%d.- %s\n", i+1, alimentos[i]);
    }

    while (pedido) {
        printf("Que deseas ordenar:\n");
        for (int i = 0; i < CANTIDAD; i++)
        {
            printf("%s.- \n", alimentos[i]);
            scanf("%d", &tempCant);
            cantidad[i] = cantidad[i] + tempCant;
        }
        printf("Desea ordenar algo mas?(Y / N)\n");
        scanf("%s", &resp);

        if (resp == 'N' || resp == 'n'){
            pedido = false;
        }
    }

    printf ("Pedido Total:\n");
    for (int i = 0; i < CANTIDAD; i++){
        printf("%s: %d x %.2f = %.2f \n", alimentos[i], cantidad[i], precios[i], (cantidad[i] * precios[i]));
    }

    for (int i = 0; i < CANTIDAD; i++){
        total += cantidad[i] * precios[i];
    }
    printf("Total a pagar $%.2f", total);


    return 0;
}
