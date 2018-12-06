section .text
global _ft_isdigit
 
_ft_isdigit:
			push rbp
			mov rbp, rsp
			cmp rdi, '9'
			jg false
			cmp rdi, '0'
			jge true
false:
			mov rax, 0
			leave
			ret
true:
			mov rax, 1
			leave
			ret