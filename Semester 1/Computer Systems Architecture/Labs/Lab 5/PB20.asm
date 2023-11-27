bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 2, 1, 3, 3, 4, 2, 6
    la equ $-a
    b db 4, 5, 7, 6, 2, 1
    lb equ $-b
    r times (la+lb) db 0
    
; our code starts here
segment code use32 class=code
    start:
    ;Two byte strings A and B are given. Obtain the string R by 
    ;   concatenating the elements of B in reverse order and the even elements of A.
        mov ecx, lb
        jecxz final1
        mov edi, 0
        mov esi, 0
        add esi, lb-1
        Repeta1:
            mov al, [b+esi]
            mov [r+edi], al
            inc edi
            dec esi
        loop Repeta1
        final1:
        
        mov ecx, la
        jecxz final2
        mov esi, 0
        Repeta2:
            mov al, [a+esi]
            test al, 1
            jnz impar
            mov [r+edi], al
            inc edi
            impar:
            inc esi
        loop Repeta2
        final2:
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
