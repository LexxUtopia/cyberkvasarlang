#ifndef cyberkvasar_vm_h
#define cyberkvasar_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 4096

typedef struct {
  Chunk* chunk;
  uint8_t* ip;
  Value stack[STACK_MAX];
  Value* stackTop;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(const char* source);
// InterpretResult interpret(Chunk* chunk);
void push(Value value);
Value pop();

#endif