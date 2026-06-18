#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <stddef.h>

// my own arena style memory allocator used ONLY in rule allocation and AST
// As AST is sequential and is freed and created once.

#define ARENA_ALIGNMENT 8

typedef struct{
    size_t size;
    size_t used;
    char* start;
}Arena;

static inline size_t align_up(size_t n, size_t alignment);

char* ask_memory(size_t);
Arena* create_arena(size_t);

void* arena_alloc(Arena*, size_t);
void destroy_arena(Arena*);
