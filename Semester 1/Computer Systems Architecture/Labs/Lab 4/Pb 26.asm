bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; Given 2 dublucuvinte R and T. Compute the doubleword Q as follows:
        ;the bits 0-6 of Q are the same as the bits 10-16 of T
        ;the bits 7-24 of Q are the same as the bits 7-24 of (R XOR T).
        ;the bits 25-31 of Q are the same as the bits 5-11 of R.
        R dd 00110010001011101100100011001011b
        T dd 11001001100101101001000111010011b
        Q dd 0

; our code starts here
segment code use32 class=code
    start:
        mov eax, 0 ; we store the result in eax
        mov edx, [T]
        and edx, 00000000000000011111110000000000b ; isolate bits 10-16 of T
        mov cl, 10
        ror edx, cl ; rotate 10 positions to the right
        or eax, edx ; update the result in eax
        
        mov edx, [R]
        mov ecx, [T]
        xor edx, ecx ; edx = R XOR T
        and edx, 00000001111111111111111110000000b ;isolate bits 7-24 of R XOR T
        or eax, edx ; update the result in eax
        
        mov edx, [R]
        and edx, 00000000000000000000111111100000b ; isolate bits 5-11 of R
        mov cl, 20
        rol edx, cl ; rotate 20 positios to the left
        or eax, edx 
        mov [Q], eax ;Q is the final result
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
