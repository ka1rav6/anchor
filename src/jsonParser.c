#include "jsonParser.h"

yyjson_doc* parseJSON(const char * file){
    yyjson_doc * doc = yyjson_read_file(file, 0, NULL, NULL);
    if (!doc){
        printf("Invalid JSON format!\n");
        exit(1);
    }
    return doc;
}


RuleEngine* build_ast(yyjson_doc* doc){
    

}
