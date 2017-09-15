global _ft_strcpy

section .text
_ft_strcpy:
	; Save rdi onto the stack
	enter	8, 0
	mov		[rsp], rdi
	; Copy
	jmp		_ft_strcpy.c
.l:	movsb
.c:	cmp		byte [rsi], 0
	jne		_ft_strcpy.l
	mov		byte [rdi], 0
	; Return original rdi
	mov		rax, [rsp]
	leave
	ret
