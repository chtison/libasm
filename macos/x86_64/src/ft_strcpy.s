global _ft_strcpy

section .text
_ft_strcpy:
	; Save rdi onto the stack
	enter	8, 0
	mov		[rsp], rdi

	; Copy
	cld
	mov		rax, 0
	jmp		c
l:	movsb
c:	cmp		byte [rsi], 0
	jne		l
	stosb

	; Return original rdi
	mov		rax, [rsp]
	leave
	ret
