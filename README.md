# Proyecto_Plataformas_Modelo_del_Sistema_Solar
# Modelo del Sistema Solar 4

**Estudiante:** [Deybin Garcia Garcia]
**Carnet:** [B93171]

## Índice
- [Introducción](#introducción)
- [Trasfondo](#trasfondo)
- [Diseño general](#diseño-general)
- [Principales retos](#principales-retos)
- [Conclusiones](#conclusiones)

## Introducción
En este proyecto, nos enfrentamos al emocionante desafío de desarrollar un programa de modelado capaz de simular un sistema solar utilizando un archivo de configuración como entrada. Nuestro objetivo principal es interpretar este archivo y generar un modelo detallado que pueda responder consultas específicas relacionadas con el sistema solar.

Para lograr este objetivo, nos sumergiremos en la investigación del modelo de Kepler, que describe con precisión las órbitas planetarias. Este modelo nos proporcionará las bases teóricas necesarias para simular de manera realista el movimiento de los planetas en nuestro programa. Como parte del proceso, documentaremos cuidadosamente nuestros hallazgos de manera organizada en un informe técnico.

El archivo de configuración constará de dos secciones fundamentales: una sección de descripción del modelo y una sección de consultas. El programa deberá ser capaz de interpretar la descripción y utilizarla para generar un modelo dinámico que pueda responder de manera precisa y eficiente a cada una de las consultas planteadas en el archivo.

La sección de descripción del archivo de configuración estará delimitada por la línea "[descripcion]". En esta sección, encontraremos diversas líneas, cada una representando los datos asociados a un objeto particular del sistema solar. Estos datos incluyen el ID del objeto, su masa en kilogramos y las coordenadas (X, Y) de su perihelio y afelio, así como también las coordenadas iniciales (X, Y) en el plano espacial al inicio de la simulación.

Por otro lado, la sección de consultas estará delimitada por la línea "[consultas]". En esta sección, encontraremos varias líneas, cada una representando una consulta específica. Cada consulta constará del ID de la consulta, el ID del objeto consultado y el tiempo transcurrido en segundos desde el inicio de la simulación.

Una vez que hayamos procesado e interpretado la descripción del modelo, nuestro programa se encargará de responder a cada una de las consultas formuladas. Utilizando el modelo de Kepler, calcularemos y proporcionaremos las coordenadas (X, Y) del objeto consultado en el tiempo especificado. Todas las respuestas se registrarán en un archivo de texto llamado "respuestas.txt", donde cada fila contendrá el ID de la consulta y las coordenadas (X, Y) correspondientes al objeto consultado en el tiempo indicado.

Durante la evaluación del código, se tendrán en cuenta diversos aspectos, como la organización y estructura del programa en diferentes archivos, el uso adecuado de estructuras de datos y la gestión de memoria dinámica, la claridad y legibilidad del código, así como también la documentación interna que explique el propósito y funcionamiento de cada parte del programa. La correctitud del programa, es decir, su capacidad para producir resultados precisos y coherentes, también será evaluada cuidadosamente.

Para facilitar el seguimiento y control de versiones del proyecto, crearemos un repositorio en GitHub. Daremos acceso al profesor (usuario @jccotoucr) para que pueda revisar y evaluar nuestro trabajo. Es importante destacar que solamente se tomará en cuenta el trabajo realizado hasta la fecha límite establecida.

Como parte del repositorio en GitHub, crearemos un archivo README en el nivel raíz. Este archivo contendrá información detallada sobre el proyecto, incluyendo el informe técnico que resume nuestra metodología, resultados y conclusiones.

Con nuestro enfoque dedicado y siguiendo estrictamente las especificaciones proporcionadas, esperamos cumplir con todos los requisitos del proyecto y entregar un programa funcional, bien estructurado y documentado que sea capaz de simular un sistema solar y responder de manera precisa a las consultas planteadas.

## Trasfondo
El programa consta de tres archivos: structures.h, file_parser.c y modelokepler.c. Analicemos cada uno de ellos para comprender el contexto y los modelos utilizados.

En el archivo structures.h, se definen dos estructuras: ObjectDescription y Query. La estructura ObjectDescription representa la descripción de un objeto en el sistema solar, con sus características como el ID del objeto, la masa, las coordenadas del perihelio y afelio, y las coordenadas iniciales en el plano espacial. La estructura Query se utiliza para representar una consulta específica, con su ID de consulta, el ID del objeto consultado y el tiempo transcurrido desde el inicio de la simulación. Estas estructuras proporcionan una forma organizada de almacenar y manipular los datos necesarios para el programa.

En el archivo file_parser.c, se encuentra la implementación de la función parseFile. Esta función se encarga de analizar un archivo de configuración y extraer la información relevante para la simulación del sistema solar. Utiliza la estructura de datos ObjectDescription y Query para almacenar los objetos y las consultas respectivamente. El archivo de configuración se divide en dos secciones delimitadas por "[descripcion]" y "[consultas]". En cada sección, se lee y se almacena la información correspondiente en las estructuras adecuadas. La función parseFile es responsable de asignar memoria dinámica a medida que se encuentran nuevos objetos y consultas en el archivo.

En el archivo modelokepler.c, se encuentra la función principal main y la función simulateKepler. La función simulateKepler utiliza los datos almacenados en las estructuras ObjectDescription y Query para simular el movimiento de los objetos en el sistema solar. En primer lugar, se abre un archivo llamado "respuestas.txt" donde se escribirán los resultados de las consultas. Luego, se recorren todas las consultas y se realiza el cálculo de las coordenadas (X, Y) del objeto consultado en el tiempo especificado. Para ello, se utilizan los principios del modelo de Kepler, que describe las órbitas planetarias. Se calcula la excentricidad, el semieje mayor, la posición radial, la anomalía verdadera y finalmente las coordenadas X e Y. Los resultados se escriben en el archivo "respuestas.txt" junto con la información de la consulta correspondiente.

En la función main, se llama a la función parseFile para procesar el archivo de configuración y obtener los objetos y consultas. Luego, se invoca la función simulateKepler, pasando los datos obtenidos. Después de la simulación, se libera la memoria dinámica asignada a las estructuras objects y queries.

En resumen, el programa utiliza las estructuras ObjectDescription y Query para almacenar los datos de los objetos y las consultas del sistema solar respectivamente. Utiliza el archivo de configuración como entrada y realiza cálculos basados en el modelo de Kepler para simular las órbitas planetarias y responder a las consultas especificadas.

## Diseño general
Archivo "structures.h"
El archivo "structures.h" es un archivo de encabezado que define dos estructuras de datos: "ObjectDescription" y "Query". Estas estructuras se utilizan para almacenar información sobre objetos astronómicos y consultas relacionadas con ellos.

La estructura "ObjectDescription" tiene los siguientes campos:

objectID: una cadena de caracteres que representa el identificador único del objeto (máximo 50 caracteres).
mass: un número de punto flotante que representa la masa del objeto.
perihelionX y perihelionY: números de punto flotante que representan las coordenadas X e Y del perihelio del objeto.
aphelionX y aphelionY: números de punto flotante que representan las coordenadas X e Y del afelio del objeto.
initialPosX y initialPosY: números de punto flotante que representan las coordenadas X e Y de la posición inicial del objeto.
La estructura "Query" tiene los siguientes campos:

queryID: una cadena de caracteres que representa el identificador único de la consulta (máximo 50 caracteres).
objectID: una cadena de caracteres que representa el identificador único del objeto asociado a la consulta.
time: un número de punto flotante que representa el tiempo de la consulta.
Estas estructuras proporcionan una manera estructurada de almacenar la información necesaria para el procesamiento del modelo de Kepler.

Archivo "file_parser.c"
El archivo "file_parser.c" implementa una función llamada parseFile que se encarga de analizar un archivo de texto y extraer la información de descripción de objetos y consultas. Esta función toma como argumentos el nombre del archivo, punteros a matrices de estructuras ObjectDescription y Query, y punteros a enteros que almacenan la cantidad de objetos y consultas, respectivamente.

La función comienza abriendo el archivo especificado y verificando si se pudo abrir correctamente. Luego, lee el archivo línea por línea y determina si cada línea pertenece a la sección de descripción de objetos o a la sección de consultas. Para realizar esta distinción, utiliza variables de estado (isDescriptionSection e isQuerySection).

Dentro del bucle de lectura de líneas, si se encuentra en la sección de descripción de objetos, se crea una nueva instancia de la estructura ObjectDescription y se asignan los valores correspondientes a sus campos utilizando la función sscanf para analizar la línea leída. A continuación, se incrementa la cantidad de objetos y se realloca la memoria para almacenar la nueva estructura en la matriz objects.

Si se encuentra en la sección de consultas, se realiza un proceso similar para crear una nueva instancia de la estructura Query, analizar la línea y almacenarla en la matriz queries.

Una vez que se han leído todas las líneas del archivo, se cierra el archivo y finaliza la función.

Este archivo es crucial para leer y procesar los datos de entrada necesarios para el modelo de Kepler.

Archivo "modelokepler.c"
El archivo "modelokepler.c" contiene la función principal main, que coordina el flujo del programa. También incluye la definición de la constante PI.

La función main comienza declarando punteros nulos a matrices de estructuras ObjectDescription y Query, así como variables enteras para almacenar la cantidad de objetos y consultas.

A continuación, se llama a la función parseFile pasando el nombre del archivo, los punteros a las matrices y los punteros a las variables de conteo. Esto permite leer y analizar el archivo de entrada y almacenar los datos en las estructuras correspondientes.

Después de eso, se llama a la función simulateKepler, que recibe las matrices de objetos y consultas, junto con los conteos respectivos. Esta función realiza cálculos relacionados con el modelo de Kepler para cada consulta y escribe los resultados en un archivo llamado "respuestas.txt".

Finalmente, se liberan las memorias asignadas dinámicamente para las matrices de objetos y consultas utilizando la función free.

Este archivo principal es responsable de coordinar la ejecución del programa y realizar los cálculos necesarios según el modelo de Kepler.

## Principales retos
Durante el desarrollo de este proyecto, se enfrentaron los siguientes retos:

1. [Reto 1]: [Explicación detallada del reto y cómo se resolvió].
2. [Reto 2]: [Explicación detallada del reto y cómo se resolvió].
3. [Reto 3]: [Explicación detallada del reto y cómo se resolvió].
4. [Reto 4]: [Explicación detallada del reto y cómo se resolvió].
5. [Reto 5]: [Explicación detallada del reto y cómo se resolvió].

## Conclusiones
En conclusión, este proyecto del Modelo del Sistema Solar 4 ha proporcionado una experiencia valiosa. Se aprendieron lecciones importantes, como [mencionar las lecciones aprendidas]. Aunque se lograron avances significativos, aún quedan preguntas sin responder [mencionar las preguntas sin responder].
