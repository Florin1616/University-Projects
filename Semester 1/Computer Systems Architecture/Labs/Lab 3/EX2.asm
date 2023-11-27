bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 7h
    b dw 15h
    c dd 24h
    d dq 39h

; our code starts here
segment code use32 class=code
    start:
        ;a-b -(c-d)+d SIGNED
        mov al, [a]
        cbw
        mov bx, [b]
        sub ax, bx ; ax = a-b
        cwde ; eax = a-b
        cdq ; edx:eax = edx:eax = a-b (quadword)
        mov ebx, eax
        mov ecx, edx ; ecx:ebx = a-b (quadword)
        mov eax, [c]
        cdq ; edx:eax = c(quadword)
        sub eax,dword[d]
        sbb edx,dword[d+4] ; edx:eax = c-d (quadword)
        sub ebx, eax
        sbb ecx, edx ; ecx:ebx = a-b-(c-d) (quadword)
        add ebx, dword[d]
        adc ecx, dword[d+4] ;ecx:ebx = a-b -(c-d)+d
               
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
