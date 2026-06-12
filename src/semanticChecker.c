#include <stdio.h>
#include <yyjson.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
 * checks to include:
 * 1. factname not in db but in expression
 * 2. unknown operator
 * 3. 
 */

bool isOperator(const char* op){
    const char* ops[9] = {">=", "<=","==", "!=", ">", "<", "and", "or", "not"};
    for (int i = 0; i < 9; i++){
        if (strcmp(op, ops[i]) == 0)
            return true;
    }
    return false;
}
