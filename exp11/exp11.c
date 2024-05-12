#include <stdio.h>
#include <stdint.h>

// Define MIPS instruction opcodes and function codes
#define LUI_OPCODE 0x0F
#define ORI_OPCODE 0x0D
#define NOP_INSTRUCTION 0x00000000

// Function to generate machine code for "li $s0, 42"
void generateMachineCode() {
    uint32_t lui_instruction = (LUI_OPCODE << 26) | (16 << 16) | (42 & 0xFFFF); // lui $s0, 0x0000
    uint32_t ori_instruction = (ORI_OPCODE << 26) | (16 << 21) | (16 << 16) | (42 & 0xFFFF); // ori $s0, $s0, 42
    
    // Output machine code in hexadecimal format
    printf("Machine code for 'li $s0, 42':\n");
    printf("lui $s0, 0x0000: 0x%08X\n", lui_instruction);
    printf("ori $s0, $s0, 42: 0x%08X\n", ori_instruction);
    printf("nop: 0x%08X\n", NOP_INSTRUCTION);
}

int main() {
    generateMachineCode();
    return 0;
}
