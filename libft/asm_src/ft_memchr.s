section .text
global _ft_memchr

_ft_memchr:
			push rbp
			mov rbp, rsp
			mov r9, rdi
			mov rcx, rdx
			mov rax, rsi
			repnz scasb
			dec rdi
			cmp al, byte [rdi]
			jne not_found
			mov rax, rdi
			leave
			ret
not_found:
			mov rax, 0
			leave
			ret
