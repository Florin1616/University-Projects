bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
     a db 11h
     b dw 19h
     c dd 65h
     d dq 24h

; our code starts here
segment code use32 class=code
    start:
    ;(a+c)-b+a + (d-c) UNSIGNED
        mov al, [a]
        mov ah, 0 ; ax = a (word)
        mov dx, 0
        push dx
        push ax
        pop eax ; eax = a (dw)
        add eax, dword[c] ; eax = a+c
        mov bx, [b] ; bx = b
        mov cx, 0
        push cx
        push bx
        pop ebx ; ebx = b(dw)
        sub eax, ebx ; eax = (a+c)-b
        mov bl, [a]
        mov bh, 0 ; bx = a (word)
        mov cx, 0
        push cx
        push bx
        pop ebx; ebx = a (doubleword)
        add eax, ebx ;eax = (a+c)-b+a
        push eax
        mov eax, dword[d]
        mov edx, dword[d+4]
        mov ebx, [c]
        mov ecx, 0 ; ecx:ebx = c(quadword) 
        sub eax, ebx
        sbb edx, ecx
        pop ebx
        mov ecx, 0
        add eax, ebx
        adc edx, ecx ; edx:eax = (a+c)-b+a + (d-c) (quadword)
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
