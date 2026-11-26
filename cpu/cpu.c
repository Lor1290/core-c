#include "cpu.h"

// program counter:
// 1. special register not in the register file
// 2. hold the address of the current instruction
// 3. after an instruction (RISC32I = 32 bit) PC = PC + 4
// 4. after branches / jump: PC = new address

// program layout
// Address: 0x00000000
// 
// [ your code ]
// [ .data section ]
// [ heap ]  -> grows down
// [ stack ] -> grows up
// 
// Address: 0xffffffff

// memory layout
// 0xffffffff -> unmapped
// stack
// head
// .data / .bss [ initialized / uninitialized globals ] 
// .text        [ program instruction, read-only ]
// reserved     [ 32kb, 64kb or more to catch null pointer or null pointer + offset errors]


RISC_V* init_state(void) {
    RISC_V* cpu = (RISC_V*) malloc(sizeof(RISC_V));

    if(!cpu) return NULL;

    cpu->pc = 0x00000000;
    cpu->sp = 0x00000000;
    cpu->inst = 0x00000000;

    cpu->memory = (uint8_t*) calloc(MEMORY_1_MB, sizeof(uint8_t));

    if(!cpu->memory) {
        free(cpu);
        return NULL;
    }

    return cpu;
}


uint8_t safe_fetch_state8l(RISC_V* cpu, uint16_t addr) {
    return cpu->memory[addr];
}
uint8_t safe_fetch_state8h(RISC_V* cpu, uint16_t addr) {
    uint8_t value = NULL;
    memcpy(value, &cpu->memory[addr+1], sizeof(value));
    
    if(!value) return NULL;
    return value;
}

uint16_t safe_fetch_state16l(RISC_V* cpu, uint32_t addr) {
    uint16_t value = NULL;
    memcpy(value, &cpu->memory[addr], sizeof(value)); 

    if(!value) return NULL;
    return value;
}
uint16_t safe_fetch_state16h(RISC_V* cpu, uint32_t addr) {
    uint16_t value = NULL;
    memcpy(value, &cpu->memory[addr+2], sizeof(value));

    if(!value) return NULL;
    return value;
}

uint32_t safe_fetch_state32(RISC_V* cpu, uint32_t addr) {
    uint32_t value = NULL;
    memcpy(value, &cpu->memory[addr], sizeof(value));

    if(!value) return NULL;
    return value;
}


void write_state8l(RISC_V* cpu, uint16_t addr, uint8_t value) {
    cpu->memory[addr] = value;
}
void write_state8h(RISC_V* cpu, uint16_t addr, uint8_t value) {
    *(&cpu->memory[addr] + sizeof(uint8_t)) = value;
}

void write_state16l(RISC_V* cpu, uint32_t addr, uint16_t value) {
    *(uint16_t *)&cpu->memory[addr] = value;
}
void write_state16h(RISC_V* cpu, uint32_t addr, uint16_t value) {
    *(uint16_t *)(&cpu->memory[addr] + sizeof(uint16_t)) = value;
}

void write_state32(RISC_V* cpu, uint32_t addr, uint32_t value) {
    *(uint32_t *)&cpu->memory[addr] = value;
}