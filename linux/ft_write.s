; ssize_t write(int fildes, const void *buf, size_t nbyte)
	global ft_write
	extern	__errno_location
	section .text

; rdi = fildes, rsi = buf, rdx = nbyte
ft_write:
  mov rax, 1 ; write syscall number
	syscall
	cmp		rax, 0
	jl		.error
	ret

.error:
	mov r8, rax
	neg r8  ; error code is returned negative value (-errno), so flip the sign.
	call	__errno_location WRT ..plt ; Set the address of errno in rax
	mov [rax], r8 ; Restore the error code in rax
	mov rax, -1
	ret