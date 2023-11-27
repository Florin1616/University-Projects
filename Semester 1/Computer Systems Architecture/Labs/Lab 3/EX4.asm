bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dw 11
    b db 19
    e dd 51
    x dq 16

; our code starts here
segment code use32 class=code
    start:
        ;x-b+8+(2*a-b)/(b*b)+e SIGNED
        mov al,[b]
        cbw
        cwde
        cdq ; edx:eax = b (quadword)
        mov ebx,dword[x]
        mov ecx ,dword[x+4]
        sub ebx, eax
        sbb ecx, edx ; ecx:ebx = x-b (quadword)
        add ebx, 8 ; ecx:ebx = x-b+8 (quadword)
        mov ax, 2
        imul word[a] ;ax = a*2
        mov dx, ax ; dx = a*2
        mov al, [b]
        cbw ;ax = b (word)
        sub dx, ax ; dx=2*a-b (word)
        push ecx 
        push ebx
        mov ax, dx; ax=2*a-b
        cwd ;dx:ax = 2*a-b (doubleword)
        mov bx, ax
        mov cx, dx ; cx:bx 2*a-b (doubleword)
        mov al, [b]
        imul byte[b] ; ax = b*b (word)
        xchg ax, bx ;bx=b*b
        mov dx, cx ; dx:ax = 2*a-b doubleword
        idiv bx ;ax= (2*a-b)/(b*b) word
        cwde
        cdq ; edx:eax = (2*a-b)/(b*b) quadword
        pop ebx
        pop ecx
        add ebx, eax
        adc ecx, edx ;ecx:ebx = x-b+8+(2*a-b)/(b*b) quadword
        mov eax, [e]
        cdq
        add ebx, eax
        adc ecx, edx ; ecx:ebx = x-b+8+(2*a-b)/(b*b)+e quadword
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
