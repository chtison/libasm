global _ft_bzero

section .text
_ft_bzero:
	cld
	mov			rcx, rsi
	mov			rax, 0
	rep stosb
	ret
