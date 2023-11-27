bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s dd 12345678h, 1A2B3C4Dh, 0FE98DC76h 
    lens equ ($-s)/4
    d times lens db 0

; our code starts here
segment code use32 class=code
    start:
        ; A string of doublewords is given. Compute the string formed by the high bytes of the 
        ;low words from the elements of the doubleword 
        ;string and these bytes should be multiple of 10.
        mov ecx,lens
        jecxz final
        mov esi,s
        mov edi,d
        cld
    repeta:
        lodsb ;mutam primul octet al cuvantului in al
        lodsb ;al doilea octet esxte acum in AL
        mov dl,al ;pastram valoarea lui AL in DL
        mov ah,0 ;punem 0 in AX ca sa putem vedea restul impartirii la 10 
        mov bl,10 ;stocam valoarea 10 in bl
        div bl ;impartim octetul superior din word ul inferior la 10
        cmp ah,0 ;verificam daca restul impartirii stocat in AH este 0
        jnz dupa
        mov al,dl ;daca restul este 0 mutam inapoi in al, byte ul superior din wordul inferior
        stosb ;mutam valoarea in edi
        dupa:
        add esi,2 ;ne mutam pe urmatorul byte inferior din word ul inferior
    loop repeta
    final:
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

        