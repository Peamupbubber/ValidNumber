#include <stdbool.h>
#include <string.h>

typedef enum token {SIGN, DIGITS, DOT, SCI, EMPTY, ERR} token;

bool isNumber(char* s);
token scan();
bool match(token t);

/* methods for the parser */
bool isInteger();
bool isDecimal();
bool I();
bool D();
bool A();
bool DP();
bool E();