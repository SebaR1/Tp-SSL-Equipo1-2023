1. *Arboles de expresión*
   
    a. Estudiar el programa del ejemplo las sección 1.5.4 Conteo de Palabras
    de [KR1988].

    b.Dibujar el árbol de expresión para la inicialización de los contadores: nl
    = nw = nc = 0.

    ![Alt text](Captura2.PNG)

    c.Dibujar el árbol de expresión para la expresión de control del segundo if:
    c == ' ' || c == '\n' || c == '\t'.

    ![Alt text](Captura.PNG)

2. *Maquina de estado* 

    a. Describir en lenguaje dot [DOT] y dentro del archivo histograma.gv la
    máquina de estado que resuelve el problema planteado.

    b. Formalizar la máquina de estados como una n-upla, basarse en el
    Capítulo #1 del Volumen #3 de [MUCH2012].

    Respuesta: 
        Esta maquina de estado es una 6-tupla. Esta esta determinada por:
                    -Un conjunto no vacio de estados (Q).
                    -Un alfabeto de caracteres reconocidos por la maquina (Σ).
                    -Un estado inicial perteneciente al conjunto de estados (q0).
                    -Un conjunto no vacio de estados finales.
                    -Una funcion de transiciones de forma T (q,x)=z siendo z el estado al cual transita desde q, leyendo x.
                    -Un conjunto no vacio de acciones.

No espaciador una particion del conjunto ASCII.
Espaciador es una particion del conjunto ASCII.
Haciendo la unión de estos obtenemos el conjunto ASCII en su totalidad. La intersección entre ellos es el conjunto vacío.

Q = {IN ,OUT}
Σ = {ASCII}
q0 = {OUT}
F = {IN, OUT}
T = {IN => Espaciador => OUT, IN => No espaciador => IN, OUT => No espaciador =>  IN, OUT => Espaciador => OUT}
A = {++cc, (v[i]=cl, ++i), cc=0 }

