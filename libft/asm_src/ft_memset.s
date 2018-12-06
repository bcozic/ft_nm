section .text
global _ft_memset

_ft_memset:
			push rbp
			mov rbp, rsp
			mov rax, rsi
			mov rcx, rdx
			mov rdx, rdi
			rep stosb
end_set:
			mov rax, rdx
			leave
			ret