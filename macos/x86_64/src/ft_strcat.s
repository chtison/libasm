global _ft_strcat
extern _ft_strcpy

section .text
_ft_strcat:
	; Save rdi onto the stack
	enter	8, 0
	mov		[rsp], rdi
	; Increment rdi until next null-byte
	cld
	mov			rcx, -1
	mov			rax, 0
	repnz scasb
	dec			rdi
	; Copy
	call		_ft_strcpy
	; Return original rdi
	mov		rax, [rsp]
	leave
	ret
