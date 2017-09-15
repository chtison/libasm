global _ft_memset

_ft_memset:
	mov		r8, rdi
	mov		rcx, rdx
	mov		rax, rsi
	cld
	rep stosb
	mov		rax, r8
	ret
