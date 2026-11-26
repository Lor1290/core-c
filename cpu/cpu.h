#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MEMORY_1_KB 1024
#define MEMORY_1_MB 1024*1024 
#define MEMORY_1_GB 1024*1024*1024 

typedef struct {
    uint32_t inst;   // instruction
    uint32_t pc;     // program counter
    uint32_t sp;     // stack pointer 

    uint8_t* memory;
} RISC_V;

RISC_V* init_state(void);

uint8_t safe_fetch_state8l(RISC_V* cpu, uint16_t addr);
uint8_t safe_fetch_state8h(RISC_V* cpu, uint16_t addr);
uint16_t safe_fetch_state16l(RISC_V* cpu, uint32_t addr);
uint16_t safe_fetch_state16h(RISC_V* cpu, uint32_t addr);
uint32_t safe_fetch_state32(RISC_V* cpu, uint32_t addr);

uint8_t unsafe_fetch_state8l(RISC_V* cpu, uint16_t addr);
uint8_t unsafe_fetch_state8h(RISC_V* cpu, uint16_t addr);
uint16_t unsafe_fetch_state16l(RISC_V* cpu, uint32_t addr);
uint16_t unsafe_fetch_state16h(RISC_V* cpu, uint32_t addr);
uint32_t unsafe_fetch_state32(RISC_V* cpu, uint32_t addr);

void write_state8l(RISC_V* cpu, uint16_t addr, uint8_t value);
void write_state8h(RISC_V* cpu, uint16_t addr, uint8_t value);
void write_state16l(RISC_V* cpu, uint32_t addr, uint16_t value);
void write_state16h(RISC_V* cpu, uint32_t addr, uint16_t value);
void write_state32(RISC_V* cpu, uint32_t addr, uint32_t value);

#endif 