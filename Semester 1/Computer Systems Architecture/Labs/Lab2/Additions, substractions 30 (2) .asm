bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dw 12h
    b dw 7h
    c dw 4h
    d dw 13h

; our code starts here
segment code use32 class=code
    start:
        ;a-b+(c-d+a)
        mov eax, 0
        mov ebx, 0
        mov ax, [a]
        sub ax, [b] ;ax = a-b
        mov bx, [c]
        sub bx, [d] ;bx=c-d
        add bx, [a] ;bx=c-d+a
        add ax, bx ;ax = a-b+(c-d+a)
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
