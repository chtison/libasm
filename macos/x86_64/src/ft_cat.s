%include "libasm.s"

global _ft_cat

%define BUF_SIZE	4096

_ft_cat:
	push	rbp
	mov		rbp, rsp
	sub		rsp, BUF_SIZE+8
	mov		[rbp-8], rdi

.l1: ; Read
	mov		rdi, [rbp-8]
	mov		rsi, rsp
	mov		rdx, BUF_SIZE
	mov		rax, SYSCALL_READ
	cmp		rax, 0
	jle		.r
	mov		r8, BUF_SIZE
.l2: ; Write
	mov		rdi, STDOUT
	mov		rsi, rsp
	add		rsi, BUF_SIZE
	sub		rsi, r8
	mov		rdx, r8
	mov		rax, SYSCALL_WRITE
	cmp		rax, 0
	jl		.r
	sub		r8, rax
	cmp		r8, 0
	jg		.l2
	je		.l1

.r:	mov		rsp, rbp
	pop		rbp
	ret
