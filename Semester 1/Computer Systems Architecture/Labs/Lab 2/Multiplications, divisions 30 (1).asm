bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 19h 
    b db 9h
    c db 11h
    d dw 3h

; our code starts here
segment code use32 class=code
    start:
        ;[(a-b)*5+d]-2*c
        mov eax, 0
        mov al, [a]
        sub al, [b] ;al = a-b
        mov bl, 5
        mul bl ; ax = (a-b)*5
        add ax, [d] ; ax=(a-b)*5 + d
        mov bx, ax  ; bx=(a-b)*5 + d
        mov al, [c] 
        mov cl, 2
        mul cl ; ax= 2*c
        sub bx, ax ; bx=[(a-b)*5+d]-2*c
        
        
        
        
        
        
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
