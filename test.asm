

        mov a, #11111110B
main:   mov r3, #7
right:  mov p1, a     ; 向右移动7次
        rl a
        call delay
        djnz r3, right
        mov r3, #7
left:  mov p1, a      ; 向左移动7次
        rr a
        call delay
        djnz r3, left
        sjmp main



; 子程序 用于延迟0.5秒
delay:    mov r0, #128
next0:    mov r1, #128
next1:    mov r2, #128
next2:    djnz r2, next2
          djnz r1, next1
          djnz r0, next0
          ret

          1 + 2 * 128 * (1 + 2 * 128 * (1 + 2 * 15))
