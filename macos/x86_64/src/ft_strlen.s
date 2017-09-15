global _ft_strlen

_ft_strlen:
	mov			rcx, -1
	mov			rax, 0
	cld
	repnz scasb
	mov			rax, rcx
	not			rax
	dec			rax
	ret
