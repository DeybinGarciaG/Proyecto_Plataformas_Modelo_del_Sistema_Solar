#include "../structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void parseFile(const char* filename, ObjectDescription** objects, int* numObjects, Query** queries, int* numQueries) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[256];
    int isDescriptionSection = 0;
    int isQuerySection = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '[') {
            if (strcmp(line, "[descripcion]\n") == 0) {
                isDescriptionSection = 1;
                isQuerySection = 0;
            } else if (strcmp(line, "[consultas]\n") == 0) {
                isDescriptionSection = 0;
                isQuerySection = 1;
            }
        } else {
            if (isDescriptionSection) {
                ObjectDescription object;
                sscanf(line, "%[^,],%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", object.objectID, &object.mass,
                       &object.perihelionX, &object.perihelionY, &object.aphelionX, &object.aphelionY,
                       &object.initialPosX, &object.initialPosY);
                (*numObjects)++;
                *objects = realloc(*objects, (*numObjects) * sizeof(ObjectDescription));
                (*objects)[(*numObjects) - 1] = object;
            } else if (isQuerySection) {
                Query query;
                sscanf(line, "%[^,],%[^,],%lf\n", query.queryID, query.objectID, &query.time);
                (*numQueries)++;
                *queries = realloc(*queries, (*numQueries) * sizeof(Query));
                (*queries)[(*numQueries) - 1] = query;
            }
        }
    }

    fclose(file);
}
