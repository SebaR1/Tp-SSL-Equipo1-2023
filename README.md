# SSL TPs Grupales

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


### Secuencia de pasos.

1. **Preprocesador**

   **a.** Hello2.c escrito. Se ve claramente un error de sintaxis al no tener un cierre de llaves y otro en invocar a una función no declarada que sería “pront”(esto daría un warning, no un error).

   **b.** Al momento de preprocesar hello2.c y generar hello2.i las conclusiones que se pueden ver es que se reemplaza la parte de #Include “stdio.h” y pasa a expandirse en las directivas que tiene con cosas que se pueden usar como un printf, declarándose. Se ven muchas palabras con “\_\_” que son identificadores reservados para que use en la implementación. No detecta errores de compilación, y también saca comentarios y los reemplaza con un “espacio”.

   **c.** Hello3.c escrito. Se ve que no está el #include <stdio.h> y añade una declaración de printf.

   **d.** El identificador int me está indicando que la función printf me va a retornar un valor tipo entero; const char \* es el tipo de dato(entrada) que le voy a pasar como primer parámetro a la función que sería un puntero al comienzo de una cadena de caracteres constante(lo que apunta no es modificable) y s sería el nombre de ese parámetro; restrict nos indica que va a ser restringido y otros punteros no lo van a poder reemplazar y “…” nos indica que va a poder tomar un número variable de argumentos.(desde 1 a más)

   **e.** No existen muchas diferencias entre uno y el otro, lo único que se añaden 4 líneas con un # delante,que fueron creadas por el compilador para mostrar información y ayudar al proceso de compilación, cada una con su significado. No se añadieron todas las lineas de codigo q habian en hello2.i porque no estaba el #include <stdio.h> y no se expandió

2. **Compilación**

   **a.** Compilar pero no ensamblar hello3.s (no deja por el error de no cerrar el main con la llave)

   **b.** Se corrigio el error.

   **c.** El objetivo de este programa ya compilado y ahora en lenguaje assembler es llamar a prontf, también llama a main y llama el valor 42 en una variable.

   **d.** Se ensamblo hello4.s a hello4.o con el comando:

   gcc -c hello4.s -o hello4.o

3. **Vinculación**

   **a.** Al momento de vincularlo se genera un error

   **b.** Se Corrigió el error en hello5.c y deja generar el ejecutable. Se entiende que ahora se está invocando la función printf que esta declarada y ahora deja generarlo.

   **c.** Se puede ejecutar pero no me da el resultado esperado. Lo que nos da el printf va a variar dependiendo de cada máquina, nos va a dar un valor que quedó en el stack en una ejecución pasada y esto va a generar un desbalance porque va a extraer un argumento que no pasamos.

4. **Corrección de Bug**

   **a.** Se agregó un argumento más para corregir que es el decimal esperado por %d y le pasamos el entero i. Funciono correctamente y dio el valor esperado


5. **Remoción de prototipo**

   **a.** Escribimos hello7.c sin el prototipo

   **b.** 
      
      **b.i** Arroja dos warnings, *declaracion implicita de la funcion 'printf'* y *incompatibilidad en la declaracion implicita de la funcion built-in 'printf'*

      **b.ii** Un prototipo es una declaracion de la funcion donde contiene el encabezado y los parametros que usa dicha funcion.
      Podrian generar dichos prototipos a traves de la declaracion de dicha funcion o a traves de la implementacion

      **b.iii** Declaracion implicita de una funcion, es aquella que no esta declarada como prototipo si no que es definida directamente

      **b.iv** La especificacion es el standar del lenguaje que indica que normas debe cumplir la implementacion de C

      **b.v** En clang cuando no hacemos un #include <stdio.h> detecta a printf() como un error porque no soporta declaraciones implicitas, mientras que GCC tiene a printf como funcion built-in y solo genera warnings

      **b.vi** Una funcion built-in es una funcion definida en la implementacion, como es el caso de *printf* en GCC

      **b.vii** Funciona bien porque GCC lo vincula automaticamente con stdio.h ya que GCC esta basado proyecto GNU de linux, con lo cual debe estar adaptado para todas las versiones, donde las versiones más antiguas toleran declaracion implicitas y las mas actuales no. GCC no va contra la especificacion porque no prohibe las declaraciones implicitas, si no que reglamenta que un codigo bien escrito no contiene declaraciones implicitas
