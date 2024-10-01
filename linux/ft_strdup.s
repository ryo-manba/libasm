; char *strdup(const char *s1)
  global ft_strdup
  extern malloc
  extern ft_strlen
  extern ft_strcpy
	extern	__errno_location

  section .text

; rdi = s
ft_strdup:
  push rdi ; Save *s1 on the stack

  call ft_strlen
  mov rdi, rax ; Move the string length to rdi
  inc rdi      ; Increment for the null terminator
  call malloc WRT ..plt
  cmp rax, 0   ; Check if malloc failed (rax = 0 means return null pointer)
  je .malloc_failed

  mov rdi, rax ; Move allocated memory address to rdi
  pop rsi      ; Restore the *s1 into second argments
  call ft_strcpy
  ret

.malloc_failed:
	mov r8, rax
	neg r8  ; error code is returned negative value (-errno), so flip the sign.
	call	__errno_location WRT ..plt ; Set the address of errno in rax
	mov [rax], r8 ; Restore the error code in rax
	mov rax, 0
	ret