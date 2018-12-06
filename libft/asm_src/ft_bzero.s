section .text
global _ft_bzero

_ft_bzero:
			push rbp
			mov rbp, rsp
			mov rax, 0
			mov rcx, rsi
			mov rdx, rdi
			rep stosb
end_set:
			leave
			ret