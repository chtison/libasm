global _ft_memcpy

_ft_memcpy:
	mov		r8, rdi
	mov		rcx, rdx
	cld
	rep movsb
	mov		rax, r8
	ret
