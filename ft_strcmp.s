global _ft_strcmp

section .text
_ft_strcmp:
	mov rax, 0
	.iter:
		mov dl, [rdi + rax]
		mov bl, [rsi + rax]

		cmp dl, bl
		jne .dif

		cmp dl, 0
		je .dif
		
		inc rax
		jmp .iter

	.dif:
		sub dl, bl
		movsx rax, dl
		ret
