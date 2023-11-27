bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s dd 15345678h, 152B3C4Dh, 0FE98DC76h
    
    l1 equ ($-s)/4 ;lungimea in doublewords
    d times l1 db 0 ;aici as avea o intrebare despre cum trebuie sa declaram d ul deoarece vrem sa stocam octeti
    trei db 3
    
; our code starts here
segment code use32 class=code
    start:
    
    ;A string of doublewords is given. Obtain the list made out of the high bytes of 
    ;the high words of each doubleword from the given list with the property that these bytes are multiple of 3.
        ; ...
        mov esi, s
        mov edi, d
        cld
        mov ecx, l1
        jecxz final
        repeta: 
            lodsb ; in al avem byte ul low din word ul low
            lodsb ; in al avem byte ul high din word ul low
            lodsb 
            lodsb ; in al avem byte ul high din word ul high
            mov dl, al
            mov ah, 0 ;il facem word ca sa putem vedea daca este divizibil cu 3
            div byte[trei]
            cmp ah, 0
            jnz nondivizibil
                mov al, dl
                stosb
            nondivizibil:
        loop repeta
    
        ; exit(0)
        final:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
