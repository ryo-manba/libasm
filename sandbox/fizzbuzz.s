.intel_syntax noprefix
.global main

main:
	mov rcx, 0x1
loop:
	# fizz
	mov rdx, 0
	mov rax, rcx
	mov r15, 3
	div r15
	# rdx is zero?
	cmp rdx, 0
	jne skipfizz

	# call write
	mov rdx, 0x4
	lea rsi, [fizz]
	mov rdi, 0x1
	mov rax, 0x1
	push rcx
	syscall
	pop rcx

skipfizz:
	# buzz
	mov rdx, 0
	mov rax, rcx
	mov r15, 5
	div r15
	# rdx is zero?
	cmp rdx, 0
	jne skipbuzz

	# call write
	mov rdx, 0x4
	lea rsi, [buzz]
	mov rdi, 0x1
	mov rax, 0x1
	push rcx
	syscall
	pop rcx

skipbuzz:
	inc rcx
	# write new line
	mov rdx, 0x1
	lea rsi, [newline]
	mov rdi, 0x1
	mov rax, 0x1
	push rcx
	syscall
	pop rcx
	cmp rcx, 16
	jz exit
	jmp loop
exit:
	mov rax, 0x3c
	syscall

fizz:
	.ascii	"fizz"
buzz:
	.ascii	"buzz"
newline:
	.ascii "\n"
