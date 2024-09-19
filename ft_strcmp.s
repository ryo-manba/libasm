; int ft_strcmp(const char *s1, const char *s2)
  global _ft_strcmp
  section .text

; s1 = rdi, s2 = rsi
_ft_strcmp:
  xor rcx, rcx
  push rbx

.loop:
  mov al, BYTE[rdi + rcx]
  cmp al, 0
  je .done

  mov bl, BYTE[rsi + rcx]
  cmp bl, 0
  je .done

  cmp al, bl
  jne .diff

  inc rcx
  jmp .loop

.diff:
  sub al, bl
  movsx rax, al ; see: https://www.sigbus.info/compilerbook#%E3%82%B9%E3%83%86%E3%83%83%E3%83%9724-%E6%96%87%E5%AD%97%E5%9E%8B%E3%82%92%E5%AE%9F%E8%A3%85%E3%81%99%E3%82%8B
  pop rbx
  ret

.done:
  xor rax, rax
  pop rbx
  ret
