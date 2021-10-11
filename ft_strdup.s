global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc

section .text
	_ft_strdup:
		mov rax, 0
		push rdi
		call _ft_strlen
		inc rax
		mov rdi, rax
		call _malloc
		cmp rax, 0
		je .stop
		pop rdi
		mov rsi, rdi
		mov rdi, rax
		call _ft_strcpy
		ret
	.stop:
		pop rdi
		ret