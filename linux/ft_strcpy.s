; char *strcpy(char * dst, const char * src);
  global ft_strcpy
  section .text

; dst = rdi, src = rsi
ft_strcpy:
  xor rcx, rcx

.loop:
  mov al, BYTE[rsi + rcx]
  mov BYTE[rdi + rcx], al
  inc rcx
  cmp al, 0
  jne .loop

.done:
  mov rax, rdi
  ret