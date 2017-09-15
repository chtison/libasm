%include "libasm.s"

global _ft_strdup
extern _ft_strlen
extern _malloc

_ft_strdup:
	; New stack frame
	push	rbp
	mov		rbp, rsp
	; Compute length of the string pointed by rdi
	push	rdi
	call	_ft_strlen
	inc		rax
	push	rax
	; Malloc
	mov		rdi, rax
	call	_malloc
	; Test result
	cmp		rax, NULL
	je		.r
	; Copy
	mov		rdi, rax
	pop		rcx
	pop		rsi
	cld
	rep movsb
	; Return
.r:	mov		rsp, rbp
	pop		rbp
	ret
