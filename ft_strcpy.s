global _ft_strcpy

section .text
    _ft_strcpy:
		mov rax, 0
		mov rdx, 0
		.iter:
			cmp [rsi + rax], byte 0
			je .close

			mov rdx, [rsi + rax]
			mov [rdi + rax], rdx

			inc rax
			jmp .iter

		.close:
			inc rax
			mov [rdi + rax], byte 0
			mov rax, rdi
			ret
