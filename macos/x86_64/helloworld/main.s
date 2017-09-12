global start
global _main

extern _printf

section .data
hello:	db 'Hello World !', 10
.len	equ $-hello
bye:	db 'Goodbye World !', 10

section .text
start:
	call _main
	ret

_main:
	; Write 'Hello World !'
	mov		rdi, 1				; stdout
	mov		rsi, hello
	mov		rdx, hello.len
	mov		rax, 0x02000004		; write
	syscall

	; Printf 'Goodbye World !'
	push	rbp
	mov		rbp, rsp
	mov 	rdi, bye
	call 	_printf
	leave

	; Exit 0
	mov		rdi, 0
	mov		rax, 0x02000001
	syscall

	ret
