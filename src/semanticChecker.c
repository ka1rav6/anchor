#include "semanticChecker.h"

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


bool isComparisonCorrect(FactDB* db, const char* factname){
    // to check if the fact is of bool type but is used in a comparison expression
    for (int i = 0; i < db->boolCount; i++){
        if (strcmp(db->boolFacts[i].name, factname) == 0){
            return false;
        }
    }
    return true;
}
