enum TokenType {
 Number,
 Addition='+',
 Multiplication='*',
 Substraction='-',
 Division='/',
 PopResult='\n',
 LexError
};
typedef enum TokenType TokenType;
typedef double TokenValue;
struct Token{
 TokenType type;
 TokenValue val;
};

bool GetNextToken(Token *t /*out*/); // Retorna si pudo leer, almacena en t el token leido.

void Scanner(FILE*,Token);