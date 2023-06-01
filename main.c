#include <stdio.h>
#include "validNumber.h"

void main(int argc, char* argv[]) {
    if(argc == 1)
        printf("Usage: ./isNumber \"input\" ... \n");
    else {
        printf("--- Valid Number Matching ---\n");
        for(int i = 1; i < argc; i++) {
            printf("%s: %s\n", argv[i], isNumber(argv[i]) ? "true" : "false");
        }
    }
}
