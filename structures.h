/********************************************
 *             structures.h
 ********************************************/

/**
 * @file structures.h
 * @brief Definiciones de estructuras para describir objetos y consultas.
 *
 * Este archivo contiene las definiciones de las estructuras ObjectDescription y Query,
 * que se utilizan para describir objetos y consultas relacionadas con ellos, respectivamente.
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H

/**
 * @struct ObjectDescription
 * @brief Estructura que describe las propiedades de un objeto.
 *
 * Esta estructura se utiliza para almacenar la descripción de un objeto,
 * incluyendo su identificador, masa, coordenadas de perihelio y afelio,
 * así como las coordenadas iniciales.
 */
typedef struct {
    char objectID[50]; /**< Identificador del objeto */
    double mass; /**< Masa del objeto */
    double perihelionX; /**< Coordenada X del perihelio */
    double perihelionY; /**< Coordenada Y del perihelio */
    double aphelionX; /**< Coordenada X del afelio */
    double aphelionY; /**< Coordenada Y del afelio */
    double initialPosX; /**< Coordenada X inicial */
    double initialPosY; /**< Coordenada Y inicial */
} ObjectDescription;

/**
 * @struct Query
 * @brief Estructura que representa una consulta relacionada con un objeto.
 *
 * Esta estructura se utiliza para almacenar la información de una consulta,
 * incluyendo su identificador, el identificador del objeto relacionado
 * y el tiempo asociado a la consulta.
 */
typedef struct {
    char queryID[50]; /**< Identificador de la consulta */
    char objectID[50]; /**< Identificador del objeto relacionado */
    double time; /**< Tiempo asociado a la consulta */
} Query;

#endif  // STRUCTURES_H