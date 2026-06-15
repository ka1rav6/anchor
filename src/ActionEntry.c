#include "ActionEntry.h"

void registerAction(const char* action, Action_f func, void* ctx) {
    ActionEntry* e = malloc(sizeof(ActionEntry));
    strcpy(e->action, action);
    e->func = func;
    e->ctx  = ctx;
    HASH_ADD_STR(g_registry, action, e);
}

ActionEntry* lookupAction(const char* action) {
    ActionEntry* e;
    HASH_FIND_STR(g_registry, action, e);
    return e;
}
