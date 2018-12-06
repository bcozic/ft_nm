%define SYSCALL(nb)		0x2000000 | nb
%define WRITE			4
%define READ			3
%define STDOUT			1
%define BUFF_SIZE		16384

section .data
string:
		.buff resb BUFF_SIZE

section .text
global _ft_cat

_ft_cat:
			push rbp
			mov rbp, rsp
			push rdi
			push rdi
start_readding:
			pop rdi
			push rdi
			lea rsi, [rel string.buff]
			mov rdx, BUFF_SIZE
			mov rax, SYSCALL(READ)
			syscall
			cmp rax, 0
			jle end
			mov rdi, STDOUT
			mov rdx, rax
			mov rax, SYSCALL(WRITE)
			syscall
			cmp rax, 0
			jl end
			jmp start_readding
end:
			leave
			ret
			