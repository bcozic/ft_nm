section .text
global _ft_tolower

_ft_tolower:
			push rbp
			mov rbp, rsp
			cmp rdi, 'Z'
			jg end
			cmp rdi, 'A'
			jge tolow
			jmp end
tolow:
			add rdi, ('a' - 'A')
end:
			mov rax, rdi
			leave
			ret