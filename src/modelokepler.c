#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../structures.h"

#define PI 3.14159265358979323846
#define G 6.67430e-11
void parseFile(const char* filename, ObjectDescription** objects, int* numObjects, Query** queries, int* numQueries);
/**
 * @brief Simula el modelo de Kepler para objetos y consultas dados.
 *
 * La función simula el modelo de Kepler utilizando los datos de los objetos y las consultas
 * proporcionados. Calcula la posición del objeto en el tiempo especificado por cada consulta
 * y escribe los resultados en el archivo "respuestas.txt".
 *
 * @param objects Arreglo de estructuras ObjectDescription que contiene los objetos.
 * @param numObjects Número de objetos en el arreglo.
 * @param queries Arreglo de estructuras Query que contiene las consultas.
 * @param numQueries Número de consultas en el arreglo.
 */
void simulateKepler(ObjectDescription* objects, int numObjects, Query* queries, int numQueries) {
    FILE* file = fopen("respuestas.txt", "w");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de respuestas.\n");
        return;
    }

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
            fprintf(file, "Objeto con ID '%s' no encontrado.\n", query.objectID);
            continue;
        }

        // Calcular la excentricidad de la órbita
        double e = sqrt(pow(object.aphelionX - object.perihelionX, 2) + pow(object.aphelionY - object.perihelionY, 2));

        // Calcular el semieje mayor de la órbita
        double a = (object.aphelionX - object.perihelionX) / (1 + e);

        // Calcular la posición radial en función del tiempo
        double T = 2 * M_PI * sqrt(pow(a, 3) / G * object.mass); // Calcular el período orbital (usando una constante G adecuada)
        double r = a * (1 - pow(e, 2)) / (1 + e * cos((2 * M_PI * query.time) / T));

        // Calcular la anomalía verdadera
        double E = 2 * atan(sqrt((1 + e) / (1 - e)) * tan(query.time * PI / T));
        double theta = 2 * atan(sqrt((1 + e) / (1 - e)) * tan(E / 2));

        // Calcular las coordenadas X e Y
        double x = r * cos(theta);
        double y = r * sin(theta);

        // Escribir resultado en el archivo
        fprintf(file, "Consulta ID: %s\n", query.queryID);
        fprintf(file, "Objeto ID: %s\n", query.objectID);
        fprintf(file, "Tiempo: %.2lf segundos\n", query.time);
        fprintf(file, "Posición X: %.2lf\n", object.initialPosX + x);
        fprintf(file, "Posición Y: %.2lf\n\n", object.initialPosY + y);
    }

    fclose(file);
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