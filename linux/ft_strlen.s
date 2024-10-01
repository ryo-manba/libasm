; size_t ft_strlen(const char* s)
  global ft_strlen
  section .text

; rdi = s, rcx = counter, rax = retval
ft_strlen:
  xor rcx, rcx

.loop:
  cmp byte[rdi + rcx], 0 ; Check if a character is a terminator.
  je .done
  inc rcx
  jmp .loop

.done:
  mov rax, rcx
  ret
