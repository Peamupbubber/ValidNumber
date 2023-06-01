#include "isNumber.h"

char* currentString;

/* Solution: Recursive descent parser with scanner and matching tokens.
 *
 * The grammer:
 * S  -> I E | D E | e
 * I  -> A DIGITS
 * D  -> A DP
 * A  -> SIGN | e
 * DP -> DIGITS DOT | DIGITS DOT DIGITS | DOT DIGITS
 * E  -> SCI I | e
 *
 * The tokens are:
 * SIGN   -> [+-]
 * DIGITS -> [0-9][0-9]*
 * DOT    -> [.]
 * SCI    -> [eE]
 * EMPTY  -> []
 * ERR    -> .
*/

/* Gets the next token from the current string */
token scan() {
    if(!strlen(currentString))
        return EMPTY;
    else if(currentString[0] == '+' || currentString[0] == '-') {
        currentString++;
        return SIGN;
    }
    else if(currentString[0] >= '0' && currentString[0] <= '9') {
        while(strlen(currentString) && currentString[0] >= '0' && currentString[0] <= '9') {
            currentString++;
        }
        return DIGITS;
    }
    else if(currentString[0] == '.') {
        currentString++;
        return DOT;
    }
    else if(currentString[0] == 'e' || currentString[0] == 'E') {
        currentString++;
        return SCI;
    }
    else
        return ERR;
}

/* matches the next token with the given one and returns false on error (invalid character from scanner) */
bool match(token t) {
    token s = scan();
    if(s == ERR || t != s)
        return false;
    else
        return true;
}

/* S -> e
 * S -> I E
 * S -> D E
*/
bool isNumber(char * s){
    currentString = s;
    if(match(EMPTY)) return true;
    
    currentString = s;
    if(isInteger() && match(EMPTY)) return true;

    currentString = s;
    return isDecimal() && match(EMPTY);
}

/* I E */
bool isInteger() {
    if(!I()) return false;
    return E();
}

/* D E */
bool isDecimal() {
    if(!D()) return false;
    return E();
}

/* I -> A DIGITS */
bool I() {
    if(!A()) return false;
    return match(DIGITS);
}

/* D -> A DP */
bool D() {
    if(!A()) return false;
    return DP();

}
/* A -> SIGN
 * A -> e
*/
bool A() {
    if(currentString[0] == '+' || currentString[0] == '-') {
        return match(SIGN);
    }
    
    return true; 
}

/* DP -> DIGITS DOT
 * DP -> DIGITS DOT DIGITS
 * DP -> DOT DIGITS
 *
 * First conditional covers both of the first two cases
*/
bool DP() {
    if(currentString[0] >= '0' && currentString[0] <= '9') {
        if(!match(DIGITS)) return false;

        if(!match(DOT)) return false;

        if(currentString[0] >= '0' && currentString[0] <= '9')
            return match(DIGITS);
        else
            return true;
    }
    else if(currentString[0] == '.') {
        if(!match(DOT)) return false;
        return match(DIGITS);
    }
    else
        return false;
}

/* E -> SCI I
 * E -> e
*/
bool E() {
    if(currentString[0] == 'e' || currentString[0] == 'E') {
        if(!match(SCI)) return false;

        return I();
    }

    return true;
}