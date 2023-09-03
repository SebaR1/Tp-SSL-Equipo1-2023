# 01-FasesErrores

## Sintaxis y Semántica de los Lenguajes

- Curso: K2051
- Año 2023
- Número de equipo: 1
- Integrantes:

  - **SebaR1:**

    - Legajo: 209.176-8
    - Romero Rocha
    - Sebastian

  - **LucasMPerez**

    - Legajo: 168.982-4
    - Pérez
    - Lucas Matías

  - **FranX90**

    - Legajo: 209.947-0
    - Lezcano
    - Francisco Daniel

  - **JulianTettamanti**

    - Legajo: 208.155-6
    - Tettamanti
    - Julian

  - **TamirFeldenblum**

    - Legajo: 203.602-2
    - Feldenblum
    - Tamir

  - **RoyerYampasi**
    - Legajo: 2041741
    - Yampasi
    - Royer

## OBJETIVO:

Este trabajo tiene como objetivo identificar las fases del proceso de traducción o Build y los posibles errores asociados a cada fase. Para lograr esa identificación se ejecutan las fases de traducción una a una, se detectan y corrigen errores, y se registran las conclusiones en readme.md.

## TAREAS:

1.  La primera tarea es investigar las funcionalidades y opciones que su compilador presenta para limitar el inicio y fin de las fases de traducción.
2.  La siguiente tarea es poner en uso lo que se encontró. Para eso se debe transcribir al readme.md cada comando ejecutado y su resultado o error correspondiente a la siguiente secuencia de pasos. También en readme.md se vuelcan las conclusiones y se resuelven los puntos solicitados. Para claridad, mantener en readme.md la misma numeración de la secuencia de pasos.

## Secuencia de pasos.

1. **Preprocesador**

   **a. Escribir hello2.c, que es una variante de hello.c:**

   ```
   #include <stdio.h>
   int/*medio*/main(void){
   int i=42;
    prontf("La respuesta es %d\n");
   ```

   _Conclución:_
   Hello2.c escrito. Se ve claramente un error de sintaxis al no tener un cierre de llaves y otro en invocar a una función no declarada que sería “pront”(esto daría un warning, no un error).

   **b. Preprocesar hello2.c, no compilar, y generar hello2.i. Analizar su contenido. ¿Qué conclusiones saca?**

   _Conclusión:_
   Al momento de preprocesar hello2.c y generar hello2.i las conclusiones que se pueden ver es que se reemplaza la parte de #Include “stdio.h” y pasa a expandirse en las directivas que tiene con cosas que se pueden usar como un printf, declarándose. Se ven muchas palabras con “\_\_” que son identificadores reservados para que use en la implementación. No detecta errores de compilación, y también saca comentarios y los reemplaza con un “espacio”.

   **c. Escribir hello3.c, una nueva variante:**

   ```
   int printf(const char * restrict s, ...);
   int main(void){
   int i=42;
   prontf("La respuesta es %d\n");
   ```

   _Conclusión:_
   Hello3.c escrito. Se ve que no está el #include <stdio.h> y añade una declaración de printf.

   **d. Investigar e indicar la semántica de la primera línea.**

   _Conclusión:_
   El identificador int me está indicando que la función printf me va a retornar un valor tipo entero; const char \* es el tipo de dato(entrada) que le voy a pasar como primer parámetro a la función que sería un puntero al comienzo de una cadena de caracteres constante(lo que apunta no es modificable) y s sería el nombre de ese parámetro; restrict nos indica que va a ser restringido y otros punteros no lo van a poder reemplazar y “…” nos indica que va a poder tomar un número variable de argumentos.(desde 1 a más)

   **e. Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferencias entre hello3.c y hello3.i.**

   _Conclusión:_
   No existen muchas diferencias entre uno y el otro, lo único que se añaden 4 líneas con un # delante,que fueron creadas por el compilador para mostrar información y ayudar al proceso de compilación, cada una con su significado. No se añadieron todas las lineas de codigo q habian en hello2.i porque no estaba el #include <stdio.h> y no se expandió

2. **Compilación**

   **a. Compilar el resultado y generar hello3.s, no ensamblar.**

   _Conclusión:_
   Compilar pero no ensamblar hello3.s (no deja por el error de no cerrar el main con la llave)

   **b. Corregir solo los errores, no los warnings, en el nuevo archivo hello4.c y empezar de nuevo, generar hello4.s, no ensamblar.**

   _Conclusión:_
   Se corrigio el error.

   **c. Leer hello4.s, investigar sobre lenguaje ensamblador, e indicar de formar sintética cual es el objetivo de ese código.**

   _Conclusión:_
   El objetivo de este programa ya compilado y ahora en lenguaje assembler es llamar a prontf, también llama a main y llama el valor 42 en una variable.

   **d. Ensamblar hello4.s en hello4.o, no vincular**

   _Conclusión:_
   Se ensamblo hello4.s a hello4.o con el comando:

   ```
   gcc -c hello4.s -o hello4.o
   ```

3. **Vinculación**

   **a. Vincular hello4.o con la biblioteca estándar y generar el ejecutable**

   _Conclusión:_
   Al momento de vincularlo se genera un error

   **b. Corregir en hello5.c y generar el ejecutable. Solo corregir lo necesario para que vincule.**

   _Conclusión:_
   Se Corrigió el error en hello5.c y deja generar el ejecutable. Se entiende que ahora se está invocando la función printf que esta declarada y ahora deja generarlo.

   **c. Ejecutar y analizar el resultado.**

   _Conclusión:_
   Se puede ejecutar pero no me da el resultado esperado. Lo que nos da el printf va a variar dependiendo de cada máquina, nos va a dar un valor que quedó en el stack en una ejecución pasada y esto va a generar un desbalance porque va a extraer un argumento que no pasamos.

4. **Corrección de Bug**

   **a. Corregir en hello6.c y empezar de nuevo; verificar que funciona como se espera.**

   _Conclusión:_
   Se agregó un argumento más para corregir que es el decimal esperado por %d y le pasamos el entero i. Funciono correctamente y dio el valor esperado

5. **Remoción de prototipo**

   **a. Escribir hello7.c, una nueva variante:**

   ```
   int main(void){
   int i=42;
   printf("La respuesta es %d\n", i);
   }
   ```

   _Conclusión:_
   Escribimos hello7.c sin el prototipo

   **b. Explicar porqué funciona**

   _Conclusión:_

   **b.i** Arroja dos warnings, _declaracion implicita de la funcion 'printf'_ y _incompatibilidad en la declaracion implicita de la funcion built-in 'printf'_

   **b.ii** Un prototipo es una declaracion de la funcion donde contiene el encabezado y los parametros que usa dicha funcion.
   Podrian generar dichos prototipos a traves de la declaracion de dicha funcion o a traves de la implementacion

   **b.iii** Declaracion implicita de una funcion, es aquella que no esta declarada como prototipo si no que es definida directamente

   **b.iv** La especificacion es el standar del lenguaje que indica que normas debe cumplir la implementacion de C

   **b.v** En clang cuando no hacemos un #include <stdio.h> detecta a printf() como un error porque no soporta declaraciones implicitas, mientras que GCC tiene a printf como funcion built-in y solo genera warnings

   **b.vi** Una funcion built-in es una funcion definida en la implementacion, como es el caso de _printf_ en GCC

   **b.vii** Funciona bien porque GCC lo vincula automaticamente con stdio.h ya que GCC esta basado proyecto GNU de linux, con lo cual debe estar adaptado para todas las versiones, donde las versiones más antiguas toleran declaracion implicitas y las mas actuales no. GCC no va contra la especificacion porque no prohibe las declaraciones implicitas, si no que reglamenta que un codigo bien escrito no contiene declaraciones implicitas

6. **Compilación Separada: Contratos y Módulos**

   **a. Escribir studio1.c (sí, studio1, no stdio) y hello8.c. La unidad de traducción studio1.c tiene una implementación de la función prontf, que es solo un wrappwer de la función estándar printf:**

   ```
   void prontf(const char* s, int i){
   printf("La respuesta es %d\n", i);
   }
   ```

   **La unidad de traducción hello8.c, muy similar a hello4.c, invoca a prontf, pero no incluye ningún header.**

   ```
   int main(void){
   int i=42;
   prontf("La respuesta es %d\n", i);
   }
   ```

   **b. Investigar como en su entorno de desarrollo puede generar un programa ejecutable que se base en las dos unidades de traducción (i.e., archivos fuente, archivos con extensión .c). Luego generar ese ejecutable y probarlo.**

   _Conclusión:_ En su entorno de desarrolo, lo que hace gcc es compilar ambos archivos hasta la etapa de linkeo y en esta etapa usando una misma biblioteca combina ambos archivos en un solo ejecutable. Al principio nos dio 2 warnings que ya vimos en el punto **5.b.i**. Esto nos demuestra que se compilan por separado. Tambien nos dio un warning hello8.c por prontf ya que esta no está definida en el standard.

   **c. Responder ¿qué ocurre si eliminamos o agregamos argumentos a la invocación de prontf? Justifique.**

   _Conclusión:_ Al momento de eliminar o agregar argumentos a la invocación de prontf no da error. Esto se debe a que prontf es una funcion wrapper que puede recibir argumentos variables, a su vez printf en su declaracion implicita puede recibir más de una variable. Por lo tanto, se ejecuta sin problema. De igual manera printf siempre va a recibir un argumento que es " por esta razon no va a dar error.

   **d. Revisitar el punto anterior, esta vez utilizando un contrato de interfaz en un archivo header.**

   **d.i Escribir el contrato en studio.h.**

   ```
   #ifndef _STUDIO_H_INCULDED_
   #define _STUDIO_H_INCULDED_
   void prontf(const char*, int);
   #endif
   ```

   **d.ii Escribir hello9.c, un cliente que sí incluye el contrato.**

   ```
   #include "studio.h" // Interfaz que importa
   int main(void){
   int i=42;
   prontf("La respuesta es %d\n", i);
   }
   ```

   **d.iii Escribir studio2.c, el proveedor que sí incluye el contrato.**

   ```
   #include "studio.h" // Interfaz que exporta
   #include <stdio.h> // Interfaz que importa
   void prontf(const char* s, int i){
   printf("La respuesta es %d\n", i);
   }
   ```

   **d.iv Responder: ¿Qué ventaja da incluir el contrato en los clientes y en el proveedor.**

   _Conclusión:_ Las ventajas de tener el contrato en el cliente es que puede tener una independencia de proveedor solo necesitando conocer y cumplir con la interfaz especifica del contrato. Lo que le de libertad para utilizar diferentes proveedores que utilicen la misma interfaz. Tambien se promueve la modularidad y reutilizacion del codigo. La libertad de usar diferentes proveedores permite la incorporacion de nuevas funcionalidades o la mejora de implementacion sin modificar el codigo.

   
