1. *Arboles de expresión*
   
    a. Estudiar el programa del ejemplo las sección 1.5.4 Conteo de Palabras
    de [KR1988].

    b.Dibujar el árbol de expresión para la inicialización de los contadores: nl = nw = nc = 0.

   ![Alt text](image.png)

    c.Dibujar el árbol de expresión para la expresión de control del segundo if:
    c == ' ' || c == '\n' || c == '\t'.

    ![Alt text](image-1.png)

2. *Maquina de estado* 

    a. Describir en lenguaje dot [DOT] y dentro del archivo histograma.gv la
    máquina de estado que resuelve el problema planteado.

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

a. Implementación #1: Una variable para el estado actual.
i. Escribir el programa histograma-1-enum-switch.c que siga la
Implementación #1, variante enum y switch.
Esta implementación es la regularización de la implementación de la
sección 1.5.4 de [KR1988]. Los estados son valores de una variable y
las transiciones son la selección estructurada y la actualización de esa
variable. Esta versión es menos eficiente que la versión de [KR1988],
pero su regularidad permite la automatización de la construcción del
programa que implementa la máquina de estados. Además de la
regularidad, esta versión debe:

 * Utilizar typedef y enum en vez de define, de tal modo que la
variable estado se pueda declarar de la siguiente manera: State
s = Out;
 * Utilizar switch en vez de if.

ii. Responder en readme.md: Indicar ventajas y desventajas de la versión
de [KR1988] y de esta implementción.

**Respuesta 3.a-ii:**


b. Implementación #2: Sentencias goto (sí, el infame goto)
- i. Leer la sección 3.8 Goto and labels de [KR1988]

- ii. Leer Go To Statement Considered Harmful de [DIJ1968].

- iii. Leer "GOTO Considered Harmful" Considered Harmful de [RUB1987].

- iv. Responder en readme.md: ¿Tiene alguna aplicación go to hoy en día?
¿Algún lenguaje moderno lo utiliza?

**Respuesta 3.b-iv:**
Podría responder que no tiene ninguna aplicación o que sí tiene y ambas serian correctas, ya que la sentencia GOTO está presente en varios lenguajes como C, C++, Fortran e incluso en Assembler. Aunque pueda utilizarse GOTO en cualquiera de estos lenguajes su uso esta desaconsejado o se considera una mala practica debido a que puede llevar a saltos inesperados, loops infinitos, dificultad de comprensión de la continuidad del cóidigo y el mantenimiento el mismo. Existen las estructuras de control mas expresivas como 'if', 'else', 'for', 'while', 'switch', por lo que el uso de GOTO es casi obsoleto. También podemos afirmar que en casi cualquier sentencia que tenga GOTO puede ser reemplazada por otra estructura de control teniendo el mismo efecto.

- v. Escribir el programa histograma-2-goto.c que siga la
Implementación #2.
En esta implementación los estados son etiquetas y las transiciones
son la selección estructurada y el salto incondicional con la sentencia
goto.

c. Implementación #3: Funciones Recursivas
i. Leer la sección 4.10 Recursividad de [KR1988].
ii. Responder en readme.md: ¿Es necesario que las funciones accedan
a a contadores? Si es así, ¿cómo hacerlo?.
Leer la sección 1.10 Variables Externas y Alcance y 4.3 Variables
Externas de [KR1988].
iii. Escribir el programa, histograma-3-rec.c que siga la implementación
#3.
En esta implementación los estados son funciones recursivas y las
transiciones son la selección estructurada y la invocación recursiva