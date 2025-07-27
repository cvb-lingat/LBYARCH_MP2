; Z[i] = A * X[i] + Y[i]

section .text
bits 64
default rel
global DAXPY_ASM

DAXPY_ASM:
    ; size@rcx, A @ XMM1, vector_X @R8, vector_Y @R9, vector_Z to be returned via stack
    
    MOV R10, [RSP+40] ; move address of vector Z to R10
    
L1:
    MOVSD XMM0, [R8]
    MULSD XMM0, XMM1 ; A * X[i]
    ADDSD XMM0, [R9] ; A * X[i] + Y[i]
    MOVSD [R10], XMM0 ; Z[i] = A * X[i] + Y[i]
    
    ADD R8, 8 ; +8 because double is 8 bytes
    ADD R9, 8
    ADD R10, 8
    
    loop L1
    
    ret
    
    