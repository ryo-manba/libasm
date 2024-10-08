; char *strdup(const char *s1)
  global _ft_strdup
  extern _malloc
  extern _ft_strlen
  extern _ft_strcpy
  extern ___error

  section .text

; rdi = s
_ft_strdup:
  push rdi ; Save *s1 on the stack

  call _ft_strlen
  mov rdi, rax ; Move the string length to rdi
  inc rdi      ; Increment for the null terminator
  call _malloc
  cmp rax, 0   ; Check if malloc failed (rax = 0 means return null pointer)
  je .malloc_failed

  mov rdi, rax ; Move allocated memory address to rdi
  pop rsi      ; Restore the *s1 into second argments
  call _ft_strcpy
  ret

.malloc_failed:
  mov r8, rax
  call ___error ; Call ___error to set the address of errno in rax
  mov [rax], r8 ; Restore the error code in rax
  mov rax, 0
  ret