#pragma once

#include <string.h>

// custom includes
#include "ConditionTree.h"
 
#define MAX_FACTS 300

typedef struct{
    char name[MAX_NAME] ;
    double val;
} NumFact;

typedef struct{
    char name[MAX_NAME];
    bool val;
} BoolFact;

typedef struct{
    BoolFact boolFacts[MAX_FACTS];
    size_t boolCount;
    NumFact numFacts[MAX_FACTS];
    size_t numCount;
}FactDB;

double getNumFact(FactDB* db, const char* name);
bool getBoolFact(FactDB db, const char* name);


