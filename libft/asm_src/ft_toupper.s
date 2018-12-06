section .text
global _ft_toupper
 
_ft_toupper:
			push rbp
			mov rbp, rsp
			cmp rdi, 'z'
			jg end
			cmp rdi, 'a'
			jge tolow
			jmp end
tolow:
			sub rdi, ('a' - 'A')
end:
			mov rax, rdi
			leave
			ret