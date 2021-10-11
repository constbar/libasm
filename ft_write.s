global _ft_write
extern ___error

section .text
	_ft_write:
		mov rax, 0x2000004
		syscall
		jc .err			; if rax != 1
		ret

	.err:
		mov rdi, rax
		call ___error   ; adr of err
		mov [rax], rdi  ; put num of err in errno
		mov rax, -1
		ret