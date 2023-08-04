1. *Arboles de expresión*
   
    a. Estudiar el programa del ejemplo las sección 1.5.4 Conteo de Palabras
    de [KR1988].

    b.Dibujar el árbol de expresión para la inicialización de los contadores: nl = nw = nc = 0.

   ![Alt text](image.png)

    c.Dibujar el árbol de expresión para la expresión de control del segundo if:
    c == ' ' || c == '\n' || c == '\t'.

    ![Alt text](image-1.png)

2. *Maquina de estado* 

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
T = {IN => Espaciador => OUT, IN => No espaciador => IN, OUT => No espaciador =>  IN, OUT => Espaciador => OUT}
A = {++cc, (v[i]=cl, ++i), cc=0 }

3. Implementaciones de Máquinas de Estado:
Las implementaciones varían en los conceptos que utilizan para representaar
los estados y las transiciones.


**a. Implementación #1**

ii. Responder en readme.md: Indicar ventajas y desventajas de la versión
de [KR1988] y de esta implementción.

**Respuesta a-ii:**
----------------------

----------------------


**b. Implementación #2**

- iv. Responder en readme.md: ¿Tiene alguna aplicación go to hoy en día?
¿Algún lenguaje moderno lo utiliza?

**Respuesta b-iv:**
Podría responder que no tiene ninguna aplicación o que sí tiene y ambas serian correctas, ya que la sentencia GOTO está presente en varios lenguajes como C, C++, Fortran e incluso en Assembler. Aunque pueda utilizarse GOTO en cualquiera de estos lenguajes su uso esta desaconsejado o se considera una mala practica debido a que puede llevar a saltos inesperados, loops infinitos, dificultad de comprensión de la continuidad del cóidigo y el mantenimiento el mismo. Existen las estructuras de control mas expresivas como 'if', 'else', 'for', 'while', 'switch', por lo que el uso de GOTO es casi obsoleto. También podemos afirmar que en casi cualquier sentencia que tenga GOTO puede ser reemplazada por otra estructura de control teniendo el mismo efecto.

**c. Implementación #3**

ii. Responder en readme.md: ¿Es necesario que las funciones accedan
a a contadores? Si es así, ¿cómo hacerlo?.

**Respuesta c.ii**
-----------------

-----------------


**d. Implementación #X**

i. Diseñar una nueva implementación e indicar en Readme.md cómo esa
implementación representa los estados y cómo las transiciones.

**Respuesta d.i**

                    arch1(1Kb)       arch2      arch3
Implementación a     0.173s           50.900s    
Implementación b     0.192s           58.402s         b
Implementación c     1.073s           c           c       
Implementación d     0.880s           d           d