%ifndef LIBASM_S
%define LIBASM_S

%define NULL	0
%define EOF		-1

%define STDIN	0
%define STDOUT	1
%define STDERR	2

%define SYSCALL_CLASS_MACH(x)	(0x01000000 | x)
%define SYSCALL_CLASS_UNIX(x)	(0x02000000 | x)

%define SYS_WRITE				SYSCALL_CLASS_UNIX(4)

%endif
