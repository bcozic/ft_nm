section .text
global _ft_strlen

_ft_strlen:
			push rbp
			mov rbp, rsp
			mov r9, rdi
			mov rcx, -1
			mov rax, 0
			repnz scasb
			sub rdi, 1
			mov rax, rdi
			sub rax, r9
			leave
			ret
