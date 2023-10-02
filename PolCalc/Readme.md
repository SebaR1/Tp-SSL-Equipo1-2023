Maquina de estado:

- Un conjunto no vacío de estados (Q).
- Un alfabeto de caracteres reconocidos por la máquina (Σ).
- Un estado inicial perteneciente al conjunto de estados (q0).
- Una función de transiciones de forma T1 (q,x)=z siendo z el estado al cual transita desde q, leyendo x.

Q = {Invocación, No número, Fin false, Número, - , Literal negativo, Resultado op, Resultado número}
Σ = digitos U {'+','-','\*','/','.'}
q0 = Invocación
T1 = {Invocación => Dígito => Número, Invocación => No dígito o punto => No número, Invocación => EOF => Fin False, Invocación => Espacio => Invoación, No número => Menos => -, No número => no menos => Resultado op, - => Dígito => Literal negativo, - => Espacio u operador => Resultado op, Literal negativo => Dígito => Literal negativo, Literal negativo => Espacio => Resultado número, Número => Dígito => Número, Número => Espacio => Resultado número}

6. Responder:
   a. ¿Es necesario modificar StackModule.h? ¿Por qué?
   b. ¿Es necesario recompilar la implementación de Stack? ¿Por qué?
   c. ¿Es necesario que Calculator muestre el lexema que originó el error
   léxico? Justifique su decisión.
   i. Si decide hacerlo, ¿de qué forma debería exponerse el lexema?
   Algunas opciones:
   • Tercer componente lexeme en Token¿De qué tipo de dato es
   aplicable?
   • Cambiar el tipo de val para que sea un union que pueda
   representar el valor para Number y valor LexError.
   ii. Implemente la solución según su decisión.

a. Si, ya que debemos escribir todas las definiciones de las funciones utilizadas en el archivo StackModule.c, mientras no hagamos ningun cambio en la declaración de las funciones no habria problema.
b. Si, se debe recompilar siempre y cuando se haga alguna modificacion en el código, mientras no haya ningun cambio en el archivo no hay necesidad de recompilarlo.
c. No es completamente necesario, es una decisión del programador. Esta en su poder mostrarle al cliente, teniendo en cuenta si este es consciente del lenguaje del programa o no. La decisión de mostrarla es pensar que el cliente puede equivocarse tipeando y quizas puede pasarse por alto el error.
i. Podria haber muchas maneras, depende totalmente del programador, una opción (la que se utilizo en esta implementación) es que cualquier caracter que no sea un digito se pase como un token a la calculadora, por lo que si en el switch principal no cumple ningun caso, se toma como un error lexico.

_BNF CALCULADORA_

Digito::= 1...9

Punto::= '.'

ParteEntera::= Digito | ParteEntera Digito

num::= Digito | ParteEntera ParteFraccionaria

ParteFraccionaria ::= Punto Digito | Punto ParteEntera

Operador::= suma | resta | mult | div

OP::= num num Operador | num OP Operador

NPI::= OP
