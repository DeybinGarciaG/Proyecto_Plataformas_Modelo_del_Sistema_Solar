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
El archivo "structures.h" es un archivo de encabezado utilizado para definir las estructuras de datos utilizadas en el programa. Veamos en detalle cada una de las estructuras definidas:

Estructura "ObjectDescription":
La estructura "ObjectDescription" representa la descripción de un objeto astronómico. Contiene los siguientes campos:
objectID: Un arreglo de caracteres que representa el identificador único del objeto. El tamaño máximo del arreglo es de 50 caracteres. Este campo permite identificar de manera única cada objeto en el sistema.
mass: Un número de punto flotante que indica la masa del objeto. Se utiliza para realizar cálculos relacionados con las propiedades gravitacionales del objeto.
perihelionX y perihelionY: Números de punto flotante que representan las coordenadas X e Y del perihelio del objeto. El perihelio es el punto más cercano en la órbita de un objeto alrededor del Sol.
aphelionX y aphelionY: Números de punto flotante que representan las coordenadas X e Y del afelio del objeto. El afelio es el punto más alejado en la órbita de un objeto alrededor del Sol.
initialPosX y initialPosY: Números de punto flotante que indican las coordenadas X e Y de la posición inicial del objeto. Estas coordenadas pueden utilizarse como referencia para el cálculo de la posición actual del objeto en función del tiempo.
En resumen, la estructura "ObjectDescription" almacena información importante sobre un objeto astronómico, incluyendo su identificación, masa y coordenadas relacionadas con su órbita.

Estructura "Query":
La estructura "Query" representa una consulta relacionada con un objeto astronómico en particular. Tiene los siguientes campos:
queryID: Un arreglo de caracteres que representa el identificador único de la consulta. Al igual que en la estructura "ObjectDescription", el tamaño máximo del arreglo es de 50 caracteres. Este campo permite identificar de manera única cada consulta.
objectID: Un arreglo de caracteres que indica el identificador único del objeto asociado a la consulta. La consulta se refiere a un objeto específico utilizando su identificador.
time: Un número de punto flotante que representa el tiempo de la consulta. Este campo indica el momento en el que se realiza la consulta.
La estructura "Query" permite especificar una consulta relacionada con un objeto astronómico en particular, proporcionando su identificación y el tiempo en el que se desea obtener información sobre la posición del objeto.

En resumen, el archivo "structures.h" define estas dos estructuras de datos para almacenar información relacionada con objetos astronómicos y consultas específicas sobre dichos objetos. Estas estructuras forman la base de datos utilizada en el programa para representar y manipular los datos necesarios para realizar cálculos basados en el modelo de Kepler.

El archivo "file_parser.c" contiene la implementación de la función parseFile, que se encarga de analizar un archivo de texto y extraer la información de descripción de objetos y consultas. Veamos en detalle cómo funciona:

La función parseFile toma como argumentos el nombre del archivo a analizar, punteros a matrices de estructuras ObjectDescription y Query, y punteros a enteros que almacenan la cantidad de objetos y consultas, respectivamente.

El primer paso de la función es abrir el archivo especificado utilizando la función fopen en modo de lectura ("r"). Si no se puede abrir el archivo correctamente, se imprime un mensaje de error y se utiliza la función exit para finalizar el programa.

A continuación, se declara un arreglo de caracteres llamado line con una longitud de 256 caracteres. Este arreglo se utilizará para leer cada línea del archivo de texto.

Las variables isDescriptionSection e isQuerySection se utilizan como indicadores para determinar en qué sección del archivo se encuentra actualmente. Ambas variables se inicializan en 0.

A continuación, se inicia un bucle while que se ejecutará mientras se puedan leer líneas del archivo utilizando la función fgets. En cada iteración, se lee una línea del archivo y se almacena en el arreglo line.

Dentro del bucle, se verifica si la línea comienza con el carácter "[". Si es así, se evalúa el contenido de la línea para determinar si pertenece a la sección de descripción de objetos o a la sección de consultas.

Si la línea es "[descripcion]\n", se establece la variable isDescriptionSection en 1 y isQuerySection en 0. Esto indica que las siguientes líneas leídas pertenecen a la sección de descripción de objetos.
Si la línea es "[consultas]\n", se establece la variable isDescriptionSection en 0 y isQuerySection en 1. Esto indica que las siguientes líneas leídas pertenecen a la sección de consultas.
Si la línea no comienza con "[" y se encuentra en la sección de descripción de objetos, significa que la línea contiene información sobre un objeto. En este caso, se crea una nueva instancia de la estructura ObjectDescription y se utiliza la función sscanf para analizar la línea y asignar los valores correspondientes a los campos de la estructura.

Después de analizar la línea y asignar los valores, se incrementa la cantidad de objetos utilizando el operador de incremento (++). Luego, se utiliza la función realloc para redimensionar la matriz de objetos (*objects) para que pueda contener el nuevo objeto. El tamaño de la matriz se calcula multiplicando la cantidad de objetos por el tamaño de la estructura ObjectDescription. Luego, se asigna el nuevo objeto a la última posición de la matriz.

Si la línea no comienza con "[" y se encuentra en la sección de consultas, significa que la línea contiene información sobre una consulta. En este caso, se sigue un proceso similar al descrito anteriormente para las estructuras de objetos. Se crea una nueva instancia de la estructura Query, se utiliza sscanf para analizar la línea y asignar los valores a los campos correspondientes, se incrementa la cantidad de consultas y se redimensiona la matriz de consultas (*queries).

Después de analizar todas las líneas del archivo, se cierra el archivo utilizando la función fclose.

En resumen, el archivo "file_parser.c" contiene la implementación de la función parseFile, que se encarga de leer y analizar un archivo de texto que contiene información sobre objetos y consultas. La función identifica las secciones correspondientes en el archivo y utiliza la función sscanf para analizar y asignar los valores a las estructuras de datos adecuadas. Al final del análisis, se obtiene la cantidad de objetos y consultas, y se redimensionan las matrices de estructuras en consecuencia.
El modelo de Kepler es un modelo matemático utilizado para describir el movimiento de los cuerpos celestes en el sistema solar. Fue desarrollado por el astrónomo alemán Johannes Kepler en el siglo XVII y se basa en las tres leyes del movimiento planetario que formuló Kepler.

Las leyes del movimiento planetario de Kepler son las siguientes:

Primera Ley de Kepler (Ley de las órbitas): Los planetas describen órbitas elípticas alrededor del Sol, donde el Sol ocupa uno de los focos de la elipse.

Segunda Ley de Kepler (Ley de las áreas): El radio que une al planeta con el Sol barre áreas iguales en tiempos iguales. Esto significa que los planetas se mueven más rápidamente cuando están más cerca del Sol (en el perihelio) y más lentamente cuando están más lejos (en el afelio).

Tercera Ley de Kepler (Ley de los periodos): El cuadrado del periodo orbital de un planeta es proporcional al cubo del semieje mayor de su órbita elíptica. Matemáticamente, se expresa como T^2 = k * a^3, donde T es el periodo orbital, a es el semieje mayor y k es una constante para un sistema dado.

En el archivo "modelokepler.c", se utilizan estas leyes y fórmulas para simular el movimiento de los objetos celestes y determinar su posición en función del tiempo.

Cálculo de la excentricidad:
La excentricidad (e) de la órbita se calcula utilizando las coordenadas del afelio y el perihelio. La fórmula es:
e = sqrt((aphelionX - perihelionX)^2 + (aphelionY - perihelionY)^2)

Cálculo del semieje mayor:
El semieje mayor (a) de la órbita se calcula dividiendo la diferencia entre las coordenadas del afelio y el perihelio entre (1 + e). La fórmula es:
a = (aphelionX - perihelionX) / (1 + e)

Cálculo de la posición radial:
La posición radial (r) del objeto en un tiempo dado se calcula utilizando la fórmula de la órbita elíptica. La fórmula es:
r = a * (1 - e^2) / (1 + e * cos((2 * PI * tiempo) / T))

Cálculo de la anomalía verdadera:
La anomalía verdadera (theta) se calcula utilizando una iteración para encontrar una solución aproximada. La fórmula utilizada es una forma iterativa de la ecuación de Kepler:
E = (2 * PI * tiempo) / T
prevE = 0.0
while (fabs(E - prevE) > error) {
prevE = E;
E = E - (E - e * sin(E) - (2 * PI * tiempo) / T) / (1 - e * cos(E));
}
theta = 2 * atan(sqrt((1 + e) / (1 - e)) * tan(E / 2))

Cálculo de las coordenadas X e Y:
Las coordenadas X e Y se calculan utilizando la posición radial (r) y la anomalía verdadera (theta). Las fórmulas son:
x = r * cos(theta)
y = r * sin(theta)

Estas fórmulas permiten calcular la posición de un objeto en función del tiempo, utilizando las propiedades de su órbita y los valores de las consultas proporcionadas en el archivo de entrada.
Función simulateKepler:
La función simulateKepler toma como argumentos un puntero a una matriz de estructuras ObjectDescription llamada objects, la cantidad de objetos numObjects, un puntero a una matriz de estructuras Query llamada queries, y la cantidad de consultas numQueries.
La función comienza abriendo un archivo llamado "respuestas.txt" utilizando la función fopen en modo de escritura ("w"). Si no se puede abrir el archivo correctamente, se imprime un mensaje de error y se devuelve.

A continuación, se inicia un bucle for que itera sobre cada consulta en la matriz de consultas queries. Dentro de este bucle, se realiza lo siguiente:

Se obtiene la consulta actual y se declara una variable object del tipo ObjectDescription. Esta variable se utilizará para almacenar el objeto asociado a la consulta.
Se realiza una búsqueda en la matriz de objetos objects para encontrar el objeto correspondiente a la consulta actual. Se compara el identificador del objeto (objectID) en la consulta con el identificador de cada objeto en la matriz hasta encontrar una coincidencia.
Si no se encuentra el objeto correspondiente, se escribe un mensaje de error en el archivo de respuestas y se continúa con la siguiente consulta.
Si se encuentra el objeto correspondiente, se realiza una serie de cálculos utilizando las propiedades del objeto y los valores de la consulta para determinar la posición del objeto en el tiempo especificado.
Se calcula la excentricidad del objeto utilizando las coordenadas del afelio y el perihelio.
Se calcula el semieje mayor de la órbita utilizando la fórmula apropiada.
Se calcula la posición radial utilizando la fórmula de la órbita elíptica y el tiempo de la consulta.
Se calcula la anomalía verdadera utilizando una iteración para encontrar una solución aproximada.
Se calculan las coordenadas X e Y utilizando la posición radial y la anomalía verdadera.
Se escribe el resultado de la consulta en el archivo de respuestas, incluyendo el ID de la consulta, el ID del objeto, el tiempo de la consulta y las coordenadas X e Y.
Al finalizar el bucle, se cierra el archivo de respuestas utilizando la función fclose.

Función main:
La función main es la función principal del programa. Comienza declarando punteros a matrices de estructuras ObjectDescription y Query, y variables enteras para almacenar la cantidad de objetos y consultas.
A continuación, se llama a la función parseFile del archivo "file_parser.c" pasando el nombre del archivo de entrada, los punteros a las matrices de objetos y consultas, y los punteros a las variables de conteo.

Después de llamar a parseFile, se utiliza la función simulateKepler para realizar los cálculos y generar las respuestas a las consultas. Se pasan las matrices de objetos y consultas, junto con los conteos correspondientes.

Finalmente, se liberan las memorias asignadas dinámicamente utilizando la función free para las matrices de objetos y consultas.

En resumen, el archivo "modelokepler.c" contiene la implementación de las funciones necesarias para leer un archivo de entrada, analizar los datos, simular el modelo de Kepler y generar respuestas a las consultas especificadas. El programa utiliza las funciones del archivo "file_parser.c" para analizar los datos de entrada y luego realiza los cálculos necesarios utilizando las fórmulas del modelo de Kepler. Los resultados se escriben en un archivo de respuestas.

## Principales retos
Durante el desarrollo de este proyecto, se enfrentaron los siguientes retos:

1. [Reto 1]: creo que el principal reto que se afronto fue encontrar las fromulas necesarias para calcular ya que en internet no se encontraban formulas que hicieran uso de los datos proposcionados por lo que tuve que hacer uso de openAI para poder conseguir las formulas con las que usea el siguiente prompts:como calcular la posicion del eje x y y  si cuento con   Masa del objeto en kg,. Posición “X” del perihelio,Posición “Y” del perihelio,Posición “X” del afelio,Posición “Y” del afelio,  Posición “X” en el plano espacial al inicio, Posición “Y” en el plano espacial al inicio,Tiempo en segundos.
Para lo que obtuve el siguiente resultado:
Para calcular la posición del objeto en el eje X y Y en función del tiempo, necesitarás conocer algunos parámetros adicionales, como la velocidad y la dirección del movimiento. Sin embargo, puedo darte una explicación general sobre cómo calcular la posición en función del tiempo en un sistema orbital.

Dado que mencionaste los conceptos de perihelio y afelio, asumiré que estás interesado en el movimiento orbital alrededor del Sol. En este caso, la trayectoria del objeto se describe típicamente por una elipse en un plano bidimensional.

Para calcular la posición en el eje X y Y en función del tiempo, se necesita una fórmula conocida como "ley de áreas iguales". Esta ley establece que el área barrida por la línea que conecta el objeto con el Sol en un intervalo de tiempo determinado es constante. A partir de esta ley, puedes determinar la posición del objeto en cualquier momento dado.

Aquí hay una descripción general de cómo calcular la posición en el eje X y Y en función del tiempo:

Determina el semieje mayor (a) y el semieje menor (b) de la elipse. Estos valores se pueden obtener a partir de las posiciones del perihelio y el afelio. La distancia entre el perihelio y el afelio es igual a 2a, y b se puede calcular utilizando la excentricidad de la órbita.

Calcula la excentricidad (e) de la órbita utilizando la fórmula:
e = (distancia al afelio - distancia al perihelio) / (distancia al afelio + distancia al perihelio)

Calcula el período orbital (T) utilizando el tiempo proporcionado.

Calcula la velocidad angular media (ω) utilizando la fórmula:
ω = 2π / T

Determina el tiempo transcurrido desde el perihelio (t). Puedes usar el tiempo proporcionado y convertirlo a segundos si es necesario.

Calcula la anomalía media (M) utilizando la fórmula:
M = ω * t

Calcula la anomalía excéntrica (E) utilizando una ecuación iterativa o mediante métodos numéricos, como el método de Newton.

Calcula la distancia desde el foco al objeto (r) utilizando la fórmula:
r = a * (1 - e * cos(E))

Calcula la posición en el eje X y Y utilizando coordenadas polares y la fórmula:
X = r * cos(E)
Y = r * sin(E)

Estos cálculos proporcionarán la posición del objeto en el eje X y Y en relación con el Sol en un sistema orbital. Sin embargo, ten en cuenta que este es un cálculo simplificado y no tiene en cuenta efectos como la perturbación gravitacional de otros cuerpos celestes. Para un análisis más preciso, se necesitarían consideraciones adicionales y métodos más avanzados. aunque la verdad no se si estan corrrectas aunque en algunos paginas si habian unas formula y fueron las que mas se parecian a algunas de internet y algunos videos de youtube
1. [Reto 2]:El segundo reto es que no recordaba cómo interactuar con los punteros, es decir, las columnas. Por lo tanto, utilicé ChatGPT para pedir ayuda en la creación de una función para realizar los cálculos, donde se proporcionaran las fórmulas que obtuvimos anteriormente. El prompt utilizado es el siguiente: "Creemos la función para simular el modelo de Kepler. Lo que tiene que hacer es revisar la consulta 1, donde vemos el ID y el tiempo. Usaremos el ID para localizar la fila correspondiente, ya que esos serán los datos que utilizaremos para los cálculos. Una vez que tenemos los datos y el tiempo, que también obtenemos de la consulta 1, utilizamos las siguientes fórmulas para calcular la posición en el eje X y Y de un objeto en una órbita planetaria:"

Masa del objeto en kilogramos (M).
Posición "X" del perihelio (x_p) y posición "Y" del perihelio (y_p).
Posición "X" del afelio (x_a) y posición "Y" del afelio (y_a).
Posición "X" en el plano espacial al inicio (x_0) y posición "Y" en el plano espacial al inicio (y_0).
Tiempo en segundos (t).
El primer paso es calcular la excentricidad de la órbita (e) utilizando las posiciones del perihelio y afelio:

e = sqrt((x_a - x_p)^2 + (y_a - y_p)^2)

A continuación, puedes calcular el semieje mayor de la órbita (a) utilizando la fórmula:

a = (x_a - x_p) / (1 + e)

Luego, puedes calcular la posición radial (r) en función del tiempo utilizando la ley de Kepler:

r = a * (1 - e^2) / (1 + e * cos((2 * pi * t) / T))

Donde T es el período orbital.

A continuación, puedes calcular la anomalía verdadera (θ) utilizando la ecuación:

θ = 2 * atan(sqrt((1 + e) / (1 - e)) * tan(E / 2))

Donde E es la anomalía excéntrica, que se puede calcular mediante la siguiente ecuación iterativa:

E = E - (E - e * sin(E) - (2 * pi * t) / T) / (1 - e * cos(E))

Finalmente, puedes obtener las coordenadas X e Y en función de la posición radial y la anomalía verdadera:

x = r * cos(θ)
y = r * sin(θ) esto para cada consulta recuerda que de la fucnion parseFile vamos a sacar el  querris y objets con los que vamos a hacer estos calculos:
Luego obtuve:void simulateKepler(ObjectDescription* objects, int numObjects, Query* queries, int numQueries) {
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
} de ahi yo hice las modificaciones para  que se guardara en el .txt ademas solucione errores que daba el codigo.
## Conclusiones
En conclusión, este proyecto del Modelo del Sistema Solar ha proporcionado una experiencia valiosa. Se aprendieron lecciones importantes, como el manejo de archivos en C y cómo usar los datos disponibles. Aunque se lograron avances significativos, aún quedan preguntas sin responder, como si están bien las fórmulas. De hecho, me gustó mucho el proyecto y en un futuro cercano me gustaría desarrollar una aplicación que pueda generar horarios a partir de los horarios que genera la universidad, ya que muchas veces no sabemos cuántos horarios tenemos disponibles porque chocan cursos.
