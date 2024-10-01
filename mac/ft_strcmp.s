; int ft_strcmp(const char *s1, const char *s2)
  global _ft_strcmp
  section .text

; s1 = rdi, s2 = rsi
_ft_strcmp:
  xor rcx, rcx

.loop:
  mov al, BYTE[rdi + rcx]
  mov r8b, BYTE[rsi + rcx]
  cmp al, r8b
  jne .diff

  cmp al, 0
  je .done

  inc rcx
  jmp .loop

.diff:
  movzx rax, al ; zero extension to support multibyte strings
  movzx r8, r8b
  sub rax, r8
  ret

.done:
  xor rax, rax
  ret
