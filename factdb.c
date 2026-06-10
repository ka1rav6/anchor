#include "factdb.h"

double getNumFact(FactDB* db, const char* name){
    for (int i = 0; i < db->numCount; i++){
        if (strcmp(db->numFacts[i].name, name) == 0)
            return db->numFacts[i].val;
    }
    return NOT_FOUND;
}

bool getBoolFact(FactDB* db, const char* name){
    for (int i = 0; i < db->boolCount; i++){
        if (strcmp(db->boolFacts[i].name, name) == 0)
            return db->boolFacts[i].val;
    }
    return NOT_FOUND;
}

    
