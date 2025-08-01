format ELF

section '.text' executable

public op_add
public op_mul
public op_sub
public op_div

op_add:
    mov eax, [esp+4]
    add eax, [esp+8]
    ret

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
