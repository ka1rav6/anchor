#include <stdio.h>
#include <string.h>
#include <yyjson.h>
#include "rule.h"

yyjson_doc* parseJSON(const char*); 

RuleEngine* build_ast(yyjson_doc*);

