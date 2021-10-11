global _ft_strlen

section .text
	_ft_strlen:
		mov rax, 0
		.iter:
			cmp [rdi + rax], byte 0
			je .close
			inc rax
			jmp .iter
			
		.close:
			ret