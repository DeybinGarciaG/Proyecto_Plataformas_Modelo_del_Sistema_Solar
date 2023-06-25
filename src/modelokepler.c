#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../structures.h"

#define PI 3.14159265358979323846
void simulateKepler(ObjectDescription* objects, int numObjects, Query* queries, int numQueries) {
    for (int i = 0; i < numQueries; i++) {
        Query query = queries[i];
        ObjectDescription object;

        // Encontrar el objeto correspondiente a la consulta
        int found = 0;
        for (int j = 0; j < numObjects; j++) {
            if (strcmp(objects[j].objectID, query.objectID) == 0) {
                object = objects[j];
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Objeto con ID '%s' no encontrado.\n", query.objectID);
            continue;
        }

        // Calcular excentricidad
        double e = sqrt(pow(object.aphelionX - object.perihelionX, 2) + pow(object.aphelionY - object.perihelionY, 2));

        // Calcular semieje mayor
        double a = (object.aphelionX - object.perihelionX) / (1 + e);

        // Calcular posición radial
        double T = 2 * PI * sqrt(pow(a, 3) / object.mass);  // Período orbital
        double r = a * (1 - pow(e, 2)) / (1 + e * cos((2 * PI * query.time) / T));

        // Calcular anomalía verdadera
        double E = (2 * PI * query.time) / T;
        double error = 1e-8;
        double prevE = 0.0;
        while (fabs(E - prevE) > error) {
            prevE = E;
            E = E - (E - e * sin(E) - (2 * PI * query.time) / T) / (1 - e * cos(E));
        }
        double theta = 2 * atan(sqrt((1 + e) / (1 - e)) * tan(E / 2));

        // Calcular coordenadas X e Y
        double x = r * cos(theta);
        double y = r * sin(theta);

        // Imprimir resultado
        printf("Consulta ID: %s\n", query.queryID);
        printf("Objeto ID: %s\n", query.objectID);
        printf("Tiempo: %.2lf segundos\n", query.time);
        printf("Posición X: %.2lf\n", object.initialPosX + x);
        printf("Posición Y: %.2lf\n\n", object.initialPosY + y);
    }
}

int main() {
    ObjectDescription* objects = NULL;
    int numObjects = 0;
    Query* queries = NULL;
    int numQueries = 0;

    parseFile("archivo.txt", &objects, &numObjects, &queries, &numQueries);

    // Hacer uso de los datos almacenados en las estructuras objects y queries
    simulateKepler(objects, numObjects, queries, numQueries);
    // Liberar memoria dinámica
    free(objects);
    free(queries);

    return 0;
}
