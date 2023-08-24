section .data
    hello db "Hello, Holberton", 0
    format db "%s", 0
    newline db 10, 0

section .text
    global main
    extern printf

main:
    push rdi             ; Preserve registers
    push rsi
    push rax

    mov rdi, format      ; Load the format string
    mov rsi, hello       ; Load the hello string
    call printf          ; Call printf

    mov rdi, format      ; Load the format string
    mov rsi, newline     ; Load the newline string
    call printf          ; Call printf

    pop rax              ; Restore registers
    pop rsi
    pop rdi

    xor rax, rax         ; Return 0
    ret

