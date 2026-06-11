#include "ConditionTree.h"

#include <string.h>
#include <yyjson.h>

yyjson_doc* parseJSON(const char * file){
    yyjson_doc * doc = yyjson_read_file(file, 0, NULL, NULL);
    if (!doc){
        printf("Invalid JSON format!\n");
        exit(1);
    }
    return doc;
}

