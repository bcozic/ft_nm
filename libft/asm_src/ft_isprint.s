section .text
global _ft_isprint
 
_ft_isprint:
			push rbp
			mov rbp, rsp
			cmp rdi, 0x7e
			jg false
			cmp rdi, 0x20
			jge true
false:
			mov rax, 0
			leave
			ret
true:
			mov rax, 1
			leave
			ret