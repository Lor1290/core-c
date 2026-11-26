#include "cpu.c"

int main(int argc, char* argv[]) {
    RISC_V* cpu = init_state();
    
    write_state32(cpu, 0x00000000, 0x04030201);

    printf("[32] Data Saved:  0x%x\n", read_state32(cpu, 0x00000000));
    printf("[16H] Data Saved: 0x%x\n", read_state16h(cpu, 0x00000000));
    printf("[16H] Data Saved: 0x%x\n", read_state16l(cpu, 0x00000000));
    printf("[16H] Data Saved: 0x%x\n", read_state8h(cpu, 0x00000000));
    printf("[16H] Data Saved: 0x%x\n", read_state8l(cpu, 0x00000000));
}