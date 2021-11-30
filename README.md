# Bank Management System

El proyecto maneja la información de los usuarios de un banco y mediante estructuras de datos utiiza la información contenida en el archivo *usuarios.txt* para implementar algoritmos que ayuden al banco a visualizar a los usuarios y a asegurar la seguridad de la información con el uso de tablas hash.

## SICT0302B: Toma decisiones

### - Usa un algoritomo de hashing adecuado para resolver un problema

Para el proyecto implemtenté una clase para crear una tabla hash, de manera que el string que recibe la función *put* es la contraseña del usuario y el int es la cantidad de dinero que el usuario almacena en su cuenta. 

La función *get* realiza una búsqueda en la tabla hash, y devuelve el dinero dentro de la cuenta en base a la contraseña recibida como parámetro.

A continuación se muestra la complejidad temporal de las funciones de la tabla hash:

***put***

La funcion *put* hace uso de la función *indexOf* para saber el indice de la llave ingresada. Después utiliza este indice para agregar la llave y el valor ingresado como parametro de la funcion, y en caso de que exista alguna colision se moverá a la siguiente posición. Por lo que para el peor de los casos su complejidad temporal es *O(n)* o lineal, en caso de que la tabla hash esté llena, pero para su mejor caso su complejidad temporal es *O(1)* o constante, debido a que solo toma un paso agregar el valor y el indice a la tabla.

***get***

La funcion *get* hace uso de la función *indexOf* para saber el indice de la llave ingresada. Después utiliza este indice para buscar el valor ingresado en esa posición, si existe un valor almacenado en este índice, la función lo devuelve, de lo contrario, la función despliega el mensaje "La llave ingresada es incorrecta.". Dado que no utiliza ciclos, la complejidad de la función es de *O(1)* o constante.

## SEG0702A: Tecnologías de Vanguardia

### - Investiga e implementa un algoritmo o una estructura de datos que no se vió durante el curso

Para este proyecto implementé el algortimo TimSort, que es un algoritmo de ordenamiento hibrido basado en el InsertionSort y el MergeSort. Diseñado para ser aplicado en muchos tipos de datos del mundo real.

### - Describe cada algoritmo de la estructura (inserción, consulta, etc...) de forma clara y con ejemplos

El algoritmo de ordenamiento TimSort es un algoritmo estable que tiene una complejidad temporal de *O(n log n)*.

El algoritmo recibe como parámetro un vector, funciona dividiendo el arreglo original en dos bloques conocidos como corridas (Run). Posteriormente ordena esas corridas una por una usando la función *insertionSort*. Una vez que ordena ambos subarreglos los mezcla en un mismo arreglo usando la función *merge* que también es utilizada en el MergeSort.

Lo que hace eficiente a TimSort es que utiliza un método conocido como *galloping* o modo gallop, este modo funciona utilizando un valor constante (asignado a RUN). Cada vez que el vector right sea mayor al vector left, después de esto se repita consecutivamente y llegue al valor asignado a RUN, se activa el modo *galloping*, de manera que TimSort determina que el arreglo ya está totalmente ordenado a partir de dichas comparaciones, en lugar de hacer todas las comparaciones, al llegar a ese número hace el merge con los elementos restantes. Esto evita que se tengan comparaciones innecesarias al hacer el merge y lo junta todo en una sola vez.
