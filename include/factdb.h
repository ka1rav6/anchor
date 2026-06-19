#pragma once

#include "uthash.h"

#include "common.h"

#include <math.h>
// custom includes
#include "ConditionTree.h"
 
#define MAX_FACTS 300
#define BITS_PER_WORD 64
#define NOT_FOUND NAN
#define BITMASK_WORDS ((MAX_FACTS + BITS_PER_WORD - 1) / BITS_PER_WORD)

typedef uint64_t u64;

typedef struct{
    char name[MAX_NAME];
    double val;

    UT_hash_handle hh;
} NumFact; 

typedef struct{
    char name[MAX_NAME];
    int bitIndex;

    UT_hash_handle hh;
} BoolFact;

typedef enum{
    BOOL, NUM
}factType;

typedef struct{
    BoolFact* boolFacts;
    u64 bits[BITMASK_WORDS];
    NumFact* numFacts;
}FactDB;


void setBit(FactDB*, int);
void clearBit(FactDB*, int);
bool testBit(FactDB*, int);



double getNumFact(FactDB*, const char*);
bool getBoolFact(FactDB*, const char*);
bool evaluate(FactDB*, Node*);
FactDB* createFactDB();
void deleteFactDB(FactDB*);
void setBoolFact(FactDB*, const char*, bool);
void setNumFact(FactDB*, const char*, double);
