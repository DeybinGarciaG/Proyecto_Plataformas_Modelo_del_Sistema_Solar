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
En el contexto de este programa, se utilizó [explicar brevemente el contexto en el que se desarrolló el programa y los modelos utilizados para generar las órbitas].

## Diseño general
El programa se divide en las siguientes partes:

1. [Parte 1]: [Descripción de la parte 1 y cómo fue programada].
2. [Parte 2]: [Descripción de la parte 2 y cómo fue programada].
3. [Parte 3]: [Descripción de la parte 3 y cómo fue programada].

## Principales retos
Durante el desarrollo de este proyecto, se enfrentaron los siguientes retos:

1. [Reto 1]: [Explicación detallada del reto y cómo se resolvió].
2. [Reto 2]: [Explicación detallada del reto y cómo se resolvió].
3. [Reto 3]: [Explicación detallada del reto y cómo se resolvió].
4. [Reto 4]: [Explicación detallada del reto y cómo se resolvió].
5. [Reto 5]: [Explicación detallada del reto y cómo se resolvió].

## Conclusiones
En conclusión, este proyecto del Modelo del Sistema Solar 4 ha proporcionado una experiencia valiosa. Se aprendieron lecciones importantes, como [mencionar las lecciones aprendidas]. Aunque se lograron avances significativos, aún quedan preguntas sin responder [mencionar las preguntas sin responder].
