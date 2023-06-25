#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct {
    char objectID[50];
    double mass;
    double perihelionX;
    double perihelionY;
    double aphelionX;
    double aphelionY;
    double initialPosX;
    double initialPosY;
} ObjectDescription;

typedef struct {
    char queryID[50];
    char objectID[50];
    double time;
} Query;

#endif  // STRUCTURES_H