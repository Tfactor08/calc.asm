format ELF

section '.text' executable

public op_add           ; make op_add callable from C
public op_mul
public op_sub
public op_div

op_add:
    mov eax, [esp+4]    ; access first argument on the stack 
    add eax, [esp+8]    ; add the second argument (result in the eax, which follows the ABI)
    ret                 ; back to the return address

op_mul:
    mov  eax, [esp+4]
    imul eax, [esp+8]
    ret

op_sub:
    mov eax, [esp+4]
    sub eax, [esp+8]
    ret

op_div:
    mov  eax,  [esp+4]
    idiv dword [esp+8]
    ret
