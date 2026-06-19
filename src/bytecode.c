#include "../include/bytecode.h"

static Bytecode* createBytecode(Arena* ar){
    Bytecode* bc = (Bytecode*)arena_alloc(ar, sizeof(Bytecode));
    bc->capacity = 8;
    bc->count = 0;
    bc->code = (Instr*)arena_alloc(ar, sizeof(Instr) * bc->capacity);
    return bc;
}


