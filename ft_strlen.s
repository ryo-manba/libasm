; size_t ft_strlen(const char* s)
section .text
  global _ft_strlen

; rdi = s, rcx = counter, rax = retval
_ft_strlen:
  xor rcx, rcx

.loop:
  cmp byte[rdi + rcx], 0 ; Check if a character is a terminator.
  je .done
  inc rcx
  jmp .loop

.done:
  mov rax, rcx
  ret
