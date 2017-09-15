%include "libasm.s"

global _ft_puts
extern _ft_strlen
extern _malloc
extern _free

_ft_puts:
	; New stack frame
	push	rbp
	mov		rbp, rsp
	; Save rdi
	push	rdi
	; Compute length of string pointed by rdi
	call	_ft_strlen
	push	rax
	inc		rax
	; Malloc
	mov		rdi, rax
	call	_malloc
	cmp		rax, NULL
	je		.e
	push	rax
	; Copy
	mov		rdi, rax
	mov		rsi, [rsp+16]
	mov		rcx, [rsp+8]
	cld
	rep movsb
	mov		byte [rdi], 10
	; Write(fd, *char, len)
	mov		rdi, STDOUT
	mov		rsi, [rsp]
	mov		rdx, [rsp+8]
	inc		rdx
	mov		rax, SYSCALL_WRITE
	syscall
	push	rax
	; Free
	mov		rdi, [rsp+8]
	call	_free
	pop		rax
	jmp		.r
	; Return
.e:	mov		rax, EOF
.r:	mov		rsp, rbp
	pop		rbp
	ret
