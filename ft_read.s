; ssize_t read(int fildes, void *buf, size_t nbyte)
  global _ft_read
  extern ___error
  section .text

; rdi = fildes, rsi = buf, rdx = nbyte
_ft_read:
  mov rax, 0x2000003 ; read syscall number
  syscall
  jc .error
  ret

.error:
  mov r8, rax
	call ___error ; Call ___error to set the address of errno in rax
	mov [rax], r8 ; Restore the error code in rax
	mov rax, -1
	ret
