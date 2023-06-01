#include <stdio.h>
#include "isNumber.h"

void main(int argc, char* argv[]) {
    if(argc == 1)
        printf("No args!\n");
    else {
        printf("--- isNumber matching ---\n");
        for(int i = 1; i < argc; i++) {
            printf("%s: %s\n", argv[i], isNumber(argv[i]) ? "true" : "false");
        }
    }
}
