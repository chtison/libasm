global _ft_strcpy

_ft_strcpy:
	mov		rax, rdi
	jmp		.c
.l:	movsb
.c:	cmp		byte [rsi], 0
	jne		.l
	mov		byte [rdi], 0
	ret
