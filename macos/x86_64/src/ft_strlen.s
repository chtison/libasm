global _ft_strlen

section .text
_ft_strlen:
	cld
	mov			rcx, -1
	mov			rax, 0
	repnz scasb
	mov			rax, rcx
	not			rax
	dec			rax
	ret
