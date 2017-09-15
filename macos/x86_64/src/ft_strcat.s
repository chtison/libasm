global _ft_strcat
extern _ft_strcpy

_ft_strcat:
	mov			r8, rdi
	; Increment rdi until next null-byte
	cld
	mov			rcx, -1
	mov			rax, 0
	repnz scasb
	dec			rdi
	; Copy
	call		_ft_strcpy
	; Return
	mov			rax, r8
	ret
