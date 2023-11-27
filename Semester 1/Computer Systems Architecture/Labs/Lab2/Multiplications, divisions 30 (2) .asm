bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 4h
    b db 13h
    c db 6h
    d db 10h
    e dw 15h
    f dw 19h
    g dw 13h
    h dw 11h

; our code starts here
segment code use32 class=code
    start:
        ;100/(e+h-3*a)
        mov ax, [e]
        add ax, [h] 
        mov bx, 0
        mov bx, ax ; bx = e+h
        mov eax, 0
        mov al, [a]
        mov cl, 3h
        mul cl
        sub bx, ax ; bx= e+h - 3*a
        mov eax, 0
        mov ax, 100h
        div bx ;ax=100/(e+h-3*a)
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
