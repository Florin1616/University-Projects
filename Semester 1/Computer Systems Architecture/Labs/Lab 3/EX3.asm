bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dw 18h
    b db 9h
    e dd 41h
    x dq 37h

; our code starts here
segment code use32 class=code
    start:
        ;x-b+8+(2*a-b)/(b*b)+e UNSIGNED
        mov al, [b]
        mov ah, 0
        mov dx, 0
        push dx
        push ax
        pop eax ; eax = b(doubleword)
        mov edx, 0 ; edx:eax = b (quadword)
        mov ebx, dword[x]
        mov ecx, dword[x+4] ; ecx:ebx = x (quadword)
        sub ebx, eax
        sbb ecx, edx ; ecx:ebx = x-b (quadword)
        add ebx, 8 ; ecx:ebx = x-b+8
        mov ax, 2
        mul word[a] ; ax = a*2 (word)
        mov dx, ax ; dx=a*2
        mov al, [b]
        mov ah, 0 ;ax = b (word)
        sub dx, ax ; dx= 2*a-b (word)
        mov ax, dx
        mov dx, 0 ; dx:ax = 2*a-b (doubleword)
        push ecx
        push ebx
        mov bx, ax
        mov cx, dx ; cx:bx = 2*a-b (doubleword)
        mov al, [b]
        mul byte[b] ; ax = b*b (word)
        xchg ax, bx 
        mov dx, cx ; dx:ax = 2*a-b (quadw) ,bx = b*b (word)
        div bx ; dx:ax = (2*a-b)/(b*b) dx = (2*a-b)%(b*b)- word  ax =(2*a-b)/(b*b) - word
        pop ebx 
        pop ecx ; ecx:ebx = x-b+8 (qw)
        mov dx, 0
        push dx
        push ax
        pop eax ; eax = (2*a-b)/(b*b) doubleword
        mov edx, 0 ; edx:eax = (2*a-b)/(b*b) (quadword)
        add ebx, eax
        adc ecx, edx ; ecx:ebx = x-b+8+(2*a-b)/(b*b) (quadword)
        mov eax, [e]
        mov edx, 0 ; edx:eax = e (quadword)
        add ebx, eax
        adc ecx, edx ;ecx:ebx = x-b+8+(2*a-b)/(b*b)+e (quadword)
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
