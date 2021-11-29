# Bank Management System

El proyecto maneja la información de los usuarios de un banco y mediante estructuras de datos utiiza la información contenida en el archivo *usuarios.txt* para implementar algoritmos que ayuden al banco a visualizar a los usuarios y a asegurar la seguridad de la información con el uso de tablas hash.

## SICT0302B: Toma decisiones

### - Usa un algoritomo de hashing adecuado para resolver un problema

Para el proyecto implemtenté una clase para crear una tabla hash, de manera que el string que recibe la función *put* es la contraseña del usuario y el int es la cantidad de dinero que el usuario almacena en su cuenta. A continuación se muestra la complejidad temporal de las funciones de la tabla hash:

***put***

La funcion *put* hace uso de la función *indexOf* para saber el indice de la llave ingresada. Después utiliza este indice para agregar la llave y el valor ingresado como parametro de la funcion, y en caso de que exista alguna colision se moverá a la siguiente posición. Por lo que para el peor de los casos su complejidad temporal es *O(n)* o lineal, en caso de que la tabla hash esté llena, pero para su mejor caso su complejidad temporal es *O(1)* o constante, debido a que solo toma un paso agregar el valor y el indice a la tabla.

***get***

La funcion *get* hace uso de la función *indexOf* para saber el indice de la llave ingresada. Después utiliza este indice para buscar el valor ingresado en esa posición, si existe un valor almacenado en este índice, la función lo devuelve, de lo contrario, la función despliega el mensaje "La llave ingresada es incorrecta.". Dado que no utiliza ciclos, la complejidad de la función es de *O(1)* o constante.

## SEG0702A: Tecnologías de Vanguardia

### - Investiga e implementa un algoritmo o una estructura de datos que no se vió durante el curso

### - Describe cada algoritmo de la estructura (inserción, consulta, etc...) de forma clara y con ejemplos
