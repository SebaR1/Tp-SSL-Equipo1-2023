1. _Arboles de expresión_

   a. Estudiar el programa del ejemplo las sección 1.5.4 Conteo de Palabras
   de [KR1988].

   b.Dibujar el árbol de expresión para la inicialización de los contadores: nl = nw = nc = 0.

   ![Alt text](image.png)

   c.Dibujar el árbol de expresión para la expresión de control del segundo if:
   c == ' ' || c == '\n' || c == '\t'.

   ![Alt text](image-1.png)

2. _Maquina de estado_

   b. Formalizar la máquina de estados como una n-upla, basarse en el
   Capítulo #1 del Volumen #3 de [MUCH2012].

   **Respuesta 2.b:** Esta máquina de estado es una 6-tupla. Está determinada por:

- Un conjunto no vacío de estados (Q).
- Un alfabeto de caracteres reconocidos por la máquina (Σ).
- Un estado inicial perteneciente al conjunto de estados (q0).
- Un conjunto no vacío de estados finales.
- Una función de transiciones de forma T (q,x)=z siendo z el estado al cual transita desde q, leyendo x.
- Un conjunto no vacío de acciones.

* **No espaciador** es una particion del conjunto ASCII.
* **Espaciador** es una particion del conjunto ASCII.
* Haciendo la unión de estos obtenemos el conjunto ASCII en su totalidad. La intersección entre ellos es el conjunto vacío.

Q = {IN ,OUT}
Σ = {ASCII}
q0 = {OUT}
F = {IN, OUT}
T = {IN => Espaciador => OUT, IN => No espaciador => IN, OUT => No espaciador => IN, OUT => Espaciador => OUT}
A = {++cc, (v[i]=cl, ++i), cc=0 }

3. Implementaciones de Máquinas de Estado:
   Las implementaciones varían en los conceptos que utilizan para representaar
   los estados y las transiciones.

**a. Implementación #1**

ii. Responder en readme.md: Indicar ventajas y desventajas de la versión
de [KR1988] y de esta implementación.

## **Respuesta a-ii:**

La ventaja principal de la version de KR1988 es su expresividad de la función, que es muy clara a simple vista. Además que no utiliza la declaración "goto" que puede ser considerada mala practica. Y la desventaja que pudimos encontrar es que no esta modularizada, osea que todo el codigo se encuentra en "main".
Hablando de la implementación goto.c su ventaja es que esta modularizada en una funcioón, lo que facilita su manipulación. Y utiliza un enfoque más estructurado para controlar el flujo del programa; Las desventajas podrian ser que el uso de "goto" haga que el programa sea más dificil de entender para programadores que no esten familiarizados.

---

**b. Implementación #2**

- iv. Responder en readme.md: ¿Tiene alguna aplicación go to hoy en día?
  ¿Algún lenguaje moderno lo utiliza?

**Respuesta b-iv:**

Podría responder que no tiene ninguna aplicación o que sí tiene y ambas serian correctas, ya que la sentencia GOTO está presente en varios lenguajes como C, C++, Fortran e incluso en Assembler. Aunque pueda utilizarse GOTO en cualquiera de estos lenguajes su uso esta desaconsejado o se considera una mala practica debido a que puede llevar a saltos inesperados, loops infinitos, dificultad de comprensión de la continuidad del cóidigo y el mantenimiento el mismo. Existen las estructuras de control mas expresivas como 'if', 'else', 'for', 'while', 'switch', por lo que el uso de GOTO es casi obsoleto. También podemos afirmar que en casi cualquier sentencia que tenga GOTO puede ser reemplazada por otra estructura de control teniendo el mismo efecto.

**c. Implementación #3**

ii. Responder en readme.md: ¿Es necesario que las funciones accedan
a a contadores? Si es así, ¿cómo hacerlo?.

## **Respuesta c.ii**

Si es necesario que accedan a los contadores. Pero simplente al valor de ellos y que en la funcion utilicen este valor para pasarlo por parametro a otra funcion o simplemente volver a la funcion principal.

**d. Implementación #X**

i. Diseñar una nueva implementación e indicar en Readme.md cómo esa
implementación representa los estados y cómo las transiciones.

## **Respuesta d.i**

En esta implementacion los estados son representados con los efectos que conlleva pasar de un estado a otro distinto, o al mismo estado, dentro de una estructura de control. Las transiciones estan representadas con estructuras de control basicas, acciones y funciones que se encuentran simplemente para modularizar las acciones y hacer el codigo mas sencillo a la vista.

**Benchmark**
---------------arch1(1Kb)----arch2(1078kB)--------arch3 

Implementación a---------0.560s---------1m05.393s--------37m25.349s

Implementación b---------0.562s---------1m04.569s--------41m54.572s

Implementación c---------0.560s----------54.544s---------41m3.252s

Implementación d---------0.561s----------46.747s--------39m50.919s

